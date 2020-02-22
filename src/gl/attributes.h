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
