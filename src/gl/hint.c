#include "hint.h"
#include <gl4eshint.h>
#include "init.h"

void gl4es_glHint(GLenum pname, GLenum mode) {
    
    if (glstate->gl_batch || glstate->list.pending)
        flush();

    LOAD_GLES(glHint);
    noerrorShim();
    switch(pname) {
        case GL_SHRINK_HINT_GL4ES:
            if (mode<=10)
                globals4es.texshrink = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_ALPHAHACK_HINT_GL4ES: 
            if (mode<=1)
                globals4es.alphahack = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_RECYCLEFBO_HINT_GL4ES: 
            if (mode<=1)
                globals4es.recyclefbo = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_MIPMAP_HINT_GL4ES: 
            if (mode<=4)
                globals4es.automipmap = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_TEXDUMP_HINT_GL4ES: 
            if (mode<=1)
                globals4es.texdump = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_COPY_HINT_GL4ES: 
            if (mode<=1)
                globals4es.copytex = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_NOLUMAPHA_HINT_GL4ES: 
            if (mode<=1)
                globals4es.nolumalpha = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_BLENDHACK_HINT_GL4ES: 
            if (mode<=1)
                globals4es.blendhack = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_BATCH_HINT_GL4ES: 
            if (mode<=1) {
                globals4es.batch = 0; flush();
                globals4es.batch = mode;
                if (mode) init_batch();
            } else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_NOERROR_HINT_GL4ES: 
            if (mode<=1)
                globals4es.noerror = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        case GL_NODOWNSAMPLING_HINT_GL4ES:
            if (mode<=1)
                globals4es.nodownsampling = mode;
            else
                errorShim(GL_INVALID_ENUM); 
            break;
        default:
            errorGL();
            gles_glHint(pname, mode);
    }
}
void glHint(GLenum pname, GLenum mode) AliasExport("gl4es_glHint");