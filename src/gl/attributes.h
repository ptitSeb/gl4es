#ifndef _GL4ES_ATTRIBUTES_H_
#define _GL4ES_ATTRIBUTES_H_

#ifndef EXPORT
 #if defined(__EMSCRIPTEN__) || defined(__APPLE__)
   #define EXPORT
 #elif defined(STATICLIB)
   #define EXPORT
 #else
   #define EXPORT __attribute__((visibility("default")))
 #endif
#endif // EXPORT

#ifndef AliasExport
 #if defined(__EMSCRIPTEN__) || defined(__APPLE__)
  #define AliasExport(name)
 #else
  #define AliasExport(name)   __attribute__((alias(name))) EXPORT
 #endif
#endif // AliasExport

// ensure APIENTRY used from platform if it defined, win32 should use STDCALL conversion
#include <GLES/glplatform.h>

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
