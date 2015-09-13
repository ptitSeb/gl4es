#include "render.h"

void push_hit() {
    // push current hit to hit list, and re-init current hit
    if (state.selectbuf.hit) {
        if (!state.selectbuf.overflow) {
            if (state.selectbuf.zmin<0.0f) state.selectbuf.zmin=0.0f;   // not really normalized...
            if (state.selectbuf.zmax>1.0f) state.selectbuf.zmax=1.0f;   // TODO, normalize for good?
            int tocopy = state.namestack.top + 3;
            if (tocopy+state.selectbuf.pos > state.selectbuf.size) {
                state.selectbuf.overflow = 1;
                tocopy = state.selectbuf.size - state.selectbuf.pos;
            }
            if(tocopy>0)
                state.selectbuf.buffer[state.selectbuf.pos+0] = state.namestack.top;
            if(tocopy>1)
                state.selectbuf.buffer[state.selectbuf.pos+1] = (unsigned int)(state.selectbuf.zmin * INT_MAX );
            if(tocopy>2)
                state.selectbuf.buffer[state.selectbuf.pos+2] = (unsigned int)(state.selectbuf.zmax * INT_MAX );
            if(tocopy>3)
                memcpy(state.selectbuf.buffer + state.selectbuf.pos + 3, state.namestack.names, (tocopy-3) * sizeof(GLuint));

            state.selectbuf.count++;
            state.selectbuf.pos += tocopy;
        }
        state.selectbuf.hit = 0;
    }
    state.selectbuf.zmin = 1.0f;
    state.selectbuf.zmax = 0.0f;
}


GLint glRenderMode(GLenum mode) {
	int ret = 0;
    if ((mode==GL_SELECT) || (mode==GL_RENDER)) {  // missing GL_FEEDBACK
        noerrorShim();
    } else {
        errorShim(GL_INVALID_ENUM);
        return 0;
    }
	if (state.render_mode == GL_SELECT) {
        push_hit();
		ret = state.selectbuf.count;
    }
	if (mode == GL_SELECT) {
		if (state.selectbuf.buffer == NULL)	{// error, cannot use Select Mode without select buffer
            errorShim(GL_INVALID_OPERATION);
			return 0;
        }
		state.selectbuf.count = 0;
        state.selectbuf.pos = 0;
        state.selectbuf.overflow = 0;
        state.selectbuf.zmin = 1.0f;
        state.selectbuf.zmax = 0.0f;
        state.selectbuf.hit = 0;
	}
    
    if((mode==GL_SELECT) && (state.gl_batch)) {
        state.gl_batch = 0;
        flush();
    }
    if((mode==GL_RENDER) && (state.gl_batch==0) && (gl_batch==1)) {
        state.gl_batch = 1;
        flush();
    }
    
	state.render_mode = mode;
	return ret;
}

void glInitNames() {
	if (state.namestack.names == 0) {
		state.namestack.names = (GLuint*)malloc(1024*sizeof(GLuint));
	}
	state.namestack.top = 0;
    noerrorShim();
}

void glPopName() {
    noerrorShim();
	if (state.render_mode != GL_SELECT)
		return;
    push_hit();
	if (state.namestack.top>0)
		state.namestack.top--;
    else
        errorShim(GL_STACK_UNDERFLOW);
}

void glPushName(GLuint name) {
    noerrorShim();
	if (state.render_mode != GL_SELECT)
		return;
	if (state.namestack.names==0)
		return;
    push_hit();
	if (state.namestack.top < 1024) {
		state.namestack.names[state.namestack.top++] = name;
	}
}

void glLoadName(GLuint name) {
    noerrorShim();
	if (state.render_mode != GL_SELECT)
		return;
	if (state.namestack.names == 0)
		return;
    push_hit();
    if (state.namestack.top == 0)
        return;
	state.namestack.names[state.namestack.top-1] = name;
}

void glSelectBuffer(GLsizei size, GLuint *buffer) {
    noerrorShim();
	state.selectbuf.buffer = buffer;
	state.selectbuf.size = size;
}

GLfloat projection[16], modelview[16];
void init_select() {
	/*
	 Initialize matrix and array vector for a select_Draw*
	*/
	 GLfloat tmp[16];
	 glGetFloatv(GL_PROJECTION_MATRIX, tmp);
	 matrix_column_row(tmp, projection);
	 glGetFloatv(GL_MODELVIEW_MATRIX, tmp);
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
	if (state.selectbuf.buffer == NULL) return;
	GLfloat *vert = copy_gl_array(vtx->pointer, vtx->type, 
			vtx->size, vtx->stride,
			GL_FLOAT, 3, 0, count+first);
	GLfloat tmp[3];
	GLfloat zmin=1.0f, zmax=0.0f;
	init_select();

	#define FOUND()	{ 		\
		if (zmin<state.selectbuf.zmin) 	state.selectbuf.zmin=zmin;	\
		if (zmax>state.selectbuf.zmax) 	state.selectbuf.zmax=zmax;	\
		state.selectbuf.hit = 1;                        \
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
		if (zmin<state.selectbuf.zmin) 	state.selectbuf.zmin=zmin;	\
		if (zmax>state.selectbuf.zmax) 	state.selectbuf.zmax=zmax;	\
		state.selectbuf.hit = 1; \
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
