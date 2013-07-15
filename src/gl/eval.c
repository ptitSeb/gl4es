// TODO: glIsEnabled(), glGetMap()

#include "eval.h"

#define set_map_coords(name)        \
    map.name._1 = name##1;          \
    map.name._2 = name##2;          \
    map.name.stride = name##stride; \
    map.name.order = name##order;

#define case_state(magic, name, w)         \
    case magic:                            \
        map.width = w;                     \
        state.map.name = (MapState *)&map; \
        break;

#define map_switch(dims)                                          \
    switch (target) {                                             \
        case_state(GL_MAP##dims##_COLOR_4, color, 4);             \
        case_state(GL_MAP##dims##_INDEX, index, 0);               \
        case_state(GL_MAP##dims##_NORMAL, normal, 0);             \
        case_state(GL_MAP##dims##_TEXTURE_COORD_1, tex_coord, 1); \
        case_state(GL_MAP##dims##_TEXTURE_COORD_2, tex_coord, 2); \
        case_state(GL_MAP##dims##_TEXTURE_COORD_3, tex_coord, 3); \
        case_state(GL_MAP##dims##_TEXTURE_COORD_4, tex_coord, 4); \
        case_state(GL_MAP##dims##_VERTEX_3, vertex, 3);           \
        case_state(GL_MAP##dims##_VERTEX_4, vertex, 4);           \
    }                                                             \
    map.points = points;

void glMap1d(GLenum target, GLdouble u1, GLdouble u2,
             GLint ustride, GLint uorder, const GLdouble *points) {
    static MapStateD map = {.type = GL_DOUBLE, .dims = 1};
    set_map_coords(u);
    map_switch(1);
}

void glMap1f(GLenum target, GLfloat u1, GLfloat u2,
             GLint ustride, GLint uorder, const GLfloat *points) {
    static MapStateF map = {.type = GL_FLOAT, .dims = 1};
    set_map_coords(u);
    map_switch(1);
}

void glMap2d(GLenum target, GLdouble u1, GLdouble u2,
             GLint ustride, GLint uorder, GLdouble v1, GLdouble v2,
             GLint vstride, GLint vorder, const GLdouble *points) {
    static MapStateD map = {.type = GL_DOUBLE, .dims = 2};
    set_map_coords(u);
    set_map_coords(v);
    map_switch(2);
}

void glMap2f(GLenum target, GLfloat u1, GLfloat u2,
             GLint ustride, GLint uorder, GLfloat v1, GLfloat v2,
             GLint vstride, GLint vorder, const GLfloat *points) {
    static MapStateF map = {.type = GL_DOUBLE, .dims = 2};
    set_map_coords(u);
    set_map_coords(v);
    map_switch(2);
}

#undef set_map_coords
#undef case_state
#undef map_switch

void glEvalCoord1d(GLdouble u) {
    if (state.map.vertex) {
        // yeah!
    }
}

void glEvalCoord1f(GLfloat u) {

}

void glEvalCoord2d(GLdouble u, GLdouble v) {

}

void glEvalCoord2f(GLfloat u, GLfloat v) {

}

/*
glEvalCoord
glEvalCoord1d
glEvalCoord1f
glEvalCoord2d
glEvalCoord2f
glEvalCoord1dv
glEvalCoord1fv
glEvalCoord2dv
glEvalCoord2fv

glMap1, glMap1d, glMap1f
glMap2, glMap2d, glMap2f
glMapGrid, glMapGrid1d, glMapGrid1f, glMapGrid2d, glMapGrid2f
glEvalMesh, glEvalMesh2
glEvalPoint, glEvalPoint1, glEvalPoint2

GL_MAP1_VERTEX_3
GL_MAP1_VERTEX_4
GL_MAP1_INDEX
GL_MAP1_COLOR_4
GL_MAP1_NORMAL
GL_MAP1_TEXTURE_COORD_1
GL_MAP1_TEXTURE_COORD_2
GL_MAP1_TEXTURE_COORD_3
GL_MAP1_TEXTURE_COORD_4
GL_MAP2_VERTEX_3
GL_MAP2_VERTEX_4
GL_MAP2_INDEX
GL_MAP2_COLOR_4
GL_MAP2_NORMAL
GL_MAP2_TEXTURE_COORD_1
GL_MAP2_TEXTURE_COORD_2
GL_MAP2_TEXTURE_COORD_3
GL_MAP2_TEXTURE_COORD_4
GL_AUTO_NORMAL
*/
