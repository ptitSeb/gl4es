#include "host.h"
#include "face.h"

#include "loader.h"
#include "gl4es.h"
#include "glstate.h"

void APIENTRY_GL4ES gl4es_glCullFace(GLenum mode) {
    if(!glstate->list.pending)
        PUSH_IF_COMPILING(glCullFace);
    if(mode!=GL_FRONT && mode!=GL_BACK && mode!=GL_FRONT_AND_BACK) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    if(glstate->face.cull == mode) {
        noerrorShim();
        return;
    }
    FLUSH_BEGINEND;
    
    glstate->face.cull = mode;
    
    host_functions.glCullFace(mode);
}

void APIENTRY_GL4ES gl4es_glFrontFace(GLenum mode) {
    if(!glstate->list.pending)
        PUSH_IF_COMPILING(glFrontFace);
    if(mode!=GL_CW && mode!=GL_CCW) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    if(glstate->face.front == mode) {
        noerrorShim();
        return;
    }
    FLUSH_BEGINEND;
    
    glstate->face.front = mode;
    
    host_functions.glFrontFace(mode);
}


AliasExport(void,glCullFace,,(GLenum mode));
AliasExport(void,glFrontFace,,(GLenum mode));
