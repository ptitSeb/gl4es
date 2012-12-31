#include <gl.h>
#include <math.h>

RenderList *activeList = NULL;
GLfloat lastColor[4] = {1.0f, 1.0f, 1.0f, 1.0f};
bool inDisplayList = false;

bool bTexGenS;
GLenum texGenS;
GLfloat texGenSv[4];

bool bTexGenT;
GLenum texGenT;
GLfloat texGenTv[4];

bool bLineStipple = false;
GLint stippleFactor = 1;
GLushort stipplePattern = 0xFFFF;

GLuint listBase = 0;

bool bBlend;
bool bTexture2d;

// config functions

void glwEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    switch (cap) {
        /*
        case GL_TEXTURE_GEN_S: bTexGenS = enable; break;
        case GL_TEXTURE_GEN_T: bTexGenT = enable; break;
        */
        case GL_BLEND: bBlend = enable; next(cap); break;
        case GL_TEXTURE_2D: bTexture2d = enable; next(cap); break;
        case GL_LINE_STIPPLE: bLineStipple = enable; break;
        default: next(cap); break;
    }
}

void glEnable(GLenum cap) {
    LOAD_GLES(void, glEnable, GLenum);
    glwEnable(cap, true, gles_glEnable);
}

void glDisable(GLenum cap) {
    LOAD_GLES(void, glDisable, GLenum);
    glwEnable(cap, false, gles_glDisable);
}

// texture generation

void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    // coord is in: GL_S, GL_T, GL_R, GL_Q
    // pname == GL_TEXTURE_GEN_MODE
    /* param is in:
        GL_OBJECT_LINEAR, GL_EYE_LINEAR,
        GL_SPHERE_MAP, GL_NORMAL_MAP, or GL_REFLECTION_MAP
    */
    switch (coord) {
        case GL_S: texGenS = param; break;
        case GL_T: texGenT = param; break;
    }
}

void glTexGenfv(GLenum coord, GLenum pname, GLfloat *param) {
    return;
    // pname is in: GL_TEXTURE_GEN_MODE, GL_OBJECT_PLANE, GL_EYE_PLANE

    if (pname == GL_TEXTURE_GEN_MODE) {
        switch (coord) {
            case GL_S: texGenS = *param; break;
            case GL_T: texGenT = *param; break;
        }
    } else {
        switch (coord) {
            case GL_S:
                // texGenS = pname;
                memcpy(texGenSv, param, 4 * sizeof(GLfloat));
                break;
            case GL_T:
                // texGenT = pname;
                memcpy(texGenTv, param, 4 * sizeof(GLfloat));
                break;
        }
    }

    /*
    If pname is GL_TEXTURE_GEN_MODE, then the array must contain
    a single symbolic constant, one of
    GL_OBJECT_LINEAR, GL_EYE_LINEAR, GL_SPHERE_MAP, GL_NORMAL_MAP,
    or GL_REFLECTION_MAP.
    Otherwise, params holds the coefficients for the texture-coordinate
    generation function specified by pname.
    */
}

// TODO: put these in a lib
GLfloat dot(GLfloat *a, GLfloat *b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]+b[2] + a[3]+b[3];
}

GLfloat genTexCoord(GLfloat *vert, GLenum type, GLfloat *params) {
    switch (type) {
        case GL_OBJECT_LINEAR:
        case GL_SPHERE_MAP:
            return dot(vert, params);
            break;
    }
    return 0;
}

void genTexCoords(GLfloat *verts, GLfloat *coords, GLint count) {
    return;
    int i;
    for (i = 0; i < count; i++) {
        GLfloat *tex = &coords[i];
        if (bTexGenS) tex[0] = genTexCoord(&verts[i], texGenS, texGenSv);
        if (bTexGenT) tex[1] = genTexCoord(&verts[i], texGenT, texGenTv);
    }
}

// misc functions

void glLineStipple(GLuint factor, GLushort pattern) {
    stippleFactor = factor;
    stipplePattern = pattern;
}

// immediate mode functions

void glBegin(GLenum mode) {
    if (! inDisplayList) {
        activeList = allocRenderList();
    }
    memcpy(activeList->lastColor, lastColor, sizeof(GLfloat) * 4);
    activeList->mode = mode;
}

