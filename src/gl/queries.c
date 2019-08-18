#include "queries.h"

#include "khash.h"
#include "gl4es.h"
#include "glstate.h"
#include "loader.h"

KHASH_MAP_IMPL_INT(queries, glquery_t *);

static GLuint lastquery = 0;
static glquery_t *active_samples_passed = 0;

void gl4es_glGenQueries(GLsizei n, GLuint * ids) {
    FLUSH_BEGINEND;
	noerrorShim();
    if (n<1) {
		errorShim(GL_INVALID_VALUE);
        return;
    }
    for (int i=0; i<n; i++) {
        ids[i] = ++lastquery;
    }
}

GLboolean gl4es_glIsQuery(GLuint id) {
	if(glstate->list.compiling) {errorShim(GL_INVALID_OPERATION); return GL_FALSE;}
	FLUSH_BEGINEND;
	khash_t(queries) *list = glstate->queries;
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

void gl4es_glDeleteQueries(GLsizei n, const GLuint* ids) {
    FLUSH_BEGINEND;
	khash_t(queries) *list = glstate->queries;
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

void gl4es_glBeginQuery(GLenum target, GLuint id) {
	if(target!=GL_SAMPLES_PASSED) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    FLUSH_BEGINEND;

   	khint_t k;
   	int ret;
    glquery_t *query;
	khash_t(queries) *list = glstate->queries;
	if (! list) {
		list = glstate->queries = kh_init(queries);
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

void gl4es_glEndQuery(GLenum target) {
	if(target!=GL_SAMPLES_PASSED) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
	if(!active_samples_passed) {
		errorShim(GL_INVALID_OPERATION);
		return;
	}
    FLUSH_BEGINEND;

    active_samples_passed = NULL;
	noerrorShim();
}

void gl4es_glGetQueryiv(GLenum target, GLenum pname, GLint* params) {
	if(target!=GL_SAMPLES_PASSED) {
		errorShim(GL_INVALID_ENUM);
		return;
	}
    FLUSH_BEGINEND;

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

void gl4es_glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) {
   	khint_t k;
   	int ret;
    FLUSH_BEGINEND;

    glquery_t *query = NULL;
	khash_t(queries) *list = glstate->queries;
	if (! list) {
		list = glstate->queries = kh_init(queries);
		// segfaults if we don't do a single put
		k = kh_put(queries, list, 1, &ret);
		kh_del(queries, list, k);
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
    		*params = GL_FALSE;
    		break;
    	case GL_QUERY_RESULT:
    		*params = query->num;
    		break;
    	default:
    		errorShim(GL_INVALID_ENUM);
    		break;
    }
}

void gl4es_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) {
   	khint_t k;
   	int ret;
    FLUSH_BEGINEND;
		
    glquery_t *query = NULL;
	khash_t(queries) *list = glstate->queries;
	if (! list) {
		list = glstate->queries = kh_init(queries);
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
    		*params = GL_FALSE;
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
void glGenQueries(GLsizei n, GLuint * ids) AliasExport("gl4es_glGenQueries");
GLboolean glIsQuery(GLuint id) AliasExport("gl4es_glIsQuery");
void glDeleteQueries(GLsizei n, const GLuint* ids) AliasExport("gl4es_glDeleteQueries");
void glBeginQuery(GLenum target, GLuint id) AliasExport("gl4es_glBeginQuery");
void glEndQuery(GLenum target) AliasExport("gl4es_glEndQuery");
void glGetQueryiv(GLenum target, GLenum pname, GLint* params) AliasExport("gl4es_glGetQueryiv");
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) AliasExport("gl4es_glGetQueryObjectiv");
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) AliasExport("gl4es_glGetQueryObjectuiv");

// ARB wrapper
void glGenQueriesARB(GLsizei n, GLuint * ids) AliasExport("gl4es_glGenQueries");
GLboolean glIsQueryARB(GLuint id) AliasExport("gl4es_glIsQuery");
void glDeleteQueriesARB(GLsizei n, const GLuint* ids) AliasExport("gl4es_glDeleteQueries");
void glBeginQueryARB(GLenum target, GLuint id) AliasExport("gl4es_glBeginQuery");
void glEndQueryARB(GLenum target) AliasExport("gl4es_glEndQuery");
void glGetQueryivARB(GLenum target, GLenum pname, GLint* params) AliasExport("gl4es_glGetQueryiv");
void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint* params) AliasExport("gl4es_glGetQueryObjectiv");
void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint* params) AliasExport("gl4es_glGetQueryObjectuiv");
