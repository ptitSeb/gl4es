#ifndef _GL4ES_FPE_H_
#define _GL4ES_FPE_H_

/*
  This is the FPE : Fixed Pipeline Emulator

  It task is to create a shader that emulate the fixed pipeline.

  So based on the current GL State, it will either take a shader from the cache or create a new one
  For conveniance, the relevant GL states element are condenced in a bitfield packed fpe_state_t structure

*/

#include "gles.h"
#include "program.h"

#define FPE_FOG_EXP    0
#define FPE_FOG_EXP2   1
#define FPE_FOG_LINEAR 2

#define FPE_FOG_SRC_DEPTH 0
#define FPE_FOG_SRC_COORD 1

#define FPE_TEX_OFF  0
#define FPE_TEX_2D   1
#define FPE_TEX_RECT 2
#define FPE_TEX_3D   3
#define FPE_TEX_CUBE 4
#define FPE_TEX_STRM 5

#define FPE_ALWAYS   0
#define FPE_NEVER    1
#define FPE_LESS     2
#define FPE_EQUAL    3
#define FPE_LEQUAL   4
#define FPE_GREATER  5
#define FPE_NOTEQUAL 6
#define FPE_GEQUAL   7

#define FPE_CM_AMBIENTDIFFUSE 0
#define FPE_CM_EMISSION       1
#define FPE_CM_AMBIENT        2
#define FPE_CM_DIFFUSE        3
#define FPE_CM_SPECULAR       4

#define FPE_MODULATE          0
#define FPE_ADD               1
#define FPE_DECAL             2
#define FPE_BLEND             3
#define FPE_REPLACE           4
#define FPE_COMBINE           5
#define FPE_COMBINE4          6

#define FPE_CR_REPLACE        0
#define FPE_CR_MODULATE       1
#define FPE_CR_ADD            2
#define FPE_CR_ADD_SIGNED     3
#define FPE_CR_INTERPOLATE    4
#define FPE_CR_SUBTRACT       5
#define FPE_CR_DOT3_RGB       6
#define FPE_CR_DOT3_RGBA      7
#define FPE_CR_MOD_ADD        8
#define FPE_CR_MOD_ADD_SIGNED 9
#define FPE_CR_MOD_SUB        10

#define FPE_SRC_TEXTURE        0
#define FPE_SRC_TEXTURE0       1
#define FPE_SRC_TEXTURE1       2
#define FPE_SRC_TEXTURE2       3
#define FPE_SRC_TEXTURE3       4
#define FPE_SRC_TEXTURE4       5
#define FPE_SRC_TEXTURE5       6
#define FPE_SRC_TEXTURE6       7
#define FPE_SRC_TEXTURE7       8
#define FPE_SRC_CONSTANT       9
#define FPE_SRC_PRIMARY_COLOR  10
#define FPE_SRC_PREVIOUS       11
#define FPE_SRC_ZERO           12
#define FPE_SRC_ONE            13
#define FPE_SRC_SECONDARY_COLOR 14

#define FPE_OP_ALPHA           0
#define FPE_OP_MINUSALPHA      1
#define FPE_OP_SRCCOLOR        2
#define FPE_OP_MINUSCOLOR      3

#define FPE_TEX_RGBA           0
#define FPE_TEX_RGB            1
#define FPE_TEX_INTENSITY      2
#define FPE_TEX_LUM_ALPHA      3
#define FPE_TEX_LUM            4
#define FPE_TEX_ALPHA          5
#define FPE_TEX_DEPTH          6

#define FPE_TG_EYELINEAR       0
#define FPE_TG_OBJLINEAR       1
#define FPE_TG_SPHEREMAP       2
#define FPE_TG_NORMALMAP       3
#define FPE_TG_REFLECMAP       4
#define FPE_TG_NONE            5  // dummy, to help fpe

