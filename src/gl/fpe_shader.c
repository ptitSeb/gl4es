#include "fpe_shader.h"

#include <stdio.h>

#include "string_utils.h"
#include "init.h"
#include "../glx/hardext.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

const char* fpeshader_signature = "// FPE_Shader generated\n";

static char* shad = NULL;
static int shad_cap = 0;

static int comments = 1;

#define ShadAppend(S) shad = Append(shad, &shad_cap, S)

const char* texvecsize[] = {"vec2", "vec2", "vec2", "vec3", "vec2"};
const char* texxyzsize[] = {"xy", "xy", "xy", "xyz", "xy"};
//                          2D          Rectangle    3D             CubeMap      Stream
const char* texname[] = {"texture2D", "texture2D", "texture2D", "textureCube", "textureStreamIMG"};    // textureRectange and 3D are emulated with 2D
const char* texsampler[] = {"sampler2D", "sampler2D", "sampler2D", "samplerCube", "samplerStreamIMG"};
int texnsize[] = {2, 2, 3, 3, 2};
const char texcoordname[] = {'s', 't', 'r', 'q'};
const char texcoordNAME[] = {'S', 'T', 'R', 'Q'};
const char texcoordxy[] = {'x', 'y', 'z', 'w'};

const char* gl4es_alphaRefSource = "uniform float _gl4es_AlphaRef;\n";

const char* fpe_texenvSrc(int src, int tmu, int twosided) {
    static char buff[200];
    switch(src) {
        case FPE_SRC_TEXTURE:
            sprintf(buff, "texColor%d", tmu);
            break;
        case FPE_SRC_TEXTURE0:
        case FPE_SRC_TEXTURE1:
        case FPE_SRC_TEXTURE2:
        case FPE_SRC_TEXTURE3:
        case FPE_SRC_TEXTURE4:
        case FPE_SRC_TEXTURE5:
        case FPE_SRC_TEXTURE6:
        case FPE_SRC_TEXTURE7:
            sprintf(buff, "texColor%d", src-FPE_SRC_TEXTURE0);  // should check if texture is enabled
            break;
        case FPE_SRC_CONSTANT:
            sprintf(buff, "_gl4es_TextureEnvColor_%d", tmu);
            break;
        case FPE_SRC_PRIMARY_COLOR:
            sprintf(buff, "%s", twosided?"((gl_FrontFacing)?Color:BackColor)":"Color");
            break;
        case FPE_SRC_PREVIOUS:
            sprintf(buff, "fColor");
            break;
        case FPE_SRC_ONE:
            sprintf(buff, "vec4(1.0)");
            break;
        case FPE_SRC_ZERO:
            sprintf(buff, "vec4(0.0)");
            break;
        case FPE_SRC_SECONDARY_COLOR:
            sprintf(buff, "%s", twosided?"((gl_FrontFacing)?SecColor:SecBackColor)":"SecColor");
            break;
    }
    return buff;
}

int fpe_texenvSecondary(fpe_state_t* state) {
    // check if one of the texenv need secondary color...
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->textype>>(i*3))&0x7;
        if(t) {
            int texenv = (state->texenv>>(i*3))&0x07;
            if(texenv==FPE_COMBINE) {
                int combine_rgb = state->texcombine[i]&0xf;
                int src_r[3];
                for (int j=0; j<3; j++) {
                    src_r[j] = (state->texsrcrgb[j]>>(i*4))&0xf;
                }
                if(combine_rgb==FPE_CR_DOT3_RGBA) {
                        src_r[2] = -1;
                } else {
                    if(combine_rgb==FPE_CR_REPLACE) {
                        src_r[1] = src_r[2] = -1;
                    } else if (combine_rgb>=FPE_CR_MOD_ADD) {
                        // need all 3
                    } else if (combine_rgb!=FPE_CR_INTERPOLATE) {
                        src_r[2] = -1;
                    }
                }
                if(src_r[0]==FPE_SRC_SECONDARY_COLOR || src_r[1]==FPE_SRC_SECONDARY_COLOR || src_r[2]==FPE_SRC_SECONDARY_COLOR)
                    return 1;
            }
        }
    }
    return 0;   
}

char* fpe_packed(int x, int s, int k) {
    static char buff[8][30];
    static int idx = 0;

    idx&=7;
    int mask = (1<<k)-1;

    const char *hex = "0123456789ABCDEF";

    int j=s/k;
    buff[idx][j] = '\0';
    for (int i=0; i<s; i+=k) {
        buff[idx][--j] = hex[(x&mask)];
        x>>=k;
    }
    return buff[idx++];
}
char* fpe_binary(int x, int s) {
    return fpe_packed(x, s, 1);
}
    

