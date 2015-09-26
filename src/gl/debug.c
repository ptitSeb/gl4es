#include "debug.h"

#define p(a) \
    case a: return #a

const char* PrintEnum(GLenum what) {
    static char fallback[64];
    switch(what)
    {
        // target
        p(GL_TEXTURE_1D);
        p(GL_TEXTURE_2D);
        p(GL_TEXTURE_3D);
        p(GL_FRAMEBUFFER);
        p(GL_RENDERBUFFER);
        p(GL_PROXY_TEXTURE_1D);
        p(GL_PROXY_TEXTURE_2D);
        p(GL_PROXY_TEXTURE_3D);
        p(GL_READ_FRAMEBUFFER);
        p(GL_DRAW_FRAMEBUFFER);
        // format
        p(GL_RED);
        p(GL_RGB);
        p(GL_RGBA);
        p(GL_RGBA8);
        p(GL_RGB8);
        p(GL_COMPRESSED_RGB_S3TC_DXT1_EXT);
        p(GL_COMPRESSED_RGBA_S3TC_DXT1_EXT);
        p(GL_COMPRESSED_RGBA_S3TC_DXT3_EXT);
        p(GL_COMPRESSED_RGBA_S3TC_DXT5_EXT);
        // type
        p(GL_UNSIGNED_BYTE);
        p(GL_UNSIGNED_BYTE_2_3_3_REV);
        p(GL_UNSIGNED_BYTE_3_3_2);
        p(GL_UNSIGNED_INT);
        p(GL_UNSIGNED_SHORT);
        p(GL_UNSIGNED_SHORT_5_5_5_1);
        p(GL_UNSIGNED_SHORT_1_5_5_5_REV);
        p(GL_UNSIGNED_SHORT_4_4_4_4);
        p(GL_UNSIGNED_SHORT_4_4_4_4_REV);
        p(GL_UNSIGNED_SHORT_5_6_5);
        p(GL_UNSIGNED_SHORT_5_6_5_REV);
        p(GL_FLOAT);
        p(GL_DOUBLE);
        // texture pack/unpack
        p(GL_UNPACK_ALIGNMENT);
        // framebuffer
        p(GL_COLOR_ATTACHMENT0);
        p(GL_COLOR_ATTACHMENT1);
        p(GL_COLOR_ATTACHMENT2);
        p(GL_COLOR_ATTACHMENT3);
        p(GL_COLOR_ATTACHMENT4);
        p(GL_DEPTH_ATTACHMENT);
        p(GL_STENCIL_ATTACHMENT);
        default:
            sprintf(fallback, "0x%04X", what);
    }
    return fallback;
}
