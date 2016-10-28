#ifdef ANDROID
#include <android/log.h>
#define  LOG_TAG    "LIBGL"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#else
#define  LOGD(...)  printf(__VA_ARGS__)
#define  LOGE(...)  fprintf(stderr, __VA_ARGS__)
#endif
