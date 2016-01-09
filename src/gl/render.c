#include "render.h"

void push_hit() {
    // push current hit to hit list, and re-init current hit
    if (glstate.selectbuf.hit) {
        if (!glstate.selectbuf.overflow) {
            if (glstate.selectbuf.zmin<0.0f) glstate.selectbuf.zmin=0.0f;   // not really normalized...
            if (glstate.selectbuf.zmax>1.0f) glstate.selectbuf.zmax=1.0f;   // TODO, normalize for good?
            int tocopy = glstate.namestack.top + 3;
            if (tocopy+glstate.selectbuf.pos > glstate.selectbuf.size) {
                glstate.selectbuf.overflow = 1;
                tocopy = glstate.selectbuf.size - glstate.selectbuf.pos;
            }
            if(tocopy>0)
                glstate.selectbuf.buffer[glstate.selectbuf.pos+0] = glstate.namestack.top;
            if(tocopy>1)
                glstate.selectbuf.buffer[glstate.selectbuf.pos+1] = (unsigned int)(glstate.selectbuf.zmin * INT_MAX );
            if(tocopy>2)
                glstate.selectbuf.buffer[glstate.selectbuf.pos+2] = (unsigned int)(glstate.selectbuf.zmax * INT_MAX );
            if(tocopy>3)
                memcpy(glstate.selectbuf.buffer + glstate.selectbuf.pos + 3, glstate.namestack.names, (tocopy-3) * sizeof(GLuint));

            glstate.selectbuf.count++;
            glstate.selectbuf.pos += tocopy;
        }
        glstate.selectbuf.hit = 0;
    }
    glstate.selectbuf.zmin = 1.0f;
    glstate.selectbuf.zmax = 0.0f;
}


GLint glshim_glRenderMode(GLenum mode) {
	int ret = 0;
    if ((mode==GL_SELECT) || (mode==GL_RENDER)) {  // missing GL_FEEDBACK
        noerrorShim();
    } else {
        errorShim(GL_INVALID_ENUM);
        return 0;
    }
	if (glstate.render_mode == GL_SELECT) {
        push_hit();
		ret = glstate.selectbuf.count;
    }
	if (mode == GL_SELECT) {
		if (glstate.selectbuf.buffer == NULL)	{// error, cannot use Select Mode without select buffer
            errorShim(GL_INVALID_OPERATION);
			return 0;
        }
		glstate.selectbuf.count = 0;
        glstate.selectbuf.pos = 0;
        glstate.selectbuf.overflow = 0;
        glstate.selectbuf.zmin = 1.0f;
        glstate.selectbuf.zmax = 0.0f;
        glstate.selectbuf.hit = 0;
	}
    
    if((mode==GL_SELECT) && (glstate.gl_batch)) {
        glstate.gl_batch = 0;
        flush();
    }
    if((mode==GL_RENDER) && (glstate.gl_batch==0) && (gl_batch==1)) {
        glstate.gl_batch = 1;
        flush();
    }
    
	glstate.render_mode = mode;
	return ret;
}

void glshim_glInitNames() {
	if (glstate.namestack.names == 0) {
		glstate.namestack.names = (GLuint*)malloc(1024*sizeof(GLuint));
	}
	glstate.namestack.top = 0;
    noerrorShim();
}

void glshim_glPopName() {
    noerrorShim();
	if (glstate.render_mode != GL_SELECT)
		return;
    push_hit();
	if (glstate.namestack.top>0)
		glstate.namestack.top--;
    else
        errorShim(GL_STACK_UNDERFLOW);
}

void glshim_glPushName(GLuint name) {
    noerrorShim();
	if (glstate.render_mode != GL_SELECT)
		return;
	if (glstate.namestack.names==0)
		return;
    push_hit();
	if (glstate.namestack.top < 1024) {
		glstate.namestack.names[glstate.namestack.top++] = name;
	}
}

void glshim_glLoadName(GLuint name) {
    noerrorShim();
	if (glstate.render_mode != GL_SELECT)
		return;
	if (glstate.namestack.names == 0)
		return;
    push_hit();
    if (glstate.namestack.top == 0)
        return;
	glstate.namestack.names[glstate.namestack.top-1] = name;
}

void glshim_glSelectBuffer(GLsizei size, GLuint *buffer) {
    noerrorShim();
	glstate.selectbuf.buffer = buffer;
	glstate.selectbuf.size = size;
}

GLfloat projection[16], modelview[16];
void init_select() {
	/*
	 Initialize matrix and array vector for a select_Draw*
	*/
	 GLfloat tmp[16];
	 glshim_glGetFloatv(GL_PROJECTION_MATRIX, tmp);
	 matrix_column_row(tmp, projection);
	 glshim_glGetFloatv(GL_MODELVIEW_MATRIX, tmp);
	 matrix_column_row(tmp, modelview);
}

