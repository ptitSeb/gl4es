#include <string.h>
#include <stdlib.h>
#include "string_utils.h"


static const char* gl4es_hacks[] = {
// this is for Psychonauts (using LIBGL_GL=21)
"#version 120\n"
"vec4 ps_r0;\n"
"vec4 ps_t0 = gl_TexCoord[0];\n",

"#version 120\n"
"vec4 ps_r0;\n"
"#define ps_t0 gl_TexCoord[0]\n",

// this is for Psychonauts (using LIBGL_GL=20)
"#version 110\n"
"vec4 ps_r0;\n"
"vec4 ps_t0 = gl_TexCoord[0];\n",

"#version 110\n"
"vec4 ps_r0;\n"
"#define ps_t0 gl_TexCoord[0]\n",

// this is for Guacamelee (yep, there is a lot of hacks, only int -> float conversions)
"float edgeGlow = step ( 0.2 , pow ( clamp ( ( dot ( vec2 ( 1 * sign ( v_texcoord3 . z ) , 1 ) , normalize ( quadCoord . xy - 0.5 ) ) - 0.4 + depth * 2.0 ) , 0.0  , 1.0  ) , 25 ) ) ;",
"float edgeGlow = step ( 0.2 , pow ( clamp ( ( dot ( vec2 ( 1.0 * sign ( v_texcoord3 . z ) , 1.0 ) , normalize ( quadCoord . xy - 0.5 ) ) - 0.4 + depth * 2.0 ) , 0.0  , 1.0  ) , 25.0 ) ) ;",

"float litfire = max ( dot ( normalize ( drops1 . rgb ) , normalize ( vec3 ( - 1 , 0 , pow ( max ( 1.0 - ocoord . x , 0.0 ) , 9 ) ) ) ) , 0 ) ;",
"float litfire = max ( dot ( normalize ( drops1 . rgb ) , normalize ( vec3 ( - 1.0 , 0.0 , pow ( max ( 1.0 - ocoord . x , 0.0 ) , 9.0 ) ) ) ) , 0.0 ) ;",

"if ( ( normalizedDepth ) < 0.0  ) discard ; ;\nif ( depth < 0 )",
"if ( ( normalizedDepth ) < 0.0  ) discard ; ;\nif ( depth < 0.0 )",

"gl_FragColor . rgba += glowHit ;\nif ( depth < 0 )",
"gl_FragColor . rgba += glowHit ;\nif ( depth < 0.0 )",

"gl_FragColor . a *= pow ( clamp ( ( depth + 1 ) , 0.0  , 1.0  ) , 70 ) ;",
"gl_FragColor . a *= pow ( clamp ( ( depth + 1.0 ) , 0.0  , 1.0  ) , 70.0 ) ;",

"if ( floor ( in_texcoord0 . y ) != 0 )",
"if ( floor ( in_texcoord0 . y ) != 0.0 )",

"if ( in_position0 . y < 0 )",
"if ( in_position0 . y < 0.0 )",

"if ( in_position0 . x < 0 )",
"if ( in_position0 . x < 0.0 )",

"branchB . y = 0 ;",
"branchB . y = 0.0 ;",

"branchB . x = 0 ;",
"branchB . x = 0.0 ;",

// this is for Battle Block Theater
"   if(texColor.w == 0)\n       gl_FragColor = texColor;",
"   if(texColor.w == 0.0)\n       gl_FragColor = texColor;",

"if(dist1 > 0)       {           float lightVal = (1-dist1) * light1Luminosity;",
"if(dist1 > 0.0)       {           float lightVal = (1.0-dist1) * light1Luminosity;",

"float lightVal = 0;",
"float lightVal = 0.0;",

"       if(dist1 > 0)\n"
"       {\n"
"			if(dist1 > 1)\n"
"				dist1 = 1;\n",
"       if(dist1 > 0.0)\n"
"       {\n"
"			if(dist1 > 1.0)\n"
"				dist1 = 1.0;\n",


"lightVal += (1-dist1) * light1Luminosity;",
"lightVal += (1.0-dist1) * light1Luminosity;",

"lightVal += (1-dist1) * light2Luminosity;",
"lightVal += (1.0-dist1) * light2Luminosity;",

"lightVal += (1-dist1) * light3Luminosity;",
"lightVal += (1.0-dist1) * light3Luminosity;",

"if(lightVal > 1)\n"
"			lightVal = 1;",
"if(lightVal > 1.0)\n"
"			lightVal = 1.0;",

"if(lightVal > 1)\n"
"           lightVal = 1;", // space and tabs make a difference...
"if(lightVal > 1.0)\n"
"           lightVal = 1.0;",

// For Night of the Zombie / Irrlicht 1.9.0
"gl_FragColor = (sample*(1-grayScaleFactor)) + (gray*grayScaleFactor);",
"gl_FragColor = (sample*(1.0-grayScaleFactor)) + (gray*grayScaleFactor);",

// For Stellaris
"\t\n\tif (Data.Type == 1) ",
"\t\n\tif (Data.Type == 1.0) ",

"\t}\n\telse if (Data.Type == 2) ",
"\t}\n\telse if (Data.Type == 2.0) ",

"\t\n\tif (Data.BlendMode == 0) ",
"\t\n\tif (Data.BlendMode == 0.0) ",

"\t\n\tif (Data.BlendMode == 1) ",
"\t\n\tif (Data.BlendMode == 1.0) ",

"\t\n\tif (Data.BlendMode == 2) ",
"\t\n\tif (Data.BlendMode == 2.0) ",


};

char* ShaderHacks(char* shader)
{
    char* Tmp = shader;
    int tmpsize = strlen(Tmp)+10;
    for (int i=0; i<sizeof(gl4es_hacks)/sizeof(gl4es_hacks[0]); i+=2)
        if(strstr(Tmp, gl4es_hacks[i])) {
            if(Tmp==shader) {Tmp = malloc(tmpsize); strcpy(Tmp, shader);}   // hacking!
            Tmp = InplaceReplace(Tmp, &tmpsize, gl4es_hacks[i], gl4es_hacks[i+1]);
        }
    return Tmp;
}