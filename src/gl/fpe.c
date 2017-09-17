#include "fpe.h"
#include "gl.h"
#include "../glx/hardext.h"
#include "matrix.h"
#include "matvec.h"
#include "program.h"
#include "shaderconv.h"
#include "debug.h"
#include "array.h"

//#define DEBUG
#ifdef DEBUG
#pragma GCC optimize 0
#define DBG(a) a
#else
#define DBG(a)
#endif

// ********* Cache handling *********

// ********* Shader stuffs handling *********
const char* dummy_vertex = \
"varying vec4 Color; \n"
"void main() {\n"
"Color = gl_Color;\n"
"gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
"}";

const char* dummy_frag = \
"varying vec4 Color; \n"
"void main() {\n"
"gl_FragColor = Color;\n"
"}\n";

void fpe_program() {
    // dummy program for now...
    if(glstate->fpe->glprogram==NULL) {
        glstate->fpe->vert = gl4es_glCreateShader(GL_VERTEX_SHADER);
        gl4es_glShaderSource(glstate->fpe->vert, 1, &dummy_vertex, NULL);
        gl4es_glCompileShader(glstate->fpe->vert);
        glstate->fpe->frag = gl4es_glCreateShader(GL_FRAGMENT_SHADER);
        gl4es_glShaderSource(glstate->fpe->frag, 1, &dummy_frag, NULL);
        gl4es_glCompileShader(glstate->fpe->frag);
        glstate->fpe->prog = gl4es_glCreateProgram();
        gl4es_glAttachShader(glstate->fpe->prog, glstate->fpe->vert);
        gl4es_glAttachShader(glstate->fpe->prog, glstate->fpe->frag);
        gl4es_glLinkProgram(glstate->fpe->prog);
        // now find the program
        khint_t k_program;
        {
            int ret;
            khash_t(programlist) *programs = glstate->glsl.programs;
            k_program = kh_get(programlist, programs, glstate->fpe->prog);
            if (k_program != kh_end(programs))
                glstate->fpe->glprogram = kh_value(programs, k_program);
        }
        DBG(printf("creating dummy FPE shader : %d(%p)\n", glstate->fpe->prog, glstate->fpe->glprogram);)
    }

}

// ********* Fixed Pipeling function wrapper *********

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
}

void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    DBG(printf("fpe_glSecondaryColorPointer(%d, %s, %d, %p)\n", size, PrintEnum(type), stride, pointer);)
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
    DBG(printf("fpe_glColorPointer(%d, %s, %d, %p)\n", size, PrintEnum(type), stride, pointer);)
    glstate->fpe_client.color.size = size;
    glstate->fpe_client.color.type = type;
    glstate->fpe_client.color.stride = stride;
    glstate->fpe_client.color.pointer = pointer;
}

void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    DBG(printf("fpe_glNormalPointer(%s, %d, %p)\n", PrintEnum(type), stride, pointer);)
    glstate->fpe_client.normal.size = 3;
    glstate->fpe_client.normal.type = type;
    glstate->fpe_client.normal.stride = stride;
    glstate->fpe_client.normal.pointer = pointer;
}

void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    DBG(printf("fpe_glTexCoordPointer(%d, %s, %d, %p) on tmu=%d\n", size, PrintEnum(type), stride, pointer, glstate->fpe_client.client);)
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
    DBG(printf("fpe_glDrawElements(%s, %d, %s, %p)\n", PrintEnum(mode), count, PrintEnum(type), indices);)
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

void fpe_glFogfv(GLenum pname, const GLfloat* params) {
    noerrorShim();
}

void fpe_glPointParameterfv(GLenum pname, const GLfloat * params) {
    noerrorShim();
}
void fpe_glPointSize(GLfloat size) {
    noerrorShim();
}


// ********* Realize GLES Environnements *********

