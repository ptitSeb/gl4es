#include "planes.h"
#include "../glx/hardext.h"

void gl4es_glClipPlanef(GLenum plane, const GLfloat *equation)
{
    PUSH_IF_COMPILING(glClipPlanef);
    if(plane<GL_CLIP_PLANE0 || plane>=GL_CLIP_PLANE0+hardext.maxplanes) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    int p = plane-GL_CLIP_PLANE0;
    noerrorShim();
    if(memcmp(glstate->planes[p], equation, 4*sizeof(GLfloat))==0) {
        errorGL();
        memcpy(glstate->planes[p], equation, 4*sizeof(GLfloat));
        LOAD_GLES(glClipPlanef);
        gles_glClipPlanef(plane, equation);
    }
}

void glClipPlanef(GLenum pname, const GLfloat* params) AliasExport("gl4es_glClipPlanef");