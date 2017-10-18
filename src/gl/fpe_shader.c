#include <string.h>
#include <stdlib.h>

#include "fpe_shader.h"
#include "string_utils.h"
#include "../glx/hardext.h"

const char* dummy_vertex = \
"varying vec4 Color; \n"
"void main() {\n"
"Color = gl_Color;\n"
"gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
"}";

const char* dummy_frag = \
"varying vec4 Color; \n"
"void main() {\n"
"gl_FragColor = Color;\n"
"}\n";

char* shad = NULL;
int shad_cap = 0;

#define ShadAppend(S) shad = Append(shad, &shad_cap, S)

const char* texvecsize[] = {"vec2", "vec3", "vec2"};
const char* texxyzsize[] = {"xy", "xyz", "xy"};
const char* texsampler[] = {"texture2D", "textureCube", "textureStream"};

const char* const* fpe_VertexShader(fpe_state_t *state) {
    // vertex is first called, so 1st time init is only here
    if(!shad_cap) shad_cap = 1024;
    if(!shad) shad = (char*)malloc(shad_cap);
    int twosided = state->twosided && state->lighting;
    int headers = 0;
    char buff[1024];

    strcpy(shad, "varying vec4 Color;\n");  // might be unused...
    headers++;
    if(twosided) {
        ShadAppend("varying vec4 BackColor;\n");
        headers++;
    }
    if(state->light_separate) {
        ShadAppend("varying vec4 SecColor;\n");
        headers++;
        if(twosided) {
            ShadAppend("varying vec4 SecBackColor;\n");
            headers++;
        }
    }
    // textures coordinates
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->texture>>(i*2))&0x3;
        if(t) {
            sprintf(buff, "varying %s _gl4es_TexCoord_%d;\n", texvecsize[t-1], i);
            ShadAppend(buff);
            headers++;
            if(state->textmat&(1<<i)) {
                sprintf(buff, "uniform mat4 _gl4es_TextureMatrix_%d;\n", i);
                ShadAppend(buff);
                headers++;
            }
        }
    }
    // let's start
    ShadAppend("\nvoid main() {\n");
    // initial Color / lighting calculation
    ShadAppend("gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n");
    if(!state->lighting) {
        ShadAppend("Color = gl_Color;\n");
    } else {
        ShadAppend("vec4 vertex = gl_ModelViewMatrix * gl_Vertex;\n");
        // material emission
        sprintf(buff, "Color = %s;\n", (state->cm_front_mode==FPE_CM_EMISSION)?"gl_Color":"gl_FrontMaterial.emission");
        ShadAppend(buff);
        if(twosided) {
            sprintf(buff, "vec4 BackColor = %s;\n", (state->cm_back_mode==FPE_CM_EMISSION)?"gl_Color":"gl_BackMaterial.emission");
            ShadAppend(buff);
        }
        sprintf(buff, "Color += %s*gl_FrontLightModelProduct.sceneColor;\n", 
            (state->cm_front_mode==FPE_CM_AMBIENT || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE)?"gl_Color":"gl_FrontMaterial.ambient");
        ShadAppend(buff);
        if(twosided) {
            sprintf(buff, "Color += %s*gl_BackLightModelProduct.sceneColor;\n", 
                (state->cm_back_mode==FPE_CM_AMBIENT || state->cm_back_mode==FPE_CM_AMBIENTDIFFUSE)?"gl_Color":"gl_BackMaterial.ambient");
            ShadAppend(buff);
        }
        if(state->light_separate) {
            ShadAppend("SecColor=vec4(0.);\n");
            if(twosided)
                ShadAppend("SecBackColor=vec4(0.);\n");
        }
        ShadAppend("float att;\n");
        ShadAppend("float spot;\n");
        ShadAppend("vec4 VP;\n");
        ShadAppend("float lVP;\n");
        ShadAppend("float nVP;\n");
        ShadAppend("float fi;\n");
        ShadAppend("vec4 aa,dd,ss;\n");
        ShadAppend("vec4 hi;\n");
        if(twosided)
            ShadAppend("vec4 back_aa,back_dd,back_ss;\n");
        ShadAppend("vec3 normal = gl_NormalMatrix * gl_Normal;\n");
        for(int i=0; i<hardext.maxlights; i++) {
            if(state->light&(1<<i)) {
                // enabled light i
                sprintf(buff, "VP = gl_LightSource[%d].position - vertex;\n", i);
                ShadAppend(buff);
                // att depend on light position w
                if((state->light_direction>>i&1)==0) {
                    ShadAppend("att = 1.0;\n");
                } else {
                    ShadAppend("lVP = length(VP);\n");
                    sprintf(buff, "att = 1.0/(gl_LightSource[%d].constantAttenuation + gl_LightSource[%d].linearAttenuation * lVP + gl_LightSource[%d].quadraticAttenuation * lVP*lVP);\n", i, i, i);
                    ShadAppend(buff);
                }
                ShadAppend("VP = normalize(VP);\n");
                // spot depend on spotlight cutoff angle
                if((state->light_cutoff180>>i&1)==0) {
                    //ShadAppend("spot = 1.0;\n");
                } else {
                    printf(buff, "spot = max(dot(VP.xyz, gl_LightSource[%d].spotDirection), 0.);\n", i);
                    ShadAppend(buff);
                    sprintf(buff, "if(spot<gl_LightSource[%d].spotCosCutoff) spot=0.0; else spot=pow(spot, gl_LightSource[%d].spotExponent);", i, i);
                    ShadAppend(buff);
                    ShadAppend("att *= spot;\n");
                }
                sprintf(buff, "nVP = max(dot(normal, VP.xyz), 0.);fi=(nVP!=0.)?1.:0.;\n");
                ShadAppend(buff);
                sprintf(buff, "aa = gl_FrontMaterial.ambient * gl_LightSource[%d].ambient;\n", i);
                ShadAppend(buff);
                if(twosided) {
                    sprintf(buff, "back_aa = gl_BackMaterial.ambient * gl_LightSource[%d].ambient;\n", i);
                    ShadAppend(buff);
                }
                sprintf(buff, "dd = nVP * gl_FrontMaterial.diffuse * gl_LightSource[%d].diffuse;\n", i);
                ShadAppend(buff);
                if(twosided) {
                    sprintf(buff, "back_dd = nVP * gl_BackMaterial.diffuse * gl_LightSource[%d].diffuse;\n", i);
                    ShadAppend(buff);
                }
                if(state->light_localviewer) {
                    ShadAppend("hi = VP + normalize(-V);\n");
                } else {
                    ShadAppend("hi = VP;\n");
                }
                sprintf(buff, "ss = fi*pow(max(dot(hi.xyz, normal),0.), gl_FrontMaterial.shininess)*gl_FrontMaterial.specular*gl_LightSource[%d].specular;\n", i);
                ShadAppend(buff);
                if(twosided) {
                    sprintf(buff, "ss = fi*pow(max(dot(hi.xyz, normal),0.), gl_BackMaterial.shininess)*gl_BackMaterial.specular*gl_LightSource[%d].specular;\n", i);
                    ShadAppend(buff);
                }
                if(state->light_separate) {
                    ShadAppend("Color += att*(aa+dd);\n");
                    ShadAppend("SecColor += att*(ss);\n");
                    if(twosided) {
                        ShadAppend("BackColor += att*(back_aa+back_dd);\n");
                        ShadAppend("SecBackColor += att*(back_ss);\n");
                    }
                } else {
                    ShadAppend("Color += att*(aa+dd+ss);\n");
                    if(twosided)
                        ShadAppend("BackColor += att*(back_aa+back_dd+back_ss);\n");
                }
                ShadAppend("Color.a = gl_FrontMaterial.diffuse.a;\n");
                if(twosided)
                    ShadAppend("BackColor.a = gl_BackMaterial.diffuse.a;\n");
            }
        }
    }
    // calculate texture coordinates
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->texture>>(i*2))&0x3;
        int mat = state->textmat&(1<<i)?1:0;
        if(t) {
            if(mat)
                sprintf(buff, "_gl4es_TexCoord_%d = (gl_MultiTexCoord%d * _gl4es_TextureMatrix_%d).%s;\n", i, i, i, texxyzsize[t-1]);
            else
                sprintf(buff, "_gl4es_TexCoord_%d = gl_MultiTexCoord%d.%s;\n", i, i, texxyzsize[t-1]);
            ShadAppend(buff);
        }
    }

    ShadAppend("}\n");

    return (const char* const*)&shad;
}

