#include "logs.h"
#include "init.h"
#include <stdarg.h>
//----------------------------------------------------------------------------
static const char * const log_prefix="LIBGL: ";
//----------------------------------------------------------------------------
void LogPrintf_NoPrefix(const char *fmt,...)
{
	va_list args;
	va_start(args,fmt);
	#ifdef ANDROID
	__android_log_vprint(ANDROID_LOG_INFO, "LIBGL", fmt, args);
	#else
	vprintf(fmt,args);
	#endif
	va_end(args);
}
//----------------------------------------------------------------------------
void LogFPrintf(FILE *fp,const char *fmt,...)
{
	fprintf(fp,log_prefix);
	va_list args;
	va_start(args,fmt);
	#ifdef ANDROID
	// also on logcat
	__android_log_vprint(ANDROID_LOG_INFO, "LIBGL", fmt, args);
	#endif
	vfprintf(fp,fmt,args);
	va_end(args);
}
//----------------------------------------------------------------------------
void LogPrintf(const char *fmt,...)
{
	#ifndef ANDROID
	printf(log_prefix);
	#endif
	va_list args;
	va_start(args,fmt);
	#ifdef ANDROID
	__android_log_vprint(ANDROID_LOG_INFO, "LIBGL", fmt, args);
	#else
	vprintf(fmt,args);
	#endif
	va_end(args);
}
//----------------------------------------------------------------------------
