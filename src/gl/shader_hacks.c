#include <string.h>
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
"branchB . x = 0.0 ;"

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