void glEnd() {
    // render if we're not in a display list
    if (! activeList) return;

    endRenderList(activeList);
    if (! inDisplayList) {
        drawRenderList(activeList);
        freeRenderList(activeList);
        activeList = NULL;
    } else {
        activeList = extendRenderList(activeList);
    }
}

void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    if (activeList) {
        lVertex3f(activeList, x, y, z);
    }
}

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (activeList) {
        lColor4f(activeList, r, g, b, a);
    } else {
        LOAD_GLES(void, glColor4f, GLfloat, GLfloat, GLfloat, GLfloat);
        gles_glColor4f(r, g, b, a);
        lastColor[0] = r; lastColor[1] = g;
        lastColor[2] = b; lastColor[3] = a;
    }
}

void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    LOAD_GLES(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat *params);
    if (activeList) {
        lMaterialfv(activeList, face, pname, params);
    } else {
        gles_glMaterialfv(face, pname, params);
    }
}

void glTexCoord2f(GLfloat s, GLfloat t) {
    if (activeList) {
        lTexCoord2f(activeList, s, t);
    }
}

// display lists
glwList **displayLists = NULL;
int listCount = 0;
int listCap = 0;

GLuint glGenLists(GLsizei range) {
    int start = listCount;
    if (displayLists == NULL) {
        listCap += range + 100;
        displayLists = (glwList **)malloc(listCap * sizeof(glwList *));
    } else if (listCount + range > listCap) {
        listCap += range + 100;
        displayLists = (glwList **)realloc(displayLists, listCap * sizeof(glwList *));
    }
    listCount += range;

    int i;
    glwList *lists = (glwList *)malloc(range * sizeof(glwList));
    for (i = 0; i < range; i++) {
        glwList list = {i, range, 0, 0, NULL};
        memcpy(lists+i, &list, sizeof(glwList));
        displayLists[start+i] = lists + i;
    }

    return start;
}

void glNewList(GLuint list) {
    if (list >= listCount) return;

    glwList *l = displayLists[list];
    if (l->created) return;

    // TODO: if activeList is defined, we probably need to clean up here
    l->created = true;
    inDisplayList = true;
    activeList = l->list = allocRenderList();
}

void glEndList(GLuint list) {
    if (inDisplayList) {
        inDisplayList = false;
        activeList = NULL;
    }
}

void glCallList(GLuint list) {
    if (list >= listCount) return;

    glwList *l = displayLists[list];
    if (l->created)
        drawRenderList(l->list);
}

void glCallLists(GLsizei n, GLenum type, const GLvoid *lists) {
    #define call(name, type)\
        case name: glCallList(*(((type *)lists + i) + listBase)); break

    // seriously wtf
    #define call_bytes(name, stride)\
        case name:\
            l = (GLubyte *)lists;\
            list = 0;\
            for (j = 0; j < stride; j++) {\
                list += *(l + (i * stride + j)) << (stride - j);\
            }\
            glCallList(list + listBase);\
            break

    unsigned int i, j;
    GLuint list;
    GLubyte *l;
    for (i = 0; i < n; i++) {
        switch (type) {
            call(GL_BYTE, GLbyte);
            call(GL_UNSIGNED_BYTE, GLubyte);
            call(GL_SHORT, GLshort);
            call(GL_UNSIGNED_SHORT, GLushort);
            call(GL_INT, GLint);
            call(GL_UNSIGNED_INT, GLuint);
            call(GL_FLOAT, GLfloat);
            call_bytes(GL_2_BYTES, 2);
            call_bytes(GL_3_BYTES, 3);
            call_bytes(GL_4_BYTES, 4);
        }
    }
    #undef call
    #undef call_bytes
}

void glDeleteList(GLuint list) {
    if (list >= listCount) return;

    glwList *l = displayLists[list];
    l->free = true;
    if (l->created) {
        freeRenderList(l->list);
        l->created = false;
    }

    // lists just grow upwards, maybe use a better storage mechanism?
}

void glDeleteLists(GLuint list, GLsizei range) {
    int i;
    for (i = 0; i < range; i++) {
        glDeleteList(list+i);
    }
}

void glListBase(GLuint base) {
    listBase = base;
}

GLboolean glIsList(GLuint list) {
    if (list < listCount) {
        glwList *l = displayLists[list];
        if (l->created)
            return true;
    }
    return false;
}
