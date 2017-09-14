#include "fpe.h"
#include "gl.h"
#include "../glx/hardext.h"
#include "matrix.h"
#include "matvec.h"
#include "program.h"
#include "shaderconv.h"
#include "debug.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

// ********* Cache handling *********

// ********* Shader stuffs handling *********
void fpe_program() {

}

// ********* Fixed Pipeling function wrapper *********
#define CHECKFPE      \
    if(!glstate->fpe) \
        fpe_program();

void fpe_glClientActiveTexture(GLenum texture) {
    DBG(printf("fpe_glClientActiveTexture(%s)\n", PrintEnum(texture));)
    glstate->fpe_client.client = texture - GL_TEXTURE0;
}

void fpe_EnableDisableClientState(GLenum cap, GLboolean val) {
    switch(cap) {
        case GL_VERTEX_ARRAY:
            glstate->fpe_client.vertex_array = val;
            break;
        case GL_COLOR_ARRAY:
            glstate->fpe_client.color_array = val;
            break;
        case GL_NORMAL_ARRAY:
            glstate->fpe_client.normal_array = val;
            break;
        case GL_TEXTURE_COORD_ARRAY:
            glstate->fpe_client.tex_coord_array[glstate->fpe_client.client] = val;
            break;
        case GL_SECONDARY_COLOR_ARRAY:
            glstate->fpe_client.secondary_array = val;
            break;
    }
}

void fpe_glEnableClientState(GLenum cap) {
    DBG(printf("fpe_glEnableClientState(%s)\n", PrintEnum(cap));)
    fpe_EnableDisableClientState(cap, GL_TRUE);
}

void fpe_glDisableClientState(GLenum cap) {
    DBG(printf("fpe_glDisableClientState(%s)\n", PrintEnum(cap));)
    fpe_EnableDisableClientState(cap, GL_FALSE);
}

void fpe_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    CHECKFPE
}

void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    glstate->fpe_client.secondary.size = size;
    glstate->fpe_client.secondary.type = type;
    glstate->fpe_client.secondary.stride = stride;
    glstate->fpe_client.secondary.pointer = pointer;
}

void fpe_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    DBG(printf("fpe_glVertexPointer(%d, %s, %d, %p)\n", size, PrintEnum(type), stride, pointer);)
    glstate->fpe_client.vert.size = size;
    glstate->fpe_client.vert.type = type;
    glstate->fpe_client.vert.stride = stride;
    glstate->fpe_client.vert.pointer = pointer;
}

void fpe_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    glstate->fpe_client.color.size = size;
    glstate->fpe_client.color.type = type;
    glstate->fpe_client.color.stride = stride;
    glstate->fpe_client.color.pointer = pointer;
}

void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    glstate->fpe_client.normal.size = 3;
    glstate->fpe_client.normal.type = type;
    glstate->fpe_client.normal.stride = stride;
    glstate->fpe_client.normal.pointer = pointer;
}

void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    glstate->fpe_client.tex[glstate->fpe_client.client].size = size;
    glstate->fpe_client.tex[glstate->fpe_client.client].type = type;
    glstate->fpe_client.tex[glstate->fpe_client.client].stride = stride;
    glstate->fpe_client.tex[glstate->fpe_client.client].pointer = pointer;
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
    DBG(printf("fpe_glDrawArrays(%s, %d, %d)\n", PrintEnum(mode), first, count);)
    realize_glenv();
    LOAD_GLES(glDrawArrays);
    gles_glDrawArrays(mode, first, count);
}

void fpe_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) {
    DBG(printf("fpe_glDrawElements(%s, %d, %s, %d)\n", PrintEnum(mode), count, PrintEnum(type), indices);)
    realize_glenv();
    LOAD_GLES(glDrawElements);
    gles_glDrawElements(mode, count, type, indices);
}

void fpe_glMatrixMode(GLenum mode) {
    noerrorShim();
}

