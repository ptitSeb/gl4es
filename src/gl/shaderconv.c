#include <string.h>
#include "shaderconv.h"
#include "../glx/hardext.h"
#include "debug.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

typedef struct {
    const char* glname;
    const char* name;
    const char* type;
    const char* prec;
    reserved_attrib_t attrib;
} builtin_attrib_t;

const builtin_attrib_t builtin_attrib[] = {
    {"gl_Vertex", "_gl4es_Vertex", "vec4", "highp", ATT_VERTEX},
    {"gl_Color", "_gl4es_Color", "vec4", "lowp", ATT_COLOR},
    {"gl_MultiTexCoord0", "_gl4es_MultiTexCoord0", "vec4", "highp", ATT_MULTITEXCOORD0},
    {"gl_MultiTexCoord1", "_gl4es_MultiTexCoord1", "vec4", "highp", ATT_MULTITEXCOORD1},
    {"gl_MultiTexCoord2", "_gl4es_MultiTexCoord2", "vec4", "highp", ATT_MULTITEXCOORD2},
    {"gl_MultiTexCoord3", "_gl4es_MultiTexCoord3", "vec4", "highp", ATT_MULTITEXCOORD3},
    {"gl_MultiTexCoord4", "_gl4es_MultiTexCoord4", "vec4", "highp", ATT_MULTITEXCOORD4},
    {"gl_MultiTexCoord5", "_gl4es_MultiTexCoord5", "vec4", "highp", ATT_MULTITEXCOORD5},
    {"gl_MultiTexCoord6", "_gl4es_MultiTexCoord6", "vec4", "highp", ATT_MULTITEXCOORD6},
    {"gl_MultiTexCoord7", "_gl4es_MultiTexCoord7", "vec4", "highp", ATT_MULTITEXCOORD7},
    {"gl_Normal", "_gl4es_Normal", "vec3", "highp", ATT_NORMAL}
};

typedef struct {
    const char* glname;
    const char* name;
    const char* type;
    int   texarray;
    reserved_matrix_t matrix;
} builtin_matrix_t;

const builtin_matrix_t builtin_matrix[] = {
    {"gl_ModelViewMatrixInverseTranspose", "_gl4es_ITModelViewMatrix", "mat4", 0, MAT_MV_IT},
    {"gl_ModelViewMatrixInverse", "_gl4es_IModelViewMatrix", "mat4", 0, MAT_MV_I},
    {"gl_ModelViewMatrixTranspose", "_gl4es_TModelViewMatrix", "mat4", 0, MAT_MV_T},
    {"gl_ModelViewMatrix", "_gl4es_ModelViewMatrix", "mat4", 0, MAT_MV},
    {"gl_ProjectionMatrixInverseTranspose", "_gl4es_ITProjectionMatrix", "mat4", 0, MAT_P_IT},
    {"gl_ProjectionMatrixInverse", "_gl4es_IProjectionMatrix", "mat4", 0, MAT_P_I},
    {"gl_ProjectionMatrixTranspose", "_gl4es_TProjectionMatrix", "mat4", 0, MAT_P_T},
    {"gl_ProjectionMatrix", "_gl4es_ProjectionMatrix", "mat4", 0, MAT_P},
    {"gl_ModelViewProjectionMatrixInverseTranspose", "_gl4es_ITModelViewProjectionMatrix", "mat4", 0, MAT_MVP_IT},
    {"gl_ModelViewProjectionMatrixInverse", "_gl4es_IModelViewProjectionMatrix", "mat4", 0, MAT_MVP_I},
    {"gl_ModelViewProjectionMatrixTranspose", "_gl4es_TModelViewProjectionMatrix", "mat4", 0, MAT_MVP_T},
    {"gl_ModelViewProjectionMatrix", "_gl4es_ModelViewProjectionMatrix", "mat4", 0, MAT_MVP},
    {"gl_TextureMatrixInverseTranspose", "_gl4es_ITTextureMatrix", "mat4", 1, MAT_T0_IT},
    {"gl_TextureMatrixInverse", "_gl4es_ITextureMatrix", "mat4", 1, MAT_T0_I},
    {"gl_TextureMatrixTranspose", "_gl4es_TTextureMatrix", "mat4", 1, MAT_T0_T},
    {"gl_TextureMatrix", "_gl4es_TextureMatrix", "mat4", 1, MAT_T0},
    {"gl_NormalMatrix", "_gl4es_NormalMatrix", "mat3", 0, MAT_N}
};

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
const char* gl4es_MaxLightsSource =
"#define _gl4es_MaxLights " STR(MAX_LIGHT) "\n";
#undef STR
#undef STR_HELPER

