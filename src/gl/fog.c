#include "fog.h"
#include "../glx/hardext.h"
#include "matrix.h"
#include "matvec.h"

void gl4es_glFogfv(GLenum pname, const GLfloat* params) {

    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
                NewStage(glstate->list.active, STAGE_FOG);
                rlFogOp(glstate->list.active, pname, params);
                return;
            }
        else flush();
    noerrorShim();
    #define GO(A,name, size) if(memcmp(A glstate->fog.name, params, size)==0) return; else memcpy(A glstate->fog.name, params, size);
    switch (pname) {
        case GL_FOG_MODE:
            GO(&, mode, sizeof(GLfloat))
            break;
        case GL_FOG_DENSITY:
            GO(&, density, sizeof(GLfloat))
            break;
        case GL_FOG_START:
            GO(&, start, sizeof(GLfloat))
            break;
        case GL_FOG_END:
            GO(&, end, sizeof(GLfloat))
            break;
        case GL_FOG_INDEX:
            GO(&, index, sizeof(GLfloat))
            return; // unsupported on GLES1.1
        case GL_FOG_COLOR:
            GO(, color, 4*sizeof(GLfloat))
            break;
        case GL_FOG_COORD_SRC:
            GO(&, coord_src, sizeof(GLfloat))
            return; // unsupported on GLES1.1
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    #undef GO
    LOAD_GLES(glFogfv);
    gles_glFogfv(pname, params);
    errorGL();
}





void glFogfv(GLenum pname, const GLfloat* params) AliasExport("gl4es_glFogfv");