void select_transform(GLfloat *a) {
	/*
	 Transform a[3] using projection and modelview matrix (init with init_select)
	*/
	GLfloat tmp[3];
	matrix_vector(modelview, a, tmp);
	matrix_vector(projection, tmp, a);
    //matrix_vector(model_proj, a, a);
}

GLboolean select_point_in_viewscreen(const GLfloat *a) {
	/* 
	 Return True is point is inside the Viewport
	*/
    if (a[0]>-1.0 && a[0]<1.0 && a[1]>-1.0 && a[1]<1.0) {
	 return true;
    }
    return false;

}

GLboolean select_segment_in_viewscreen(const GLfloat *a, const GLfloat *b) {
	/*
	 Return True is the segment is fully inside viewscreen
	 or cross the viewscreen
	 Viewscreen is  (-1,-1)(+1,+1) 
	 False if completly outside
	*/
	// Fast either point inside viewport
	if (select_point_in_viewscreen(a)) return true;
	if (select_point_in_viewscreen(b)) return true;
	// Using Liang-Barsky algorithm
	GLfloat vx, vy;
	vx=b[0]-a[0];
	vy=b[1]-a[1];
	GLfloat p[4] = {-vx, vx, -vy, vy};
	GLfloat q[4] = {a[0] + 1.0f, +1.0f - a[0], a[1] + 1.0f, +1.0f - a[1]};
	GLfloat u1 = 0.0f;
	GLfloat u2 = 1.0f;

	for (int i=0; i<4; i++) {
		if (p[i] == 0.0f) {
			if (q[i]<0.0f)
				return false;
		} else {
			GLfloat t =q[i] / p[i];
			if (p[i]<0.0) { 
                if(t>u2) return false;
                else if(u1<t)
                    u1 = t;
            }
			else if (p[i]>0.0) {
                if(t<u1) return false;
                else if (u2>t)
                    u2 = t;
            }
		}
	}
	return true;
}

GLboolean select_triangle_in_viewscreen(const GLfloat *a, const GLfloat *b, const GLfloat *c) {
	/*
	 Return True is the triangle is in the viewscreen, or completly include, or include the viewscreen
	*/
	 // Check if any segment intersect the viewscreen (include test if any point is inside the viewscreen)
	 if (select_segment_in_viewscreen(a, b)) return true;
	 if (select_segment_in_viewscreen(b, c)) return true;
	 if (select_segment_in_viewscreen(c, a)) return true;

	 // Now check if the viewscreen is completly inside the triangle
	 #define sign(p1, p2, p3) (p1[0]-p3[0])*(p2[1]-p3[1])-(p2[0]-p3[0])*(p1[1]-p3[1])
	 for (int i=0; i<4; i++) {
	 	GLboolean b1,b2,b3;
	 	GLfloat pt[2];
	 	pt[0] = (i%2)?-1.0f:+1.0f;
	 	pt[1] = (i>2)?-1.0f:+1.0f;
	 	b1 = (sign(pt, a, b))<0.0f;
	 	b2 = (sign(pt, b, c))<0.0f;
	 	b3 = (sign(pt, c, a))<0.0f;
	 	if ((b1==b2) && (b2==b3)) {
	 		return true;
	 	}
	 }
	 #undef sign

	 return false;
}

void select_glDrawArrays(const pointer_state_t* vtx, GLenum mode, GLuint first, GLuint count) {
	if (count == 0) return;
	if (vtx->pointer == NULL) return;
	if (glstate.selectbuf.buffer == NULL) return;
	GLfloat *vert = copy_gl_array(vtx->pointer, vtx->type, 
			vtx->size, vtx->stride,
			GL_FLOAT, 3, 0, count+first);
	GLfloat tmp[3];
	GLfloat zmin=1.0f, zmax=0.0f;
	init_select();

	#define FOUND()	{ 		\
		if (zmin<glstate.selectbuf.zmin) 	glstate.selectbuf.zmin=zmin;	\
		if (zmax>glstate.selectbuf.zmax) 	glstate.selectbuf.zmax=zmax;	\
		glstate.selectbuf.hit = 1;                        \
        free(vert);         \
        return;                                         \
		}
    // transform the points
	for (int i=first; i<count+first; i++) {
		select_transform(vert+i*3);
		if (vert[i*3+2]<zmin) zmin=vert[i*3+2];
		if (vert[i*3+2]>zmax) zmax=vert[i*3+2];
    }
    // intersect with screen now
    GLfloat *vert2 = vert + first*3;
	for (int i=0; i<count; i++) {
		switch (mode) {
			case GL_POINTS:
				if (select_point_in_viewscreen(vert2+i*3))
					FOUND();
				break;
			case GL_LINES:
				if (i%2==1) {
					if (select_segment_in_viewscreen(vert2+(i-1)*3, vert2+i*3))
						FOUND();
				}
				break;
			case GL_LINE_STRIP:
			case GL_LINE_LOOP:		//FIXME: the last "loop" segment is missing here
				if (i>0) {
					if (select_segment_in_viewscreen(vert2+(i-1)*3, vert2+i*3))
						FOUND();
				}
				break;
			case GL_TRIANGLES:
				if (i%3==2) {
					if (select_triangle_in_viewscreen(vert2+(i-2)*3, vert2+(i-1)*3, vert2+i*3))
						FOUND();
				}
				break;
			case GL_TRIANGLE_STRIP:
				if (i>1) {
					if (select_triangle_in_viewscreen(vert2+(i-2)*3, vert2+(i-1)*3, vert2+i*3))
						FOUND();
				}
				break;
			case GL_TRIANGLE_FAN:
				if (i>1) {
					if (select_triangle_in_viewscreen(vert2, vert2+(i-1)*3, vert2+i*3))
						FOUND();
				}
				break;
			default:
				return;		// Should never go there!
		}
	}
	free(vert);
	#undef FOUND
}