const char* gl4es_LightSourceParametersSource = 
"struct gl_LightSourceParameters\n"
"{\n"
"   vec4 ambient;\n"
"   vec4 diffuse;\n"
"   vec4 specular;\n"
"   vec4 position;\n"
//"   vec4 halfVector;\n"   //halfVector = normalize(position - gl_Vertex), so just replace it when used
"   vec3 spotDirection;\n"
"   float spotExponent;\n"
"   float spotCutoff;\n"
"   float spotCosCutoff;\n"
"   float constantAttenuation;\n"
"   float linearAttenuation;\n"
"   float quadraticAttenuation;\n"
"};\n"
"uniform gl_LightSourceParameters gl_LightSource[gl_MaxLights];\n";

const char* gl4es_MaterialParametersSource =
"struct gl_MaterialParameters\n"
"{\n"
"   vec4 emission;\n"
"   vec4 ambient;\n"
"   vec4 diffuse;\n"
"   vec4 specular;\n"
"   float shininess;\n"
"};\n"
"uniform gl_MaterialParameters gl_FrontMaterial;\n"
"uniform gl_MaterialParameters gl_BackMaterial;\n";

const char* gl4es_LightModelProductsSource =
"struct gl_LightModelProducts\n"
"{\n"
"   vec4 sceneColor;\n"
"};\n"
"uniform gl_LightModelProducts gl_FrontLightModelProduct;\n"
"uniform gl_LightModelProducts gl_BackLightModelProduct;\n";

const char* gl4es_LightProductsSource =
"struct gl_LightProducts\n"
"{\n"
"   vec4 ambient;\n"
"   vec4 diffuse;\n"
"   vec4 specular;\n"
"};\n"
"uniform gl_LightProducts gl_FrontLightProduct[gl_MaxLights];\n"
"uniform gl_LightProducts gl_BackLightProduct[gl_MaxLights];\n";

const char* AllSeparators = " \t\n\r.,;()[]{}-<>+*/%&\\\"'^$=!:?";

int CountString(char* pBuffer, const char* S);
char* ResizeIfNeeded(char* pBuffer, int *size, int addsize);

char* InplaceReplace(char* pBuffer, int* size, const char* S, const char* D)
{
    int lS = strlen(S), lD = strlen(D);
    pBuffer = ResizeIfNeeded(pBuffer, size, (lD-lS)*CountString(pBuffer, S));
    char* p = pBuffer;
    while((p = strstr(p, S)))
    {
        // found an occurence of S
        // check if good to replace, strchr also found '\0' :)
        if(strchr(AllSeparators, p[lS])!=NULL) {
            // move out rest of string
            memmove(p+lD, p+lS, strlen(p)-lS+lD+1);
            // replace
            memcpy(p, D, strlen(D));
            // next
            p+=lD;
        } else p+=lS;
    }
    
    return pBuffer;
}

void InplaceInsert(char* pBuffer, const char* S)
{
    char* p = pBuffer;
    int lS = strlen(S), ll = strlen(pBuffer);
    memmove(p+lS, p, ll+1);
    memcpy(p, S, lS);
}

char* GetLine(char* pBuffer, int num)
{
    char *p = pBuffer;
    while(num-- && (p=strstr(p, "\n"))) p+=strlen("\n");
    return (p)?p:pBuffer;
}

int CountLine(const char* pBuffer)
{
    int n=0;
    const char* p = pBuffer;
    while(p=strstr(p, "\n")) {
        p+=strlen("\n");
        n++;
    }
    return n;
}

int CountString(char* pBuffer, const char* S)
{
    char* p = pBuffer;
    int lS = strlen(S);
    int n = 0;
    while((p = strstr(p, S)))
    {
        // found an occurence of S
        // check if good to count, strchr also found '\0' :)
        if(strchr(AllSeparators, p[lS])!=NULL)
            n++;
        p+=lS;
    }
    return n;
}

char* ResizeIfNeeded(char* pBuffer, int *size, int addsize) {
    char* p = pBuffer;
    int newsize = strlen(pBuffer)+addsize+1;
    if (newsize>*size) {
        newsize += 100;
        p = (char*)realloc(pBuffer, newsize);
        *size=newsize;
    }
    return p;
}

