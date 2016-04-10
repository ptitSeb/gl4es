#include "pixel.h"
#include "debug.h"

static const colorlayout_t *get_color_map(GLenum format) {
    #define map(fmt, ...)                               \
        case fmt: {                                     \
        static colorlayout_t layout = {fmt, __VA_ARGS__}; \
        return &layout; }
    switch (format) {
        map(GL_RED, 0, -1, -1, -1);
        map(GL_R,   0, -1, -1, -1);
        map(GL_RG,  0,  1, -1, -1);
        map(GL_RGBA,0,  1, 2, 3);
        map(GL_RGB, 0,  1, 2, -1);
        map(GL_BGRA,2,  1, 0, 3);
        map(GL_BGR, 2,  1, 0, -1);
		map(GL_LUMINANCE_ALPHA, 0, 0, 0, 1);
		map(GL_LUMINANCE, 0, 0, 0, -1);
		map(GL_ALPHA,-1, -1, -1, 0);
        default:
            printf("libGL: unknown pixel format %s\n", PrintEnum(format));
            break;
    }
    static colorlayout_t null = {0};
    return &null;
    #undef map
}

static inline
bool remap_pixel(const GLvoid *src, GLvoid *dst,
                 const colorlayout_t *src_color, GLenum src_type,
                 const colorlayout_t *dst_color, GLenum dst_type) {

    #define type_case(constant, type, ...)        \
        case constant: {                          \
            const type *s = (const type *)src;    \
            type *d = (type *)dst;                \
            type v = *s;                          \
            __VA_ARGS__                           \
            break;                                \
        }

    #define default(arr, amod, vmod, key, def) \
        (key >= 0)? arr[amod key] vmod : def

    #define carefully(arr, amod, key, value) \
        if (key >= 0) d[amod key] = value;

    #define read_each(amod, vmod)                                 \
        pixel.r = default(s, amod, vmod, src_color->red, 0.0f);      \
        pixel.g = default(s, amod, vmod, src_color->green, 0.0f);    \
        pixel.b = default(s, amod, vmod, src_color->blue, 0.0f);     \
        pixel.a = default(s, amod, vmod, src_color->alpha, 1.0f);

    #define write_each(amod, vmod)                         \
        carefully(d, amod, dst_color->red, pixel.r vmod)   \
        carefully(d, amod, dst_color->green, pixel.g vmod) \
        carefully(d, amod, dst_color->blue, pixel.b vmod)  \
        carefully(d, amod, dst_color->alpha, pixel.a vmod)

    // this pixel stores our intermediate color
    // it will be RGBA and normalized to between (0.0 - 1.0f)
    pixel_t pixel;
    int max_a = src_color->red;
    if (src_color->green>max_a) max_a=src_color->green;
    if (src_color->blue>max_a) max_a=src_color->blue;
    if (src_color->alpha>max_a) max_a=src_color->alpha;
    switch (src_type) {
        type_case(GL_DOUBLE, GLdouble, read_each(,))
        type_case(GL_FLOAT, GLfloat, read_each(,))
        type_case(GL_BYTE, GLbyte, read_each(, / 128.0f))
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        type_case(GL_UNSIGNED_BYTE, GLubyte, read_each(, / 255.0f))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, read_each(max_a - , / 255.0f))
        type_case(GL_UNSIGNED_SHORT_1_5_5_5_REV, GLushort,
            s = (GLushort[]){
                 (v & 0x001f),
                ((v & 0x03e0) >> 5),
                ((v & 0x7c00) >> 10),
                ((v & 0x8000) >> 15)*31,
            };
            read_each(, / 31.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_6_5_REV, GLushort,
            s = (GLushort[]){
                (v &  0x001f)*2,
                ((v & 0x07e0) >> 5),
                ((v & 0xF800) >> 11)*2,
            };
            read_each(, / 63.0f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4_REV, GLushort,
            s = (GLushort[]){
                 (v & 0x000f),
                ((v & 0x00f0) >> 4),
                ((v & 0x0f00) >> 8),
                ((v & 0xf000) >> 12)
            };
            read_each(, / 15.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            s = (GLushort[]){
                ((v & 0xF800) >>11)*2,
                ((v & 0x07e0) >> 5),
                ((v & 0x001f)     )*2,
            };
            read_each(, / 63.0f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            s = (GLushort[]){
                ((v & 0xf000) >>12),
                ((v & 0x0f00) >> 8),
                ((v & 0x00f0) >> 4),
                ((v & 0x000f)     )
            };
            read_each(, / 15.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_5_5_1, GLushort,
            s = (GLushort[]){
                ((v & 0xf800) >> 11),
                ((v & 0x07c0) >> 6),
                ((v & 0x003e) >> 1),
                ((v & 1))*31,
            };
            read_each(, / 31.0f);
        )
        default:
            // TODO: add glSetError?
            printf("libGL: Unsupported source data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    max_a = dst_color->red;
    if (dst_color->green>max_a) max_a=dst_color->green;
    if (dst_color->blue>max_a) max_a=dst_color->blue;
    if (dst_color->alpha>max_a) max_a=dst_color->alpha;
    if ((dst_color->red==dst_color->green) && (dst_color->red==dst_color->blue)) {
        // special case
        GLfloat aa = (pixel.r + pixel.g + pixel.b)/3.0f;    //*TODO* find a better formula. real luminance is not just the mean value.
        pixel.r = pixel.b = pixel.b = aa;
    }
    switch (dst_type) {
        type_case(GL_FLOAT, GLfloat, write_each(,))
        type_case(GL_BYTE, GLbyte, write_each(, * 127.0f))
        type_case(GL_UNSIGNED_BYTE, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8_REV, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, write_each(max_a - , * 255.0))
        // TODO: force 565 to RGB? then we can change [4] -> 3
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            GLfloat color[4];
            color[dst_color->red] = pixel.r;
            color[dst_color->green] = pixel.g;
            color[dst_color->blue] = pixel.b;
            *d = (((GLushort)(color[0] * 31.0f) & 0x1f) << 11) |
                 (((GLushort)(color[1] * 63.0f) & 0x3f) << 5) |
                 (((GLushort)(color[2] * 31.0f) & 0x1f));
        )
        type_case(GL_UNSIGNED_SHORT_5_5_5_1, GLushort,
            GLfloat color[4];
            color[dst_color->red] = pixel.r;
            color[dst_color->green] = pixel.g;
            color[dst_color->blue] = pixel.b;
            color[dst_color->alpha] = pixel.a;
            // TODO: can I macro this or something? it follows a pretty strict form.
            *d = (((GLushort)(color[0] * 31.0f) & 0x1f)     ) |
                 (((GLushort)(color[1] * 31.0f) & 0x1f) << 5) |
                 (((GLushort)(color[2] * 31.0f) & 0x1f) << 10)  |
                 (((GLushort)(color[3] * 1)  & 0x01) << 15);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            GLfloat color[4];
            color[dst_color->red] = pixel.r;
            color[dst_color->green] = pixel.g;
            color[dst_color->blue] = pixel.b;
            color[dst_color->alpha] = pixel.a;
            *d = (((GLushort)(color[0] * 15.0) & 0x0f) << 12) |
                 (((GLushort)(color[1] * 15.0) & 0x0f) << 8) |
                 (((GLushort)(color[2] * 15.0) & 0x0f) << 4) |
                 (((GLushort)(color[3] * 15.0) & 0x0f));
        )
        default:
            printf("libGL: Unsupported target data type: %s\n", PrintEnum(dst_type));
            return false;
            break;
    }
    return true;

    #undef type_case
    #undef default
    #undef carefully
    #undef read_each
    #undef write_each
}
static inline
bool transform_pixel(const GLvoid *src, GLvoid *dst, 
                 const colorlayout_t *src_color, GLenum src_type,
                 const GLfloat *scale, const GLfloat *bias) {

    #define type_case(constant, type, ...)        \
        case constant: {                          \
            const type *s = (const type *)src;    \
            type *d = (type *)dst;                \
            type v = *s;                          \
            __VA_ARGS__                           \
            break;                                \
        }

    #define default(arr, amod, vmod, key, def) \
        (amod key) >= 0 ? arr[amod key] vmod : def

    #define carefully(arr, amod, key, value) \
        if ((amod key) >= 0) d[amod key] = value;

    #define read_each(amod, vmod)                                 \
        pixel.r = default(s, amod, vmod, src_color->red, 0.0f);      \
        pixel.g = default(s, amod, vmod, src_color->green, 0.0f);    \
        pixel.b = default(s, amod, vmod, src_color->blue, 0.0f);     \
        pixel.a = default(s, amod, vmod, src_color->alpha, 1.0f);

    #define write_each(amod, vmod)                         \
        carefully(d, amod, src_color->red, pixel.r vmod)   \
        carefully(d, amod, src_color->green, pixel.g vmod) \
        carefully(d, amod, src_color->blue, pixel.b vmod)  \
        carefully(d, amod, src_color->alpha, pixel.a vmod)

    #define transformf(pix, number)                         \
        pix=pix*scale[number]+bias[number];   \
        if (pix<0.0) pix=0.0;                               \
        if (pix>1.0) pix=1.0;


    // this pixel stores our intermediate color
    // it will be RGBA and normalized to between (0.0 - 1.0f)
    pixel_t pixel;
    int max_a = src_color->red;
    if (src_color->green>max_a) max_a=src_color->green;
    if (src_color->blue>max_a) max_a=src_color->blue;
    if (src_color->alpha>max_a) max_a=src_color->alpha;
    switch (src_type) {
        type_case(GL_DOUBLE, GLdouble, read_each(,))
        type_case(GL_FLOAT, GLfloat, read_each(,))
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        type_case(GL_UNSIGNED_BYTE, GLubyte, read_each(, / 255.0f))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, read_each(max_a - , / 255.0f))
        type_case(GL_UNSIGNED_SHORT_1_5_5_5_REV, GLushort,
            s = (GLushort[]){
                (v & 31),
                ((v & 0x03e0) >> 5),
                ((v & 0x7c00) >> 10),
                ((v & 0x8000) >> 15)*31,
            };
            read_each(, / 31.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            s = (GLushort[]){
                (v & 31)*2,
                ((v & 0x07e0) >> 5),
                ((v & 0xF800) >> 11)*2,
            };
            read_each(, / 63.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_5_5_1, GLushort,
            s = (GLushort[]){
                ((v & 0xf800) >> 11),
                ((v & 0x07c0) >> 6),
                ((v & 0x003e) >> 1),
                ((v & 1))*31,
            };
            read_each(, / 31.0f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            s = (GLushort[]){
                (v & 0x000f),
                ((v & 0x00f0) >> 4),
                ((v & 0x0f00) >> 8),
                ((v & 0xf000) >> 12)
            };
            read_each(, / 15.0f);
        )
        default:
            // TODO: add glSetError?
            printf("libGL: transform_pixel: Unsupported source data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    transformf(pixel.r, 0);
    transformf(pixel.g, 1);
    transformf(pixel.b, 2);
    transformf(pixel.a, 3);

    switch (src_type) {
        type_case(GL_FLOAT, GLfloat, write_each(,))
        type_case(GL_UNSIGNED_BYTE, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8_REV, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, write_each(max_a - , * 255.0))
        // TODO: force 565 to RGB? then we can change [4] -> 3
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            *d = ((GLuint)(color[2] * 31.0f) & 0x1f << 11) |
                 ((GLuint)(color[1] * 63.0f) & 0x3f << 5) |
                 ((GLuint)(color[0] * 31.0f) & 0x1f);
        )
        type_case(GL_UNSIGNED_SHORT_5_5_5_1, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            color[src_color->alpha] = pixel.a;
            // TODO: can I macro this or something? it follows a pretty strict form.
            *d = ((GLuint)(color[0] * 31.0f) & 0x1f << 0) |
                 ((GLuint)(color[1] * 31.0f) & 0x1f << 5) |
                 ((GLuint)(color[2] * 31.0f) & 0x1f << 10)  |
                 ((GLuint)(color[3] * 1)  & 0x01 << 15);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            color[src_color->alpha] = pixel.a;
            *d = ((GLushort)(color[3] * 15.0f) & 0x0f << 12) |
                 ((GLushort)(color[2] * 15.0f) & 0x0f << 8) |
                 ((GLushort)(color[1] * 15.0f) & 0x0f << 4) |
                 ((GLushort)(color[0] * 15.0f) & 0x0f);
        )
        default:
            printf("libGL: Unsupported target data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    return true;

    #undef transformf
    #undef type_case
    #undef default
    #undef carefully
    #undef read_each
    #undef write_each
}

static inline
bool half_pixel(const GLvoid *src0, const GLvoid *src1, 
                 const GLvoid *src2, const GLvoid *src3, 
                 GLvoid *dst, 
                 const colorlayout_t *src_color, GLenum src_type) {

    #define type_case(constant, type, ...)        \
        case constant: {                          \
            const type *s[4];                     \
            s[0] = (const type *)src0;            \
            s[1] = (const type *)src1;            \
            s[2] = (const type *)src2;            \
            s[3] = (const type *)src3;            \
            type *d = (type *)dst;                \
            type v[4];                            \
            v[0] = *s[0];                         \
            v[1] = *s[1];                         \
            v[2] = *s[2];                         \
            v[3] = *s[3];                         \
            __VA_ARGS__                           \
            break;                                \
        }

    #define default(arr, amod, vmod, key, def) \
        (amod key) >= 0 ? arr[amod key] vmod : def

    #define carefully(arr, amod, key, value) \
        if ((amod key) >= 0) d[amod key] = value;

    #define read_i_each(amod, vmod, i)                                   \
        pix[i].r = default(s[i], amod, vmod, src_color->red, 0.0f);      \
        pix[i].g = default(s[i], amod, vmod, src_color->green, 0.0f);    \
        pix[i].b = default(s[i], amod, vmod, src_color->blue, 0.0f);     \
        pix[i].a = default(s[i], amod, vmod, src_color->alpha, 1.0f);

    #define read_each(amod, vmod)   \
        read_i_each(amod, vmod, 0);   \
        read_i_each(amod, vmod, 1);   \
        read_i_each(amod, vmod, 2);   \
        read_i_each(amod, vmod, 3);

    #define write_each(amod, vmod)                         \
        carefully(d, amod, src_color->red, pixel.r vmod)   \
        carefully(d, amod, src_color->green, pixel.g vmod) \
        carefully(d, amod, src_color->blue, pixel.b vmod)  \
        carefully(d, amod, src_color->alpha, pixel.a vmod)

    // this pixel stores our intermediate color
    // it will be RGBA and normalized to between (0.0 - 1.0f)
    pixel_t pix[4], pixel;
    int max_a = src_color->red;
    if (src_color->green>max_a) max_a=src_color->green;
    if (src_color->blue>max_a) max_a=src_color->blue;
    if (src_color->alpha>max_a) max_a=src_color->alpha;
    switch (src_type) {
        type_case(GL_DOUBLE, GLdouble, read_each(,))
        type_case(GL_FLOAT, GLfloat, read_each(,))
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        type_case(GL_UNSIGNED_BYTE, GLubyte, read_each(, / 255.0f))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, read_each(max_a - , / 255.0f))
        type_case(GL_UNSIGNED_SHORT_1_5_5_5_REV, GLushort,
            for (int ii=0; ii<4; ii++) {
                s[ii] = (GLushort[]) {
                    (v[ii] & 31),
                    ((v[ii] & 0x03e0) >> 5),
                    ((v[ii] & 0x7c00) >> 10),
                    ((v[ii] & 0x8000) >> 15)*31,
                };
            };
            read_each(, / 31.0f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4_REV, GLushort,
            for (int ii=0; ii<4; ii++) {
                s[ii] = (GLushort[]) {
                    ((v[ii] & 0x000f)     ),
                    ((v[ii] & 0x00f0) >> 4),
                    ((v[ii] & 0x0f00) >> 8),
                    ((v[ii] & 0xf000) >>12)
                };
            };
            read_each(, / 15.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            for (int ii=0; ii<4; ii++) {
                s[ii] = (GLushort[]) {
                    ((v[ii] & 0x001f)     )*2,
                    ((v[ii] & 0x07e0) >> 5),
                    ((v[ii] & 0xF800) >>11)*2,
                };
            };
            read_each(, / 63.0f);
        )
        type_case(GL_UNSIGNED_SHORT_5_5_5_1, GLushort,
            for (int ii=0; ii<4; ii++) {
                s[ii] = (GLushort[]) {
                    ((v[ii] & 0xf800) >>11),
                    ((v[ii] & 0x07c0) >> 6),
                    ((v[ii] & 0x003e) >> 1),
                    ((v[ii] & 1)    )*31,
                };
            };
            read_each(, / 31.0f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            for (int ii=0; ii<4; ii++) {
                s[ii] = (GLushort[]) {
                    ((v[ii] & 0xf000) >>12),
                    ((v[ii] & 0x0f00) >> 8),
                    ((v[ii] & 0x00f0) >> 4),
                    ((v[ii] & 0x000f)     )
                };
            };
            read_each(, / 15.0f);
        )
        default:
            // TODO: add glSetError?
            printf("libGL: half_pixel: Unsupported source data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    pixel.r = (pix[0].r + pix[1].r + pix[2].r + pix[3].r) * 0.25f;
    pixel.g = (pix[0].g + pix[1].g + pix[2].g + pix[3].g) * 0.25f;
    pixel.b = (pix[0].b + pix[1].b + pix[2].b + pix[3].b) * 0.25f;
    pixel.a = (pix[0].a + pix[1].a + pix[2].a + pix[3].a) * 0.25f;

    switch (src_type) {
        type_case(GL_FLOAT, GLfloat, write_each(,))
        type_case(GL_UNSIGNED_BYTE, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8_REV, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, write_each(max_a - , * 255.0))
       // TODO: force 565 to RGB? then we can change [4] -> 3
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            *d = ((GLuint)(color[0] * 31.0f) & 0x1f << 11) |
                 ((GLuint)(color[1] * 63.0f) & 0x3f << 5) |
                 ((GLuint)(color[2] * 31.0f) & 0x1f);
        )
        type_case(GL_UNSIGNED_SHORT_5_5_5_1, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            color[src_color->alpha] = pixel.a;
            // TODO: can I macro this or something? it follows a pretty strict form.
            *d = ((GLuint)(color[0] * 31.0f) & 0x1f << 0) |
                 ((GLuint)(color[1] * 31.0f) & 0x1f << 5) |
                 ((GLuint)(color[2] * 31.0f) & 0x1f << 10)  |
                 ((GLuint)(color[3] * 1)  & 0x01 << 15);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            color[src_color->alpha] = pixel.a;
            *d = ((GLushort)(color[0] * 15.0f) & 0x0f << 12) |
                 ((GLushort)(color[1] * 15.0f) & 0x0f << 8) |
                 ((GLushort)(color[2] * 15.0f) & 0x0f << 4) |
                 ((GLushort)(color[3] * 15.0f) & 0x0f);
        )
        default:
            printf("libGL: half_pixel: Unsupported target data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    return true;

    #undef type_case
    #undef default
    #undef carefully
    #undef read_each
    #undef read_each_i
    #undef write_each
}


static inline
bool quarter_pixel(const GLvoid *src[16], 
                 GLvoid *dst, 
                 const colorlayout_t *src_color, GLenum src_type) {

    #define type_case(constant, type, ...)        \
        case constant: {                          \
            const type *s[16];                    \
            for (int aa=0; aa<16; aa++)           \
                s[aa] = (const type *)src[aa];    \
            type *d = (type *)dst;                \
            type v[16];                           \
            for (int aa=0; aa<16; aa++)           \
                v[aa] = *s[aa];                   \
            __VA_ARGS__                           \
            break;                                \
        }

    #define default(arr, amod, vmod, key, def) \
        (amod key) >= 0 ? arr[amod key] vmod : def

    #define carefully(arr, amod, key, value) \
        if ((amod key) >= 0) d[amod key] = value;

    #define read_i_each(amod, vmod, i)                                   \
        pix[i].r = default(s[i], amod, vmod, src_color->red, 0.0f);      \
        pix[i].g = default(s[i], amod, vmod, src_color->green, 0.0f);    \
        pix[i].b = default(s[i], amod, vmod, src_color->blue, 0.0f);     \
        pix[i].a = default(s[i], amod, vmod, src_color->alpha, 1.0f);

    #define read_each(amod, vmod)   \
        read_i_each(amod, vmod, 0);   \
        read_i_each(amod, vmod, 1);   \
        read_i_each(amod, vmod, 2);   \
        read_i_each(amod, vmod, 3);   \
        read_i_each(amod, vmod, 4);   \
        read_i_each(amod, vmod, 5);   \
        read_i_each(amod, vmod, 6);   \
        read_i_each(amod, vmod, 7);   \
        read_i_each(amod, vmod, 8);   \
        read_i_each(amod, vmod, 9);   \
        read_i_each(amod, vmod,10);   \
        read_i_each(amod, vmod,11);   \
        read_i_each(amod, vmod,12);   \
        read_i_each(amod, vmod,13);   \
        read_i_each(amod, vmod,14);   \
        read_i_each(amod, vmod,15);   \

    #define write_each(amod, vmod)                         \
        carefully(d, amod, src_color->red, pixel.r vmod)   \
        carefully(d, amod, src_color->green, pixel.g vmod) \
        carefully(d, amod, src_color->blue, pixel.b vmod)  \
        carefully(d, amod, src_color->alpha, pixel.a vmod)

    // this pixel stores our intermediate color
    // it will be RGBA and normalized to between (0.0 - 1.0f)
    pixel_t pix[16], pixel;
    int max_a = src_color->red;
    if (src_color->green>max_a) max_a=src_color->green;
    if (src_color->blue>max_a) max_a=src_color->blue;
    if (src_color->alpha>max_a) max_a=src_color->alpha;
    switch (src_type) {
        type_case(GL_DOUBLE, GLdouble, read_each(,))
        type_case(GL_FLOAT, GLfloat, read_each(,))
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        type_case(GL_UNSIGNED_BYTE, GLubyte, read_each(, / 255.0f))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, read_each(max_a - , / 255.0f))
        type_case(GL_UNSIGNED_SHORT_1_5_5_5_REV, GLushort,
            for (int ii=0; ii<16; ii++) {
                s[ii] = (GLushort[]) {
                    (v[ii] & 31),
                    ((v[ii] & 0x03e0) >> 5),
                    ((v[ii] & 0x7c00) >> 10),
                    ((v[ii] & 0x8000) >> 15)*31,
                };
            };
            read_each(, / 31.0f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            for (int ii=0; ii<16; ii++) {
                s[ii] = (GLushort[]) {
                    (v[ii] & 0x000f),
                    ((v[ii] & 0x00f0) >> 4),
                    ((v[ii] & 0x0f00) >> 8),
                    ((v[ii] & 0xf000) >> 12)
                };
            };
            read_each(, / 15.0f);
        )
        default:
            // TODO: add glSetError?
            printf("libGL: quarter_pixel: Unsupported source data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    pixel.r = (pix[0].r + pix[1].r + pix[2].r + pix[3].r + pix[4].r + pix[5].r + pix[6].r + pix[7].r + pix[8].r + pix[9].r + pix[10].r + pix[11].r + pix[12].r + pix[13].r + pix[14].r + pix[15].r) * 0.0625f;
    pixel.g = (pix[0].g + pix[1].g + pix[2].g + pix[3].g + pix[4].g + pix[5].g + pix[6].g + pix[7].g + pix[8].g + pix[9].g + pix[10].g + pix[11].g + pix[12].g + pix[13].g + pix[14].g + pix[15].g) * 0.0625f;
    pixel.b = (pix[0].b + pix[1].b + pix[2].b + pix[3].b + pix[4].b + pix[5].b + pix[6].b + pix[7].b + pix[8].b + pix[9].b + pix[10].b + pix[11].b + pix[12].b + pix[13].b + pix[14].b + pix[15].b) * 0.0625f;
    pixel.a = (pix[0].a + pix[1].a + pix[2].a + pix[3].a + pix[4].a + pix[5].a + pix[6].a + pix[7].a + pix[8].a + pix[9].a + pix[10].a + pix[11].a + pix[12].a + pix[13].a + pix[14].a + pix[15].a) * 0.0625f;

    switch (src_type) {
        type_case(GL_FLOAT, GLfloat, write_each(,))
        type_case(GL_UNSIGNED_BYTE, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8_REV, GLubyte, write_each(, * 255.0))
        type_case(GL_UNSIGNED_INT_8_8_8_8, GLubyte, write_each(max_a - , * 255.0))
       // TODO: force 565 to RGB? then we can change [4] -> 3
        type_case(GL_UNSIGNED_SHORT_5_6_5, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            *d = ((GLuint)(color[0] * 31) & 0x1f << 11) |
                 ((GLuint)(color[1] * 63) & 0x3f << 5) |
                 ((GLuint)(color[2] * 31) & 0x1f);
        )
        type_case(GL_UNSIGNED_SHORT_4_4_4_4, GLushort,
            GLfloat color[4];
            color[src_color->red] = pixel.r;
            color[src_color->green] = pixel.g;
            color[src_color->blue] = pixel.b;
            color[src_color->alpha] = pixel.a;
            *d = ((GLushort)(color[0] * 15.0) & 0x0f << 12) |
                 ((GLushort)(color[1] * 15.0) & 0x0f << 8) |
                 ((GLushort)(color[2] * 15.0) & 0x0f << 4) |
                 ((GLushort)(color[3] * 15.0) & 0x0f);
        )
        default:
            printf("libGL: quarter_pixel Unsupported target data type: %s\n", PrintEnum(src_type));
            return false;
            break;
    }
    return true;

    #undef type_case
    #undef default
    #undef carefully
    #undef read_each
    #undef read_each_i
    #undef write_each
}

bool pixel_convert(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   GLenum dst_format, GLenum dst_type, GLuint stride) {
    const colorlayout_t *src_color, *dst_color;
    GLuint pixels = width * height;
    GLuint dst_size = pixels * pixel_sizeof(dst_format, dst_type);
    GLuint dst_width = ((stride?stride:width) - width) * pixel_sizeof(dst_format, dst_type);
    GLuint src_width = width * pixel_sizeof(src_format, src_type);

    //printf("pixel conversion: %ix%i - %s, %s (%d) ==> %s, %s (%d), transform=%i\n", width, height, PrintEnum(src_format), PrintEnum(src_type),pixel_sizeof(src_format, src_type), PrintEnum(dst_format), PrintEnum(dst_type), pixel_sizeof(dst_format, dst_type), raster_need_transform());
    src_color = get_color_map(src_format);
    dst_color = get_color_map(dst_format);
    if (!dst_size || !pixel_sizeof(src_format, src_type)
        || !src_color->type || !dst_color->type) {
        printf("pixel conversion, anticipated abort\n");
        return false;
    }

    if ((src_type == dst_type) && (src_color->type == dst_color->type)) {
        if (*dst == src)
            return true;
        if (*dst == NULL)        // alloc dst only if dst==NULL
            *dst = malloc(dst_size);
        if (stride)	// for in-place conversion
			for (int yy=0; yy<height; yy++)
				memcpy((*dst)+yy*(dst_width+src_width), src+yy*src_width, src_width);
        else
			memcpy(*dst, src, dst_size);
        return true;
    }
    GLsizei src_stride = pixel_sizeof(src_format, src_type);
    GLsizei dst_stride = pixel_sizeof(dst_format, dst_type);
    if (*dst == src || *dst == NULL)
        *dst = malloc(dst_size);
    uintptr_t src_pos = (uintptr_t)src;
    uintptr_t dst_pos = (uintptr_t)*dst;
    // fast optimized loop for common conversion cases first...
    if ((src_format == GL_BGRA) && (dst_format == GL_RGBA) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        GLuint tmp;
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				tmp = *(const GLuint*)src_pos;
				*(GLuint*)dst_pos = (tmp&0xff00ff00) | ((tmp&0x00ff0000)>>16) | ((tmp&0x000000ff)<<16);
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_RGBA) && (dst_format == GL_LUMINANCE_ALPHA) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        GLuint tmp;
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//tmp = *(const GLuint*)src_pos;
                unsigned char* byte_src = (unsigned char*)src_pos;
                *(GLushort*)dst_pos = ((((int)byte_src[0])*77 + ((int)byte_src[1])*151 + ((int)byte_src[2])*28)&0xff00)>>8 | (byte_src[3]<<8);
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_BGRA) && (dst_format == GL_LUMINANCE_ALPHA) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        GLuint tmp;
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//tmp = *(const GLuint*)src_pos;
                unsigned char* byte_src = (unsigned char*)src_pos;
                *(GLushort*)dst_pos = ((((int)byte_src[2])*77 + ((int)byte_src[1])*151 + ((int)byte_src[0])*28)&0xff00)>>8 | (byte_src[3]<<8);
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if (((src_format == GL_RGBA)||(src_format == GL_RGB)) && (dst_format == GL_LUMINANCE) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        GLuint tmp;
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//tmp = *(const GLuint*)src_pos;
                unsigned char* byte_src = (unsigned char*)src_pos;
                *(unsigned char*)dst_pos = (((int)byte_src[0])*77 + ((int)byte_src[1])*151 + ((int)byte_src[2])*28)>>8;
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if (((src_format == GL_BGRA)||(src_format == GL_BGR)) && (dst_format == GL_LUMINANCE) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        GLuint tmp;
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//tmp = *(const GLuint*)src_pos;
                unsigned char* byte_src = (unsigned char*)src_pos;
                *(unsigned char*)dst_pos = (((int)byte_src[2])*77 + ((int)byte_src[1])*151 + ((int)byte_src[0])*28)>>8;
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if (((src_format == GL_BGR)||(src_format == GL_BGRA)) && (dst_format == GL_RGB) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				((char*)dst_pos)[0] = ((char*)src_pos)[2];
				((char*)dst_pos)[1] = ((char*)src_pos)[1];
				((char*)dst_pos)[2] = ((char*)src_pos)[0];
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_RGBA) && (dst_format == GL_RGB) && (dst_type == GL_UNSIGNED_BYTE) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				((char*)dst_pos)[0] = ((char*)src_pos)[0];
				((char*)dst_pos)[1] = ((char*)src_pos)[1];
				((char*)dst_pos)[2] = ((char*)src_pos)[2];
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if (((src_format == GL_RGB)||(src_format == GL_RGBA)) && (dst_format == GL_RGB) && (dst_type == GL_UNSIGNED_SHORT_5_6_5) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				*(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[2]&0xf8)>>(3)) | ((GLushort)(((char*)src_pos)[1]&0xfc)<<(5-2)) | ((GLushort)(((char*)src_pos)[0]&0xf8)<<(11-3));
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if (((src_format == GL_BGR) || (src_format == GL_BGRA)) && (dst_format == GL_RGB) && (dst_type == GL_UNSIGNED_SHORT_5_6_5) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				*(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[0]&0xf8)>>(3)) | ((GLushort)(((char*)src_pos)[1]&0xfc)<<(5-2)) | ((GLushort)(((char*)src_pos)[2]&0xf8)<<(11-3));
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_RGBA) && (dst_format == GL_RGBA) && (dst_type == GL_UNSIGNED_SHORT_5_5_5_1) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				*(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[2]&0xf8)>>(3-1)) | ((GLushort)(((char*)src_pos)[1]&0xf8)<<(5-2)) | ((GLushort)(((char*)src_pos)[0]&0xf8)<<(10-2)) | ((GLushort)(((char*)src_pos)[3])>>15);
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_BGRA) && (dst_format == GL_RGBA) && (dst_type == GL_UNSIGNED_SHORT_5_5_5_1) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				*(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[0]&0xf8)>>(3-1)) | ((GLushort)(((char*)src_pos)[1]&0xf8)<<(5-2)) | ((GLushort)(((char*)src_pos)[2]&0xf8)<<(10-2)) | ((GLushort)(((char*)src_pos)[3])>>15);
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_RGBA) && (dst_format == GL_RGBA) && (dst_type == GL_UNSIGNED_SHORT_4_4_4_4) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				*(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[3]&0xf0))>>(4) | ((GLushort)(((char*)src_pos)[2]&0xf0)) | ((GLushort)(((char*)src_pos)[1]&0xf0))<<(4) | ((GLushort)(((char*)src_pos)[0]&0xf0))<<(8);
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
    if ((src_format == GL_BGRA) && (dst_format == GL_RGBA) && (dst_type == GL_UNSIGNED_SHORT_4_4_4_4) && ((src_type == GL_UNSIGNED_BYTE)||(src_type == GL_UNSIGNED_INT_8_8_8_8_REV))) {
        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				*(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[3]&0xf0)>>(4)) | ((GLushort)(((char*)src_pos)[0]&0xf0)) | ((GLushort)(((char*)src_pos)[1]&0xf0)<<(4)) | ((GLushort)(((char*)src_pos)[2]&0xf0)<<(8));
				src_pos += src_stride;
				dst_pos += dst_stride;
			}
			if (stride)
				dst_pos += dst_width;
        }
        return true;
    }
	if (! remap_pixel((const GLvoid *)src_pos, (GLvoid *)dst_pos, 
					  src_color, src_type, dst_color, dst_type)) {
		// fake convert, to get if it's ok or not
		return false;
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			remap_pixel((const GLvoid *)src_pos, (GLvoid *)dst_pos, 
							  src_color, src_type, dst_color, dst_type);
			src_pos += src_stride;
			dst_pos += dst_stride;
		}
		if (stride)
			dst_pos += dst_width;
	}
	return true;
}

bool pixel_transform(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   const GLfloat *scales, const GLfloat *bias)
{
    const colorlayout_t *src_color;
    GLuint pixels = width * height;
    GLuint dst_size = pixels * pixel_sizeof(src_format, src_type);
    src_color = get_color_map(src_format);
    GLsizei src_stride = pixel_sizeof(src_format, src_type);
    if (*dst == src || *dst == NULL)
        *dst = malloc(dst_size);
    uintptr_t src_pos = (uintptr_t)src;
    uintptr_t dst_pos = (uintptr_t)*dst;
	if (! transform_pixel((const GLvoid *)src_pos, (GLvoid *)dst_pos,
					  src_color, src_type, scales, bias)) {
		// fake convert, to get if it's ok or not
		return false;
	}
    for (int aa=0; aa<dst_size; aa++) {
        for (int i = 0; i < pixels; i++) {
            transform_pixel((const GLvoid *)src_pos, (GLvoid *)dst_pos,
                              src_color, src_type, scales, bias);
            src_pos += src_stride;
            dst_pos += src_stride;
        }
        return true;
    }
    return false;
}

bool pixel_scale(const GLvoid *old, GLvoid **new,
                 GLuint width, GLuint height,
                 GLfloat ratio,
                 GLenum format, GLenum type) {
    GLuint pixel_size, new_width, new_height;
    new_width = width * ratio;
    new_height = height * ratio;
    printf("scaling %ux%u -> %ux%u\n", width, height, new_width, new_height);
    GLvoid *dst;
    uintptr_t src, pos, pixel;

    pixel_size = pixel_sizeof(format, type);
    dst = malloc(pixel_size * new_width * new_height);
    src = (uintptr_t)old;
    pos = (uintptr_t)dst;
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            pixel = src + ((x / ratio) +
                          (y / ratio) * width) * pixel_size;
            memcpy((GLvoid *)pos, (GLvoid *)pixel, pixel_size);
            pos += pixel_size;
        }
    }
    *new = dst;
    return true;
}

bool pixel_halfscale(const GLvoid *old, GLvoid **new,
                 GLuint width, GLuint height,
                 GLenum format, GLenum type) {
    GLuint pixel_size, new_width, new_height;
    new_width = width / 2; if(new_width==0) new_width=1;
    new_height = height / 2; if(new_height==0) new_height==1;
/*    if (new_width*2!=width || new_height*2!=height) {
        printf("LIBGL: halfscaling %ux%u failed\n", width, height);
        return false;
    }*/
//    printf("LIBGL: halfscaling %ux%u -> %ux%u\n", width, height, new_width, new_height);
    const colorlayout_t *src_color;
    src_color = get_color_map(format);
    GLvoid *dst;
    uintptr_t src, pos, pix0, pix1, pix2, pix3;

    pixel_size = pixel_sizeof(format, type);
    dst = malloc(pixel_size * new_width * new_height);
    src = (uintptr_t)old;
    pos = (uintptr_t)dst;
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            pix0 = src + ((x * 2) +
                          (y * 2) * width) * pixel_size;
            pix1 = src + ((x * 2 + 1) +
                          (y * 2) * width) * pixel_size;
            pix2 = src + ((x * 2) +
                          (y * 2 + 1) * width) * pixel_size;
            pix3 = src + ((x * 2 + 1) +
                          (y * 2 + 1) * width) * pixel_size;
            half_pixel((GLvoid *)pix0, (GLvoid *)pix1, (GLvoid *)pix2, (GLvoid *)pix3, (GLvoid *)pos, src_color, type);
            pos += pixel_size;
        }
    }
    *new = dst;
    return true;
}

bool pixel_thirdscale(const GLvoid *old, GLvoid **new,
                 GLuint width, GLuint height,
                 GLenum format, GLenum type) {
    GLuint pixel_size, new_width, new_height, dest_size;
    new_width = width / 2;
    new_height = height / 2;
    if (new_width*2!=width || new_height*2!=height || format!=GL_RGBA || type!=GL_UNSIGNED_BYTE) {
        //printf("LIBGL: thirdscaling %ux%u failed\n", width, height);
        return false;
    }
//    printf("LIBGL: halfscaling %ux%u -> %ux%u\n", width, height, new_width, new_height);
    const colorlayout_t *src_color;
    src_color = get_color_map(format);
    GLvoid *dst;
    uintptr_t src, pos, pix0, pix1, pix2, pix3;

    pixel_size = pixel_sizeof(format, type);
    dest_size = pixel_sizeof(format, GL_UNSIGNED_SHORT_4_4_4_4);
    dst = malloc(dest_size * new_width * new_height);
    src = (uintptr_t)old;
    pos = (uintptr_t)dst;
    GLubyte tmp[4];
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            pix0 = src + ((x * 2) +
                          (y * 2) * width) * pixel_size;
            pix1 = src + ((x * 2 + 1) +
                          (y * 2) * width) * pixel_size;
            pix2 = src + ((x * 2) +
                          (y * 2 + 1) * width) * pixel_size;
            pix3 = src + ((x * 2 + 1) +
                          (y * 2 + 1) * width) * pixel_size;
            half_pixel((GLvoid *)pix0, (GLvoid *)pix1, (GLvoid *)pix2, (GLvoid *)pix3, (GLvoid *)tmp, src_color, type);
            *((GLushort*)pos) = (((GLushort)tmp[0])&0xf0)<<8 | (((GLushort)tmp[1])&0xf0)<<4 | (((GLushort)tmp[2])&0xf0) | (((GLushort)tmp[3])>>4);
            pos += dest_size;
        }
    }
    *new = dst;
    return true;
}

bool pixel_quarterscale(const GLvoid *old, GLvoid **new,
                 GLuint width, GLuint height,
                 GLenum format, GLenum type) {
    GLuint pixel_size, new_width, new_height;
    new_width = width / 4;
    new_height = height / 4;
/*    if (new_width*4!=width || new_height*4!=height) {
        printf("LIBGL: quarterscaling %ux%u failed\n", width, height);
        return false;
    }*/
//    printf("LIBGL: quarterscaling %ux%u -> %ux%u\n", width, height, new_width, new_height);
    const colorlayout_t *src_color;
    src_color = get_color_map(format);
    GLvoid *dst;
    uintptr_t src, pos, pix[16];

    pixel_size = pixel_sizeof(format, type);
    dst = malloc(pixel_size * new_width * new_height);
    src = (uintptr_t)old;
    pos = (uintptr_t)dst;
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            for (int dx=0; dx<4; dx++) {
                for (int dy=0; dy<4; dy++) {
                    pix[dx+dy*4] = src + ((x * 4 + dx) +
                                          (y * 4 + dy) * width) * pixel_size;
                }
            }
            quarter_pixel((const GLvoid **)pix, (GLvoid *)pos, src_color, type);
            pos += pixel_size;
        }
    }
    *new = dst;
    return true;
}

bool pixel_to_ppm(const GLvoid *pixels, GLuint width, GLuint height,
                  GLenum format, GLenum type, GLuint name) {
    if (! pixels)
        return false;

    GLvoid *src=0;
    char filename[64];
    int size = /*4 * */3 * width * height;
    if (format == GL_RGB && type == GL_UNSIGNED_BYTE) {
        src = (GLvoid*)pixels;
    } else {
        if (! pixel_convert(pixels, (GLvoid **)&src, width, height, format, type, GL_RGB, GL_UNSIGNED_BYTE, 0)) {
            return false;
        }
    }

    snprintf(filename, 64, "/tmp/tex.%d.ppm", name);
    FILE *fd = fopen(filename, "w");
    fprintf(fd, "P6 %d %d %d\n", width, height, 255);
    fwrite(src, 1, size, fd);
    fclose(fd);
    return true;
}
