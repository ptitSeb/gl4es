#ifndef __FPE_SHADER_H
#define __FPE_SHADER_H

#include "fpe.h"

const char* fpeshader_signature;

const char* const* fpe_VertexShader(fpe_state_t *state);
const char* const* fpe_FragmentShader(fpe_state_t *state);

const char* const* fpe_CustomVertexShader(const char* initial, fpe_state_t* state);
const char* const* fpe_CustomFragmentShader(const char* initial, fpe_state_t* state);

#endif //__FPE_SHADER_H