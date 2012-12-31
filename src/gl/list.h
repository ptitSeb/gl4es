#ifndef DISPLAY_LIST_H
#define DISPLAY_LIST_H

typedef struct RenderListT {
    unsigned long len;
    unsigned long cap;
    GLenum mode;
    GLfloat lastNormal[3];
    GLfloat lastColor[4];
    GLfloat lastTex[2];

    GLfloat *vert;
    GLfloat *normal;
    GLfloat *color;
    GLfloat *tex;
    struct RenderListT *next;
} RenderList;

#define DEFAULT_RENDER_LIST_CAPACITY 100

RenderList *allocRenderList();
RenderList *extendRenderList(RenderList *list);
void freeRenderList(RenderList *list);
void ensureRenderListSize(RenderList *list);
void drawRenderList(RenderList *list);
void swizzleRenderList(RenderList *list);
void endRenderList(RenderList *list);

void lVertex3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z);
void lNormal3f(RenderList *list, GLfloat x, GLfloat y, GLfloat z);
void lColor4f(RenderList *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
void lTexCoord2f(RenderList *list, GLfloat s, GLfloat t);

#endif
