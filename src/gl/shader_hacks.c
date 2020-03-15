#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "string_utils.h"


static const char* gl4es_hacks[] = {
// this is for Guacamelee (yep, there is a lot of hacks, only int -> float conversions)
// 1
"float edgeGlow = step ( 0.2 , pow ( clamp ( ( dot ( vec2 ( 1 * sign ( v_texcoord3 . z ) , 1 ) , normalize ( quadCoord . xy - 0.5 ) ) - 0.4 + depth * 2.0 ) , 0.0  , 1.0  ) , 25 ) ) ;",
"float edgeGlow = step ( 0.2 , pow ( clamp ( ( dot ( vec2 ( 1.0 * sign ( v_texcoord3 . z ) , 1.0 ) , normalize ( quadCoord . xy - 0.5 ) ) - 0.4 + depth * 2.0 ) , 0.0  , 1.0  ) , 25.0 ) ) ;",
// 2
"float litfire = max ( dot ( normalize ( drops1 . rgb ) , normalize ( vec3 ( - 1 , 0 , pow ( max ( 1.0 - ocoord . x , 0.0 ) , 9 ) ) ) ) , 0 ) ;",
"float litfire = max ( dot ( normalize ( drops1 . rgb ) , normalize ( vec3 ( - 1.0 , 0.0 , pow ( max ( 1.0 - ocoord . x , 0.0 ) , 9.0 ) ) ) ) , 0.0 ) ;",
// 3
"if ( ( normalizedDepth ) < 0.0  ) discard ; ;\nif ( depth < 0 )",
"if ( ( normalizedDepth ) < 0.0  ) discard ; ;\nif ( depth < 0.0 )",
// 4
"gl_FragColor . rgba += glowHit ;\nif ( depth < 0 )",
"gl_FragColor . rgba += glowHit ;\nif ( depth < 0.0 )",
// 5
"gl_FragColor . a *= pow ( clamp ( ( depth + 1 ) , 0.0  , 1.0  ) , 70 ) ;",
"gl_FragColor . a *= pow ( clamp ( ( depth + 1.0 ) , 0.0  , 1.0  ) , 70.0 ) ;",
// 6
"if ( floor ( in_texcoord0 . y ) != 0 )",
"if ( floor ( in_texcoord0 . y ) != 0.0 )",
// 7
"if ( in_position0 . y < 0 )",
"if ( in_position0 . y < 0.0 )",
// 8
"if ( in_position0 . x < 0 )",
"if ( in_position0 . x < 0.0 )",
// 9
"branchB . y = 0 ;",
"branchB . y = 0.0 ;",
// 10
"branchB . x = 0 ;",
"branchB . x = 0.0 ;",

// this is for Battle Block Theater
// 1
"   if(texColor.w == 0)\n       gl_FragColor = texColor;",
"   if(texColor.w == 0.0)\n       gl_FragColor = texColor;",
// 2
"if(dist1 > 0)       {           float lightVal = (1-dist1) * light1Luminosity;",
"if(dist1 > 0.0)       {           float lightVal = (1.0-dist1) * light1Luminosity;",
// 3
"float lightVal = 0;",
"float lightVal = 0.0;",
// 4
"       if(dist1 > 0)\n"
"       {\n"
"			if(dist1 > 1)\n"
"				dist1 = 1;\n",
"       if(dist1 > 0.0)\n"
"       {\n"
"			if(dist1 > 1.0)\n"
"				dist1 = 1.0;\n",
// 5
"lightVal += (1-dist1) * light1Luminosity;",
"lightVal += (1.0-dist1) * light1Luminosity;",
// 6
"lightVal += (1-dist1) * light2Luminosity;",
"lightVal += (1.0-dist1) * light2Luminosity;",
// 7
"lightVal += (1-dist1) * light3Luminosity;",
"lightVal += (1.0-dist1) * light3Luminosity;",
// 8
"if(lightVal > 1)\n"
"			lightVal = 1;",
"if(lightVal > 1.0)\n"
"			lightVal = 1.0;",
// 9
"if(lightVal > 1)\n"
"           lightVal = 1;", // space and tabs make a difference...
"if(lightVal > 1.0)\n"
"           lightVal = 1.0;",

// For Night of the Zombie / Irrlicht 1.9.0
"gl_FragColor = (sample*(1-grayScaleFactor)) + (gray*grayScaleFactor);",
"gl_FragColor = (sample*(1.0-grayScaleFactor)) + (gray*grayScaleFactor);",

// For Knytt Underground
"vec2 val = texture_coordinate1+coeff*2*(i/float(iterations-1.0) - 0.5);",
"vec2 val = texture_coordinate1+coeff*2.0*(float(i)/float(iterations-1) - 0.5);",

"    b /= iterations;",
"    b /= float(iterations);",

// For Antichamber
"attribute vec4 _Un_AttrPosition0;\n"
"vec4 Un_AttrPosition0 = _Un_AttrPosition0;\n",
"attribute vec4 _Un_AttrPosition0;\n"
"#define Un_AttrPosition0 _Un_AttrPosition0\n",

"attribute vec4 _Un_AttrColor0;\n"
"vec4 Un_AttrColor0 = _Un_AttrColor0;\n",
"attribute vec4 _Un_AttrColor0;\n"
"#define Un_AttrColor0 _Un_AttrColor0\n",

"attribute vec4 _Un_AttrColor1;\n"
"vec4 Un_AttrColor1 = _Un_AttrColor1;\n",
"attribute vec4 _Un_AttrColor1;\n"
"#define Un_AttrColor1 _Un_AttrColor1\n",

"attribute vec4 _Un_AttrTangent0;\n"
"vec4 Un_AttrTangent0 = _Un_AttrTangent0;\n",
"attribute vec4 _Un_AttrTangent0;\n"
"#define Un_AttrTangent0 _Un_AttrTangent0\n",

"attribute vec4 _Un_AttrNormal0;\n"
"vec4 Un_AttrNormal0 = _Un_AttrNormal0;\n",
"attribute vec4 _Un_AttrNormal0;\n"
"#define Un_AttrNormal0 _Un_AttrNormal0\n",

"attribute vec4 _Un_AttrBlendIndices0;\n"
"vec4 Un_AttrBlendIndices0 = _Un_AttrBlendIndices0;\n",
"attribute vec4 _Un_AttrBlendIndices0;\n"
"#define Un_AttrBlendIndices0 _Un_AttrBlendIndices0\n",

"attribute vec4 _Un_AttrBlendWeight0;\n"
"vec4 Un_AttrBlendWeight0 = _Un_AttrBlendWeight0;\n",
"attribute vec4 _Un_AttrBlendWeight0;\n"
"#define Un_AttrBlendWeight0 _Un_AttrBlendWeight0\n",

"attribute vec4 _Un_AttrBinormal0;\n"
"vec4 Un_AttrBinormal0 = _Un_AttrBinormal0;\n",
"attribute vec4 _Un_AttrBinormal0;\n"
"#define Un_AttrBinormal0 _Un_AttrBinormal0\n",

"attribute vec4 _Un_AttrTexCoord0;\n"
"vec4 Un_AttrTexCoord0 = _Un_AttrTexCoord0;\n",
"attribute vec4 _Un_AttrTexCoord0;\n"
"#define Un_AttrTexCoord0 _Un_AttrTexCoord0\n",

"attribute vec4 _Un_AttrTexCoord1;\n"
"vec4 Un_AttrTexCoord1 = _Un_AttrTexCoord1;\n",
"attribute vec4 _Un_AttrTexCoord1;\n"
"#define Un_AttrTexCoord1 _Un_AttrTexCoord1\n",

"attribute vec4 _Un_AttrTexCoord2;\n"
"vec4 Un_AttrTexCoord2 = _Un_AttrTexCoord2;\n",
"attribute vec4 _Un_AttrTexCoord2;\n"
"#define Un_AttrTexCoord2 _Un_AttrTexCoord2\n",

"attribute vec4 _Un_AttrTexCoord3;\n"
"vec4 Un_AttrTexCoord3 = _Un_AttrTexCoord3;\n",
"attribute vec4 _Un_AttrTexCoord3;\n"
"#define Un_AttrTexCoord3 _Un_AttrTexCoord3\n",

"attribute vec4 _Un_AttrTexCoord4;\n"
"vec4 Un_AttrTexCoord4 = _Un_AttrTexCoord4;\n",
"attribute vec4 _Un_AttrTexCoord4;\n"
"#define Un_AttrTexCoord4 _Un_AttrTexCoord4\n",

"attribute vec4 _Un_AttrTexCoord5;\n"
"vec4 Un_AttrTexCoord5 = _Un_AttrTexCoord5;\n",
"attribute vec4 _Un_AttrTexCoord5;\n"
"#define Un_AttrTexCoord5 _Un_AttrTexCoord5\n",

"attribute vec4 _Un_AttrTexCoord6;\n"
"vec4 Un_AttrTexCoord6 = _Un_AttrTexCoord6;\n",
"attribute vec4 _Un_AttrTexCoord6;\n"
"#define Un_AttrTexCoord6 _Un_AttrTexCoord6\n",

"attribute vec4 _Un_AttrTexCoord7;\n"
"vec4 Un_AttrTexCoord7 = _Un_AttrTexCoord7;\n",
"attribute vec4 _Un_AttrTexCoord7;\n"
"#define Un_AttrTexCoord7 _Un_AttrTexCoord7\n",

};

