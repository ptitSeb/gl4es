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
	vprintf(fmt,args);
	va_end(args);
}
//----------------------------------------------------------------------------
void LogFPrintf(FILE *fp,const char *fmt,...)
{
	fprintf(fp,log_prefix);
	va_list args;
	va_start(args,fmt);
	vfprintf(fp,fmt,args);
	va_end(args);
}
//----------------------------------------------------------------------------
void LogPrintf(const char *fmt,...)
{
	printf(log_prefix);
	va_list args;
	va_start(args,fmt);
	vprintf(fmt,args);
	va_end(args);
}
//----------------------------------------------------------------------------