char* ConvertShader(const char* pBuffer, int isVertex)
{
  DBG(printf("Shader source:\n%s\n", pBuffer);)
  // first change the version header, and add default precision
  char* newptr;
  newptr=strstr(pBuffer, "#version");
  if (!newptr) 
    newptr = (char*)pBuffer;
  else {
    while(*newptr!=0x0a) newptr++;
  }
  const char* GLESHeader = "#version 100\nprecision mediump float;\n";
  int tmpsize = strlen(newptr)*2+strlen(GLESHeader)+100;
  char* Tmp = (char*)malloc(tmpsize);
  strcpy(Tmp, GLESHeader);
  int headline = 2;
  // check if gl_FragDepth is used
  int fragdepth = (strstr(pBuffer, "gl_FragDepth"))?1:0;
  const char* GLESUseFragDepth = "#extension GL_EXT_frag_depth : enable";
  const char* GLESFakeFragDepth = "mediump float fakeFragDepth = 0.0;";
  if (fragdepth) {
    strcat(Tmp, hardext.fragdepth?GLESUseFragDepth:GLESFakeFragDepth);
    headline++;
  }
  strcat(Tmp, newptr);
    // now check to remove trailling "f" after float, as it's not supported too
  newptr = Tmp;
  // simple state machine...
  int state = 0;
  while (*newptr!=0x00) {
    switch(state) {
      case 0:
        if ((*newptr >= '0') && (*newptr <= '9'))
          state = 1;  // integer part
        else if (*newptr == '.')
          state = 2;  // fractional part
        else if ((*newptr==' ') || (*newptr==0x0d) || (*newptr==0x0a) || (*newptr=='-') || (*newptr=='+') || (*newptr=='*') || (*newptr=='/') || (*newptr=='(') || (*newptr==')' || (*newptr=='>') || (*newptr=='<')))
          state = 0; // separator
        else 
          state = 3; // something else
        break;
      case 1: // integer part
        if ((*newptr >= '0') && (*newptr <= '9'))
          state = 1;  // integer part
        else if (*newptr == '.')
          state = 2;  // fractional part
        else if ((*newptr==' ') || (*newptr==0x0d) || (*newptr==0x0a) || (*newptr=='-') || (*newptr=='+') || (*newptr=='*') || (*newptr=='/') || (*newptr=='(') || (*newptr==')' || (*newptr=='>') || (*newptr=='<')))
          state = 0; // separator
        else  if ((*newptr == 'f' )) {
          // remove that f
          memmove(newptr, newptr+1, strlen(newptr+1)+1);
          newptr--;
        } else
          state = 3;
          break;
      case 2: // fractionnal part
        if ((*newptr >= '0') && (*newptr <= '9'))
          state = 2;
        else if ((*newptr==' ') || (*newptr==0x0d) || (*newptr==0x0a) || (*newptr=='-') || (*newptr=='+') || (*newptr=='*') || (*newptr=='/') || (*newptr=='(') || (*newptr==')' || (*newptr=='>') || (*newptr=='<')))
          state = 0; // separator
        else  if ((*newptr == 'f' )) {
          // remove that f
          memmove(newptr, newptr+1, strlen(newptr+1)+1);
          newptr--;
        } else
          state = 3;
          break;
      case 3:
        if ((*newptr==' ') || (*newptr==0x0d) || (*newptr==0x0a) || (*newptr=='-') || (*newptr=='+') || (*newptr=='*') || (*newptr=='/') || (*newptr=='(') || (*newptr==')' || (*newptr=='>') || (*newptr=='<')))
          state = 0; // separator
        else      
          state = 3;
          break;
    }
    newptr++;
  }
  Tmp = InplaceReplace(Tmp, &tmpsize, "gl_FragDepth", (hardext.fragdepth)?"gl_FragDepthEXT":"fakeFragDepth");
  {
    // check for builtin matrix uniform...
    int n = sizeof(builtin_matrix)/sizeof(builtin_matrix_t);
    for (int i=0; i<n; i++) {
        if(strstr(Tmp, builtin_matrix[i].glname)) {
            // ok, this attribute is used
            // replace gl_name by _gl4es_ one
            Tmp = InplaceReplace(Tmp, &tmpsize, builtin_matrix[i].glname, builtin_matrix[i].name);
            // insert a declaration of it
            char def[100];
            if(builtin_matrix[i].texarray)
                sprintf(def, "uniform %s%s %s[%d];\n", (isVertex)?"highp ":"", builtin_matrix[i].type, builtin_matrix[i].name, hardext.maxtex);
            else
                sprintf(def, "uniform %s%s %s;\n", (isVertex)?"highp ":"", builtin_matrix[i].type, builtin_matrix[i].name);
            Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(def));
            InplaceInsert(GetLine(Tmp, headline++), def);
        }
    }
  }
  if(isVertex) {
      // check for builtin OpenGL attributes...
      int n = sizeof(builtin_attrib)/sizeof(builtin_attrib_t);
      for (int i=0; i<n; i++) {
          if(strstr(Tmp, builtin_attrib[i].glname)) {
              // ok, this attribute is used
              // replace gl_name by _gl4es_ one
              Tmp = InplaceReplace(Tmp, &tmpsize, builtin_attrib[i].glname, builtin_attrib[i].name);
              // insert a declaration of it
              char def[100];
              sprintf(def, "attribute %s %s %s;\n", builtin_attrib[i].prec, builtin_attrib[i].type, builtin_attrib[i].name);
              Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(def));
              InplaceInsert(GetLine(Tmp, headline++), def);
          }
      }
  }
  // check for builtin OpenGL gl_LightSource & friends
  // TODO: Handling of gl_LightSource[x].halfVector => normalize(gl_LightSource[x].position - glVertex), but what if in the FragShader ?
  if(strstr(Tmp, "gl_LightSourceParameters") || strstr(Tmp, "gl_LightSource"))
  {
    Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(gl4es_LightSourceParametersSource));
    InplaceInsert(GetLine(Tmp, headline), gl4es_LightSourceParametersSource);
    headline+=CountLine(gl4es_LightSourceParametersSource);
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_LightSourceParameters", "_gl4es_LightSourceParameters");
  }
  if(strstr(Tmp, "gl_LightModelProducts") || strstr(Tmp, "gl_FrontLightModelProduct") || strstr(Tmp, "gl_BackLightModelProduct"))
  {
    Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(gl4es_LightModelProductsSource));
    InplaceInsert(GetLine(Tmp, headline), gl4es_LightModelProductsSource);
    headline+=CountLine(gl4es_LightModelProductsSource);
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_LightModelProducts", "_gl4es_LightModelProducts");
  }
  if(strstr(Tmp, "gl_LightProducts") || strstr(Tmp, "gl_FrontLightProduct") || strstr(Tmp, "gl_BackLightProduct"))
  {
    Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(gl4es_LightProductsSource));
    InplaceInsert(GetLine(Tmp, headline), gl4es_LightProductsSource);
    headline+=CountLine(gl4es_LightProductsSource);
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_LightProducts", "_gl4es_LightProducts");
  }
  if(strstr(Tmp, "gl_MaterialParameters ") || (strstr(Tmp, "gl_FrontMaterial")) || strstr(Tmp, "gl_BackMaterial"))
  {
    Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(gl4es_MaterialParametersSource));
    InplaceInsert(GetLine(Tmp, headline), gl4es_MaterialParametersSource);
    headline+=CountLine(gl4es_MaterialParametersSource);
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_MaterialParameters", "_gl4es_MaterialParameters");
  }
  if(strstr(Tmp, "gl_LightSource"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_LightSource", "_gl4es_LightSource");
  if(strstr(Tmp, "gl_FrontLightModelProduct"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_FrontLightModelProduct", "_gl4es_FrontLightModelProduct");
  if(strstr(Tmp, "gl_BackLightModelProduct"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_BackLightModelProduct", "_gl4es_BackLightModelProduct");
  if(strstr(Tmp, "gl_FrontLightProduct"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_FrontLightProduct", "_gl4es_FrontLightProduct");
  if(strstr(Tmp, "gl_BackLightProduct"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_BackLightProduct", "_gl4es_BackLightProduct");
  if(strstr(Tmp, "gl_FrontMaterial"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_FrontMaterial", "_gl4es_FrontMaterial");
  if(strstr(Tmp, "gl_BackMaterial"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_BackMaterial", "_gl4es_BackMaterial");
  if(strstr(Tmp, "gl_MaxLights"))
  {
    Tmp = ResizeIfNeeded(Tmp, &tmpsize, strlen(gl4es_MaxLightsSource));
    InplaceInsert(GetLine(Tmp, 2), gl4es_MaxLightsSource);
    headline+=CountLine(gl4es_MaxLightsSource);
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_MaxLights", "_gl4es_MaxLights");
  }
  if(strstr(Tmp, "gl_NormalScale"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_NormalScale", "_gl4es_NormalScale");
  if(strstr(Tmp, "gl_ClipPlane"))
    Tmp = InplaceReplace(Tmp, &tmpsize, "gl_ClipPlane", "_gl4es_ClipPlane");

  // finish
  DBG(printf("New Shader source:\n%s\n", Tmp);)
  return Tmp;
}

int isBuiltinAttrib(const char* name) {
    int ret = -1;
    int n = sizeof(builtin_attrib)/sizeof(builtin_attrib_t);
    for (int i=0; i<n && ret==-1; i++) {
        if (strcmp(builtin_attrib[i].name, name)==0)
            ret=builtin_attrib[i].attrib;
    }
    return ret;
}

int isBuiltinMatrix(const char* name) {
    int ret = -1;
    int n = sizeof(builtin_matrix)/sizeof(builtin_matrix_t);
    for (int i=0; i<n && ret==-1; i++) {
        if (strncmp(builtin_matrix[i].name, name, strlen(builtin_matrix[i].name))==0) {
            int l=strlen(builtin_matrix[i].name);
            if(strlen(name)==l || (strlen(name)==l+3 && name[l]=='[' && builtin_matrix[i].texarray)) {
                ret=builtin_matrix[i].matrix;
                if(builtin_matrix[i].texarray) {
                    int n = name[l+1] - '0';
                    ret+=n*4;
                }
            }
        }
    }
    return ret;
}