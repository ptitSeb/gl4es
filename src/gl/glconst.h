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
