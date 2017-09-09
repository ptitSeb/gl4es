#include "fpe.h"
#include "gl.h"
#include "../glx/hardext.h"

// ********* Cache handling *********

// ********* Shader stuffs handling *********
void fpe_program() {

}

// ********* Fixed Pipeling function wrapper *********
#define CHECKFPE      \
    if(!glstate->fpe) \
        fpe_program();

void fpe_glEnableClientState(GLenum cap) {
    CHECKFPE
}

void fpe_glDisableClientState(GLenum cap) {
    CHECKFPE
}

void fpe_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    CHECKFPE
}

void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glEnable(GLenum cap) {
    gl4es_glEnable(cap);    // may reset fpe curent program
}
void fpe_glDisable(GLenum cap) {
    gl4es_glDisable(cap);   // may reset fpe curent program
}

void fpe_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    noerrorShim();
}

void fpe_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    noerrorShim();
}

void fpe_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    CHECKFPE
    realize_fpeenv();
    LOAD_GLES(glDrawArrays);
    gles_glDrawArrays(mode, first, count);
}

void fpe_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) {
    CHECKFPE
    realize_fpeenv();
    LOAD_GLES(glDrawElements);
    gles_glDrawElements(mode, count, type, indices);
}


// ********* Realize GLES Environnements *********

void realize_glenv() {
    if(hardext.esversion==1) return;
    LOAD_GLES2(glUseProgram);
    // activate program if needed
    if(glstate->gleshard.program != glstate->glsl.program) {
        glstate->gleshard.program = glstate->glsl.program;
        gles_glUseProgram(glstate->gleshard.program);
    }
    // set VertexAttrib if needed
    for(int i=0; i<hardext.maxvattrib; i++) {
        vertexattrib_t *v = &glstate->gleshard.vertexattrib[i];
        vertexattrib_t *w = &glstate->gleshard.wanted[i];
        // enable / disable Array if needed
        if(v->vaarray != w->vaarray) {
            LOAD_GLES2(glEnableVertexAttribArray)
            LOAD_GLES2(glDisableVertexAttribArray);
            v->vaarray = w->vaarray;
            if(v->vaarray)
                gles_glEnableVertexAttribArray(i);
            else
                gles_glDisableVertexAttribArray(i);
        }
        // check if new value has to be sent to hardware
        if(v->vaarray) {
            // array case
            if(v->size!=w->size || v->type!=w->type || v->normalized!=w->normalized 
                || v->stride!=w->stride || v->pointer!=w->pointer || v->buffer!=w->buffer) {
                v->size = w->size;
                v->type = w->type;
                v->normalized = w->normalized;
                v->stride = w->stride;
                v->pointer = w->pointer;
                v->buffer = w->buffer;
                LOAD_GLES2(glVertexAttribPointer);
                gles_glVertexAttribPointer(i, v->size, v->type, v->normalized, v->stride, (GLvoid*)((uintptr_t)v->pointer+((v->buffer)?(uintptr_t)v->buffer->data:0)));
            }
        } else {
            // single value case
            if(memcmp(v->current, w->current, 4*sizeof(GLfloat))==0) {
                memcpy(glstate->gleshard.vertexattrib[i].current, glstate->vao->vertexattrib[i].current, 4*sizeof(GLfloat));
                LOAD_GLES2(glVertexAttrib4fv);
                gles_glVertexAttrib4fv(i, glstate->gleshard.vertexattrib[i].current);
            }
        }
    }
}
void realize_fpeenv() {

}
void realize_blitenv(int alpha) {
    LOAD_GLES2(glUseProgram);
    if(glstate->gleshard.program != ((alpha)?glstate->blit->program_alpha:glstate->blit->program)) {
        glstate->gleshard.program = ((alpha)?glstate->blit->program_alpha:glstate->blit->program);
        gles_glUseProgram(glstate->gleshard.program);
    }
    // set VertexAttrib if needed
    for(int i=0; i<hardext.maxvattrib; i++) {
        vertexattrib_t *v = &glstate->gleshard.vertexattrib[i];
        // enable / disable Array if needed
        if(v->vaarray != ((i<2)?1:0)) {
            LOAD_GLES2(glEnableVertexAttribArray)
            LOAD_GLES2(glDisableVertexAttribArray);
            v->vaarray = ((i<2)?1:0);
            if(v->vaarray)
                gles_glEnableVertexAttribArray(i);
            else
                gles_glDisableVertexAttribArray(i);
        }
        // check if new value has to be sent to hardware
        if(i<2) {
            // array case
            if(v->size!=2 || v->type!=GL_FLOAT || v->normalized!=0 
                || v->stride!=0 || v->pointer!=((i==0)?glstate->blit->vert:glstate->blit->tex) 
                || v->buffer!=0) {
                v->size = 2;
                v->type = GL_FLOAT;
                v->normalized = 0;
                v->stride = 0;
                v->pointer = ((i==0)?glstate->blit->vert:glstate->blit->tex);
                v->buffer = 0;
                LOAD_GLES2(glVertexAttribPointer);
                gles_glVertexAttribPointer(i, v->size, v->type, v->normalized, v->stride, v->pointer);
            }
        }
        if(i==2 && alpha) {
            if(memcmp(v->current, glstate->color, 4*sizeof(GLfloat))==0) {
                memcpy(glstate->gleshard.vertexattrib[i].current, glstate->color, 4*sizeof(GLfloat));
                LOAD_GLES2(glVertexAttrib4fv);
                gles_glVertexAttrib4fv(i, glstate->gleshard.vertexattrib[i].current);
            }
        }
    }

}