const char* const* fpe_VertexShader(fpe_state_t *state) {
    // vertex is first called, so 1st time init is only here
    if(!shad_cap) shad_cap = 1024;
    if(!shad) shad = (char*)malloc(shad_cap);
    int lighting = state->lighting;
    int twosided = state->twosided && lighting;
    int light_separate = state->light_separate && lighting;
    int secondary = (state->colorsum && !(lighting && light_separate)) || fpe_texenvSecondary(state);
    int fog = state->fog;
    int fogsource = state->fogsource;
    int fogmode = state->fogmode;
    int color_material = state->color_material && lighting;
    int point = state->point;
    int pointsprite = state->pointsprite;
    int headers = 0;
    int planes = state->plane;
    char buff[1024];
    int need_vertex = 0;
    int need_eyeplane[MAX_TEX][4] = {0};
    int need_objplane[MAX_TEX][4] = {0};
    int need_adjust[MAX_TEX] = {0};
    int need_lightproduct[2][MAX_LIGHT] = {0};
    int cm_front_nullexp = state->cm_front_nullexp;
    int cm_back_nullexp = state->cm_back_nullexp;

    strcpy(shad, fpeshader_signature);

    comments = globals4es.comments;
    DBG(comments=1-comments;)   // When DEBUG is activated, the effect of LIBGL_COMMENTS is reversed

    if(comments) {
        sprintf(buff, "// ** Vertex Shader **\n// ligthting=%d (twosided=%d, separate=%d, color_material=%d)\n// secondary=%d, planes=%s\n// texture=%s, point=%d\n",
            lighting, twosided, light_separate, color_material, secondary, fpe_binary(planes, 6), fpe_packed(state->textype, 24, 3), point);
        ShadAppend(buff);
        headers+=CountLine(buff);
    }
    ShadAppend("varying vec4 Color;\n");  // might be unused...
    headers++;
    if(planes) {
        for (int i=0; i<hardext.maxplanes; i++) {
            if((planes>>i)&1) {
                sprintf(buff, "uniform highp vec4 _gl4es_ClipPlane_%d;\n", i);
                ShadAppend(buff);
                ++headers;
                sprintf(buff, "varying mediump float clippedvertex_%d;\n", i);
                ShadAppend(buff);
                ++headers;
            }
        }
    }
    if(lighting) {
        sprintf(buff, 
            "struct _gl4es_FPELightSourceParameters1\n"
            "{\n"
            "%s"
            "   highp vec4 specular;\n"
            "   highp vec4 position;\n"
            "   highp vec3 spotDirection;\n"
            "   highp float spotExponent;\n"
            "   highp float spotCosCutoff;\n"
            "   highp float constantAttenuation;\n"
            "   highp float linearAttenuation;\n"
            "   highp float quadraticAttenuation;\n"
            "};\n", 
            (color_material)?
            "   highp vec4 ambient;\n"
            "   highp vec4 diffuse;\n"
            : ""
            );
        ShadAppend(buff);
        headers += CountLine(buff);
        sprintf(buff, 
            "struct _gl4es_FPELightSourceParameters0\n"
            "{\n"
            "%s"
            "   highp vec4 specular;\n"
            "   highp vec4 position;\n"
            "   highp vec3 spotDirection;\n"
            "   highp float spotExponent;\n"
            "   highp float spotCosCutoff;\n"
            "};\n", 
            (color_material)?
            "   highp vec4 ambient;\n"
            "   highp vec4 diffuse;\n"
            : ""
            );
        ShadAppend(buff);
        headers += CountLine(buff);

        sprintf(buff,
                "struct _gl4es_LightProducts\n"
                "{\n"
                "   highp vec4 ambient;\n"
                "   highp vec4 diffuse;\n"
                "   highp vec4 specular;\n"
                "};\n"                
        );
        ShadAppend(buff);
        headers += CountLine(buff);

        if(!(cm_front_nullexp && color_material)) {
            ShadAppend("uniform highp float _gl4es_FrontMaterial_shininess;\n");
            headers++;
        }
        if(twosided && !(cm_back_nullexp && color_material)) {
            ShadAppend("uniform highp float _gl4es_BackMaterial_shininess;\n");
            headers++;
        }
        if(!(color_material && (state->cm_front_mode==FPE_CM_DIFFUSE || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE))) {
            ShadAppend("uniform highp float _gl4es_FrontMaterial_alpha;\n");
            headers++;
            if(twosided) {
                ShadAppend("uniform highp float _gl4es_BackMaterial_alpha;\n");
                headers++;
            }
        }
        for(int i=0; i<hardext.maxlights; i++) {
            if(state->light&(1<<i)) {
                sprintf(buff, "uniform _gl4es_FPELightSourceParameters%d _gl4es_LightSource_%d;\n", (state->light_direction>>i&1)?1:0, i);
                ShadAppend(buff);
                headers++;

                sprintf(buff, "uniform _gl4es_LightProducts _gl4es_FrontLightProduct_%d;\n", i);
                ShadAppend(buff);
                headers++;

                if(twosided) {
                    sprintf(buff, "uniform _gl4es_LightProducts _gl4es_BackLightProduct_%d;\n", i);
                    ShadAppend(buff);
                    headers++;
                }
            }
        }
    }
    if(twosided) {
        ShadAppend("varying vec4 BackColor;\n");
        headers++;
    }
    if(light_separate || secondary) {
        ShadAppend("varying vec4 SecColor;\n");
        headers++;
        if(twosided) {
            ShadAppend("varying vec4 SecBackColor;\n");
            headers++;
        }
    }
    if(fog) {
        ShadAppend("varying float FogF;\n");
        headers++;
        if(fogsource==FPE_FOG_SRC_DEPTH && need_vertex<1)
            need_vertex = 1;
    }
    // textures coordinates
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->textype>>(i*3))&0x7;
        if(t) {
            sprintf(buff, "varying %s _gl4es_TexCoord_%d;\n", texvecsize[t-1], i);
            ShadAppend(buff);
            headers++;
            if(state->textmat&(1<<i)) {
                sprintf(buff, "uniform highp mat4 _gl4es_TextureMatrix_%d;\n", i);
                ShadAppend(buff);
                headers++;
            }
        }
    }
    // let's start
    ShadAppend("\nvoid main() {\n");
    int need_normal = 0;
    int normal_line = CountLine(shad) - headers;
    if(planes) {
        for (int i=0; i<hardext.maxplanes; i++) {
            if((planes>>i)&1) {
                sprintf(buff, "clippedvertex_%d = dot(vertex, _gl4es_ClipPlane_%d);\n", i, i);
                ShadAppend(buff);
            }
        }
        if(!need_vertex)
            need_vertex  = 1;
        //ShadAppend("gl_Position = clipvertex;\n");
    }
    ShadAppend("gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n");
    // initial Color / lighting calculation
    if(!lighting) {
        ShadAppend("Color = gl_Color;\n");
        if(secondary) {
            ShadAppend("SecColor = gl_SecondaryColor;\n");
        }
    } else {
        if(comments) {
            sprintf(buff, "// ColorMaterial On/Off=%d Front = %d Back = %d\n", color_material, state->cm_front_mode, state->cm_back_mode);
            ShadAppend(buff);
        }
        // material emission
        char fm_emission[60], fm_ambient[60], fm_diffuse[60], fm_specular[60];
        char bm_emission[60], bm_ambient[60], bm_diffuse[60], bm_specular[60];
        sprintf(fm_emission, "%s", (color_material && state->cm_front_mode==FPE_CM_EMISSION)?"gl_Color":"gl_FrontMaterial.emission");
        sprintf(fm_ambient, "%s", (color_material && (state->cm_front_mode==FPE_CM_AMBIENT || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE))?"gl_Color":"gl_FrontMaterial.ambient");
        sprintf(fm_diffuse, "%s", (color_material && (state->cm_front_mode==FPE_CM_DIFFUSE || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE))?"gl_Color.xyz * _gl4es_LightSource_":"_gl4es_FrontLightProduct_");
        sprintf(fm_specular, "%s", (color_material && state->cm_front_mode==FPE_CM_SPECULAR)?"gl_Color.xyz * _gl4es_LightSource_":"_gl4es_FrontLightProduct_");
        if(twosided) {
            sprintf(bm_emission, "%s", (color_material && state->cm_back_mode==FPE_CM_EMISSION)?"gl_Color":"gl_BackMaterial.emission");
            sprintf(bm_ambient, "%s", (color_material && (state->cm_back_mode==FPE_CM_AMBIENT || state->cm_back_mode==FPE_CM_AMBIENTDIFFUSE))?"gl_Color":"gl_BackMaterial.ambient");
            sprintf(bm_diffuse, "%s", (color_material && (state->cm_back_mode==FPE_CM_DIFFUSE || state->cm_back_mode==FPE_CM_AMBIENTDIFFUSE))?"gl_Color.xyz * _gl4es_LightSource_":"_gl4es_BackLightProduct_");
            sprintf(bm_specular, "%s", (color_material && state->cm_back_mode==FPE_CM_SPECULAR)?"gl_Color.xyz * _gl4es_LightSource_":"_gl4es_BackLightProduct_");
        }

        if(color_material && 
            (state->cm_front_mode==FPE_CM_EMISSION 
            || state->cm_front_mode==FPE_CM_AMBIENT
            || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE
            || (twosided && 
                (state->cm_back_mode==FPE_CM_EMISSION || state->cm_back_mode==FPE_CM_AMBIENT || state->cm_back_mode==FPE_CM_AMBIENTDIFFUSE)))) 
        {
            sprintf(buff, "Color = %s;\n", fm_emission);
            ShadAppend(buff);
            if(twosided) {
                sprintf(buff, "vec4 BackColor = %s;\n", bm_emission);
                ShadAppend(buff);
            }
            sprintf(buff, "Color += %s*gl_LightModel.ambient;\n", fm_ambient);
            ShadAppend(buff);
            if(twosided) {
                sprintf(buff, "BackColor += %s*gl_LightModel.ambient;\n", bm_ambient);
                ShadAppend(buff);
            }
        } else {
            ShadAppend("Color = gl_FrontLightModelProduct.sceneColor;\n");
            if(twosided) {
                ShadAppend("BackColor = gl_BackLightModelProduct.sceneColor;\n");
            }
        }
        if(light_separate) {
            ShadAppend("SecColor=vec4(0.);\n");
            if(twosided)
                ShadAppend("SecBackColor=vec4(0.);\n");
        }
        ShadAppend("highp float att;\n");
        ShadAppend("highp float spot;\n");
        ShadAppend("highp vec3 VP;\n");
        ShadAppend("highp float lVP;\n");
        ShadAppend("highp float nVP;\n");
        ShadAppend("highp vec3 aa,dd,ss;\n");
        ShadAppend("highp vec3 hi;\n");
        if(twosided)
            ShadAppend("highp vec3 back_aa,back_dd,back_ss;\n");
        need_normal = 1;
        for(int i=0; i<hardext.maxlights; i++) {
            if(state->light&(1<<i)) {
                if(comments) {
                    sprintf(buff, "// light %d on, light_direction=%d, light_cutoff180=%d\n", i, (state->light_direction>>i&1), (state->light_cutoff180>>i&1));
                    ShadAppend(buff);
                }
                // enabled light i
                // att depend on light position w
                if((state->light_direction>>i&1)==0) { // flag is 1 if light is has w!=0
                    ShadAppend("att = 1.0;\n");
                    sprintf(buff, "VP = normalize(_gl4es_LightSource_%d.position.xyz);\n", i);
                    ShadAppend(buff);
                } else {
                    sprintf(buff, "VP = _gl4es_LightSource_%d.position.xyz - vertex.xyz;\n", i);
                    ShadAppend(buff);
                    ShadAppend("lVP = length(VP);\n");
                    sprintf(buff, "att = 1.0/(_gl4es_LightSource_%d.constantAttenuation + lVP*(_gl4es_LightSource_%d.linearAttenuation + _gl4es_LightSource_%d.quadraticAttenuation * lVP));\n", i, i, i);
                    ShadAppend(buff);
                    ShadAppend("VP = normalize(VP);\n");
                    if(!need_vertex) need_vertex=1;
                }
                // spot depend on spotlight cutoff angle
                if((state->light_cutoff180>>i&1)==0) {
                    //ShadAppend("spot = 1.0;\n");
                } else {
                    /*if((state->light_direction>>i&1)==0) {
                        sprintf(buff, "spot = max(dot(-normalize(vertex.xyz), _gl4es_LightSource_%d.spotDirection), 0.);\n", i);
                        if(!need_vertex) need_vertex=1;
                    } else*/ {
                        sprintf(buff, "spot = max(dot(-VP, _gl4es_LightSource_%d.spotDirection), 0.);\n", i);
                    }
                    ShadAppend(buff);
                    sprintf(buff, "if(spot<_gl4es_LightSource_%d.spotCosCutoff) spot=0.0; else spot=pow(spot, _gl4es_LightSource_%d.spotExponent);\n", i, i);
                    ShadAppend(buff);
                    ShadAppend("att *= spot;\n");
                }
                if(color_material && (state->cm_front_mode==FPE_CM_AMBIENT || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE)) {
                    sprintf(buff, "aa = %s.xyz * _gl4es_LightSource_%d.ambient.xyz;\n", fm_ambient, i);
                    ShadAppend(buff);
                } else {
                    sprintf(buff, "aa = _gl4es_FrontLightProduct_%d.ambient.xyz;\n", i);
                    ShadAppend(buff);
                    need_lightproduct[0][i] = 1;
                }
                if(twosided) {
                    if(color_material && (state->cm_back_mode==FPE_CM_AMBIENT || state->cm_back_mode==FPE_CM_AMBIENTDIFFUSE)) {
                        sprintf(buff, "back_aa = %s.xyz * _gl4es_LightSource_%d.ambient.xyz;\n", bm_ambient, i);
                        ShadAppend(buff);
                    } else {
                        sprintf(buff, "back_aa = _gl4es_BackLightProduct_%d.ambient.xyz;\n", i);
                        ShadAppend(buff);
                        need_lightproduct[1][i] = 1;                     
                    }                        
                }
                sprintf(buff, "nVP = dot(normal, VP);\n");
                ShadAppend(buff);
                sprintf(buff, "dd = (nVP>0.)?(nVP * %s%d.diffuse.xyz):vec3(0.);\n", fm_diffuse, i);
                ShadAppend(buff);
                need_lightproduct[0][i] = 1;
                if(twosided) {
                    sprintf(buff, "back_dd = (nVP<0.)?(-nVP * %s%d.diffuse.xyz):vec3(0.);\n", bm_diffuse, i);
                    ShadAppend(buff);
                    need_lightproduct[1][i] = 1;
                }
                if(state->light_localviewer) {
                    ShadAppend("hi = normalize(VP + normalize(-vertex.xyz));\n");
                    if(!need_vertex) need_vertex=1;
                } else {
                    ShadAppend("hi = normalize(VP + vec3(0., 0., 1.));\n");
                }
                ShadAppend("lVP = dot(normal, hi);\n");
                if(cm_front_nullexp)
                    sprintf(buff, "ss = (nVP>0. && lVP>0.)?(pow(lVP, %s)*%s%d.specular.xyz):vec3(0.);\n", (color_material)?"gl_FrontMaterial.shininess":"_gl4es_FrontMaterial_shininess", fm_specular, i);
                else
                    sprintf(buff, "ss = (nVP>0. && lVP>0.)?(%s%d.specular.xyz):vec3(0.);\n", fm_specular, i);
                ShadAppend(buff);
                if(twosided) {
                    if(state->cm_back_nullexp)    // 1, exp is not null
                        sprintf(buff, "back_ss = (nVP<0. && lVP<0.)?(pow(-lVP, %s)*%s%d.specular.xyz):vec3(0.);\n", (color_material)?"gl_BackMaterial.shininess":"_gl4es_BackMaterial_shininess", bm_specular, i);
                    else
                        sprintf(buff, "back_ss = (nVP<0. && lVP<0.)?(%s%d.specular.xyz):vec3(0.);\n", bm_specular, i);
                    ShadAppend(buff);
                }
                if(state->light_separate) {
                    ShadAppend("Color.rgb += att*(aa+dd);\n");
                    ShadAppend("SecColor.rgb += att*(ss);\n");
                    if(twosided) {
                        ShadAppend("BackColor.rgb += att*(back_aa+back_dd);\n");
                        ShadAppend("SecBackColor.rgb += att*(back_ss);\n");
                    }
                } else {
                    ShadAppend("Color.rgb += att*(aa+dd+ss);\n");
                    if(twosided)
                        ShadAppend("BackColor.rgb += att*(back_aa+back_dd+back_ss);\n");
                }
                if(comments) {
                    sprintf(buff, "// end of light %d\n", i);
                    ShadAppend(buff);
                }
            }
        }
        sprintf(buff, "Color.a = %s;\n", (color_material && (state->cm_front_mode==FPE_CM_DIFFUSE || state->cm_front_mode==FPE_CM_AMBIENTDIFFUSE))?"gl_Color.a":"_gl4es_FrontMaterial_alpha");
        ShadAppend(buff);
        ShadAppend("Color.rgb = clamp(Color.rgb, 0., 1.);\n");
        if(twosided) {
            sprintf(buff, "BackColor.a = %s;\n", (color_material && (state->cm_back_mode==FPE_CM_DIFFUSE || state->cm_back_mode==FPE_CM_AMBIENTDIFFUSE))?"gl_Color.a":"_gl4es_BackMaterial_alpha");
            ShadAppend("BackColor.rgb = clamp(BackColor.rgb, 0., 1.);\n");
            ShadAppend(buff);
        }
        if(state->light_separate) {
            ShadAppend("SecColor.rgb = clamp(SecColor.rgb, 0., 1.);\n");
            if(twosided) {
                ShadAppend("SecBackColor.rgb = clamp(SecBackColor.rgb, 0., 1.);\n");
            }
        }
    }
    // calculate texture coordinates
    if(comments)
        ShadAppend("// texturing\n");
    if(state->texgen_s || state->texgen_t || state->texgen_r || state->texgen_q)
        ShadAppend("vec4 tmp_tcoor;\n");
    int spheremap = 0;
    int reflectmap = 0;
    if(state->textmat)
        ShadAppend("vec4 tmp_tex;\n");
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->textype>>(i*3))&0x7;
        int mat = state->textmat&(1<<i)?1:0;
        int adjust = state->texadjust&(1<<i)?1:0;
        int tg[4];
        tg[0] = state->texgen_s&(1<<i)?1:0;
        tg[1] = state->texgen_t&(1<<i)?1:0;
        tg[2] = state->texgen_r&(1<<i)?1:0;
        tg[3] = state->texgen_q&(1<<i)?1:0;
        int ntc = texnsize[t-1];
        if(t) {
            if(comments) {
                sprintf(buff, "// texture %d active: %X %s %s\n", i, t, mat?"with matrix":"", adjust?"npot adjusted":"");
                ShadAppend(buff);
            }
            char texcoord[50];
            if (tg[0] || tg[1] || tg[2] || tg[3]) {
                // One or more texgen is active
                if(tg[0]) tg[0] = (state->texgen_s_mode>>(i*3)&7); else tg[0] = FPE_TG_NONE;
                if(tg[1]) tg[1] = (state->texgen_t_mode>>(i*3)&7); else tg[1] = FPE_TG_NONE;
                if(tg[2]) tg[2] = (state->texgen_r_mode>>(i*3)&7); else tg[2] = FPE_TG_NONE;
                if(tg[3]) tg[3] = (state->texgen_q_mode>>(i*3)&7); else tg[3] = FPE_TG_NONE;
                if(comments) {
                    sprintf(buff, "//  texgen %d / %d / %d / %d\n", tg[0], tg[1], tg[2], tg[3]);
                    ShadAppend(buff);
                }
                sprintf(texcoord, "tmp_tcoor");
                ShadAppend("tmp_tcoor=vec4(0., 0., 0., 1.);\n");
                if(mat) {
                    ntc = 4;
                }
                for (int j=0; j<ntc; j++) {
                    if(tg[j]==FPE_TG_NORMALMAP) {
                        need_normal=1;
                        sprintf(buff, "tmp_tcoor.%c=normal.%c;\n", texcoordxy[j], texcoordxy[j]);
                    } else if(tg[j]==FPE_TG_SPHEREMAP) {
                        if(!spheremap) {
                            spheremap = 1;
                            if(!need_vertex) need_vertex=1;
                            need_normal = 1;
                            ShadAppend("vec3 tmpsphere = reflect(normalize(vertex.xyz), normal);\n");
                            ShadAppend("tmpsphere.z+=1.0;\n");
                            ShadAppend("tmpsphere.xy = tmpsphere.xy*(0.5*inversesqrt(dot(tmpsphere, tmpsphere))) + vec2(0.5);");
                        }
                        sprintf(buff, "tmp_tcoor.%c=tmpsphere.%c;\n", texcoordxy[j], texcoordxy[j]);
                    } else if(tg[j]==FPE_TG_OBJLINEAR) {
                        sprintf(buff, "tmp_tcoor.%c=dot(gl_Vertex, _gl4es_ObjectPlane%c_%d);\n", texcoordxy[j], texcoordNAME[j], i);
                        need_objplane[i][j] = 1;
                    } else if(tg[j]==FPE_TG_EYELINEAR) {
                        sprintf(buff, "tmp_tcoor.%c=dot(vertex, _gl4es_EyePlane%c_%d);\n", texcoordxy[j], texcoordNAME[j], i);
                        need_eyeplane[i][j] = 1;
                        if(!need_vertex) need_vertex=1;
                    } else if(tg[j]==FPE_TG_REFLECMAP) {
                        if(!reflectmap) {
                            reflectmap = 1;
                            if(!need_vertex) need_vertex=1;
                            need_normal = 1;
                            ShadAppend("vec3 tmpreflect = reflect(normalize(vertex.xyz), normal);\n");
                        }
                        sprintf(buff, "tmp_tcoor.%c=tmpreflect.%c;\n", texcoordxy[j], texcoordxy[j]);
                    } else if(tg[j]==FPE_TG_NONE) {
                        sprintf(buff, "tmp_tcoor.%c=gl_MultiTexCoord%d.%c;\n", texcoordxy[j], i, texcoordxy[j]);
                    }
                    ShadAppend(buff);
                }
            } else {
                sprintf(texcoord, "gl_MultiTexCoord%d", i);
            }
            if(mat) {
                // it would be better to use texture2Dproj in fragment shader, but that will complicate the varying definition...
                sprintf(buff, "tmp_tex = (_gl4es_TextureMatrix_%d * %s);\n", i, texcoord);
                ShadAppend(buff);
                sprintf(buff, "_gl4es_TexCoord_%d = tmp_tex.%s / tmp_tex.q;\n", i, texxyzsize[t-1]);
                //sprintf(buff, "_gl4es_TexCoord_%d = (_gl4es_TextureMatrix_%d * %s).%s;\n", i, i, texcoord, texxyzsize[t-1]);
            } else
                sprintf(buff, "_gl4es_TexCoord_%d = %s.%s / %s.q;\n", i, texcoord, texxyzsize[t-1], texcoord);
            ShadAppend(buff);
            if(adjust) {
                need_adjust[i] = 1;
                sprintf(buff, "_gl4es_TexCoord_%d.xy *= _gl4es_TexAdjust_%d;\n", i, i);    // to avoid error on Cube map... but will that work anyway?
                ShadAppend(buff);
            }
        }
    }
    // point sprite special case
    if(point) {
        if(!need_vertex)
            need_vertex = 1;
        ShadAppend("float ps_d = length(vertex);\n");
        sprintf(buff, "gl_PointSize = clamp(gl_Point.size*inversesqrt(gl_Point.distanceConstantAttenuation + ps_d*(gl_Point.distanceLinearAttenuation + ps_d*gl_Point.distanceQuadraticAttenuation)), gl_Point.sizeMin, gl_Point.sizeMax);\n");
        ShadAppend(buff);
    }
    // insert normal, vertex and eye/obj planes if needed
    if(need_vertex) {
        buff[0] = '\0';
        if(need_vertex==1)
            strcat(buff, "vec4 ");
        strcat(buff, "vertex = gl_ModelViewMatrix * gl_Vertex;\n");
        shad = ResizeIfNeeded(shad, &shad_cap, strlen(buff));
        InplaceInsert(GetLine(shad, normal_line + headers), buff);
        normal_line += CountLine(buff);
    }
    if(need_normal) {
#if 0
        if(state->rescaling)
            strcpy(buff, "vec3 normal = gl_NormalScale*(gl_NormalMatrix * gl_Normal);\n");
        else
            strcpy(buff, "vec3 normal = gl_NormalMatrix * gl_Normal;\n");
        if(state->normalize)
            strcat(buff, "normal = normalize(normal);\n");
#else
// Implementions may choose to normalize for rescale...
        if(state->rescaling || state->normalize)
            strcpy(buff, "vec3 normal = normalize(gl_NormalMatrix * gl_Normal);\n");
        else
            strcpy(buff, "vec3 normal = gl_NormalMatrix * gl_Normal;\n");
#endif
        shad = ResizeIfNeeded(shad, &shad_cap, strlen(buff));
        InplaceInsert(GetLine(shad, normal_line + headers), buff);
    }
    buff[0] = '\0';
    for (int i=0; i<MAX_TEX; i++) {
        char tmp[100];
        for (int j=0; j<4; j++) {
            if(need_objplane[i][j]) {
                sprintf(tmp, "uniform vec4 _gl4es_ObjectPlane%c_%d;\n", texcoordNAME[j], i);
                strcat(buff, tmp);
            }
            if(need_eyeplane[i][j]) {
                sprintf(tmp, "uniform vec4 _gl4es_EyePlane%c_%d;\n", texcoordNAME[j], i);
                strcat(buff, tmp);
            }
        }
        if(need_adjust[i]) {
            sprintf(tmp, "uniform vec2 _gl4es_TexAdjust_%d;\n", i);
            strcat(buff, tmp);
        }
    }
    if(buff[0]!='\0') {
        shad = ResizeIfNeeded(shad, &shad_cap, strlen(buff));
        InplaceInsert(GetLine(shad, headers), buff);
        headers += CountLine(buff);
    }
    if(fog) {
        if(comments) {
            sprintf(buff, "// Fog On: mode=%X, source=%X\n", fogmode, fogsource);
            ShadAppend(buff);
        }
        sprintf(buff, "float fog_c = %s;\n", fogsource==FPE_FOG_SRC_DEPTH?"abs(vertex.z)":"FogCoord"); // either vertex.z of length(vertex), let's choose the faster here
        ShadAppend(buff);
        switch(fogmode) {
            case FPE_FOG_EXP:
                ShadAppend("FogF = clamp(exp(-gl_Fog.density * fog_c), 0., 1.);\n");
                break;
            case FPE_FOG_EXP2:
                ShadAppend("FogF = clamp(exp(-(gl_Fog.density * fog_c)*(gl_Fog.density * fog_c)), 0., 1.);\n");
                break;
            case FPE_FOG_LINEAR:
                ShadAppend("FogF = clamp((gl_Fog.end - fog_c) * gl_Fog.scale, 0., 1.);\n");
                break;
        }
    }
        

    ShadAppend("}\n");

    DBG(printf("FPE Shader: \n%s\n", shad);)

    return (const char* const*)&shad;
}

