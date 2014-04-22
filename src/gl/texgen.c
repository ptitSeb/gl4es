#include "texgen.h"

void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    // coord is in: GL_S, GL_T, GL_R, GL_Q
    // pname == GL_TEXTURE_GEN_MODE
    /* param is in:
        GL_OBJECT_LINEAR, GL_EYE_LINEAR,
        GL_SPHERE_MAP, GL_NORMAL_MAP, or GL_REFLECTION_MAP
    */
    /*
    switch (coord) {
        case GL_S: state.texgen[state.texture.active].S = param; break;
        case GL_T: state.texgen[state.texture.active].T = param; break;
    }
    */
    GLfloat params[4] = {0,0,0,0};
    params[0]=param;
    glTexGenfv(coord, pname, params);
}

void glTexGenfv(GLenum coord, GLenum pname, GLfloat *param) {

    if (state.list.compiling && state.list.active) {
		rlTexGenfv(state.list.active, coord, pname, param);
		return;
	}

    // pname is in: GL_TEXTURE_GEN_MODE, GL_OBJECT_PLANE, GL_EYE_PLANE
    if (pname == GL_TEXTURE_GEN_MODE) {
        switch (coord) {
            case GL_S: state.texgen[state.texture.active].S = param[0]; break;
            case GL_T: state.texgen[state.texture.active].T = param[0]; break;
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
		case GL_SPHERE_MAP:
		case GL_REFLECTION_MAP:
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

void matrix_vector(const GLfloat *a, const GLfloat *b, GLfloat *c) {
    c[0] = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3];
    c[1] = a[4] * b[0] + a[5] * b[1] + a[6] * b[2] + a[7];
    c[2] = a[8] * b[0] + a[9] * b[1] + a[10] * b[2] + a[11];
}

void vector_matrix(const GLfloat *a, const GLfloat *b, GLfloat *c) {
    c[0] = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + b[12];
    c[1] = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + b[13];
    c[2] = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + b[14];
}

void vector_normalize(GLfloat *a) {
    float det=1.0f/sqrtf(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
    a[0]*=det;
    a[1]*=det;
    a[2]*=det;
}

void matrix_inverse(const GLfloat *m, GLfloat *r) {

    r[0] = m[5]*m[10]*m[15] - m[5]*m[14]*m[11] - m[6]*m[9]*m[15] + m[6]*m[13]*m[11] + m[7]*m[9]*m[14] - m[7]*m[13]*m[10];
    r[1] = -m[1]*m[10]*m[15] + m[1]*m[14]*m[11] + m[2]*m[9]*m[15] - m[2]*m[13]*m[11] - m[3]*m[9]*m[14] + m[3]*m[13]*m[10];
    r[2] = m[1]*m[6]*m[15] - m[1]*m[14]*m[7] - m[2]*m[5]*m[15] + m[2]*m[13]*m[7] + m[3]*m[5]*m[14] - m[3]*m[13]*m[6];
    r[3] = -m[1]*m[6]*m[11] + m[1]*m[10]*m[7] + m[2]*m[5]*m[11] - m[2]*m[9]*m[7] - m[3]*m[5]*m[10] + m[3]*m[9]*m[6];

    r[4] = -m[4]*m[10]*m[15] + m[4]*m[14]*m[11] + m[6]*m[8]*m[15] - m[6]*m[12]*m[11] - m[7]*m[8]*m[14] + m[7]*m[12]*m[10];
    r[5] = m[0]*m[10]*m[15] - m[0]*m[14]*m[11] - m[2]*m[8]*m[15] + m[2]*m[12]*m[11] + m[3]*m[8]*m[14] - m[3]*m[12]*m[10];
    r[6] = -m[0]*m[6]*m[15] + m[0]*m[14]*m[7] + m[2]*m[4]*m[15] - m[2]*m[12]*m[7] - m[3]*m[4]*m[14] + m[3]*m[12]*m[6];
    r[7] = m[0]*m[6]*m[11] - m[0]*m[10]*m[7] - m[2]*m[4]*m[11] + m[2]*m[8]*m[7] + m[3]*m[4]*m[10] - m[3]*m[8]*m[6];

    r[8] = m[4]*m[9]*m[15] - m[4]*m[13]*m[11] - m[5]*m[8]*m[15] + m[5]*m[12]*m[11] + m[7]*m[8]*m[13] - m[7]*m[12]*m[9];
    r[9] = -m[0]*m[9]*m[15] + m[0]*m[13]*m[11] + m[1]*m[8]*m[15] - m[1]*m[12]*m[11] - m[3]*m[8]*m[13] + m[3]*m[12]*m[9];
    r[10] = m[0]*m[5]*m[15] - m[0]*m[13]*m[7] - m[1]*m[4]*m[15] + m[1]*m[12]*m[7] + m[3]*m[4]*m[13] - m[3]*m[12]*m[5];
    r[11] = -m[0]*m[5]*m[11] + m[0]*m[9]*m[7] + m[1]*m[4]*m[11] - m[1]*m[8]*m[7] - m[3]*m[4]*m[9] + m[3]*m[8]*m[5];

    r[12] = -m[4]*m[9]*m[14] + m[4]*m[13]*m[10] + m[5]*m[8]*m[14] - m[5]*m[12]*m[10] - m[6]*m[8]*m[13] + m[6]*m[12]*m[9];
    r[13] = m[0]*m[9]*m[14] - m[0]*m[13]*m[10] - m[1]*m[8]*m[14] + m[1]*m[12]*m[10] + m[2]*m[8]*m[13] - m[2]*m[12]*m[9];
    r[14] = -m[0]*m[5]*m[14] + m[0]*m[13]*m[6] + m[1]*m[4]*m[14] - m[1]*m[12]*m[6] - m[2]*m[4]*m[13] + m[2]*m[12]*m[5];
    r[15] = m[0]*m[5]*m[10] - m[0]*m[9]*m[6] - m[1]*m[4]*m[10] + m[1]*m[8]*m[6] + m[2]*m[4]*m[9] - m[2]*m[8]*m[5];

    GLfloat det = m[0]*r[0] + m[1]*r[4] + m[2]*r[8] + m[3]*r[12];
    for (int i = 0; i < 16; i++) r[i] /= det;
}

void dot_loop(const GLfloat *verts, const GLfloat *params, GLfloat *out, GLint count) {
#ifdef __ARM_NEON__0
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

void sphere_loop(const GLfloat *verts, const GLfloat *norm, GLfloat *out, GLint count) {
    // based on https://www.opengl.org/wiki/Mathematics_of_glTexGen
    if (!norm) {
        printf("LIBGL: GL_SPHERE_MAP without Normals");
        return;
    }
    // First get the ModelviewMatrix
    GLfloat ModelviewMatrix[16], InvModelview[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, InvModelview);
    // column major -> row major
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            ModelviewMatrix[i*4+j]=InvModelview[i+j*4];
    // And get the inverse
    matrix_inverse(ModelviewMatrix, InvModelview);
    GLfloat eye[3], eye_norm[3], reflect[3];
    GLfloat a;
    for (int i=0; i<count; i++) {
        matrix_vector(ModelviewMatrix, verts+i*3, eye);
        vector_normalize(eye);
        vector_matrix(norm+i*3, InvModelview, eye_norm);
        vector_normalize(eye_norm);
        a=dot(eye, eye_norm)*2.0f;
        for (int i=0; i<3; i++)
            reflect[i]=eye[i]-eye_norm[i]*a;
        reflect[2]+=1.0f;
        a = 1.0f / (2.0f*sqrtf(dot(reflect, reflect)));
        out[i*2+0] = reflect[0]*a + 0.5f;
        out[i*2+1] = reflect[1]*a + 0.5f;
    }

}

void eye_loop(const GLfloat *verts, const GLfloat *param, GLfloat *out, GLint count) {
    // based on https://www.opengl.org/wiki/Mathematics_of_glTexGen
    // First get the ModelviewMatrix
    GLfloat ModelviewMatrix[16], InvModelview[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, InvModelview);
    // column major -> row major
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            ModelviewMatrix[i*4+j]=InvModelview[i+j*4];
    // And get the inverse
    matrix_inverse(ModelviewMatrix, InvModelview);
    GLfloat plane[3], tmp[3];
    vector_matrix(param, InvModelview, plane);
    for (int i=0; i<count; i++) {
        matrix_vector(ModelviewMatrix, verts+i*3, tmp);
        out[i*2]=dot(plane, tmp);
    }

}

static inline void tex_coord_loop(GLfloat *verts, GLfloat *norm, GLfloat *out, GLint count, GLenum type, GLfloat *params) {
    switch (type) {
        case GL_OBJECT_LINEAR:
            dot_loop(verts, params, out, count);
            break;
        case GL_EYE_LINEAR:
            eye_loop(verts, params, out, count);
            break;
        case GL_SPHERE_MAP:
            //printf("LIBGL: GL_SPHERE_MAP with only 1 TexGen available");  //Broken here
            break;
    }
}

void gen_tex_coords(GLfloat *verts, GLfloat *norm, GLfloat **coords, GLint count, int texture) {
    // TODO: do less work when called from glDrawElements?
    if ((*coords)==NULL) *coords = (GLfloat *)malloc(count * 2 * sizeof(GLfloat));
    // special case: SPHERE_MAP needs both texgen to make sense
    if ((state.enable.texgen_s[texture] && (state.texgen[texture].S==GL_SPHERE_MAP)) && (state.enable.texgen_t[texture] && (state.texgen[texture].T==GL_SPHERE_MAP)))
    {
        sphere_loop(verts, norm, *coords, count);
        return;
    }
    if (state.enable.texgen_s[texture])
        tex_coord_loop(verts, norm, *coords, count, state.texgen[texture].S, state.texgen[texture].Sv);
    if (state.enable.texgen_t[texture])
        tex_coord_loop(verts, norm, *coords+1, count, state.texgen[texture].T, state.texgen[texture].Tv);
}
