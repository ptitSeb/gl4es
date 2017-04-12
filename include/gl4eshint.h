#ifndef _GL4ES_HINT_H_
#define _GL4ES_HINT_H_

// Custom hints to handles some specifics gl4es options

// same as using LIBGL_SHRINK=x
#define GL_SHRINK_HINT_GL4ES            0xA101
// same as using LIBGL_ALPHAHACK=x
#define GL_ALPHAHACK_HINT_GL4ES         0xA102
// same as using LIBGL_RECYCLEFBO=x
#define GL_RECYCLEFBO_HINT_GL4ES        0xA103
// same as using LIBGL_MIPMAP=x
#define GL_MIPMAP_HINT_GL4ES            0xA104
// same as using LIBGL_TEXDUMP=x
#define GL_TEXDUMP_HINT_GL4ES           0xA105
// same as using LIBGL_COPY=x
#define GL_COPY_HINT_GL4ES              0xA106
// same as using LIBGL_NOLUMALPHA=x
#define GL_NOLUMAPHA_HINT_GL4ES         0xA107
// same as using LIBGL_BLENDHACK=x
#define GL_BLENDHACK_HINT_GL4ES         0xA108
// same as using LIBGL_BATCH=x
#define GL_BATCH_HINT_GL4ES             0xA109
// same as using LIBGL_NOERROR=x
#define GL_NOERROR_HINT_GL4ES           0xA10A
// same as using LIBGL_NODOWNSAMPLING=x
#define GL_NODOWNSAMPLING_HINT_GL4ES	0xA10B
// same as using LIBGL_NOVAOCACHE=x
#define GL_NOVAOCACHE_HINT_GL4ES	    0xA10C
// same as using LIBGL_BEGINEND=x
#define GL_BEGINEND_HINT_GL4ES	        0xA10D
// same as using LIBGL_AVOID16BITS=x
#define GL_AVOID16BITS_HINT_GL4ES	    0xA10E

#endif