const char* const* fpe_FragmentShader(fpe_state_t *state) {
    int headers = 0;
    int lighting = state->lighting;
    int twosided = state->twosided && lighting;
    int light_separate = state->light_separate && lighting;
    int secondary = (state->colorsum && !(lighting && light_separate)) || fpe_texenvSecondary(state);
    int alpha_test = state->alphatest;
    int alpha_func = state->alphafunc;
    int fog = state->fog;
    int fogsource = state->fogsource;
    int fogmode = state->fogmode;
    int planes = state->plane;
    int point = state->point;
    int pointsprite = state->pointsprite;
    int pointsprite_coord = state->pointsprite_coord;
    int pointsprite_upper = state->pointsprite_upper;
    int texenv_combine = 0;
    char buff[1024];

    strcpy(shad, fpeshader_signature);

    // check texture streaming
    {
        int need_stream = 0;
        for (int i=0; i<hardext.maxtex; i++) {
            const int t = (state->textype>>(i*3))&0x7;
            if(t==FPE_TEX_STRM)
                need_stream = 1;
        }
        if(need_stream)
            ShadAppend("#extension GL_IMG_texture_stream2 : enable\n");
    }
    
    if(comments) {
        sprintf(buff, "// ** Fragment Shader **\n// lighting=%d, alpha=%d, secondary=%d, planes=%s, textype=%s, texformat=%s point=%d\n", lighting, alpha_test, secondary, fpe_binary(planes, 6), fpe_packed(state->textype, 24, 3), fpe_packed(state->texformat, 24, 3), point);
        ShadAppend(buff);
        headers+=CountLine(buff);
    }
    ShadAppend("varying vec4 Color;\n");
    headers++;
    if(twosided) {
        ShadAppend("varying vec4 BackColor;\n");
        headers++;
    }
    if(light_separate || secondary) {
        ShadAppend("varying vec4 SecColor;\n");
        headers++;
        if(twosided) {
            ShadAppend("varying vec4 SecBackColor;\n");
            headers++;
        }
    }
    if(fog) {
        ShadAppend("varying float FogF;\n");
        headers++;
    }
    if(planes) {
        //ShadAppend("varying vec4 clipvertex;\n");
        for (int i=0; i<hardext.maxplanes; i++) {
            if((planes>>i)&1) {
                sprintf(buff, "varying mediump float clippedvertex_%d;\n", i);
                ShadAppend(buff);
                headers++;
            }
        }
    }
    /*if(fog && fogsource==FPE_FOG_SRC_COORD) {
        ShadAppend("varying float FogCoord;\n");
        headers++;
    }*/
    // textures coordinates
    for (int i=0; i<hardext.maxtex; i++) {
        int t = (state->textype>>(i*3))&0x7;
        if(point && !pointsprite) t=0;
        if(t) {
            sprintf(buff, "varying %s _gl4es_TexCoord_%d;\n", texvecsize[t-1], i);
            ShadAppend(buff);
            sprintf(buff, "uniform %s _gl4es_TexSampler_%d;\n", texsampler[t-1], i);
            ShadAppend(buff);
            headers++;

            int texenv = (state->texenv>>(i*3))&0x07;
            if (texenv>=FPE_COMBINE) {
                int n = 1+texenv-FPE_COMBINE;
                if(n>texenv_combine) texenv_combine=n;
                if((state->texrgbscale>>i)&1) {
                    sprintf(buff, "uniform float _gl4es_TexEnvRGBScale_%d;\n", i);
                    ShadAppend(buff);
                    headers++;
                }
                if((state->texalphascale>>i)&1) {
                    sprintf(buff, "uniform float _gl4es_TexEnvAlphaScale_%d;\n", i);
                    ShadAppend(buff);
                    headers++;
                }
            }
        }
    }
    if(alpha_test && alpha_func>FPE_NEVER) {
        ShadAppend(gl4es_alphaRefSource);
        headers++;
    } 

    ShadAppend("void main() {\n");

    //*** Clip Planes (it's probably not the best idea to do that here...)
    if(planes) {
        ShadAppend("if((");
        int k=0;
        for (int i=0; i<hardext.maxplanes; i++) {
            if((planes>>i)&1) {
                //sprintf(buff, "%smin(0., dot(clipvertex, gl_ClipPlane[%d]))", k?"+":"",  i);
                sprintf(buff, "%smin(0., clippedvertex_%d)", k?"+":"",  i);
                ShadAppend(buff);
                k=1;
            }
        }
        ShadAppend(")<0.) discard;\n");
    }

    //*** initial color
    sprintf(buff, "vec4 fColor = %s;\n", twosided?"(gl_FrontFacing)?Color:BackColor":"Color");
    ShadAppend(buff);

    //*** apply textures
    if(state->textype && (!point || pointsprite) ) {
        // fetch textures first
        for (int i=0; i<hardext.maxtex; i++) {
            int t = (state->textype>>(i*3))&0x7;
            if(t) {
                if(point && pointsprite && pointsprite_coord) {
                    if(pointsprite_upper)
                        sprintf(buff, "vec4 texColor%d = %s(_gl4es_TexSampler_%d, vec2(gl_PointCoord.x, 1.-gl_PointCoord.y));\n", i, texname[t-1], i);
                    else
                        sprintf(buff, "vec4 texColor%d = %s(_gl4es_TexSampler_%d, gl_PointCoord);\n", i, texname[t-1], i);
                } else
                    sprintf(buff, "vec4 texColor%d = %s(_gl4es_TexSampler_%d, _gl4es_TexCoord_%d);\n", i, texname[t-1], i, i);
                ShadAppend(buff);
            }
        }

        // TexEnv stuff
        if(texenv_combine>0) {
            if(texenv_combine==2)
                ShadAppend("vec4 Arg0, Arg1, Arg2, Arg3;\n");
            else
                ShadAppend("vec4 Arg0, Arg1, Arg2;\n");
        }
        // fetch textures first
        for (int i=0; i<hardext.maxtex; i++) {
            int t = (state->textype>>(i*3))&0x7;
            if(t) {
                int texenv = (state->texenv>>(i*3))&0x07;
                int texformat = (state->texformat>>(i*3))&0x07;
                if(comments) {
                    sprintf(buff, "// Texture %d active: %X, texenv=%X, format=%X\n", i, t, texenv, texformat);
                    ShadAppend(buff);
                }
                int needclamp = 1;
                switch (texenv) {
                    case FPE_MODULATE:
                        if(texformat==FPE_TEX_RGB || texformat==FPE_TEX_LUM) {
                            sprintf(buff, "fColor.rgb *= texColor%d.rgb;\n", i);
                            ShadAppend(buff);
                        } else if(texformat==FPE_TEX_ALPHA) {
                            sprintf(buff, "fColor.a *= texColor%d.a;\n", i);
                            ShadAppend(buff);
                        } else {
                            sprintf(buff, "fColor *= texColor%d;\n", i);
                            ShadAppend(buff);
                        }
                        needclamp = 0;
                        break;
                    case FPE_ADD:
                        if(texformat!=FPE_TEX_ALPHA) {
                            sprintf(buff, "fColor.rgb += texColor%d.rgb;\n", i);
                            ShadAppend(buff);
                        }
                        if(texformat==FPE_TEX_INTENSITY || texformat==FPE_TEX_DEPTH)
                            sprintf(buff, "fColor.a += texColor%d.a;\n", i);
                        else
                            sprintf(buff, "fColor.a *= texColor%d.a;\n", i);
                        ShadAppend(buff);
                        break;
                    case FPE_DECAL:
                        sprintf(buff, "fColor.rgb = mix(fColor.rgb, texColor%d.rgb, texColor%d.a);\n", i, i);
                        ShadAppend(buff);
                        needclamp = 0;
                        break;
                    case FPE_BLEND:
                        // create the Uniform for TexEnv Constant color
                        sprintf(buff, "uniform lowp vec4 _gl4es_TextureEnvColor_%d;\n", i);
                        shad = ResizeIfNeeded(shad, &shad_cap, strlen(buff));
                        InplaceInsert(GetLine(shad, headers), buff);
                        headers+=CountLine(buff);
                        needclamp=0;
                        if(texformat!=FPE_TEX_ALPHA) {
                            sprintf(buff, "fColor.rgb = mix(fColor.rgb, _gl4es_TextureEnvColor_%d.rgb, texColor%d.rgb);\n", i, i);
                            ShadAppend(buff);
                        }
                        switch(texformat) {
                            case FPE_TEX_LUM:
                            case FPE_TEX_RGB:
                                // no change in alpha channel
                                break;
                            case FPE_TEX_INTENSITY:
                            case FPE_TEX_DEPTH:
                                sprintf(buff, "fColor.a = mix(fColor.a, _gl4es_TextureEnvColor_%d.a, texColor%d.a);\n", i, i);
                                ShadAppend(buff);
                                break;
                            default:
                                sprintf(buff, "fColor.a *= texColor%d.a;\n", i);
                                ShadAppend(buff);
                        }
                        ShadAppend(buff);
                        break;
                    case FPE_REPLACE:
                        if(texformat==FPE_TEX_RGB || texformat==FPE_TEX_LUM) {
                            sprintf(buff, "fColor.rgb = texColor%d.rgb;\n", i);
                            ShadAppend(buff);
                        } else if(texformat==FPE_TEX_ALPHA) {
                            sprintf(buff, "fColor.a = texColor%d.a;\n", i);
                            ShadAppend(buff);
                        } else {
                            sprintf(buff, "fColor = texColor%d;\n", i);
                            ShadAppend(buff);
                        }
                        break;
                    case FPE_COMBINE:
                    case FPE_COMBINE4:
                        {
                            int constant = 0;
                            // parse the combine state
                            int combine_rgb = state->texcombine[i]&0xf;
                            int combine_alpha = (state->texcombine[i]>>4)&0xf;
                            int src_r[4], op_r[4];
                            int src_a[4], op_a[4];
                            for (int j=0; j<4; j++) {
                                src_a[j] = (state->texsrcalpha[j]>>(i*4))&0xf;
                                op_a[j] = (state->texopalpha[j]>>i)&1;
                                src_r[j] = (state->texsrcrgb[j]>>(i*4))&0xf;
                                op_r[j] = (state->texoprgb[j]>>(i*2))&3;
                            }
                            if(combine_rgb==FPE_CR_DOT3_RGBA) {
                                    src_a[0] = src_a[1] = src_a[2] = -1;
                                    op_a[0] = op_a[1] = op_a[2] = -1;
                                    src_r[2] = op_r[2] = -1;
                                    src_r[3] = op_r[3] = -1;
                                    src_a[3] = op_a[3] = -1;
                            } else {
                                if(combine_alpha==FPE_CR_REPLACE) {
                                    src_a[1] = src_a[2] = src_a[3] = -1;
                                    op_a[1] = op_a[2] = op_a[3] = -1;
                                } else if (combine_alpha>=FPE_CR_MOD_ADD || combine_alpha==FPE_CR_INTERPOLATE) {
                                    // need all 3
                                    src_a[3] = -1; op_a[3] = -1;
                                } else {
                                    if(texenv==FPE_COMBINE4 && (combine_alpha==FPE_CR_ADD || combine_alpha==FPE_CR_ADD_SIGNED)) {
                                        // need all 4
                                    } else {
                                        src_a[2] = src_a[3] = -1;
                                        op_a[2] = op_a[3] = -1;
                                    }
                                }
                                if(combine_rgb==FPE_CR_REPLACE) {
                                    src_r[1] = src_r[2] = src_r[3] = -1;
                                    op_r[1] = op_r[2] = op_r[3] = -1;
                                } else if (combine_rgb>=FPE_CR_MOD_ADD || combine_rgb==FPE_CR_INTERPOLATE) {
                                    // need all 3
                                    src_r[3] = -1; op_r[3] = -1;
                                } else {
                                    if(texenv==FPE_COMBINE4 && (combine_rgb==FPE_CR_ADD || combine_rgb==FPE_CR_ADD_SIGNED)) {
                                        // need all 4
                                    } else {
                                        src_r[2] = src_r[3] = -1;
                                        op_r[2] = op_r[3] = -1;
                                    }
                                }
                            }
                            // is texture constants needed ?
                            for (int j=0; j<4; j++) {
                                if (src_a[j]==FPE_SRC_CONSTANT || src_r[j]==FPE_SRC_CONSTANT)
                                    constant=1;
                            }
                            if(comments) {
                                sprintf(buff, " //  Combine RGB: fct=%d, Src/Op: 0=%d/%d 1=%d/%d 2=%d/%d 3=%d/%d\n", combine_rgb, src_r[0], op_r[0], src_r[1], op_r[1], src_r[2], op_r[2], src_r[3], op_r[3]);
                                ShadAppend(buff);
                                sprintf(buff, " //  Combine Alpha: fct=%d, Src/Op: 0=%d/%d 1=%d/%d 2=%d/%d 3=%d/%d\n", combine_alpha, src_a[0], op_a[0], src_a[1], op_a[1], src_a[2], op_a[2], src_a[3], op_a[3]);
                                ShadAppend(buff);
                            }
                            if(constant) {
                                // yep, create the Uniform
                                sprintf(buff, "uniform lowp vec4 _gl4es_TextureEnvColor_%d;\n", i);
                                shad = ResizeIfNeeded(shad, &shad_cap, strlen(buff));
                                InplaceInsert(GetLine(shad, headers), buff);
                                headers+=CountLine(buff);                            
                            }
                            for (int j=0; j<4; j++) {
                                if(op_r[j]!=-1)
                                switch(op_r[j]) {
                                    case FPE_OP_SRCCOLOR:
                                        sprintf(buff, "Arg%d.rgb = %s.rgb;\n", j, fpe_texenvSrc(src_r[j], i, twosided));
                                        ShadAppend(buff);
                                        break;
                                    case FPE_OP_MINUSCOLOR:
                                        sprintf(buff, "Arg%d.rgb = vec3(1.) - %s.rgb;\n", j, fpe_texenvSrc(src_r[j], i, twosided));
                                        ShadAppend(buff);
                                        break;
                                    case FPE_OP_ALPHA:
                                        sprintf(buff, "Arg%d.rgb = vec3(%s.a);\n", j, fpe_texenvSrc(src_r[j], i, twosided));
                                        ShadAppend(buff);
                                        break;
                                    case FPE_OP_MINUSALPHA:
                                        sprintf(buff, "Arg%d.rgb = vec3(1. - %s.a);\n", j, fpe_texenvSrc(src_r[j], i, twosided));
                                        ShadAppend(buff);
                                        break;
                                }
                                if(op_a[j]!=-1)
                                switch(op_a[j]) {
                                    case FPE_OP_ALPHA:
                                        sprintf(buff, "Arg%d.a = %s.a;\n", j, fpe_texenvSrc(src_a[j], i, twosided));
                                        ShadAppend(buff);
                                        break;
                                    case FPE_OP_MINUSALPHA:
                                        sprintf(buff, "Arg%d.a = 1. - %s.a;\n", j, fpe_texenvSrc(src_a[j], i, twosided));
                                        ShadAppend(buff);
                                        break;
                                }
                            }
                                
                            switch(combine_rgb) {
                                case FPE_CR_REPLACE:
                                    ShadAppend("fColor.rgb = Arg0.rgb;\n");
                                    break;
                                case FPE_CR_MODULATE:
                                    ShadAppend("fColor.rgb = Arg0.rgb * Arg1.rgb;\n");
                                    break;
                                case FPE_CR_ADD:
                                    if(texenv==FPE_COMBINE4)
                                        ShadAppend("fColor.rgb = Arg0.rgb*Arg1.rgb + Arg2.rgb*Arg3.rgb;\n");
                                    else
                                        ShadAppend("fColor.rgb = Arg0.rgb + Arg1.rgb;\n");
                                    break;
                                case FPE_CR_ADD_SIGNED:
                                    if(texenv==FPE_COMBINE4)
                                        ShadAppend("fColor.rgb = Arg0.rgb*Arg1.rgb + Arg2.rgb*Arg3.rgb - vec3(0.5);\n");
                                    else
                                        ShadAppend("fColor.rgb = Arg0.rgb + Arg1.rgb - vec3(0.5);\n");
                                    break;
                                case FPE_CR_INTERPOLATE:
                                    ShadAppend("fColor.rgb = Arg0.rgb*Arg2.rgb + Arg1.rgb*(vec3(1.)-Arg2.rgb);\n");
                                    break;
                                case FPE_CR_SUBTRACT:
                                    ShadAppend("fColor.rgb = Arg0.rgb - Arg1.rgb;\n");
                                    break;
                                case FPE_CR_DOT3_RGB:
                                    ShadAppend("fColor.rgb = vec3(4.*((Arg0.r-0.5)*(Arg1.r-0.5)+(Arg0.g-0.5)*(Arg1.g-0.5)+(Arg0.b-0.5)*(Arg1.b-0.5)));\n");
                                    break;
                                case FPE_CR_DOT3_RGBA:
                                    ShadAppend("fColor = vec4(4.*((Arg0.r-0.5)*(Arg1.r-0.5)+(Arg0.g-0.5)*(Arg1.g-0.5)+(Arg0.b-0.5)*(Arg1.b-0.5)));\n");
                                    break;
                                case FPE_CR_MOD_ADD:
                                    ShadAppend("fColor.rgb = Arg0.rgb*Arg2.rgb + Arg1.rgb;\n");
                                    break;
                                case FPE_CR_MOD_ADD_SIGNED:
                                    ShadAppend("fColor.rgb = Arg0.rgb*Arg2.rgb + Arg1.rgb - vec3(0.5);\n");
                                    break;
                                case FPE_CR_MOD_SUB:
                                    ShadAppend("fColor.rgb = Arg0.rgb*Arg2.rgb - Arg1.rgb;\n");
                                    break;
                            }
                            if(combine_rgb!=FPE_CR_DOT3_RGBA) 
                            switch(combine_alpha) {
                                case FPE_CR_REPLACE:
                                    ShadAppend("fColor.a = Arg0.a;\n");
                                    break;
                                case FPE_CR_MODULATE:
                                    ShadAppend("fColor.a = Arg0.a * Arg1.a;\n");
                                    break;
                                case FPE_CR_ADD:
                                    if(texenv==FPE_COMBINE4)
                                        ShadAppend("fColor.a = Arg0.a*Arg1.a + Arg2.a*Arg3.a;\n");
                                    else
                                        ShadAppend("fColor.a = Arg0.a + Arg1.a;\n");
                                    break;
                                case FPE_CR_ADD_SIGNED:
                                    if(texenv==FPE_COMBINE4)
                                        ShadAppend("fColor.a = Arg0.a*Arg1.a + Arg2.a*Arg3.a - 0.5;\n");
                                    else
                                        ShadAppend("fColor.a = Arg0.a + Arg1.a - 0.5;\n");
                                    break;
                                case FPE_CR_INTERPOLATE:
                                    ShadAppend("fColor.a = Arg0.a*Arg2.a + Arg1.a*(1.-Arg2.a);\n");
                                    break;
                                case FPE_CR_SUBTRACT:
                                    ShadAppend("fColor.a = Arg0.a - Arg1.a;\n");
                                    break;
                                case FPE_CR_MOD_ADD:
                                    ShadAppend("fColor.a = Arg0.a*Arg2.a + Arg1.a;\n");
                                    break;
                                case FPE_CR_MOD_ADD_SIGNED:
                                    ShadAppend("fColor.a = Arg0.a*Arg2.a + Arg1.a - 0.5;\n");
                                    break;
                                case FPE_CR_MOD_SUB:
                                    ShadAppend("fColor.a = Arg0.a*Arg2.a - Arg1.a;\n");
                                    break;
                            }
                            if((state->texrgbscale>>i)&1) {
                                sprintf(buff, "fColor.rgb *= _gl4es_TexEnvRGBScale_%d;\n", i);
                                ShadAppend(buff);
                            }
                            if((state->texalphascale>>i)&1) {
                                sprintf(buff, "fColor.a *= _gl4es_TexEnvAlphaScale_%d;\n", i);
                                ShadAppend(buff);
                            }
                        }
                        break;
                }
                if(needclamp)
                    ShadAppend("fColor = clamp(fColor, 0., 1.);\n");
            }
        }
    }
    //*** Alpha Test
    if(alpha_test) {
        if(comments) {
            sprintf(buff, "// Alpha Test, fct=%X\n", alpha_func);
            ShadAppend(buff);
        }
        if(alpha_func==FPE_ALWAYS) {
            // nothing here...
        } else if (alpha_func==FPE_NEVER) {
            ShadAppend("discard;\n"); // Never pass...
        } else {
            // FPE_LESS FPE_EQUAL FPE_LEQUAL FPE_GREATER FPE_NOTEQUAL FPE_GEQUAL
            // but need to negate the operator
            const char* alpha_test_op[] = {">=","!=",">","<=","==","<"}; 
            sprintf(buff, "if (floor(fColor.a*255.) %s _gl4es_AlphaRef) discard;\n", alpha_test_op[alpha_func-FPE_LESS]);
            ShadAppend(buff);
        }
    }

    //*** Add secondary color
    if(light_separate || secondary) {
        if(comments) {
            sprintf(buff, "// Add Secondary color (%s %s)\n", light_separate?"light":"", secondary?"secondary":"");
            ShadAppend(buff);
        }
        sprintf(buff, "fColor.rgb += (%s).rgb;\n", twosided?"(gl_FrontFacing)?SecColor:SecBackColor":"SecColor");
        ShadAppend(buff);
        ShadAppend("fColor.rgb = clamp(fColor.rgb, 0., 1.);\n");
    }

    //*** Fog
    if(fog) {
        if(comments) {
            sprintf(buff, "// Fog On: mode=%X, source=%X\n", fogmode, fogsource);
            ShadAppend(buff);
        }
        ShadAppend("fColor.rgb = mix(gl_Fog.color.rgb, fColor.rgb, FogF);\n");
    }

    //done
    ShadAppend("gl_FragColor = fColor;\n");
    ShadAppend("}");

    DBG(printf("FPE Shader: \n%s\n", shad);)

    return (const char* const*)&shad;
}