void select_glDrawElements(const pointer_state_t* vtx, GLenum mode, GLuint count, GLenum type, GLvoid * indices) {
	if (count == 0) return;
	if (vtx->pointer == NULL) return;

	GLushort *ind = (GLushort*)indices;

	GLsizei min, max;
	getminmax_indices(indices, &max, &min, count);
    max++;
	GLfloat *vert = copy_gl_array(vtx->pointer, vtx->type, 
			vtx->size, vtx->stride,
			GL_FLOAT, 3, 0, max);
	GLfloat tmp[3];
	init_select();
	GLfloat zmin=1.0f, zmax=0.0f;
	for (int i=min; i<max; i++) {
		select_transform(vert+i*3);
		if (vert[i*3+2]<zmin) zmin=vert[i*3+2];
		if (vert[i*3+2]>zmax) zmax=vert[i*3+2];
	}
	if (zmin<0.0f) zmin = 0.0f;
	if (zmax>1.0f) zmax = 1.0f;

	#define FOUND()	{ 		\
		if (zmin<glstate.selectbuf.zmin) 	glstate.selectbuf.zmin=zmin;	\
		if (zmax>glstate.selectbuf.zmax) 	glstate.selectbuf.zmax=zmax;	\
		glstate.selectbuf.hit = 1; \
        free(vert);              \
        return;                  \
		}

	for (int i=0; i<count; i++) {
		switch (mode) {
			case GL_POINTS:
				if (select_point_in_viewscreen(vert+ind[i]*3))
					FOUND();
				break;
			case GL_LINES:
				if (i%2==1) {
					if (select_segment_in_viewscreen(vert+ind[(i-1)]*3, vert+ind[i]*3))
						FOUND();
				}
				break;
			case GL_LINE_STRIP:
			case GL_LINE_LOOP:		//FIXME: the last "loop" segment is missing here
				if (i>0) {
					if (select_segment_in_viewscreen(vert+ind[(i-1)]*3, vert+ind[i]*3))
						FOUND();
				}
				break;
			case GL_TRIANGLES:
				if (i%3==2) {
					if (select_triangle_in_viewscreen(vert+ind[(i-2)]*3, vert+ind[(i-1)]*3, vert+ind[i]*3))
						FOUND();
				}
				break;
			case GL_TRIANGLE_STRIP:
				if (i>1) {
					if (select_triangle_in_viewscreen(vert+ind[(i-2)]*3, vert+ind[(i-1)]*3, vert+ind[i]*3))
						FOUND();
				}
				break;
			case GL_TRIANGLE_FAN:
				if (i>1) {
					if (select_triangle_in_viewscreen(vert+ind[0]*3, vert+ind[(i-1)]*3, vert+ind[i]*3))
						FOUND();
				}
				break;
			default:
				return;		// Should never go there!
		}
	}
	free(vert);
	#undef FOUND
}

//Direct wrapper
GLint glRenderMode(GLenum mode) __attribute__((alias("glshim_glRenderMode")));
void glInitNames() __attribute__((alias("glshim_glInitNames")));
void glPopName() __attribute__((alias("glshim_glPopName")));
void glPushName(GLuint name) __attribute__((alias("glshim_glPushName")));
void glLoadName(GLuint name) __attribute__((alias("glshim_glLoadName")));
void glSelectBuffer(GLsizei size, GLuint *buffer) __attribute__((alias("glshim_glSelectBuffer")));