const char* const* fpe_FragmentShader(fpe_state_t *state) {
    int headers = 0;
    int lighting = state->lighting;
    int twosided = state->twosided && lighting;
    int light_separate = state->light_separate && lighting;
    int alpha_test = state->alphatest;
    int alpha_func = state->alphafunc;
    char buff[100];

    strcpy(shad, "varying vec4 Color;\n");
    headers++;
    if(twosided) {
        ShadAppend("varying vec4 BackColor;\n");
        headers++;
    }
    if(light_separate) {
        ShadAppend("varying vec4 SecColor;\n");
        headers++;
        if(twosided) {
            ShadAppend("varying vec4 SecBackColor;\n");
            headers++;
        }
    }
    if(alpha_test && alpha_func>FPE_NEVER) {
        ShadAppend("uniform float _gl4es_AlphaRef;\n");
        headers++;
    }
    // textures coordinates
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->texture>>(i*2))&0x3;
        if(t) {
            sprintf(buff, "varying %s _gl4es_TexCoord_%d;\n", texvecsize[t-1], i);
            ShadAppend(buff);
            sprintf(buff, "uniform sampler2D _gl4es_TexSampler_%d;\n", i);
            ShadAppend(buff);
            headers++;
        }
    }

    ShadAppend("void main() {\n");
    //*** initial color
    sprintf(buff, "vec4 fColor = %s;\n", twosided?"(gl_FrontFacing)?Color:BackColor":"Color");
    ShadAppend(buff);

    //*** apply textures
    if(state->texture) {
        ShadAppend("lowp vec4 texColor;\n");
        for (int i=0; i<hardext.maxtex; i++) {
            int t = (state->texture>>(i*2))&0x3;
            if(t) {
                sprintf(buff, "texColor = %s(_gl4es_TexSampler_%d, _gl4es_TexCoord_%d);\n", texsampler[t-1], i, i);
                ShadAppend(buff);
                // TODO: Implement TexEnv stuff
                ShadAppend("fColor *= texColor;\n");
            }
        }
    }
    //*** Alpha Test
    if(alpha_test) {
        if(alpha_func==GL_ALWAYS) {
            // nothing here...
        } else if (alpha_func==GL_NEVER) {
            ShadAppend("discard;\n"); // Never pass...
        } else {
            const char* alpha_test_op[] = {">=","!=",">","<=","==","<"}; // need to have the !operation
            sprintf(buff, "if(fColor.a %s _gl4es_AlphaRef) discard;\n", alpha_test_op[alpha_func-FPE_LESS]);
            ShadAppend(buff);
        }
    }
    //*** Fog

    //*** Add secondary colors
    if(light_separate) {
        sprintf(buff, "fColor += vec4((%s).rgb, 0.);\n", twosided?"(gl_FrontFacing)?SecColor:BackSecColor":"SecColor");
        ShadAppend(buff);
    }

    //done
    ShadAppend("gl_FragColor = fColor;\n");
    ShadAppend("}");

    return (const char* const*)&shad;
}

