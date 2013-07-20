#include "gl.h"

#ifndef DISPLAY_LIST_H
#define DISPLAY_LIST_H

typedef struct {
    int face;
    int pname;
    GLfloat color[4];
    int count;
} RenderMaterial;

KHASH_MAP_INIT_INT(material, RenderMaterial *)

typedef struct CallListT {
    unsigned long len;
    unsigned long cap;
    UnknownCall **calls;
} CallList;

typedef struct RenderListT {
    unsigned long len;
    unsigned long cap;
    GLenum mode;
    GLfloat lastNormal[3];
    GLfloat lastColor[4];
    GLfloat lastTex[2];

    CallList calls;
    GLfloat *vert;
    GLfloat *normal;
    GLfloat *color;
    GLfloat *tex;
    GLushort *indices;
    GLboolean q2t;

    khash_t(material) *material;
    GLuint texture;
    struct RenderListT *next;
} RenderList;

#define DEFAULT_CALL_LIST_CAPACITY 20
#define DEFAULT_RENDER_LIST_CAPACITY 20

extern RenderList *alloc_renderlist();
extern RenderList *extend_renderlist(RenderList *list);
extern void free_renderlist(RenderList *list);
static void resize_renderlist(RenderList *list);
extern void draw_renderlist(RenderList *list);
extern void q2t_renderlist(RenderList *list);
extern void end_renderlist(RenderList *list);

extern void rlBindTexture(RenderList *list, GLuint texture);
extern void rlColor4f(RenderList *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
extern void rlMaterialfv(RenderList *list, GLenum face, GLenum pname, const GLfloat * params);
extern void rlNormal3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z);
extern void rlPushCall(RenderList *list, UnknownCall *data);
extern void rlTexCoord2f(RenderList *list, GLfloat s, GLfloat t);
extern void rlVertex3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z);

#endif
