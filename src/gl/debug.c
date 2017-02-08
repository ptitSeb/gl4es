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
        p(GL_TEXTURE_CUBE_MAP);
        p(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
        p(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
        p(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
        p(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
        p(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
        p(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
        // format
        p(GL_RED);
        p(GL_R);
        p(GL_R3_G3_B2);
        p(GL_RGB);
        p(GL_BGR);
        p(GL_RGB8);
        p(GL_RGB5);
        p(GL_RGB16);
        p(GL_RGB16F);
        p(GL_RGB32F);
        p(GL_BGRA);
        p(GL_RGBA);
        p(GL_RGBA4);
        p(GL_RGB5_A1);
        p(GL_RGB10_A2);
        p(GL_RGBA8);
        p(GL_RGBA16);
        p(GL_RGBA16F);
        p(GL_RGBA32F);
        p(GL_COMPRESSED_RGB_S3TC_DXT1_EXT);
        p(GL_COMPRESSED_RGBA_S3TC_DXT1_EXT);
        p(GL_COMPRESSED_RGBA_S3TC_DXT3_EXT);
        p(GL_COMPRESSED_RGBA_S3TC_DXT5_EXT);
        p(GL_LUMINANCE8_ALPHA8);
        p(GL_LUMINANCE_ALPHA);
        p(GL_LUMINANCE4_ALPHA4);
        p(GL_LUMINANCE16_ALPHA16);
        p(GL_LUMINANCE);
        p(GL_ALPHA);
        p(GL_LUMINANCE8);
        p(GL_LUMINANCE16);
        p(GL_ALPHA8);
        p(GL_COMPRESSED_ALPHA);
        p(GL_COMPRESSED_LUMINANCE);
        p(GL_COMPRESSED_LUMINANCE_ALPHA);
        p(GL_COMPRESSED_RGB);
        p(GL_COMPRESSED_RGBA);
        // type
        p(GL_BYTE);
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
        // texture infos
        p(GL_TEXTURE_WIDTH);
        p(GL_TEXTURE_HEIGHT);
        p(GL_TEXTURE_COMPRESSED);
        p(GL_TEXTURE_BORDER);
        p(GL_TEXTURE_INTERNAL_FORMAT);
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
        // VBO
        p(GL_STATIC_DRAW);
        p(GL_READ_WRITE);
        p(GL_ARRAY_BUFFER);
        p(GL_ELEMENT_ARRAY_BUFFER);
        p(GL_PIXEL_PACK_BUFFER);
        p(GL_PIXEL_UNPACK_BUFFER);
        // Texture
        p(GL_TEXTURE0);
        p(GL_TEXTURE1);
        p(GL_TEXTURE2);
        p(GL_TEXTURE3);
        p(GL_TEXTURE4);
        p(GL_TEXTURE5);
        p(GL_TEXTURE6);
        p(GL_TEXTURE7);
        // mode
        p(GL_POINTS);
        p(GL_LINES);
        p(GL_LINE_LOOP);
        p(GL_LINE_STRIP);
        p(GL_TRIANGLES);
        p(GL_TRIANGLE_STRIP);
        p(GL_TRIANGLE_FAN);
        p(GL_QUADS);
        p(GL_QUAD_STRIP);
        p(GL_POLYGON);
        // texgen
        p(GL_S);
        p(GL_T);
        p(GL_Q);
        p(GL_TEXTURE_GEN_MODE);
        p(GL_OBJECT_LINEAR);
        p(GL_EYE_LINEAR);
        p(GL_SPHERE_MAP);
        p(GL_NORMAL_MAP);
        p(GL_REFLECTION_MAP);
        // matrix mode
        p(GL_PROJECTION);
        p(GL_MODELVIEW);
        p(GL_TEXTURE);
        // blend
        p(GL_SRC_ALPHA);
        p(GL_DST_ALPHA);
        p(GL_ONE_MINUS_SRC_ALPHA);
        p(GL_ONE_MINUS_DST_ALPHA);
        // lights
        p(GL_LIGHT0);
        p(GL_LIGHT1);
        p(GL_LIGHT2);
        p(GL_LIGHT3);
        p(GL_LIGHT4);
        p(GL_LIGHT5);
        p(GL_LIGHT6);
        p(GL_LIGHT7);
        p(GL_AMBIENT);
        p(GL_DIFFUSE);
        p(GL_SPECULAR);
        p(GL_POSITION);
        p(GL_SPOT_DIRECTION);
        p(GL_SPOT_EXPONENT);
        p(GL_SPOT_CUTOFF);
        p(GL_CONSTANT_ATTENUATION);
        p(GL_LINEAR_ATTENUATION);
        p(GL_QUADRATIC_ATTENUATION);
        default:
            sprintf(fallback, "0x%04X", what);
    }
    return fallback;
}