void realize_glenv() {
    if(hardext.esversion==1) return;
    LOAD_GLES2(glUseProgram);
    // activate program if needed
    if(glstate->glsl.program) {
        if(glstate->gleshard.program != glstate->glsl.program)
        {
            glstate->gleshard.program = glstate->glsl.program;
            glstate->gleshard.glprogram = glstate->glsl.glprogram;
            gles_glUseProgram(glstate->gleshard.program);
            DBG(printf("Use GLSL program %d\n", glstate->gleshard.program);)
        }
    } else {
        fpe_program();
        if(glstate->gleshard.program != glstate->fpe->prog)
        {
            glstate->gleshard.program = glstate->fpe->prog;
            glstate->gleshard.glprogram = glstate->fpe->glprogram;
            gles_glUseProgram(glstate->gleshard.program);
            DBG(printf("Use FPE program %d\n", glstate->gleshard.program);)
        }
    }
    program_t *glprogram = glstate->gleshard.glprogram;
    // setup fixed pipeline builtin vertex attrib if needed
    if(glprogram->has_builtin_attrib)
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
    if(glprogram->has_builtin_matrix)
    {
        if(glprogram->builtin_matrix[MAT_MVP]!=-1 || glprogram->builtin_matrix[MAT_MVP_I]!=-1
            || glprogram->builtin_matrix[MAT_MVP_T]!=-1 || glprogram->builtin_matrix[MAT_MVP_IT]!=-1)
        {
            GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MVP], 1, GL_FALSE, getMVPMat());
            GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MVP_T], 1, GL_TRUE, getMVPMat());
            if(glprogram->builtin_matrix[MAT_MVP_I]!=-1 || glprogram->builtin_matrix[MAT_MVP_IT]!=-1) {
                GLfloat invmat[16];
                matrix_inverse(getMVPMat(), invmat);
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MVP_I], 1, GL_FALSE, invmat);
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MVP_IT], 1, GL_TRUE, invmat);
            }
        }
        if(glprogram->builtin_matrix[MAT_MV]!=-1 || glprogram->builtin_matrix[MAT_MV_I]!=-1
            || glprogram->builtin_matrix[MAT_MV_T]!=-1 || glprogram->builtin_matrix[MAT_MV_IT]!=-1)
        {
            GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MV], 1, GL_FALSE, getMVMat());
            GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MV_T], 1, GL_TRUE, getMVMat());
            if(glprogram->builtin_matrix[MAT_MV_I]!=-1 || glprogram->builtin_matrix[MAT_MV_IT]!=-1) {
                GLfloat invmat[16];
                matrix_inverse(getMVMat(), invmat);
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MV_I], 1, GL_FALSE, invmat);
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_MV_IT], 1, GL_TRUE, invmat);
            }
        }
        if(glprogram->builtin_matrix[MAT_P]!=-1 || glprogram->builtin_matrix[MAT_P_I]!=-1
            || glprogram->builtin_matrix[MAT_P_T]!=-1 || glprogram->builtin_matrix[MAT_P_IT]!=-1)
        {
            GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_P], 1, GL_FALSE, getPMat());
            GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_P_T], 1, GL_TRUE, getPMat());
            if(glprogram->builtin_matrix[MAT_P_I]!=-1 || glprogram->builtin_matrix[MAT_P_IT]!=-1) {
                GLfloat invmat[16];
                matrix_inverse(getPMat(), invmat);
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_P_I], 1, GL_FALSE, invmat);
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_P_IT], 1, GL_TRUE, invmat);
            }
        }
        //Normal matrix (mat3 version of transpose(inverse(gl_ModelViewMatrix)))
        if(glprogram->builtin_matrix[MAT_N]!=-1 || glprogram->builtin_normalrescale!=-1)
        {
            if(glprogram->builtin_normalrescale!=-1 && !glstate->fpe_state->rescaling)
            {
                float tmp = 1.0f;
                GoUniformfv(glprogram, glprogram->builtin_normalrescale, 1, 1, &tmp);
            }
            if((glprogram->builtin_normalrescale!=-1 && glstate->fpe_state->rescaling) || glprogram->builtin_matrix[MAT_N]!=-1)
            {
                GLfloat invmat[16], matn[9];
                matrix_inverse(getMVMat(), invmat);
                for(int i=0; i<3; i++)
                    for(int j=0; j<3; j++)
                        matn[i+j*3]=invmat[j+i*4];  // transpose and reduce to 3x3
                GoUniformMatrix3fv(glprogram, glprogram->builtin_matrix[MAT_N], 1, GL_FALSE, matn);
                if(glprogram->builtin_normalrescale!=-1) {
                    float tmp = 1.0f/sqrtf(invmat[3*3+1]*invmat[3*3+1]+invmat[3*3+2]*invmat[3*3+2]+invmat[3*3+3]*invmat[3*3+3]);
                    GoUniformfv(glprogram, glprogram->builtin_normalrescale, 1, 1, &tmp);
                }
            }
        }
        //Texture matrices
        for (int i=0; i<MAX_TEX; i++) {
            if(glprogram->builtin_matrix[MAT_T0+i*4]!=-1 || glprogram->builtin_matrix[MAT_T0_I+i*4]!=-1
                || glprogram->builtin_matrix[MAT_T0_T+i*4]!=-1 || glprogram->builtin_matrix[MAT_T0_IT+i*4]!=-1)
            {
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_T0+i*4], 1, GL_FALSE, getTexMat(i));
                GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_T0_T+i*4], 1, GL_TRUE, getTexMat(i));
                if(glprogram->builtin_matrix[MAT_T0_I+i*4]!=-1 || glprogram->builtin_matrix[MAT_T0_IT+i*4]!=-1) {
                    GLfloat invmat[16];
                    matrix_inverse(getTexMat(i), invmat);
                    GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_T0_I+i*4], 1, GL_FALSE, invmat);
                    GoUniformMatrix4fv(glprogram, glprogram->builtin_matrix[MAT_T0_IT+i*4], 1, GL_TRUE, invmat);
                }
            }
        }
    }
    // set light and material if needed
    if(glprogram->has_builtin_light)
    {
        for (int i=0; i<MAX_LIGHT; i++) {
            if(glprogram->builtin_lights[i].ambient!=-1) {
               GLfloat tmp[4];
               GoUniformfv(glprogram, glprogram->builtin_lights[i].ambient, 4, 1, glstate->light.lights[i].ambient);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].diffuse, 4, 1, glstate->light.lights[i].diffuse);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].specular, 4, 1, glstate->light.lights[i].specular);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].position, 4, 1, glstate->light.lights[i].position);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].spotDirection, 3, 1, glstate->light.lights[i].spotDirection);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].spotExponent, 1, 1, &glstate->light.lights[i].spotExponent);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].spotCutoff, 1, 1, &glstate->light.lights[i].spotCutoff);
               tmp[0] = cosf(glstate->light.lights[i].spotCutoff*3.1415926535f/180.0f);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].spotCosCutoff, 1, 1, tmp);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].constantAttenuation, 1, 1, &glstate->light.lights[i].constantAttenuation);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].linearAttenuation, 1, 1, &glstate->light.lights[i].linearAttenuation);
               GoUniformfv(glprogram, glprogram->builtin_lights[i].quadraticAttenuation, 1, 1, &glstate->light.lights[i].quadraticAttenuation);
            }
            if(glprogram->builtin_lightprod[0][i].ambient!=-1) {
                GLfloat tmp[4];
                vector4_mult(glstate->material.front.ambient, glstate->light.lights[i].ambient, tmp); //TODO: Check that
                GoUniformfv(glprogram, glprogram->builtin_lightprod[0][i].ambient, 4, 1, tmp);
                vector4_mult(glstate->material.front.diffuse, glstate->light.lights[i].diffuse, tmp);
                GoUniformfv(glprogram, glprogram->builtin_lightprod[0][i].diffuse, 4, 1, tmp);
                vector4_mult(glstate->material.front.specular, glstate->light.lights[i].specular, tmp);
                GoUniformfv(glprogram, glprogram->builtin_lightprod[0][i].specular, 4, 1, tmp);
            }
            if(glprogram->builtin_lightprod[1][i].ambient!=-1) {
                GLfloat tmp[4];
                vector4_mult(glstate->material.back.ambient, glstate->light.lights[i].ambient, tmp); //TODO: Check that
                GoUniformfv(glprogram, glprogram->builtin_lightprod[1][i].ambient, 4, 1, tmp);
                vector4_mult(glstate->material.back.diffuse, glstate->light.lights[i].diffuse, tmp);
                GoUniformfv(glprogram, glprogram->builtin_lightprod[1][i].diffuse, 4, 1, tmp);
                vector4_mult(glstate->material.back.specular, glstate->light.lights[i].specular, tmp);
                GoUniformfv(glprogram, glprogram->builtin_lightprod[1][i].specular, 4, 1, tmp);
            }
        }
        if(glprogram->builtin_material[0].ambient!=-1) {
            GoUniformfv(glprogram, glprogram->builtin_material[0].emission, 4, 1, glstate->material.front.emission);
            GoUniformfv(glprogram, glprogram->builtin_material[0].ambient, 4, 1, glstate->material.front.ambient);
            GoUniformfv(glprogram, glprogram->builtin_material[0].diffuse, 4, 1, glstate->material.front.diffuse);
            GoUniformfv(glprogram, glprogram->builtin_material[0].specular, 4, 1, glstate->material.front.specular);
            GoUniformfv(glprogram, glprogram->builtin_material[0].shininess, 1, 1, &glstate->material.front.shininess);
        }
        if(glprogram->builtin_material[1].ambient!=-1) {
            GoUniformfv(glprogram, glprogram->builtin_material[1].emission, 4, 1, glstate->material.back.emission);
            GoUniformfv(glprogram, glprogram->builtin_material[1].ambient, 4, 1, glstate->material.back.ambient);
            GoUniformfv(glprogram, glprogram->builtin_material[1].diffuse, 4, 1, glstate->material.back.diffuse);
            GoUniformfv(glprogram, glprogram->builtin_material[1].specular, 4, 1, glstate->material.back.specular);
            GoUniformfv(glprogram, glprogram->builtin_material[1].shininess, 1, 1, &glstate->material.back.shininess);
        }
        if(glprogram->builtin_lightmodelprod[0].sceneColor!=-1) {
            GLfloat tmp[4];
            vector4_mult(glstate->material.front.ambient, glstate->light.ambient, tmp);  //TODO: check that
            vector4_add(tmp, glstate->material.front.emission, tmp);
            GoUniformfv(glprogram, glprogram->builtin_lightmodelprod[0].sceneColor, 4, 1, tmp);
        }
        if(glprogram->builtin_lightmodelprod[1].sceneColor!=-1) {
            GLfloat tmp[4];
            vector4_mult(glstate->material.back.ambient, glstate->light.ambient, tmp);  //TODO: check that
            vector4_add(tmp, glstate->material.back.emission, tmp);
            GoUniformfv(glprogram, glprogram->builtin_lightmodelprod[1].sceneColor, 4, 1, tmp);
        }
    }
    // check point sprite if needed
    if(glprogram->has_builtin_pointsprite)
    {
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.size, 1, 1, &glstate->pointsprite.size);
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.sizeMin, 1, 1, &glstate->pointsprite.sizeMin);
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.sizeMax, 1, 1, &glstate->pointsprite.sizeMax);
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.fadeThresholdSize, 1, 1, &glstate->pointsprite.fadeThresholdSize);
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.distanceConstantAttenuation, 1, 1, glstate->pointsprite.distance+0);
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.distanceLinearAttenuation, 1, 1, glstate->pointsprite.distance+1);
        GoUniformfv(glprogram, glprogram->builtin_pointsprite.distanceQuadraticAttenuation, 1, 1, glstate->pointsprite.distance+2);
    }

    // set VertexAttrib if needed
    for(int i=0; i<hardext.maxvattrib; i++) 
    if(glprogram->va_size[i])   // only check used VA...
    {
        vertexattrib_t *v = &glstate->gleshard.vertexattrib[i];
        vertexattrib_t *w = &glstate->gleshard.wanted[i];
        int dirty = 0;
        // enable / disable Array if needed
        if(v->vaarray != w->vaarray) {
            dirty = 1;
            LOAD_GLES2(glEnableVertexAttribArray)
            LOAD_GLES2(glDisableVertexAttribArray);
            v->vaarray = w->vaarray;
            DBG(printf("VertexAttribArray[%d]:%s\n", i, (v->vaarray)?"Enable":"Disable");)
            if(v->vaarray)
                gles_glEnableVertexAttribArray(i);
            else
                gles_glDisableVertexAttribArray(i);
        }
        // check if new value has to be sent to hardware
        if(v->vaarray) {
            // array case
            if(dirty || v->size!=w->size || v->type!=w->type || v->normalized!=w->normalized 
                || v->stride!=w->stride || v->pointer!=w->pointer || v->buffer!=w->buffer) {
                v->size = w->size;
                v->type = w->type;
                v->normalized = w->normalized;
                v->stride = w->stride;
                v->pointer = w->pointer;
                v->buffer = w->buffer;
                LOAD_GLES2(glVertexAttribPointer);
                gles_glVertexAttribPointer(i, v->size, v->type, v->normalized, v->stride, (GLvoid*)((uintptr_t)v->pointer+((v->buffer)?(uintptr_t)v->buffer->data:0)));
                DBG(printf("glVertexAttribPointer(%d, %d, %s, %d, %d, %p)\n", i, v->size, PrintEnum(v->type), v->normalized, v->stride, (GLvoid*)((uintptr_t)v->pointer+((v->buffer)?(uintptr_t)v->buffer->data:0)));)
            }
        } else {
            // single value case
            if(dirty || memcmp(v->current, w->current, 4*sizeof(GLfloat))) {
                memcpy(v->current, w->current, 4*sizeof(GLfloat));
                LOAD_GLES2(glVertexAttrib4fv);
                gles_glVertexAttrib4fv(i, v->current);
                DBG(printf("glVertexAttrib4fv(%d, %p) => (%f, %f, %f, %f)\n", i, v->current, v->current[0], v->current[1], v->current[2], v->current[3]);)
            }
        }
    } else {
        // disable VAArray, to be on the safe side
        vertexattrib_t *v = &glstate->gleshard.vertexattrib[i];
        if(v->vaarray) {
            LOAD_GLES2(glDisableVertexAttribArray);
            v->vaarray = 0;
            DBG(printf("VertexAttribArray[%d]:%s\n", i, "Disable");)
            gles_glDisableVertexAttribArray(i);
        }
    }
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
            if(memcmp(v->current, glstate->color, 4*sizeof(GLfloat))) {
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
const char* normalrescale_code = "_gl4es_NormalScale";
const char* clipplanes_code = "_gl4es_ClipPlane[";
const char* point_code = "_gl4es_Point";
int builtin_CheckUniform(program_t *glprogram, char* name, GLint id) {
    int builtin = isBuiltinMatrix(name);
    // check matrices
    if(builtin!=-1) {
        glprogram->builtin_matrix[builtin] = id;
        glprogram->has_builtin_matrix = 1;
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
        glprogram->has_builtin_light = 1;
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
        glprogram->has_builtin_light = 1;
        return 1;
    }
    if(strncmp(name, frontlightmodelprod_code, strlen(frontlightmodelprod_code))==0 
    || strncmp(name, backlightmodelprod_code, strlen(backlightmodelprod_code))==0)
    {
        // it's a front light model product
        int n=(strncmp(name, frontlightmodelprod_code, strlen(frontlightmodelprod_code))==0)?0:1;
        if(strstr(name, ".sceneColor")) glprogram->builtin_lightmodelprod[n].sceneColor = id;
        glprogram->has_builtin_light = 1;
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
        glprogram->has_builtin_light = 1;
        return 1;
    }
    if(strncmp(name, normalrescale_code, strlen(normalrescale_code))==0)
    {
        glprogram->builtin_normalrescale = id;
        glprogram->has_builtin_matrix = 1;  // this is in the matrix block
        return 1;
    }
    if(strncmp(name, clipplanes_code, strlen(clipplanes_code))==0) {
        // it a clip plane! grab it's number
        int n = name[strlen(clipplanes_code)]-'0';   // only 6 clip planes, so this works
        glprogram->builtin_clipplanes[n] = id;
        glprogram->has_builtin_clipplanes = 1;
        return 1;
    }
    if(strncmp(name, point_code, strlen(point_code))==0)
    {
        // it's a Point parameter
        if(strstr(name, ".size")) glprogram->builtin_pointsprite.size = id;
        else if(strstr(name, ".sizeMin")) glprogram->builtin_pointsprite.sizeMin = id;
        else if(strstr(name, ".sizeMax")) glprogram->builtin_pointsprite.sizeMax = id;
        else if(strstr(name, ".fadeThresholdSize")) glprogram->builtin_pointsprite.fadeThresholdSize = id;
        else if(strstr(name, ".distanceConstantAttenuation")) glprogram->builtin_pointsprite.distanceConstantAttenuation = id;
        else if(strstr(name, ".distanceLinearAttenuation")) glprogram->builtin_pointsprite.distanceLinearAttenuation = id;
        else if(strstr(name, ".distanceQuadraticAttenuation")) glprogram->builtin_pointsprite.distanceQuadraticAttenuation = id;
        glprogram->has_builtin_pointsprite = 1;
        return 1;
    }

    return 0;
}

int builtin_CheckVertexAttrib(program_t *glprogram, char* name, GLint id) {
    int builtin = isBuiltinAttrib(name);
    if(builtin!=-1) {
        glprogram->builtin_attrib[builtin] = id;
        glprogram->has_builtin_attrib = 1;
        return 1;
    }
    return 0;
}
