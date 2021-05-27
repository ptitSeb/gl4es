#ifndef _GL4ES_ATTRIBUTES_H_
#define _GL4ES_ATTRIBUTES_H_

#ifndef EXPORT
 #if defined(__EMSCRIPTEN__) || defined(__APPLE__)
   #define EXPORT
 #elif defined(STATICLIB)
   #define EXPORT
 #elif defined(_WIN32) || defined(__CYGWIN__)
   #define EXPORT __declspec(dllexport)
 #elif defined(__GNUC__)
   #define EXPORT __attribute__((visibility("default")))
 #else
   #define EXPORT
 #endif
#endif // EXPORT

#ifndef _STR
 #define _STR(n) #n
#endif

#ifndef AliasDecl
 #ifdef __GNUC__
  #define AliasDecl(RET,NAME,DEF,OLD) \
   RET NAME DEF __attribute__((alias(_STR(OLD))))
 #elif defined(_MSC_VER)
  #define AliasDecl(RET,NAME,DEF,OLD) \
      __pragma(comment(linker, "/ALTERNATENAME:" _STR(NAME) "=" _STR(OLD))) \
      RET NAME DEF
 #else
  #define AliasDecl(RET,NAME,DEF,OLD) \
      RET NAME DEF
 #endif
#endif // AliasDecl

#ifndef AliasExport
 #if !defined(__EMSCRIPTEN__) && !defined(__APPLE__)
  #define _STR(n) #n
  #ifdef __GNUC__
   #define AliasExport(RET,NAME,X,DEF) \
      EXPORT RET NAME##X DEF __attribute__((alias(_STR(gl4es_##NAME))))
   #define AliasExport_A(RET,NAME,X,DEF,INM) \
      EXPORT RET NAME##X DEF __attribute__((alias(_STR(gl4es_##INM))))
  #elif defined(_MSC_VER)
   #define _DIR(DIR,ENM,INM) \
       __pragma(comment(linker, "/" DIR ":" _STR(ENM) "=" _STR(INM)))
   #ifndef STATICLIB
    #define _EXP(ENM,INM) _DIR("EXPORT",ENM,INM)
   #else
    #define _EXP(ENM,INM)
   #endif
    #define _DECL(ENM,INM) _EXP(ENM,INM) _DIR("ALTERNATENAME",ENM,INM)
   #define AliasExport(RET,NAME,X,DEF) _DECL(NAME##X,gl4es_##NAME) \
       RET NAME##X DEF
   #define AliasExport_A(RET,NAME,X,DEF,INM) _DECL(NAME##X,gl4es_##INM) \
       RET NAME##X DEF
  #endif
 #endif
 #ifndef AliasExport
  #define AliasExport(RET,NAME,X,DEF) RET NAME##X DEF
  #define AliasExport_A(RET,NAME,X,DEF,INM) RET NAME##X DEF
 #endif
#endif // AliasExport

// ensure APIENTRY used from platform if it defined, win32 should use STDCALL conversion
#include <GLES/glplatform.h>
#ifndef NOEGL
#include <EGL/eglplatform.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

#ifndef SOFTFLOAT
#ifdef __arm__
#define SOFTFLOAT __attribute__((pcs("aapcs")))
#else
#define SOFTFLOAT
#endif
#endif // SOFTFLOAT

#ifndef APIENTRY_GLES
#ifdef GLES_SOFTFLOAT
#define APIENTRY_GLES APIENTRY SOFTFLOAT
#else
#define APIENTRY_GLES APIENTRY
#endif
#endif // APIENTRY_GLES


#ifndef APIENTRY_GL4ES
#ifdef GL_SOFTFLOAT
#define APIENTRY_GL4ES APIENTRY SOFTFLOAT
#else
#define APIENTRY_GL4ES APIENTRY
#endif
#endif //APIENTRY_GL4ES

#ifndef FASTMATH
#ifdef __GNUC__
 #ifdef __arm__
  #ifdef __ARM_PCS_VFP
   //#warning Arm Hardfloat detected
   #define FASTMATH
  #else // __ARM_PCS_VFP
   #if defined(__ARM_FP) && defined(PANDORA)
    //#warning Arm SoftFP detected
    #define FASTMATH __attribute__((pcs("aapcs-vfp")))
   #else // defined(__ARM_FP) && defined(PANDORA)
	//#warning Arm no FP detected
	#define FASTMATH
   #endif // defined(__ARM_FP) && defined(PANDORA)
  #endif // __ARM_PCS_VFP
 #else // __arm__
  #define FASTMATH
 #endif // __arm__
#else // __GNUC__
 #define FASTMATH
#endif // __GNUC__
#endif // FASTMATH

#endif // _GL4ES_ATTRIBUTES_H_
