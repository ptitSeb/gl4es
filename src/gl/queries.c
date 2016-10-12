#include "queries.h"

static GLuint lastquery = 0;
static glquery_t *active_samples_passed = 0;
extern int glshim_queries;

void glshim_glGenQueries(GLsizei n, GLuint * ids) {
	noerrorShim();
    if (n<1) {
		errorShim(GL_INVALID_VALUE);
        return;
    }
    for (int i=0; i<n; i++) {
        ids[i] = ++lastquery;
    }
}

GLboolean glshim_glIsQuery(GLuint id) {
	khash_t(queries) *list = glstate.queries;
	khint_t k;
	noerrorShim();
    if (list) {
		k = kh_get(queries, list, id);
		if (k != kh_end(list)) {
			return GL_TRUE;
		}
	}
	return GL_FALSE;
}

void glshim_glDeleteQueries(GLsizei n, const GLuint* ids) {
	khash_t(queries) *list = glstate.queries;
    if (list) {
        khint_t k;
        glquery_t *query;
        for (int i = 0; i < n; i++) {
            GLuint t = ids[i];
            if (t) {    // don't allow to remove default one
                k = kh_get(queries, list, t);
                if (k != kh_end(list)) {
                    query = kh_value(list, k);
                    kh_del(queries, list, k);
                    free(query);
                    if(active_samples_passed==query)
                    	active_samples_passed = NULL;
                }
            }
        }
    }
    noerrorShim();
}

void glshim_glBeginQuery(GLenum target, GLuint id) {
	if(target!=GL_SAMPLES_PASSED) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    if (glstate.gl_batch) {
         flush();
    }
   	khint_t k;
   	int ret;
    glquery_t *query;
	khash_t(queries) *list = glstate.queries;
	if (! list) {
		list = glstate.queries = kh_init(queries);
		// segfaults if we don't do a single put
		kh_put(queries, list, 1, &ret);
		kh_del(queries, list, 1);
	}
    k = kh_get(queries, list, id);
    if (k != kh_end(list)) {
        query = kh_value(list, k);
    } else {
        k = kh_put(queries, list, id, &ret);
        query = kh_value(list, k) = malloc(sizeof(glquery_t));
    }
    query->target = target;
    query->num = 0;
    active_samples_passed = query;
    noerrorShim();
}

void glshim_glEndQuery(GLenum target) {
	if(target!=GL_SAMPLES_PASSED) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	if(!active_samples_passed) {
		errorShim(GL_INVALID_OPERATION);
		return;
	}
    if (glstate.gl_batch) {
         flush();
    }
    active_samples_passed = NULL;
	noerrorShim();
}

void glshim_glGetQueryiv(GLenum target, GLenum pname, GLint* params) {
	if(target!=GL_SAMPLES_PASSED) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	noerrorShim();
	switch (pname) {
		case GL_CURRENT_QUERY:
			*params = (active_samples_passed)?active_samples_passed->id:0;
			break;
		case GL_QUERY_COUNTER_BITS:
			*params = 0;	//no counter...
			break;
		default:
			errorShim(GL_INVALID_ENUM);
	}
}

void glshim_glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) {
   	khint_t k;
   	int ret;
    glquery_t *query = NULL;
	khash_t(queries) *list = glstate.queries;
	if (! list) {
		list = glstate.queries = kh_init(queries);
		// segfaults if we don't do a single put
		kh_put(queries, list, 1, &ret);
		kh_del(queries, list, 1);
	}
    k = kh_get(queries, list, id);
    if (k != kh_end(list)) {
        query = kh_value(list, k);
    }
    if(!query) {
    	errorShim(GL_INVALID_OPERATION);
    	return;
    }
    noerrorShim();
    switch (pname) {
    	case GL_QUERY_RESULT_AVAILABLE:
    		*params = GL_TRUE;
    		break;
    	case GL_QUERY_RESULT:
    		*params = query->num;
    		break;
    	default:
    		errorShim(GL_INVALID_ENUM);
    		break;
    }
}

void glshim_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) {
   	khint_t k;
   	int ret;
    glquery_t *query = NULL;
	khash_t(queries) *list = glstate.queries;
	if (! list) {
		list = glstate.queries = kh_init(queries);
		// segfaults if we don't do a single put
		kh_put(queries, list, 1, &ret);
		kh_del(queries, list, 1);
	}
    k = kh_get(queries, list, id);
    if (k != kh_end(list)) {
        query = kh_value(list, k);
    }
    if(!query) {
    	errorShim(GL_INVALID_OPERATION);
    	return;
    }
    noerrorShim();
    switch (pname) {
    	case GL_QUERY_RESULT_AVAILABLE:
    		*params = GL_TRUE;
    		break;
    	case GL_QUERY_RESULT:
    		*params = query->num;
    		break;
    	default:
    		errorShim(GL_INVALID_ENUM);
    		break;
    }
}


//Direct wrapper
void glGenQueries(GLsizei n, GLuint * ids) AliasExport("glshim_glGenQueries");
GLboolean glIsQuery(GLuint id) AliasExport("glshim_glIsQuery");
void glDeleteQueries(GLsizei n, const GLuint* ids) AliasExport("glshim_glDeleteQueries");
void glBeginQuery(GLenum target, GLuint id) AliasExport("glshim_glBeginQuery");
void glEndQuery(GLenum target) AliasExport("glshim_glEndQuery");
void glGetQueryiv(GLenum target, GLenum pname, GLint* params) AliasExport("glshim_glGetQueryiv");
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) AliasExport("glshim_glGetQueryObjectiv");
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) AliasExport("glshim_glGetQueryObjectuiv");
