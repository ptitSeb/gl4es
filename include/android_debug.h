#ifndef __ANDROID_DEBUG_H__
#define __ANDROID_DEBUG_H__

// Redirect printf() to Android log
// Put this file into CFLAGS: "-include ../android_debug.h"

#include <stdio.h>
#include <stdarg.h>
#include <android/log.h>

#ifdef __cplusplus
// Include everything beforehand, so we wont' get compiler errors because of our #define
#include <string>
#include <ios>
#include <streambuf>
#include <sstream>
#include <fstream>
#include <iostream>

namespace std
{
	class android_cout: public ostringstream
	{
		public:
		android_cout() {}
		template <class T>
		android_cout &operator<<(const T &v)
		{
			*((ostringstream*)this) << v;
			if( this->str().find('\n') != ::std::string::npos )
			{
				__android_log_print(ANDROID_LOG_INFO, "glshim", "%s", this->str().c_str());
				this->str().clear();
			}
			return *this;
		}
		~android_cout()
		{
			__android_log_print(ANDROID_LOG_INFO, "glshim", "%s", this->str().c_str());
			this->str().clear();
		}
	};
	static const char * android_endl = "\n";
}
#define cout android_cout()
#define cerr android_cout()
#define endl android_endl

#endif

#define printf(...) __android_log_print(ANDROID_LOG_INFO, "glshim", __VA_ARGS__)

// Override fprintf(stderr, ...) constructs
static inline int __sdl_logged_fprintf(FILE *stream, const char *format, ...)
{
	int ret = 0;
	va_list args;
	va_start(args, format);
	if( stream == stderr || stream == stdout )
		ret = __android_log_vprint(ANDROID_LOG_INFO, "glshim", format, args);
	else
		ret = vfprintf(stream, format, args);
	va_end(args);
	return ret;
}

#define fprintf(...) __sdl_logged_fprintf(__VA_ARGS__)

#endif