void fpe_glLightModelf(GLenum pname, GLfloat param) {
    noerrorShim();
}
void fpe_glLightModelfv(GLenum pname, const GLfloat* params) {
    noerrorShim();
}
void fpe_glLightfv(GLenum light, GLenum pname, const GLfloat* params) {
    noerrorShim();
}
void fpe_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    noerrorShim();
}
void fpe_glMaterialf(GLenum face, GLenum pname, const GLfloat param) {
    noerrorShim();
}


// ********* Realize GLES Environnements *********

void realize_glenv() {
    if(hardext.esversion==1) return;
    LOAD_GLES2(glUseProgram);
    // activate program if needed
    if(glstate->gleshard.program != glstate->glsl.program) {
        glstate->gleshard.program = glstate->glsl.program;
        glstate->gleshard.glprogram = glstate->glsl.glprogram;
        gles_glUseProgram(glstate->gleshard.program);
    }
    // setup fixed pipeline builtin vertex attrib if needed
    program_t *glprogram = glstate->gleshard.glprogram;
    {
        int vaarray = 0;
        int id = -1;
        // Vertex....
        id = glprogram->builtin_attrib[ATT_VERTEX];
        if(id!=-1) {
            vertexattrib_t *w = &glstate->gleshard.wanted[id];
            pointer_state_t *p = &glstate->fpe_client.vert;
            w->vaarray = glstate->fpe_client.vertex_array;
            if(w->vaarray) {
                w->size = p->size;
                w->type = p->type;
                w->normalized = (p->type==GL_FLOAT)?GL_FALSE:GL_TRUE;
                w->stride = p->stride;
                w->pointer = p->pointer;
                w->buffer = NULL;
            } else {
                memcpy(w->current, glstate->vertex, 4*sizeof(GLfloat));
            }
        }
        // Color....
        id = glprogram->builtin_attrib[ATT_COLOR];
        if(id!=-1) {
            vertexattrib_t *w = &glstate->gleshard.wanted[id];
            pointer_state_t *p = &glstate->fpe_client.color;
            w->vaarray = glstate->fpe_client.color_array;
            if(w->vaarray) {
                w->size = p->size;
                w->type = p->type;
                w->normalized = (p->type==GL_FLOAT)?GL_FALSE:GL_TRUE;
                w->stride = p->stride;
                w->pointer = p->pointer;
                w->buffer = NULL;
            } else {
                memcpy(w->current, glstate->color, 4*sizeof(GLfloat));
            }
        }
        // TexCoordX
        for(int tex=0; tex<hardext.maxtex; tex++) {
            id = glprogram->builtin_attrib[ATT_MULTITEXCOORD0+tex];
            if(id!=-1) {
                vertexattrib_t *w = &glstate->gleshard.wanted[id];
                pointer_state_t *p = &glstate->fpe_client.tex[tex];
                w->vaarray = glstate->fpe_client.tex_coord_array[tex];
                if(w->vaarray) {
                    w->size = p->size;
                    w->type = p->type;
                    w->normalized = (p->type==GL_FLOAT)?GL_FALSE:GL_TRUE;
                    w->stride = p->stride;
                    w->pointer = p->pointer;
                    w->buffer = NULL;
                } else {
                    memcpy(w->current, glstate->texcoord[tex], 4*sizeof(GLfloat));
                }
            }
        }
        // Normal....
        id = glprogram->builtin_attrib[ATT_NORMAL];
        if(id!=-1) {
            vertexattrib_t *w = &glstate->gleshard.wanted[id];
            pointer_state_t *p = &glstate->fpe_client.normal;
            w->vaarray = glstate->fpe_client.normal_array;
            if(w->vaarray) {
                w->size = p->size;
                w->type = p->type;
                w->normalized = (p->type==GL_FLOAT)?GL_FALSE:GL_TRUE;
                w->stride = p->stride;
                w->pointer = p->pointer;
                w->buffer = NULL;
            } else {
                memcpy(w->current, glstate->normal, 3*sizeof(GLfloat));
                w->current[3] = 1.0f;
            }
        }
        //TODO: Secondary colors
    }
    // setup fixed pipeline builtin matrix uniform if needed
    {
        if(glprogram->builtin_matrix[MAT_MVP]!=-1 || glprogram->builtin_matrix[MAT_MVP_I]!=-1
            || glprogram->builtin_matrix[MAT_MVP_T]!=-1 || glprogram->builtin_matrix[MAT_MVP_IT]!=-1)
        {
            gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MVP], 1, GL_FALSE, getMVPMat());
            gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MVP_T], 1, GL_TRUE, getMVPMat());
            if(glprogram->builtin_matrix[MAT_MVP_I]!=-1 || glprogram->builtin_matrix[MAT_MVP_IT]!=-1) {
                GLfloat invmat[16];
                matrix_inverse(getMVPMat(), invmat);
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MVP_I], 1, GL_FALSE, invmat);
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MVP_IT], 1, GL_TRUE, invmat);
            }
        }
        if(glprogram->builtin_matrix[MAT_MV]!=-1 || glprogram->builtin_matrix[MAT_MV_I]!=-1
            || glprogram->builtin_matrix[MAT_MV_T]!=-1 || glprogram->builtin_matrix[MAT_MV_IT]!=-1)
        {
            gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MV], 1, GL_FALSE, getMVMat());
            gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MV_T], 1, GL_TRUE, getMVMat());
            if(glprogram->builtin_matrix[MAT_MV_I]!=-1 || glprogram->builtin_matrix[MAT_MV_IT]!=-1) {
                GLfloat invmat[16];
                matrix_inverse(getMVMat(), invmat);
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MV_I], 1, GL_FALSE, invmat);
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_MV_IT], 1, GL_TRUE, invmat);
            }
        }
        if(glprogram->builtin_matrix[MAT_P]!=-1 || glprogram->builtin_matrix[MAT_P_I]!=-1
            || glprogram->builtin_matrix[MAT_P_T]!=-1 || glprogram->builtin_matrix[MAT_P_IT]!=-1)
        {
            gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_P], 1, GL_FALSE, getPMat());
            gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_P_T], 1, GL_TRUE, getPMat());
            if(glprogram->builtin_matrix[MAT_P_I]!=-1 || glprogram->builtin_matrix[MAT_P_IT]!=-1) {
                GLfloat invmat[16];
                matrix_inverse(getPMat(), invmat);
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_P_I], 1, GL_FALSE, invmat);
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_P_IT], 1, GL_TRUE, invmat);
            }
        }
        //Normal matrix (mat3 version of transpose(inverse(gl_ModelViewMatrix)))
        if(glprogram->builtin_matrix[MAT_N]!=-1)
        {
            GLfloat invmat[16], matn[9];
            matrix_inverse(getMVMat(), invmat);
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    matn[i+j*3]=invmat[j+i*4];  // transpose and reduce to 3x3
            gl4es_glUniformMatrix3fv(glprogram->builtin_matrix[MAT_N], 1, GL_FALSE, matn);
        }
        //Texture matrices
        for (int i=0; i<MAX_TEX; i++) {
            if(glprogram->builtin_matrix[MAT_T0+i*4]!=-1 || glprogram->builtin_matrix[MAT_T0_I+i*4]!=-1
                || glprogram->builtin_matrix[MAT_T0_T+i*4]!=-1 || glprogram->builtin_matrix[MAT_T0_IT+i*4]!=-1)
            {
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_T0+i*4], 1, GL_FALSE, getTexMat(i));
                gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_T0_T+i*4], 1, GL_TRUE, getTexMat(i));
                if(glprogram->builtin_matrix[MAT_T0_I+i*4]!=-1 || glprogram->builtin_matrix[MAT_T0_IT+i*4]!=-1) {
                    GLfloat invmat[16];
                    matrix_inverse(getTexMat(i), invmat);
                    gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_T0_I+i*4], 1, GL_FALSE, invmat);
                    gl4es_glUniformMatrix4fv(glprogram->builtin_matrix[MAT_T0_IT+i*4], 1, GL_TRUE, invmat);
                }
            }
        }
    }
    // set light and material if needed
    {
        for (int i=0; i<MAX_LIGHT; i++) {
            if(glprogram->builtin_lights[i].ambient!=-1) {
               GLfloat tmp[4];
               gl4es_glUniform4fv(glprogram->builtin_lights[i].ambient, 1, glstate->light.lights[i].ambient);
               gl4es_glUniform4fv(glprogram->builtin_lights[i].diffuse, 1, glstate->light.lights[i].diffuse);
               gl4es_glUniform4fv(glprogram->builtin_lights[i].specular, 1, glstate->light.lights[i].specular);
               gl4es_glUniform4fv(glprogram->builtin_lights[i].position, 1, glstate->light.lights[i].position);
               gl4es_glUniform3fv(glprogram->builtin_lights[i].spotDirection, 1, glstate->light.lights[i].spotDirection);
               gl4es_glUniform1f(glprogram->builtin_lights[i].spotExponent, glstate->light.lights[i].spotExponent);
               gl4es_glUniform1f(glprogram->builtin_lights[i].spotCutoff, glstate->light.lights[i].spotCutoff);
               gl4es_glUniform1f(glprogram->builtin_lights[i].spotCosCutoff, cosf(glstate->light.lights[i].spotCutoff*3.1415926535f/180.0f));
               gl4es_glUniform1f(glprogram->builtin_lights[i].constantAttenuation, glstate->light.lights[i].constantAttenuation);
               gl4es_glUniform1f(glprogram->builtin_lights[i].linearAttenuation, glstate->light.lights[i].linearAttenuation);
               gl4es_glUniform1f(glprogram->builtin_lights[i].quadraticAttenuation, glstate->light.lights[i].quadraticAttenuation);
            }
            if(glprogram->builtin_lightprod[0][i].ambient!=-1) {
                GLfloat tmp[4];
                vector4_mult(glstate->material.front.ambient, glstate->light.lights[i].ambient, tmp); //TODO: Check that
                gl4es_glUniform4fv(glprogram->builtin_lightprod[0][i].ambient, 1, tmp);
                vector4_mult(glstate->material.front.diffuse, glstate->light.lights[i].diffuse, tmp);
                gl4es_glUniform4fv(glprogram->builtin_lightprod[0][i].diffuse, 1, tmp);
                vector4_mult(glstate->material.front.specular, glstate->light.lights[i].specular, tmp);
                gl4es_glUniform4fv(glprogram->builtin_lightprod[0][i].specular, 1, tmp);
            }
            if(glprogram->builtin_lightprod[1][i].ambient!=-1) {
                GLfloat tmp[4];
                vector4_mult(glstate->material.back.ambient, glstate->light.lights[i].ambient, tmp); //TODO: Check that
                gl4es_glUniform4fv(glprogram->builtin_lightprod[1][i].ambient, 1, tmp);
                vector4_mult(glstate->material.back.diffuse, glstate->light.lights[i].diffuse, tmp);
                gl4es_glUniform4fv(glprogram->builtin_lightprod[1][i].diffuse, 1, tmp);
                vector4_mult(glstate->material.back.specular, glstate->light.lights[i].specular, tmp);
                gl4es_glUniform4fv(glprogram->builtin_lightprod[1][i].specular, 1, tmp);
            }
        }
        if(glprogram->builtin_material[0].ambient!=-1) {
            gl4es_glUniform4fv(glprogram->builtin_material[0].emission, 1, glstate->material.front.emission);
            gl4es_glUniform4fv(glprogram->builtin_material[0].ambient, 1, glstate->material.front.ambient);
            gl4es_glUniform4fv(glprogram->builtin_material[0].diffuse, 1, glstate->material.front.diffuse);
            gl4es_glUniform4fv(glprogram->builtin_material[0].specular, 1, glstate->material.front.specular);
            gl4es_glUniform1f(glprogram->builtin_material[0].shininess, glstate->material.front.shininess);
        }
        if(glprogram->builtin_material[1].ambient!=-1) {
            gl4es_glUniform4fv(glprogram->builtin_material[1].emission, 1, glstate->material.back.emission);
            gl4es_glUniform4fv(glprogram->builtin_material[1].ambient, 1, glstate->material.back.ambient);
            gl4es_glUniform4fv(glprogram->builtin_material[1].diffuse, 1, glstate->material.back.diffuse);
            gl4es_glUniform4fv(glprogram->builtin_material[1].specular, 1, glstate->material.back.specular);
            gl4es_glUniform1f(glprogram->builtin_material[1].shininess, glstate->material.back.shininess);
        }
        if(glprogram->builtin_lightmodelprod[0].sceneColor!=-1) {
            GLfloat tmp[4];
            vector4_mult(glstate->material.front.ambient, glstate->light.ambient, tmp);  //TODO: check that
            vector4_add(tmp, glstate->material.front.emission, tmp);
            gl4es_glUniform4fv(glprogram->builtin_lightmodelprod[0].sceneColor, 1, tmp);
        }
        if(glprogram->builtin_lightmodelprod[1].sceneColor!=-1) {
            GLfloat tmp[4];
            vector4_mult(glstate->material.back.ambient, glstate->light.ambient, tmp);  //TODO: check that
            vector4_add(tmp, glstate->material.back.emission, tmp);
            gl4es_glUniform4fv(glprogram->builtin_lightmodelprod[1].sceneColor, 1, tmp);
        }
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
    realize_glenv();
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

// ********* Builtin GL Uniform, VertexAttrib and co *********

void builtin_Init(program_t *glprogram) {
    // initialise emulated builtin matrix uniform to -1
    for (int i=0; i<MAT_MAX; i++)
        glprogram->builtin_matrix[i] = -1;
    for (int i=0; i<MAX_LIGHT; i++) {
        glprogram->builtin_lights[i].ambient = -1;
        glprogram->builtin_lights[i].diffuse = -1;
        glprogram->builtin_lights[i].specular = -1;
        glprogram->builtin_lights[i].position = -1;
        glprogram->builtin_lights[i].halfVector = -1;
        glprogram->builtin_lights[i].spotDirection = -1;
        glprogram->builtin_lights[i].spotExponent = -1;
        glprogram->builtin_lights[i].spotCutoff = -1;
        glprogram->builtin_lights[i].spotCosCutoff = -1;
        glprogram->builtin_lights[i].constantAttenuation = -1;
        glprogram->builtin_lights[i].linearAttenuation = -1;
        glprogram->builtin_lights[i].quadraticAttenuation = -1;
    }
    for (int i=0; i<2; i++) { // 0:Front, 1:Back
        glprogram->builtin_material[i].emission = -1;
        glprogram->builtin_material[i].ambient = -1;
        glprogram->builtin_material[i].diffuse = -1;
        glprogram->builtin_material[i].specular = -1;
        glprogram->builtin_material[i].shininess = -1;
        
        glprogram->builtin_lightmodelprod[i].sceneColor = -1;

        for (int j=0; j<MAX_LIGHT; j++) {
            glprogram->builtin_lightprod[i][j].ambient = -1;
            glprogram->builtin_lightprod[i][j].diffuse = -1;
            glprogram->builtin_lightprod[i][j].specular = -1;
        }
    }

    // initialise emulated builtin attrib to -1
    for (int i=0; i<ATT_MAX; i++)
        glprogram->builtin_attrib[i] = -1;
}

const char* lightsource_code = "_gl4es_LightSource[";
const char* frontmaterial_code = "_gl4es_FrontMaterial";
const char* backmaterial_code = "_gl4es_BackMaterial";
const char* frontlightmodelprod_code = "_gl4es_FrontLightModelProduct";
const char* backlightmodelprod_code = "_gl4es_BackLightModelProduct";
const char* frontlightprod_code = "_gl4es_FrontLightProduct[";
const char* backlightprod_code = "_gl4es_BackLightProduct[";
int builtin_CheckUniform(program_t *glprogram, char* name, GLint id) {
    int builtin = isBuiltinMatrix(name);
    // check matrices
    if(builtin!=-1) {
        glprogram->builtin_matrix[builtin] = id;
        return 1;
    }
    // lightsource
    if(strncmp(name, lightsource_code, strlen(lightsource_code))==0) {
        // it a light! grab it's number
        int n = name[strlen(lightsource_code)]-'0';   // only 8 light, so this works
        if(strstr(name, ".ambient")) glprogram->builtin_lights[n].ambient = id;
        else if(strstr(name, ".diffuse")) glprogram->builtin_lights[n].diffuse = id;
        else if(strstr(name, ".specular")) glprogram->builtin_lights[n].specular = id;
        else if(strstr(name, ".position")) glprogram->builtin_lights[n].position = id;
        else if(strstr(name, ".halfVector")) glprogram->builtin_lights[n].halfVector = id;
        else if(strstr(name, ".spotDirection")) glprogram->builtin_lights[n].spotDirection = id;
        else if(strstr(name, ".spotExponent")) glprogram->builtin_lights[n].spotExponent = id;
        else if(strstr(name, ".spotCutoff")) glprogram->builtin_lights[n].spotCutoff = id;
        else if(strstr(name, ".spotCosCutoff")) glprogram->builtin_lights[n].spotCosCutoff = id;
        else if(strstr(name, ".constantAttenuation")) glprogram->builtin_lights[n].constantAttenuation = id;
        else if(strstr(name, ".linearAttenuation")) glprogram->builtin_lights[n].linearAttenuation = id;
        else if(strstr(name, ".quadraticAttenuation")) glprogram->builtin_lights[n].quadraticAttenuation = id;
        return 1;
    }
    if(strncmp(name, frontmaterial_code, strlen(frontmaterial_code))==0 
        || strncmp(name, backmaterial_code, strlen(backmaterial_code))==0)
    {
        // it's a material
        int n=(strncmp(name, frontmaterial_code, strlen(frontmaterial_code))==0)?0:1;
        if(strstr(name, ".emission")) glprogram->builtin_material[n].emission = id;
        else if(strstr(name, ".ambient")) glprogram->builtin_material[n].ambient = id;
        else if(strstr(name, ".diffuse")) glprogram->builtin_material[n].diffuse = id;
        else if(strstr(name, ".specular")) glprogram->builtin_material[n].specular = id;
        else if(strstr(name, ".shininess")) glprogram->builtin_material[n].shininess = id;
        return 1;
    }
    if(strncmp(name, frontlightmodelprod_code, strlen(frontlightmodelprod_code))==0 
    || strncmp(name, backlightmodelprod_code, strlen(backlightmodelprod_code))==0)
    {
        // it's a front light model product
        int n=(strncmp(name, frontlightmodelprod_code, strlen(frontlightmodelprod_code))==0)?0:1;
        if(strstr(name, ".sceneColor")) glprogram->builtin_lightmodelprod[n].sceneColor = id;
        return 1;
    }
    if(strncmp(name, frontlightprod_code, strlen(frontlightprod_code))==0 
    || strncmp(name, backlightprod_code, strlen(backlightprod_code))==0)
    {
        // it's a material
        int i=(strncmp(name, frontlightprod_code, strlen(frontlightprod_code))==0)?0:1;
        int n = name[strlen(i?backlightprod_code:frontlightprod_code)]-'0';   // only 8 light, so this works
        if(strstr(name, ".ambient")) glprogram->builtin_lightprod[i][n].ambient = id;
        else if(strstr(name, ".diffuse")) glprogram->builtin_lightprod[i][n].diffuse = id;
        else if(strstr(name, ".specular")) glprogram->builtin_lightprod[i][n].specular = id;
        return 1;
    }

    return 0;
}

int builtin_CheckVertexAttrib(program_t *glprogram, char* name, GLint id) {
    int builtin = isBuiltinAttrib(name);
    if(builtin!=-1) {
        glprogram->builtin_attrib[builtin] = id;
        return 1;
    }
    return 0;
}
