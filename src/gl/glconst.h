#define GL_QUADS      7
#define GL_QUAD_STRIP 8
#define GL_POLYGON    9

#define GL_TEXTURE_GEN_S    0x0C60
#define GL_TEXTURE_GEN_T    0x0C61
#define GL_TEXTURE_GEN_MODE 0x2500

#define GL_LINE_SMOOTH            0x0B20
#define GL_LINE_STIPPLE           0x0B24
#define GL_LINE_STIPPLE_PATTERN   0x0B25
#define GL_LINE_STIPPLE_REPEAT    0x0B26
#define GL_LINE_WIDTH             0x0B21
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_WIDTH_RANGE       0x0B22

#define GL_OBJECT_LINEAR    0x2401
#define GL_OBJECT_PLANE     0x2501
#define GL_EYE_LINEAR       0x2400
#define GL_EYE_PLANE        0x2502
#define GL_SPHERE_MAP       0x2402

#define GL_CURRENT_BIT          0x00001
#define GL_POINT_BIT            0x00002
#define GL_LINE_BIT             0x00004
#define GL_POLYGON_BIT          0x00008
#define GL_POLYGON_STIPPLE_BIT  0x00010
#define GL_PIXEL_MODE_BIT       0x00020
#define GL_LIGHTING_BIT         0x00040
#define GL_FOG_BIT              0x00080
// some of these are already defined in GLES
// #define GL_DEPTH_BUFFER_BIT     0x00100
#define GL_ACCUM_BUFFER_BIT     0x00200
// #define GL_STENCIL_BUFFER_BIT   0x00400
#define GL_VIEWPORT_BIT         0x00800
#define GL_TRANSFORM_BIT        0x01000
#define GL_ENABLE_BIT           0x02000
// #define GL_COLOR_BUFFER_BIT     0x04000
#define GL_HINT_BIT             0x08000
#define GL_EVAL_BIT             0x10000
#define GL_LIST_BIT             0x20000
#define GL_TEXTURE_BIT          0x40000
#define GL_SCISSOR_BIT          0x80000
#define GL_ALL_ATTRIB_BITS      0xFFFFF
#define GL_MULTISAMPLE_BIT      0x20000000

#define GL_CLIENT_PIXEL_STORE_BIT  0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_ALL_CLIENT_ATTRIB_BITS  0xFFFFFFFF
#define GL_CLIENT_ALL_ATTRIB_BITS  0xFFFFFFFF

#define GL_S                    0x2000
#define GL_T                    0x2001
#define GL_R                    0x2002
#define GL_Q                    0x2003

#define GL_BGR                  0x80E0
#define GL_BGRA                 0x80E1

#define GL_INT                  0x1404
#define GL_UNSIGNED_INT         0x1405
#define GL_FLOAT                0x1406
#define GL_2_BYTES              0x1407
#define GL_3_BYTES              0x1408
#define GL_4_BYTES              0x1409
#define GL_DOUBLE               0x140A

#define GL_COMPILE              0x1300
#define GL_COMPILE_AND_EXECUTE  0x1301

// fog
#define GL_FOG                  0x0B60
#define GL_FOG_MODE             0x0B65
#define GL_FOG_DENSITY          0x0B62
#define GL_FOG_COLOR            0x0B66
#define GL_FOG_INDEX            0x0B61
#define GL_FOG_START            0x0B63
#define GL_FOG_END              0x0B64
#define GL_LINEAR               0x2601
#define GL_EXP                  0x0800
#define GL_EXP2                 0x0801

// lighting
#define GL_LIGHTING             0x0B50
#define GL_LIGHT0               0x4000
#define GL_LIGHT1               0x4001
#define GL_LIGHT2               0x4002
#define GL_LIGHT3               0x4003
#define GL_LIGHT4               0x4004
#define GL_LIGHT5               0x4005
#define GL_LIGHT6               0x4006
#define GL_LIGHT7               0x4007
#define GL_SPOT_EXPONENT        0x1205
#define GL_SPOT_CUTOFF          0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION   0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_AMBIENT              0x1200
#define GL_DIFFUSE              0x1201
#define GL_SPECULAR             0x1202
#define GL_SHININESS            0x1601
#define GL_EMISSION             0x1600
#define GL_POSITION             0x1203
#define GL_SPOT_DIRECTION       0x1204
#define GL_AMBIENT_AND_DIFFUSE  0x1602
#define GL_COLOR_INDEXES        0x1603
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_AMBIENT  0x0B53
#define GL_FRONT_AND_BACK       0x0408
#define GL_SHADE_MODEL          0x0B54
#define GL_FLAT                 0x1D00
#define GL_SMOOTH               0x1D01
#define GL_COLOR_MATERIAL       0x0B57
#define GL_COLOR_MATERIAL_FACE  0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_NORMALIZE            0x0BA1

// pixel transfer
#define GL_MAP_COLOR             0x0D10
#define GL_MAP_STENCIL           0x0D11
#define GL_INDEX_SHIFT           0x0D12
#define GL_INDEX_OFFSET          0x0D13
#define GL_RED_SCALE             0x0D14
#define GL_RED_BIAS              0x0D15
#define GL_GREEN_SCALE           0x0D18
#define GL_GREEN_BIAS            0x0D19
#define GL_BLUE_SCALE            0x0D1A
#define GL_BLUE_BIAS             0x0D1B
#define GL_ALPHA_SCALE           0x0D1C
#define GL_ALPHA_BIAS            0x0D1D
#define GL_DEPTH_SCALE           0x0D1E
#define GL_DEPTH_BIAS            0x0D1F
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_PIXEL_MAP_S_TO_S      0x0C71
#define GL_PIXEL_MAP_I_TO_I      0x0C70
#define GL_PIXEL_MAP_I_TO_R      0x0C72
#define GL_PIXEL_MAP_I_TO_G      0x0C73
#define GL_PIXEL_MAP_I_TO_B      0x0C74
#define GL_PIXEL_MAP_I_TO_A      0x0C75
#define GL_PIXEL_MAP_R_TO_R      0x0C76
#define GL_PIXEL_MAP_G_TO_G      0x0C77
#define GL_PIXEL_MAP_B_TO_B      0x0C78
#define GL_PIXEL_MAP_A_TO_A      0x0C79
#define GL_PACK_ALIGNMENT        0x0D05
#define GL_PACK_LSB_FIRST        0x0D01
#define GL_PACK_ROW_LENGTH       0x0D02
#define GL_PACK_SKIP_PIXELS      0x0D04
#define GL_PACK_SKIP_ROWS        0x0D03
#define GL_PACK_SWAP_BYTES       0x0D00
#define GL_UNPACK_ALIGNMENT      0x0CF5
#define GL_UNPACK_LSB_FIRST      0x0CF1
#define GL_UNPACK_ROW_LENGTH     0x0CF2
#define GL_UNPACK_SKIP_PIXELS    0x0CF4
#define GL_UNPACK_SKIP_ROWS      0x0CF3
#define GL_UNPACK_SWAP_BYTES     0x0CF0
#define GL_ZOOM_X                0x0D16
#define GL_ZOOM_Y                0x0D17
