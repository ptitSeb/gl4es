#include "gl.h"

#ifndef __FPE_H_
#define __FPE_H_
/*
  This is the FPE : Fixed Pipeline Emulator

  It task is to create a shader that emulate the fixed pipeline.

  So based on the current GL State, it will either take a shader from the cache or create a new one
  For conveniance, the relevant GL states element are condenced in a bitfield packed fpe_state_t structure

*/

#define FPE_FOG_OFF 0
#define FPE_FOG_LINEAR 1
#define FPE_FOG_EXP 2
#define FPE_FOG_EXP2 3

#define FPE_TEX_OFF  0
#define FPE_TEX_2D   1
#define FPE_TEX_CUBE 2
#define FPE_TEX_STRM 3

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

typedef struct {
    uint8_t light;              //  0: 7  the 8 lights packed
    uint8_t light_cutoff180;    //        the 8 lights cutoff!=180 flags
    uint8_t light_direction;    //        the 8 lights position[3].w==0 flags
    uint16_t texture;           // 17:32  8 texture stored on 2 bits
    int plane:6;                //  8:13  the 6 planes packed
    int fogmode:2;              // 14:15  fog mode
    int colorsum:1;             // 16:16  secondary color enabled
    int lighting:1;             // 33:33  global lighting enabled
    int normalize:1;            // 34:34  normalization
    int rescaling:1;            // 35:35  rescale normal
    int alphfunc:3;             // 36:38  alpha functions
    int alphatest:1;            // 39:39  alpha test
    int twosided:1;             // 40:40  lightmodel: two sided
    int color_material:1;       // 41:41  color material enabled
    int cm_front_mode:3;        // 42:44  front color material mode
    int cm_back_mode:3;         // 45:47  back color material mode
    int light_separate:1;       // 48:48  light separate specular color
    int light_localviewer:1;    // 49:49  light local viewer
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

KHASH_MAP_INIT_INT(fpecachelist, fpe_cache_t *);

fpe_fpe_t *fpe_GetCache();

void fpe_glEnableClientState(GLenum cap);
void fpe_glDisableClientState(GLenum cap);
void fpe_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glEnable(GLenum cap);
void fpe_glDisable(GLenum cap);
void fpe_glDrawArrays(GLenum mode, GLint first, GLsizei count);
void fpe_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void fpe_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void fpe_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void fpe_glClientActiveTexture(GLenum texture);
void fpe_glFogfv(GLenum pname, const GLfloat* params);

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

void realize_glenv();
void realize_blitenv(int alpha);

#endif