const char* const* fpe_CustomVertexShader(const char* initial, fpe_state_t* state)
{
    if(!shad_cap) shad_cap = 1024;
    if(!shad) shad = (char*)malloc(shad_cap);
    // nothing here yet...

    strcpy(shad, "");
    ShadAppend(initial);

    return (const char* const*)&shad;
}
const char* const* fpe_CustomFragmentShader(const char* initial, fpe_state_t* state)
{
    if(!shad_cap) shad_cap = 1024;
    if(!shad) shad = (char*)malloc(shad_cap);

    int alpha_test = state->alphatest;
    int alpha_func = state->alphafunc;
    char buff[1024];
    int headline = 3; // version and 2 precision lines

    strcpy(shad, "");
    ShadAppend(initial);

    // only alpha_test trigger a custom custom shader for now
    if(alpha_test) {
        // wrap real main...
        shad = InplaceReplace(shad, &shad_cap, "main", "_gl4es_main");
    }
    if(strstr(shad, "_gl4es_main")) {
        ShadAppend("void main() {\n");
        ShadAppend(" _gl4es_main();\n");

        //*** Alpha Test
        if(alpha_test) {
            if(alpha_test && alpha_func>FPE_NEVER) {
                shad = ResizeIfNeeded(shad, &shad_cap, strlen(gl4es_alphaRefSource));
                InplaceInsert(GetLine(shad, headline), gl4es_alphaRefSource);
                headline+=CountLine(gl4es_alphaRefSource);
            } 
            if(comments) {
                sprintf(buff, "// Alpha Test, fct=%X\n", alpha_func);
                ShadAppend(buff);
            }
            if(alpha_func==FPE_ALWAYS) {
                // nothing here...
            } else if (alpha_func==FPE_NEVER) {
                ShadAppend("discard;\n"); // Never pass...
            } else {
                // FPE_LESS FPE_EQUAL FPE_LEQUAL FPE_GREATER FPE_NOTEQUAL FPE_GEQUAL
                // but need to negate the operator
                const char* alpha_test_op[] = {">=","!=",">","<=","==","<"}; 
                sprintf(buff, "if (floor(gl_FragColor.a*255.) %s _gl4es_AlphaRef) discard;\n", alpha_test_op[alpha_func-FPE_LESS]);
                ShadAppend(buff);
            }
        }

        ShadAppend("}");
    }

    return (const char* const*)&shad;
}
