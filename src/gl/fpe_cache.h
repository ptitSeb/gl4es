#ifndef __FPE_CACHE_H__
#define __FPE_CACHE_H__

typedef struct fpe_state_s fpe_state_t;
typedef fpe_state_t *kh_fpe_t;
typedef struct fpe_fpe_s fpe_fpe_t;
typedef struct kh_fpecachelist_s kh_fpecachelist_t;
#ifndef fpe_cache_t
#define fpe_cache_t kh_fpecachelist_t
#endif

fpe_cache_t* fpe_NewCache();
void fpe_disposeCache(fpe_cache_t* cache, int freeprog);
fpe_fpe_t *fpe_GetCache(fpe_cache_t *cur, fpe_state_t *state, int fixed);

void fpe_InitPSA();
void fpe_FreePSA();

#endif //__FPE_CACHE_H__