typedef struct {
    uint32_t texsrcrgb[4];               // 8 texenv src rgb n (SRC_n_RGB is 4 bits)
    uint32_t texsrcalpha[4];             // 8 texenv src alpha n (SRC_n_ALPHA is 4 bits)
    uint8_t texcombine[8];               // 8 texture combined (RGB as lower 4 bits, A as higher 4 bits)
    uint16_t texoprgb[4];                // 8 texenv src op (OPERATION_n_RGB is 2 bits)
    uint8_t texopalpha[4];               // 8 texenv src op (OPERATION_n_ALPHA is 1 bits)
    uint8_t texrgbscale;                 // 8 flags if RGB_SCALE for texture is != 1.0
    uint8_t texalphascale;               // 8 flags if ALPHA_SCALE for texture is != 1.0
    uint8_t light;                       // 8 lights packed
    uint8_t light_cutoff180;             // 8 lights cutoff!=180 flags
    uint8_t light_direction;             // 8 lights position[3].w==0 flags
    uint8_t textmat;                     // 8 flags if texture matrix is not identity
    uint8_t texadjust;                   // 8 flags if texture need adjustement
    unsigned int textype:24;                    // 8 textures type stored on 3 bits
    unsigned int texformat:24;           // 8 textures (simplified) internal format on 3 bits
    unsigned int texenv:24;              // 8 texenv flags, each stored on 3bits
    uint8_t      texgen_s;               // 8 texgen S enabled on 1 bit
    unsigned int texgen_s_mode:24;       // 8 texgen S on 3 bits
    uint8_t      texgen_t;               // 8 texgen S enabled on 1 bit
    unsigned int texgen_t_mode:24;       // 8 texgen T on 3 bits
    uint8_t      texgen_r;               // 8 texgen S enabled on 1 bit
    unsigned int texgen_r_mode:24;       // 8 texgen R on 3 bits
    uint8_t      texgen_q;               // 8 texgen S enabled on 1 bit
    unsigned int texgen_q_mode:24;       // 8 texgen Q on 3 bits
    unsigned int plane:6;                // 6 planes packed
    unsigned int fogmode:2;              // fog mode
    unsigned int fogsource:1;            // fog source
    unsigned int fog:1;                  // Fog enabled or not
    unsigned int colorsum:1;             // secondary color enabled
    unsigned int lighting:1;             // global lighting enabled
    unsigned int normalize:1;            // normalization
    unsigned int rescaling:1;            // rescale normal
    unsigned int alphafunc:3;            // alpha functions
    unsigned int alphatest:1;            // alpha test
    unsigned int twosided:1;             // lightmodel: two sided
    unsigned int color_material:1;       // color material enabled
    unsigned int cm_front_mode:3;        // front color material mode
    unsigned int cm_back_mode:3;         // back color material mode
    unsigned int cm_front_nullexp:1;     // front material shininess is 0
    unsigned int cm_back_nullexp:1;      // back material shininess is 0
    unsigned int light_separate:1;       // light separate specular color
    unsigned int light_localviewer:1;    // light local viewer
    unsigned int point:1;                // point rendering
    unsigned int pointsprite:1;          // point sprite rendering
    unsigned int pointsprite_coord:1;    // point sprite coord replace
    unsigned int pointsprite_upper:1;    // if coord is upper left and not lower left
}__attribute__((packed)) fpe_state_t;

typedef struct {
  GLuint  frag, vert, prog;   // shader info
  fpe_state_t state;          // state relevent to the current fpe program
  program_t *glprogram;
} fpe_fpe_t;

typedef struct {
  void      *cache;
  fpe_fpe_t *fpe;
} fpe_cache_t;

KHASH_MAP_DECLARE_INT(fpecachelist, fpe_cache_t *);

fpe_fpe_t *fpe_GetCache();
void fpe_disposeCache(fpe_cache_t* cache, int freeprog);

void fpe_glEnableClientState(GLenum cap);
void fpe_glDisableClientState(GLenum cap);
void fpe_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glEnable(GLenum cap);
void fpe_glDisable(GLenum cap);
void fpe_glDrawArrays(GLenum mode, GLint first, GLsizei count);
void fpe_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void fpe_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void fpe_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void fpe_glClientActiveTexture(GLenum texture);
void fpe_glFogfv(GLenum pname, const GLfloat* params);
void fpe_glAlphaFunc(GLenum func, GLclampf ref);

void fpe_glMatrixMode(GLenum mode);

void fpe_glLightModelf(GLenum pname, GLfloat param);
void fpe_glLightModelfv(GLenum pname, const GLfloat* params);
void fpe_glLightfv(GLenum light, GLenum pname, const GLfloat* params);
void fpe_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);
void fpe_glMaterialf(GLenum face, GLenum pname, const GLfloat param);

void fpe_glPointParameterfv(GLenum pname, const GLfloat * params);
void fpe_glPointSize(GLfloat size);

void builtin_Init(program_t *glprogram);
int builtin_CheckUniform(program_t *glprogram, char* name, GLint id, int size);
int builtin_CheckVertexAttrib(program_t *glprogram, char* name, GLint id);

void realize_glenv(int ispoint, int first, int count, GLenum type, const void* indices, void** scratch);
void realize_blitenv(int alpha);

#endif // _GL4ES_FPE_H_
