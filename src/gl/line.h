#ifndef _GL4ES_LINE_H
#define _GL4ES_LINE_H

#include "gles.h"
#include "list.h"

#ifndef GL4ES_EMULATED_LINE_WIDTH_MAX
#define GL4ES_EMULATED_LINE_WIDTH_MAX 64.0f
#endif

/* gl4es_draw_wide_lines: FALLBACK = caller should native-draw;
 * HANDLED = drew the quads, or there is nothing to draw. */
#define GL4ES_WIDE_FALLBACK 0
#define GL4ES_WIDE_HANDLED  1

void APIENTRY_GL4ES gl4es_glLineStipple(GLuint factor, GLushort pattern);
GLfloat *gen_stipple_tex_coords(GLfloat *vert, GLushort *sindices, modeinit_t *modes, int stride, int length, GLfloat* noalloctex);
void bind_stipple_tex();

int gl4es_wide_lines_needed(void);
int gl4es_draw_wide_lines(
    GLenum mode,
    const GLfloat *vert, int vert_stride,
    const GLfloat *color, int color_stride,
    const GLfloat *secondary, int secondary_stride,
    const GLfloat *fogcoord, int fogcoord_stride,
    const GLfloat *normal, int normal_stride,
    GLfloat * const *tex, const int *tex_stride, int maxtex,
    const GLushort *indices, int count,
    int from_polygon_mode, int instance_count);

#endif // _GL4ES_LINE_H