// For Stellaris
static const char* gl4es_sign_1[] = {
"if (Data.Type == 1)",
"if (Data.BlendMode == 0)",
};
static const char* gl4es_hacks_1[] = {
"if (Data.Type == 1)",
"if (Data.Type == 1.0)",

"if (Data.Type == 2)",
"if (Data.Type == 2.0)",

"if (Data.Type == 3)",
"if (Data.Type == 3.0)",

"if (Data.BlendMode == 0)",
"if (Data.BlendMode == 0.0)",

"if (Data.BlendMode == 1)",
"if (Data.BlendMode == 1.0)",

"if (Data.BlendMode == 2)",
"if (Data.BlendMode == 2.0)",

"Out.vMaskingTexCoord = saturate(v.vTexCoord * 1000);",
"Out.vMaskingTexCoord = saturate(v.vTexCoord * 1000.0);",

"float vTime = 0.9 - saturate( (Time - AnimationTime) * 4 );",
"float vTime = 0.9 - saturate( (Time - AnimationTime) * 4.0 );",

"float vTime = 0.9 - saturate( (Time - AnimationTime) * 16 );",
"float vTime = 0.9 - saturate( (Time - AnimationTime) * 16.0 );",
};

// For Psychonauts
static const char* gl4es_sign_2[] = {
"vec4 ps_t3 = gl_TexCoord[3];",
"vec4 ps_t2 = gl_TexCoord[2];",
"vec4 ps_t1 = gl_TexCoord[1];",
"vec4 ps_t0 = gl_TexCoord[0];",
};

