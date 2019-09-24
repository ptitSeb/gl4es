#include "pointsprite.h"

#include "../glx/hardext.h"
#include "debug.h"
#include "fpe.h"
#include "gl4es.h"
#include "glstate.h"
#include "loader.h"

void gl4es_glPointParameteri(GLenum pname, GLint param)
{
    gl4es_glPointParameterf(pname, param);
}
void glPointParameteri(GLenum pname, GLint param) AliasExport("gl4es_glPointParameteri");

void gl4es_glPointParameteriv(GLenum pname, const GLint * params)
{
    GLfloat tmp[3];
    int v=(pname==GL_POINT_DISTANCE_ATTENUATION)?3:1;
    for (int i=0; i<v; i++) tmp[i] = params[i];
    gl4es_glPointParameterfv(pname, tmp);
}
void glPointParameteriv(GLenum pname, const GLint * params) AliasExport("gl4es_glPointParameteriv");

void gl4es_glPointParameterf(GLenum pname, GLfloat param) {
    PUSH_IF_COMPILING(glPointParameterf);
    gl4es_glPointParameterfv(pname, &param);
}
void glPointParameterf(GLenum pname, GLfloat param) AliasExport("gl4es_glPointParameterf");
void glPointParameterfARB(GLenum pname, GLfloat param) AliasExport("gl4es_glPointParameterf");
void glPointParameterfEXT(GLenum pname, GLfloat param) AliasExport("gl4es_glPointParameterf");

void gl4es_glPointParameterfv(GLenum pname, const GLfloat * params)
{
    if (glstate->list.active)
        if (glstate->list.compiling) {
            if (pname == GL_POINT_DISTANCE_ATTENUATION) {
                NewStage(glstate->list.active, STAGE_POINTPARAM);
                rlPointParamOp(glstate->list.active, 1, params);
                return;
            } else {
                gl4es_glPointParameterf(pname, params[0]);
                return;
            }
        } else gl4es_flush();

    switch(pname) {
        case GL_POINT_SIZE_MIN:
            if(*params<0.0f) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->pointsprite.sizeMin == *params) {
                noerrorShim();
                return;
            }
            glstate->pointsprite.sizeMin = *params;
            break;
        case GL_POINT_SIZE_MAX:
            if(*params<0.0f) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->pointsprite.sizeMax == *params) {
                noerrorShim();
                return;
            }
            glstate->pointsprite.sizeMax = *params;
            break;
        case GL_POINT_FADE_THRESHOLD_SIZE:
            if(*params<0.0f) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->pointsprite.fadeThresholdSize == *params) {
                noerrorShim();
                return;
            }
            glstate->pointsprite.fadeThresholdSize = *params;
            break;
        case GL_POINT_DISTANCE_ATTENUATION:
            if(*params<0.0f) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(memcmp(glstate->pointsprite.distance, params, 3*sizeof(GLfloat))==0) {
                noerrorShim();
                return;
            }
            memcpy(glstate->pointsprite.distance, params, 3*sizeof(GLfloat));
            break;
        case GL_POINT_SPRITE_COORD_ORIGIN:
            if(*params!=GL_UPPER_LEFT && *params!=GL_LOWER_LEFT) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->pointsprite.coordOrigin == *params) {
                noerrorShim();
                return;
            }
            if(glstate->fpe_state) {
                if(*params==GL_LOWER_LEFT)
                    glstate->fpe_state->pointsprite_upper = 0;
                else
                    glstate->fpe_state->pointsprite_upper = 1;
            }
            glstate->pointsprite.coordOrigin = *params;
            break;
    }

    LOAD_GLES_FPE(glPointParameterfv);
    errorGL();
    gles_glPointParameterfv(pname, params);
}
void glPointParameterfv(GLenum pname, const GLfloat * params) AliasExport("gl4es_glPointParameterfv");
void glPointParameterfvARB(GLenum pname, const GLfloat * params) AliasExport("gl4es_glPointParameterfv");
void glPointParameterfvEXT(GLenum pname, const GLfloat * params) AliasExport("gl4es_glPointParameterfv");

void gl4es_glPointSize(GLfloat size) {
    if(size<=0.0f) {
        errorShim(GL_INVALID_VALUE);
        return;
    }
    glstate->pointsprite.size = size;
    errorGL();
    LOAD_GLES_FPE(glPointSize);
    gles_glPointSize(size);
}
void glPointSize(GLfloat size) AliasExport("gl4es_glPointSize");
