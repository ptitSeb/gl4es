#include "texgen.h"

void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    // coord is in: GL_S, GL_T, GL_R, GL_Q
    // pname == GL_TEXTURE_GEN_MODE
    /* param is in:
        GL_OBJECT_LINEAR, GL_EYE_LINEAR,
        GL_SPHERE_MAP, GL_NORMAL_MAP, or GL_REFLECTION_MAP
    */
    switch (coord) {
        case GL_S: state.texgen[state.texture.active].S = param; break;
        case GL_T: state.texgen[state.texture.active].T = param; break;
    }
}

void glTexGenfv(GLenum coord, GLenum pname, GLfloat *param) {
    // pname is in: GL_TEXTURE_GEN_MODE, GL_OBJECT_PLANE, GL_EYE_PLANE

    if (pname == GL_TEXTURE_GEN_MODE) {
        switch (coord) {
            case GL_S: state.texgen[state.texture.active].S = *param; break;
            case GL_T: state.texgen[state.texture.active].T = *param; break;
        }
    } else {
        switch (coord) {
            case GL_S:
                memcpy(state.texgen[state.texture.active].Sv, param, 4 * sizeof(GLfloat));
                break;
            case GL_T:
                memcpy(state.texgen[state.texture.active].Tv, param, 4 * sizeof(GLfloat));
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
void glGetTexGenfv(GLenum coord,GLenum pname,GLfloat *params) {
	switch(pname) {
		case GL_TEXTURE_GEN_MODE:
			switch (coord) {
				case GL_S: *params = state.texgen[state.texture.active].S; break;
				case GL_T: *params = state.texgen[state.texture.active].T; break;
				default: *params = GL_EYE_LINEAR;
			}
			break;
		case GL_OBJECT_PLANE:
		case GL_EYE_PLANE:	// probably wrong...
			switch (coord) {
				case GL_S:
				memcpy(params, state.texgen[state.texture.active].Sv, 4 * sizeof(GLfloat));
				break;
				case GL_T:
				memcpy(params, state.texgen[state.texture.active].Tv, 4 * sizeof(GLfloat));
				break;
			}
		break;
	}
}


GLfloat dot(const GLfloat *a, const GLfloat *b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

GLfloat gen_tex_coord(GLfloat *vert, GLenum type, GLfloat *params) {
    switch (type) {
        case GL_OBJECT_LINEAR:
        case GL_SPHERE_MAP:
            return dot(vert, params);
            break;
    }
    return 0;
}

void dot_loop(const GLfloat *verts, const GLfloat *params, GLfloat *out, GLint count) {
#ifdef __ARM_NEON__
    float32x2_t acc;
    float32x2x3_t vert;
    float32x2x3_t param = vld3_f32((const float32_t *)params);
    for (; count != 0; count -= 1) {
        vert = vld3_f32((const float32_t *)verts);
        acc = vmul_f32(vert.val[0], param.val[0]);
        acc = vmla_f32(acc, vert.val[1], param.val[1]);
        acc = vmla_f32(acc, vert.val[2], param.val[2]);
        acc = vadd_f32(acc, param.val[3]);
        vst1_f32((float32_t *)out, acc);

        out += 2;
        verts += 3;
    }
#else
    for (int i = 0; i < count; i++) {
        out[0] = dot(verts, params) + params[3];
        out += 2;
        verts += 3;
    }
#endif
}

static inline void tex_coord_loop(GLfloat *verts, GLfloat *out, GLint count, GLenum type, GLfloat *params) {
    switch (type) {
        case GL_OBJECT_LINEAR:
        case GL_SPHERE_MAP:
            dot_loop(verts, params, out, count);
    }
}

void gen_tex_coords(GLfloat *verts, GLfloat **coords, GLint count, int texture) {
    // TODO: do less work when called from glDrawElements?

    *coords = (GLfloat *)malloc(count * 2 * sizeof(GLfloat));
    if (state.enable.texgen_s[texture])
        tex_coord_loop(verts, *coords, count, state.texgen[texture].S, state.texgen[texture].Sv);
    if (state.enable.texgen_t[texture])
        tex_coord_loop(verts, *coords+1, count, state.texgen[texture].T, state.texgen[texture].Tv);

    int i;
    for (i = 0; i < count; i++) {
        GLfloat *tex = &(*coords)[i];
        if (state.enable.texgen_s[texture])
            tex[0] = gen_tex_coord(&verts[i], state.texgen[texture].S, state.texgen[texture].Sv);

        if (state.enable.texgen_t[texture])
            tex[1] = gen_tex_coord(&verts[i], state.texgen[texture].T, state.texgen[texture].Tv);
    }
}
