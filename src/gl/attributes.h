#ifndef _GL4ES_ATTRIBUTES_H_
#define _GL4ES_ATTRIBUTES_H_

#ifndef AliasExport
 #ifdef __EMSCRIPTEN__
  #define AliasExport(name)
 #else
  #define AliasExport(name)   __attribute__((alias(name))) __attribute__((visibility("default")))
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
