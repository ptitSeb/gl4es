#include "fpe.h"

#include "../glx/hardext.h"
#include "array.h"
#include "debug.h"
#include "enum_info.h"
#include "fpe_shader.h"
#include "glcase.h"
#include "init.h"
#include "loader.h"
#include "matrix.h"
#include "matvec.h"
#include "program.h"
#include "shaderconv.h"
#include "fpe_cache.h"

//#define DEBUG
#ifdef DEBUG
#pragma GCC optimize 0
#define DBG(a) a
#else
#define DBG(a)
#endif

static kh_inline khint_t _hash_fpe(fpe_state_t *p)
{
    const char* s = (const char*)p;
	khint_t h = (khint_t)*s;
	for (int i=0 ; i<sizeof(fpe_state_t); ++i) h = (h << 5) - h + (khint_t)*(++s);
	return h;
}

#define kh_fpe_hash_func(key) _hash_fpe(key)

#define kh_fpe_hash_equal(a, b) (memcmp(a, b, sizeof(fpe_state_t)) == 0)

#define KHASH_MAP_INIT_FPE(name, khval_t)								\
	KHASH_INIT(name, kh_fpe_t, khval_t, 1, kh_fpe_hash_func, kh_fpe_hash_equal)

KHASH_MAP_INIT_FPE(fpecachelist, fpe_fpe_t *);

// ********* Cache handling *********

fpe_cache_t* fpe_NewCache() {
    khash_t(fpecachelist) *cache = kh_init(fpecachelist);
    int r;
    fpe_fpe_t dummy;
    memset(&dummy, 0, sizeof(fpe_fpe_t));
    khint_t k = kh_put(fpecachelist, cache, &dummy.state, &r);
    kh_del(fpecachelist, cache, k);
    return cache;
}

void fpe_disposeCache(fpe_cache_t* cache, int freeprog) {
    if(!cache) return;
    fpe_fpe_t *m;
    kh_foreach_value(cache, m, 
        if(freeprog) {
            if(m->glprogram)
                gl4es_glDeleteProgram(m->glprogram->id);
        }
        free(m);
    )
    kh_destroy(fpecachelist, cache);
}

fpe_fpe_t *fpe_GetCache(fpe_cache_t *cur, fpe_state_t *state, int fixed) {
    khint_t k;
    int r;

    k = kh_get(fpecachelist, cur, state);
    if(k != kh_end(cur)) {
        return kh_value(cur, k);
    } else {
        fpe_fpe_t *n = (fpe_fpe_t*)calloc(1, sizeof(fpe_fpe_t));
        memcpy(&n->state, state, sizeof(fpe_state_t));
        k = kh_put(fpecachelist, cur, &n->state, &r);
        kh_value(cur, k) = n;
        return n;
    }
}

