// TODO: glIsEnabled(), glGetMap()

#include "eval.h"
#include "math/eval.h"

#define set_map_coords(n)         \
    map->n._1 = n##1;             \
    map->n._2 = n##2;             \
    map->n.d = 1.0/(n##2 - n##1); \
    map->n.stride = n##stride;    \
    map->n.order = n##order;

#define case_state(dims, magic, name, w)                  \
    case magic: {                                         \
        map->width = w;                                   \
        MapStateF *m = (MapStateF *)state.map##dims.name; \
        if (m) {                                          \
            if (m->free)                                  \
                free((void *)m->points);                  \
            free(m);                                      \
        }                                                 \
        state.map##dims.name = (MapState *)map;           \
        break;                                            \
    }

#define map_switch(dims)                                                \
    switch (target) {                                                   \
        case_state(dims, GL_MAP##dims##_COLOR_4, color4, 4);            \
        case_state(dims, GL_MAP##dims##_INDEX, index, 3);               \
        case_state(dims, GL_MAP##dims##_NORMAL, normal, 3);             \
        case_state(dims, GL_MAP##dims##_TEXTURE_COORD_1, texture1, 1);   \
        case_state(dims, GL_MAP##dims##_TEXTURE_COORD_2, texture2, 2);   \
        case_state(dims, GL_MAP##dims##_TEXTURE_COORD_3, texture3, 3);   \
        case_state(dims, GL_MAP##dims##_TEXTURE_COORD_4, texture4, 4);   \
        case_state(dims, GL_MAP##dims##_VERTEX_3, vertex3, 3);           \
        case_state(dims, GL_MAP##dims##_VERTEX_4, vertex4, 4);           \
    }                                                                   \
    map->points = points;

void glMap1d(GLenum target, GLdouble u1, GLdouble u2,
             GLint ustride, GLint uorder, const GLdouble *d_points) {
    MapStateF *map = malloc(sizeof(MapStateF));
    map->type = GL_FLOAT; map->dims = 1; map->free = true;
    set_map_coords(u);

    GLfloat *points = malloc(uorder * sizeof(GLfloat));
    for (int i = 0; i < uorder; i++) {
        points[i] = d_points[i];
    }
    map_switch(1);
}

void glMap1f(GLenum target, GLfloat u1, GLfloat u2,
             GLint ustride, GLint uorder, const GLfloat *points) {
    MapStateF *map = malloc(sizeof(MapStateF));
    map->type = GL_FLOAT; map->dims = 1;
    set_map_coords(u);
    map_switch(1);
}

void glMap2d(GLenum target, GLdouble u1, GLdouble u2,
             GLint ustride, GLint uorder, GLdouble v1, GLdouble v2,
             GLint vstride, GLint vorder, const GLdouble *d_points) {
    MapStateF *map = malloc(sizeof(MapStateF));
    map->type = GL_FLOAT; map->dims = 2;; map->free = true;
    set_map_coords(u);
    set_map_coords(v);
    GLfloat *points = malloc(uorder * vorder * sizeof(GLfloat));
    for (int i = 0; i < uorder * vorder; i++) {
        points[i] = d_points[i];
    }
    map_switch(2);
}

void glMap2f(GLenum target, GLfloat u1, GLfloat u2,
             GLint ustride, GLint uorder, GLfloat v1, GLfloat v2,
             GLint vstride, GLint vorder, const GLfloat *points) {
    MapStateF *map = malloc(sizeof(MapStateF));
    map->type = GL_FLOAT; map->dims = 2;
    set_map_coords(u);
    set_map_coords(v);
    map_switch(2);
}

#undef set_map_coords
#undef case_state
#undef map_switch

#define p_map(d, name, func, code) {             \
    MapState *_map = state.map##d.name;          \
    if (_map) {                                  \
        if (_map->type == GL_DOUBLE) {           \
            MapStateD *map = (MapStateD *)_map;  \
            printf("double: not implemented\n"); \
            /* code */                           \
        } else if (_map->type == GL_FLOAT) {     \
            MapStateF *map = (MapStateF *)_map;  \
            GLfloat out[4];                      \
            code                                 \
            func##v(out);                        \
        }                                        \
    }}

#define iter_maps(d, code)                  \
    p_map(d, color4, glColor4f, code);      \
    p_map(d, index, glIndexf, code);        \
    p_map(d, normal, glNormal3f, code);     \
    p_map(d, texture1, glTexCoord1f, code); \
    p_map(d, texture2, glTexCoord2f, code); \
    p_map(d, texture3, glTexCoord3f, code); \
    p_map(d, texture4, glTexCoord4f, code); \
    p_map(d, vertex3, glVertex3f, code);    \
    p_map(d, vertex4, glVertex4f, code);

void glEvalCoord1d(GLdouble u) {
    glEvalCoord1f(u);
}

void glEvalCoord1f(GLfloat u) {
    iter_maps(1,
        GLfloat uu = (u - map->u._1) * map->u.d;
        _math_horner_bezier_curve(map->points, out, uu, map->width, map->u.order);
    )
}

void glEvalCoord2d(GLdouble u, GLdouble v) {
    glEvalCoord2f(u, v);
}

void glEvalCoord2f(GLfloat u, GLfloat v) {
    iter_maps(2,
        GLfloat uu = (u - map->u._1) * map->u.d;
        GLfloat vv = (v - map->v._1) * map->v.d;
        // TODO: GL_AUTONORMAL

        _math_horner_bezier_surf((GLfloat *)map->points, out, uu, vv,
                                 map->width, map->u.order, map->v.order);
    )
}

#undef p_map
#undef iter_maps

void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    glMapGrid1f(un, u1, u2);
}

void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    // TODO: double support?
    MapStateF *map;
    if (! state.map_grid)
        state.map_grid = malloc(sizeof(MapStateF));

    map = (MapStateF *)state.map_grid;
    map->dims = 1;
    map->u.n = un;
    map->u._1 = u1;
    map->u._2 = u2;
}

void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2,
                 GLint vn, GLdouble v1, GLdouble v2) {
    glMapGrid2f(un, u1, u2, vn, v1, v2);
}

void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2,
                 GLint vn, GLfloat v1, GLfloat v2) {
    // TODO: double support?
    MapStateF *map;
    if (! state.map_grid)
        state.map_grid = malloc(sizeof(MapStateF));

    map = (MapStateF *)state.map_grid;
    map->dims = 2;
    map->u.n = un;
    map->u._1 = u1;
    map->u._2 = u2;
    map->v.n = vn;
    map->v._1 = v1;
    map->v._2 = v2;
}

static inline GLenum eval_mesh_prep(MapStateF **map, GLenum mode) {
    if (state.map2.vertex4) {
        *map = (MapStateF *)state.map2.vertex4;
    } else if (state.map2.vertex3) {
        *map = (MapStateF *)state.map2.vertex3;
    } else {
        return 0;
    }

    if ((*map)->type == GL_DOUBLE) {
        printf("libGL: GL_DOUBLE map not implemented\n");
        return 0;
    }

    switch (mode) {
        case GL_POINT: return GL_POINTS;
        case GL_LINE: return GL_LINE_STRIP;
        case GL_FILL: return GL_TRIANGLE_STRIP;
        case 0: return 1;
        default:
            printf("unknown glEvalMesh mode: %x\n", mode);
            return 0;
    }
}

void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    MapStateF *map;
    GLenum renderMode = eval_mesh_prep(&map, mode);
    if (! renderMode)
        return;

    GLfloat u, du, u1;
    du = map->u.d;
    GLint i;
    glBegin(renderMode);
    for (u = u1, i = i1; i <= i2; i++, u += du) {
        glEvalCoord1f(u);
    }
    glEnd();
}

void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    MapStateF *map;
    GLenum renderMode = eval_mesh_prep(&map, mode);
    if (! renderMode)
        return;

    GLfloat u, du, u1, v, dv, v1;
    du = map->u.d;
    dv = map->v.d;
    GLint i, j;
    glBegin(renderMode);
    for (v = v1, j = j1; j <= j2; j++, v += dv) {
        for (u = u1, i = i1; i <= i2; i++, u += du) {
            glEvalCoord2f(u, v);
            if (mode == GL_FILL)
                glEvalCoord2f(u, v + dv);
        }
    }
    glEnd();
    if (mode == GL_LINE) {
        glBegin(renderMode);
        for (u = u1, i = i1; i <= i2; i++, u += du) {
            for (v = v1, j = j1; j <= j2; j++, v += dv) {
                glEvalCoord2f(u, v);
            }
        }
        glEnd();
    }
}

void glEvalPoint1(GLint i) {
    MapStateF *map;
    if (eval_mesh_prep(&map, 0))
        glEvalCoord1f(i + map->u.d);
}

void glEvalPoint2(GLint i, GLint j) {
    MapStateF *map;
    if (eval_mesh_prep(&map, 0))
        glEvalCoord2f(i + map->u.d, j + map->v.d);
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
