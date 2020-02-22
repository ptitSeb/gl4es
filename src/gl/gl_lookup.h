#ifndef _GL_LOOKUP_H_
#define _GL_LOOKUP_H_

#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;

#define EX(func_name) MAP(#func_name, func_name)

#define ARB(func_name) MAP(#func_name "ARB", func_name)

#define EXT(func_name) MAP(#func_name "EXT", func_name)

#define _EX(func_name) MAP(#func_name, gl4es_ ## func_name)

#define _ARB(func_name) MAP(#func_name "ARB", gl4es_ ## func_name)

#define _EXT(func_name) MAP(#func_name "EXT", gl4es_ ## func_name)

#ifndef STUB_FCT
#error STUB_FCT is not defined
#endif

#define STUB(func_name)                       \
    if (strcmp(name, #func_name) == 0) {      \
        if(!globals4es.silentstub) LOGD("GL4ES stub: %s\n", #func_name); \
        return (void *)STUB_FCT;              \
    }


void *gl4es_GetProcAddress(const char *name);

#endif //_GL_LOOKUP_H_