static const char* gl4es_sign_2_main = 
"void main()\n"
"{\n";


static const char* gl4es_hacks_2_1[] = {
"vec4 ps_t3;",
"vec4 ps_t2;",
"vec4 ps_t1;",
"vec4 ps_t0;",
};

static const char* gl4es_hacks_2_2[] = {
"\tps_t3 = gl_TexCoord[3];",
"\tps_t2 = gl_TexCoord[2];",
"\tps_t1 = gl_TexCoord[1];",
"\tps_t0 = gl_TexCoord[0];",
};

static char* ShaderHacks_1(char* shader, char* Tmp, int* tmpsize)
{
    // check for all signature first
    for (int i=0; i<sizeof(gl4es_sign_1)/sizeof(gl4es_sign_1[0]); i++)
        if(!strstr(Tmp, gl4es_sign_1[i]))
            return Tmp;
    // Do the replace
    for (int i=0; i<sizeof(gl4es_hacks_1)/sizeof(gl4es_hacks_1[0]); i+=2)
        if(strstr(Tmp, gl4es_hacks_1[i])) {
            if(Tmp==shader) {Tmp = malloc(*tmpsize); strcpy(Tmp, shader);}   // hacking!
            Tmp = InplaceReplaceSimple(Tmp, tmpsize, gl4es_hacks_1[i], gl4es_hacks_1[i+1]);
        }
    return Tmp;
}

static char* ShaderHacks_2_1(char* shader, char* Tmp, int* tmpsize, int i)
{
    char* p = strstr(Tmp, gl4es_sign_2[i]);
    if(!p) return Tmp;  // not found
    char* m = strstr(Tmp, gl4es_sign_2_main);
    if(!m) return Tmp;  // main signature not found
    if((uintptr_t)p > (uintptr_t)m) return Tmp; // main is before, aborting...
    // ok, instance found, insert main line...
    if(Tmp==shader) {Tmp = malloc(*tmpsize); strcpy(Tmp, shader); m = strstr(Tmp, gl4es_sign_2_main);}   // hacking!
    m += strlen(gl4es_sign_2_main);
    Tmp = InplaceInsert(m, gl4es_hacks_2_2[i], Tmp, tmpsize);
    Tmp = InplaceReplaceSimple(Tmp, tmpsize, gl4es_sign_2[i], gl4es_hacks_2_1[i]);
    return Tmp;
}

static char* ShaderHacks_2(char* shader, char* Tmp, int* tmpsize)
{
    // check for each signature
    for (int i=0; i<sizeof(gl4es_sign_2)/sizeof(gl4es_sign_2[0]); i++)
        Tmp = ShaderHacks_2_1(shader, Tmp, tmpsize, i);
    return Tmp;
}

char* ShaderHacks(char* shader)
{
    char* Tmp = shader;
    int tmpsize = strlen(Tmp)+10;
    // specific hacks
    Tmp = ShaderHacks_1(shader, Tmp, &tmpsize);
    Tmp = ShaderHacks_2(shader, Tmp, &tmpsize);
    // generic
    for (int i=0; i<sizeof(gl4es_hacks)/sizeof(gl4es_hacks[0]); i+=2)
        if(strstr(Tmp, gl4es_hacks[i])) {
            if(Tmp==shader) {Tmp = malloc(tmpsize); strcpy(Tmp, shader);}   // hacking!
            Tmp = InplaceReplaceSimple(Tmp, &tmpsize, gl4es_hacks[i], gl4es_hacks[i+1]);
        }
    return Tmp;
}