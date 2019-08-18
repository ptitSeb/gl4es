#include "depth.h"

#include "gl4es.h"
#include "glstate.h"
#include "loader.h"

void gl4es_glDepthFunc(GLenum func) {
    if(glstate->list.compiling) {
        PUSH_IF_COMPILING(glDepthFunc);
    }
    noerrorShim();
    if (glstate->depth.func == func)
        return;
    FLUSH_BEGINEND;
    glstate->depth.func = func;
    LOAD_GLES(glDepthFunc);
    errorGL();
    gles_glDepthFunc(func);
}

void gl4es_glDepthMask(GLboolean flag) {
    if(glstate->list.compiling) {
        PUSH_IF_COMPILING(glDepthMask);
    }
    noerrorShim();
    if (glstate->depth.mask == flag)
        return;
    FLUSH_BEGINEND;
    glstate->depth.mask = flag;
    LOAD_GLES(glDepthMask);
    errorGL();
    gles_glDepthMask(flag);
}

GLfloat clamp(GLfloat a) {
    return (a<0.f)?0.f:((a>1.f)?1.f:a);
}

void gl4es_glDepthRangef(GLclampf near, GLclampf far) {
    near = clamp(near);
    far = clamp(far);
    if(glstate->list.compiling) {
        PUSH_IF_COMPILING(glDepthRangef);
    }
    noerrorShim();
    if ((glstate->depth.near == near) && (glstate->depth.far == far))
        return;
    FLUSH_BEGINEND;
    glstate->depth.near = near;
    glstate->depth.far = far;
    LOAD_GLES(glDepthRangef);
    errorGL();
    gles_glDepthRangef(near, far);
}

void gl4es_glClearDepthf(GLclampf depth) {
    depth = clamp(depth);
    if(glstate->list.compiling) {
        PUSH_IF_COMPILING(glClearDepthf);
    }
    noerrorShim();
    glstate->depth.clear = depth;
    LOAD_GLES(glClearDepthf);
    errorGL();
    gles_glClearDepthf(depth);
}

void glDepthFunc(GLenum func) AliasExport("gl4es_glDepthFunc");
void glDepthMask(GLboolean flag) AliasExport("gl4es_glDepthMask");
void glDepthRangef(GLclampf nearVal, GLclampf farVal) AliasExport("gl4es_glDepthRangef");

