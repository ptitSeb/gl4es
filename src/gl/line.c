#include "line.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../glx/hardext.h"
#include "buffers.h"
#include "debug.h"
#include "fpe.h"
#include "gl4es.h"
#include "glstate.h"
#include "list.h"
#include "loader.h"
#include "matrix.h"
#include "matvec.h"
#include "texture.h"
#include "wrap/gl4es.h"


//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

void APIENTRY_GL4ES gl4es_glLineStipple(GLuint factor, GLushort pattern) {
    DBG(printf("glLineStipple(%d, 0x%04X)\n", factor, pattern);)
    if(glstate->list.active) {
        if (glstate->list.compiling) {
            NewStage(glstate->list.active, STAGE_LINESTIPPLE);
            glstate->list.active->linestipple_op = 1;
            glstate->list.active->linestipple_factor = factor;
            glstate->list.active->linestipple_pattern = pattern;
            return;
        } else gl4es_flush();
    }
    if(factor<1) factor = 1;
    if(factor>256) factor = 256;
    if(pattern!=glstate->linestipple.pattern || factor!=glstate->linestipple.factor || !glstate->linestipple.texture) {
        glstate->linestipple.factor = factor;
        glstate->linestipple.pattern = pattern;
        for (int i = 0; i < 16; i++) {
            glstate->linestipple.data[i] = ((pattern >> i) & 1) ? 255 : 0;
        }

        // "Push" current Texture0 binding
        GLuint old_act = glstate->texture.active;
        if(old_act)
            gl4es_glActiveTexture(GL_TEXTURE0);
        GLuint old_tex = glstate->texture.bound[0][ENABLED_TEX2D]->texture;
        // create / update stipple texture
        if (! glstate->linestipple.texture) {
            gl4es_glGenTextures(1, &glstate->linestipple.texture);
            gl4es_glBindTexture(GL_TEXTURE_2D, glstate->linestipple.texture);
            gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            gl4es_glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA,
                16, 1, 0, GL_ALPHA, GL_UNSIGNED_BYTE, glstate->linestipple.data);
        } else {
            gl4es_glBindTexture(GL_TEXTURE_2D, glstate->linestipple.texture);
            gl4es_glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 16, 1, 
                GL_ALPHA, GL_UNSIGNED_BYTE, glstate->linestipple.data);
        }
        // "Pop" texture 0 binding
        gl4es_glBindTexture(GL_TEXTURE_2D, old_tex);
        if(old_act)
            gl4es_glActiveTexture(GL_TEXTURE0+old_act);
        // all done
        noerrorShim();
    }
}
AliasExport(void,glLineStipple,,(GLuint factor, GLushort pattern));

void bind_stipple_tex() {
    gl4es_glBindTexture(GL_TEXTURE_2D, glstate->linestipple.texture);
}

GLfloat *gen_stipple_tex_coords(GLfloat *vert, GLushort *sindices, modeinit_t *modes, int stride, int length, GLfloat* noalloctex) {
    DBG(printf("Generate stripple tex (stride=%d, noalloctex=%p) length=%d:", stride, noalloctex, length);)
    // generate our texture coords
    GLfloat *tex = noalloctex?noalloctex:(GLfloat *)malloc(modes[length-1].ilen * 4 * sizeof(GLfloat));
    GLfloat *texPos = tex;
    GLfloat *vertPos = vert;

    GLfloat x1, x2, y1, y2;
    GLfloat oldlen, len;
    const GLfloat* mvp = getMVPMat();
    GLfloat v[4];
    GLfloat w = (GLfloat)glstate->raster.viewport.width;
    GLfloat h = (GLfloat)glstate->raster.viewport.height;
    if(stride==0) stride = 4; else stride/=sizeof(GLfloat);
    int texstride = noalloctex?stride:4;
    // projected coordinates here, and transform to screen pixel using viewport
    // because projected coordinates are from -1. to +1., w and h are to be divided by 2...
    w*=0.5f; h*=0.5f;
    int i=0;
    for (int k=0; k<length; k++) {
        GLenum mode = modes[k].mode_init;
        DBG(printf("[%s->%d] ", PrintEnum(mode), modes[k].ilen);)
        oldlen = len = 0.f;
        if(modes[k].ilen<2)
            continue;
        if(mode==GL_LINES || length>1)  // always line when multiple lines were merged
            for (; i < modes[k].ilen; i+=2) {
                if(sindices)
                    vertPos = vert+stride*sindices[i];
                vector_matrix(vertPos, mvp, v);
                if(sindices)
                    vertPos = vert+stride*sindices[i+1];
                else
                    vertPos+=stride;
                // need to take "w" component into account...
                if(v[3]==0.0f) {
                    x1=v[0]*w; y1=v[1]*h;
                } else {
                    x1=(v[0]/v[3])*w; y1=(v[1]/v[3])*h;
                }
                vector_matrix(vertPos, mvp, v);
                vertPos+=stride;
                if(v[3]==0.0f) {
                    x2=v[0]*w; y2=v[1]*h;
                } else {
                    x2=(v[0]/v[3])*w; y2=(v[1]/v[3])*h;
                }
                oldlen = len;
                len += sqrtf((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) / (glstate->linestipple.factor * 16.f);
                DBG(printf("%f->%f (%f,%f -> %f,%f)\t", oldlen, len, x1, y1, x2, y2);)
                if(sindices)
                    texPos = tex+texstride*sindices[i+0];   // it gets written 2*, but that should be ok, it's the same value
                memset(texPos, 0, 4*sizeof(GLfloat));
                texPos[0] = oldlen; texPos[3] = 1.0f;
                if(sindices)
                    texPos = tex+texstride*sindices[i+1];
                else
                    texPos+=texstride;
                memset(texPos, 0, 4*sizeof(GLfloat));
                texPos[0] = len; texPos[3] = 1.0f;
                texPos+=texstride;
            }
        else { // GL_LINE_STRIP and GL_LINE_LOOPS works the same here 
                // (well, last segment, the "loop" one, will look strange, but I will not add a vertex for that)
            if(sindices)
                vertPos = vert+stride*sindices[i];
            vector_matrix(vertPos, mvp, v);
            x2=(v[0]/v[3])*w; y2=(v[1]/v[3])*h;
            vertPos+=stride;
            DBG(printf("%f\t", len);)
            memset(texPos, 0, 4*sizeof(GLfloat));
            texPos[0] = len; texPos[3] = 1.0f;
            texPos+=texstride;
            ++i;
            for (; i < modes[k].ilen; i++) {
                x1 = x2; y1 = y2;
                if(sindices)
                    vertPos = vert+stride*sindices[i];
                vector_matrix(vertPos, mvp, v);
                vertPos+=stride;
                x2=(v[0]/v[3])*w; y2=(v[1]/v[3])*h;
                len += sqrtf((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) / (glstate->linestipple.factor * 16.f);
                DBG(printf("->%f\t", len);)
                if(sindices)
                    texPos = tex+texstride*sindices[i];
                memset(texPos, 0, 4*sizeof(GLfloat));
                texPos[0] = len; texPos[3] = 1.0f;
                texPos+=texstride;
            }
        }
    }
    DBG(printf("\n");)
    return tex;
}

int gl4es_wide_lines_needed(void)
{
    gl4es_probe_line_width_and_depth();
    int maxw = hardext.maxlinewidth;
    if (maxw < 1)
        maxw = 1;
    if (glstate->line_width <= (GLfloat)maxw)
        return 0;
    /* raster.viewport is 0 until the first glViewport. Treating that
     * as 1 px makes Δndc = width and fills the clip volume. */
    if (glstate->raster.viewport.width < 1 ||
            glstate->raster.viewport.height < 1)
        return 0;
    for (int i = 0; i < hardext.maxplanes; i++)
        if (glstate->enable.plane[i])
            return 0;
    return 1;
}

typedef struct {
    GLfloat clip[4];
    GLfloat color[4];
    GLfloat secondary[4];
    GLfloat fog;
    GLfloat normal[3];
    GLfloat tex[MAX_TEX][4];
} wide_end_t;

typedef struct {
    GLfloat *vert;
    GLfloat *color;
    GLfloat *secondary;
    GLfloat *fogcoord;
    GLfloat *normal;
    GLfloat *tex[MAX_TEX];
    int cap;
} wide_bufs_t;

static wide_bufs_t g_wide;

static int wide_realloc(GLfloat **slot, size_t nfloats)
{
    GLfloat *p = (GLfloat *)realloc(*slot, nfloats * sizeof(GLfloat));
    if (!p)
        return 0;
    *slot = p;
    return 1;
}

static int wide_ensure(int nverts, int have_color, int have_secondary,
                       int have_fog, int have_normal, int have_tex_mask)
{
    int ncap = g_wide.cap;
    if (ncap < nverts) {
        ncap = ncap ? ncap : 64;
        while (ncap < nverts) {
            if (ncap > (1 << 28) / 2)
                return 0;
            ncap *= 2;
        }
    }
    if (ncap != g_wide.cap) {
        if (!wide_realloc(&g_wide.vert, (size_t)ncap * 4))
            return 0;
        if (g_wide.color && !wide_realloc(&g_wide.color, (size_t)ncap * 4))
            return 0;
        if (g_wide.secondary && !wide_realloc(&g_wide.secondary, (size_t)ncap * 4))
            return 0;
        if (g_wide.fogcoord && !wide_realloc(&g_wide.fogcoord, (size_t)ncap))
            return 0;
        if (g_wide.normal && !wide_realloc(&g_wide.normal, (size_t)ncap * 3))
            return 0;
        for (int a = 0; a < MAX_TEX; a++) {
            if (g_wide.tex[a] &&
                    !wide_realloc(&g_wide.tex[a], (size_t)ncap * 4))
                return 0;
        }
        g_wide.cap = ncap;
    }
    if (g_wide.cap < 1)
        return 0;
    if (have_color && !g_wide.color &&
            !wide_realloc(&g_wide.color, (size_t)g_wide.cap * 4))
        return 0;
    if (have_secondary && !g_wide.secondary &&
            !wide_realloc(&g_wide.secondary, (size_t)g_wide.cap * 4))
        return 0;
    if (have_fog && !g_wide.fogcoord &&
            !wide_realloc(&g_wide.fogcoord, (size_t)g_wide.cap))
        return 0;
    if (have_normal && !g_wide.normal &&
            !wide_realloc(&g_wide.normal, (size_t)g_wide.cap * 3))
        return 0;
    for (int a = 0; a < MAX_TEX; a++) {
        if ((have_tex_mask & (1 << a)) && !g_wide.tex[a] &&
                !wide_realloc(&g_wide.tex[a], (size_t)g_wide.cap * 4))
            return 0;
    }
    return 1;
}

static const GLfloat *wide_at(const GLfloat *base, int stride, int components, int i)
{
    if (!base)
        return NULL;
    if (!stride)
        stride = components * (int)sizeof(GLfloat);
    return (const GLfloat *)((const char *)base + (size_t)i * (size_t)stride);
}

static void wide_load_end(wide_end_t *e, int src,
                          const GLfloat *vert, int vert_stride,
                          const GLfloat *color, int color_stride,
                          const GLfloat *secondary, int secondary_stride,
                          const GLfloat *fogcoord, int fogcoord_stride,
                          const GLfloat *normal, int normal_stride,
                          GLfloat * const *tex, const int *tex_stride, int maxtex)
{
    const GLfloat *p = wide_at(vert, vert_stride, 4, src);
    const GLfloat *mvp = getMVPMat();
    vector_matrix(p, mvp, e->clip);
    if (color) {
        const GLfloat *c = wide_at(color, color_stride, 4, src);
        memcpy(e->color, c, 4 * sizeof(GLfloat));
    }
    if (secondary) {
        const GLfloat *c = wide_at(secondary, secondary_stride, 4, src);
        memcpy(e->secondary, c, 4 * sizeof(GLfloat));
    }
    if (fogcoord) {
        const GLfloat *c = wide_at(fogcoord, fogcoord_stride, 1, src);
        e->fog = c[0];
    }
    if (normal) {
        const GLfloat *c = wide_at(normal, normal_stride, 3, src);
        memcpy(e->normal, c, 3 * sizeof(GLfloat));
    }
    for (int a = 0; a < maxtex; a++) {
        if (tex && tex[a]) {
            int ts = tex_stride ? tex_stride[a] : 0;
            const GLfloat *c = wide_at(tex[a], ts, 4, src);
            memcpy(e->tex[a], c, 4 * sizeof(GLfloat));
        }
    }
}

static void wide_lerp_end(wide_end_t *d, const wide_end_t *e0, const wide_end_t *e1,
                          GLfloat t, int have_color, int have_secondary,
                          int have_fog, int have_normal, int maxtex,
                          GLfloat * const *tex)
{
    int k;
    for (k = 0; k < 4; k++)
        d->clip[k] = e0->clip[k] + t * (e1->clip[k] - e0->clip[k]);
    if (have_color)
        for (k = 0; k < 4; k++)
            d->color[k] = e0->color[k] + t * (e1->color[k] - e0->color[k]);
    if (have_secondary)
        for (k = 0; k < 4; k++)
            d->secondary[k] = e0->secondary[k] + t * (e1->secondary[k] - e0->secondary[k]);
    if (have_fog)
        d->fog = e0->fog + t * (e1->fog - e0->fog);
    if (have_normal)
        for (k = 0; k < 3; k++)
            d->normal[k] = e0->normal[k] + t * (e1->normal[k] - e0->normal[k]);
    for (int u = 0; u < maxtex; u++) {
        if (tex && tex[u])
            for (k = 0; k < 4; k++)
                d->tex[u][k] = e0->tex[u][k] + t * (e1->tex[u][k] - e0->tex[u][k]);
    }
}

static void wide_emit_corner(int dst, const wide_end_t *e,
                             GLfloat ndc_x, GLfloat ndc_y,
                             int have_color, int have_secondary,
                             int have_fog, int have_normal, int maxtex,
                             GLfloat * const *tex)
{
    g_wide.vert[dst * 4 + 0] = ndc_x * e->clip[3];
    g_wide.vert[dst * 4 + 1] = ndc_y * e->clip[3];
    g_wide.vert[dst * 4 + 2] = e->clip[2];
    g_wide.vert[dst * 4 + 3] = e->clip[3];
    if (have_color && g_wide.color)
        memcpy(g_wide.color + dst * 4, e->color, 4 * sizeof(GLfloat));
    if (have_secondary && g_wide.secondary)
        memcpy(g_wide.secondary + dst * 4, e->secondary, 4 * sizeof(GLfloat));
    if (have_fog && g_wide.fogcoord)
        g_wide.fogcoord[dst] = e->fog;
    if (have_normal && g_wide.normal)
        memcpy(g_wide.normal + dst * 3, e->normal, 3 * sizeof(GLfloat));
    for (int a = 0; a < maxtex; a++) {
        if (tex && tex[a] && g_wide.tex[a])
            memcpy(g_wide.tex[a] + dst * 4, e->tex[a], 4 * sizeof(GLfloat));
    }
}

static int wide_emit_segment(int dst, wide_end_t e0, wide_end_t e1,
                             GLfloat width, GLfloat vp_w, GLfloat vp_h,
                             int have_color, int have_secondary,
                             int have_fog, int have_normal, int maxtex,
                             GLfloat * const *tex)
{
    GLfloat zw0 = e0.clip[2] + e0.clip[3];
    GLfloat zw1 = e1.clip[2] + e1.clip[3];
    if (zw0 < 0.f && zw1 < 0.f)
        return dst;
    if (zw0 < 0.f || zw1 < 0.f) {
        GLfloat den = zw1 - zw0;
        if (den == 0.f)
            return dst;
        GLfloat t = -zw0 / den;
        wide_end_t mid;
        wide_lerp_end(&mid, &e0, &e1, t, have_color, have_secondary,
                      have_fog, have_normal, maxtex, tex);
        if (zw0 < 0.f)
            e0 = mid;
        else
            e1 = mid;
    }
    if (e0.clip[3] <= 0.f || e1.clip[3] <= 0.f)
        return dst;

    GLfloat ndc0x = e0.clip[0] / e0.clip[3];
    GLfloat ndc0y = e0.clip[1] / e0.clip[3];
    GLfloat ndc1x = e1.clip[0] / e1.clip[3];
    GLfloat ndc1y = e1.clip[1] / e1.clip[3];
    GLfloat dx_px = (ndc1x - ndc0x) * vp_w * 0.5f;
    GLfloat dy_px = (ndc1y - ndc0y) * vp_h * 0.5f;
    GLfloat len2 = dx_px * dx_px + dy_px * dy_px;

    GLfloat hx, hy;
    GLfloat x00, y00, x01, y01, x10, y10, x11, y11;
    if (len2 < 1e-8f) {
        /* Half-extent = width/2 pixels = width/vp in NDC
         * (window_x = (ndc_x + 1) * vp_w / 2). */
        hx = width / vp_w;
        hy = width / vp_h;
        x00 = ndc0x - hx; y00 = ndc0y - hy;
        x01 = ndc0x + hx; y01 = ndc0y - hy;
        x10 = ndc0x + hx; y10 = ndc0y + hy;
        x11 = ndc0x - hx; y11 = ndc0y + hy;
        wide_emit_corner(dst + 0, &e0, x00, y00, have_color, have_secondary,
                         have_fog, have_normal, maxtex, tex);
        wide_emit_corner(dst + 1, &e0, x01, y01, have_color, have_secondary,
                         have_fog, have_normal, maxtex, tex);
        wide_emit_corner(dst + 2, &e0, x10, y10, have_color, have_secondary,
                         have_fog, have_normal, maxtex, tex);
        wide_emit_corner(dst + 3, &e0, x00, y00, have_color, have_secondary,
                         have_fog, have_normal, maxtex, tex);
        wide_emit_corner(dst + 4, &e0, x10, y10, have_color, have_secondary,
                         have_fog, have_normal, maxtex, tex);
        wide_emit_corner(dst + 5, &e0, x11, y11, have_color, have_secondary,
                         have_fog, have_normal, maxtex, tex);
        return dst + 6;
    }
    GLfloat inv = 1.f / sqrtf(len2);
    GLfloat nx = -dy_px * inv;
    GLfloat ny =  dx_px * inv;
    hx = nx * width / vp_w;
    hy = ny * width / vp_h;
    x00 = ndc0x - hx; y00 = ndc0y - hy;
    x01 = ndc0x + hx; y01 = ndc0y + hy;
    x10 = ndc1x - hx; y10 = ndc1y - hy;
    x11 = ndc1x + hx; y11 = ndc1y + hy;
    wide_emit_corner(dst + 0, &e0, x00, y00, have_color, have_secondary,
                     have_fog, have_normal, maxtex, tex);
    wide_emit_corner(dst + 1, &e0, x01, y01, have_color, have_secondary,
                     have_fog, have_normal, maxtex, tex);
    wide_emit_corner(dst + 2, &e1, x10, y10, have_color, have_secondary,
                     have_fog, have_normal, maxtex, tex);
    wide_emit_corner(dst + 3, &e0, x01, y01, have_color, have_secondary,
                     have_fog, have_normal, maxtex, tex);
    wide_emit_corner(dst + 4, &e1, x11, y11, have_color, have_secondary,
                     have_fog, have_normal, maxtex, tex);
    wide_emit_corner(dst + 5, &e1, x10, y10, have_color, have_secondary,
                     have_fog, have_normal, maxtex, tex);
    return dst + 6;
}

typedef struct {
    gl4es_mvp_save_t mvp;
    GLenum polygon_mode;
    int cull;
    int lighting;
    int fog;
    int fill_offset;
    int want_fill;
    int texgen_s[MAX_TEX];
    int texgen_t[MAX_TEX];
    int texgen_r[MAX_TEX];
    int texgen_q[MAX_TEX];
    int any_texgen;
    int old_tex;
    GLuint old_array;
    GLuint old_index;
} wide_draw_save_t;

static void wide_draw_begin(int from_polygon_mode, wide_draw_save_t *s)
{
    memset(s, 0, sizeof(*s));
    gl4es_mvp_save(&s->mvp);
    gl4es_mvp_load_identity();

    s->polygon_mode = glstate->polygon_mode ? glstate->polygon_mode : GL_FILL;
    if (s->polygon_mode != GL_FILL)
        gl4es_glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    s->cull = glstate->enable.cull_face;
    if (s->cull)
        gl4es_glDisable(GL_CULL_FACE);

    s->lighting = glstate->enable.lighting;
    if (s->lighting)
        gl4es_glDisable(GL_LIGHTING);

    s->fog = glstate->enable.fog;
    if (s->fog)
        gl4es_glDisable(GL_FOG);

    s->old_tex = glstate->texture.active;
    s->any_texgen = 0;
    for (int a = 0; a < hardext.maxtex; a++) {
        s->texgen_s[a] = glstate->enable.texgen_s[a];
        s->texgen_t[a] = glstate->enable.texgen_t[a];
        s->texgen_r[a] = glstate->enable.texgen_r[a];
        s->texgen_q[a] = glstate->enable.texgen_q[a];
        if (s->texgen_s[a] || s->texgen_t[a] || s->texgen_r[a] || s->texgen_q[a]) {
            if (glstate->texture.active != a)
                gl4es_glActiveTexture(GL_TEXTURE0 + a);
            if (s->texgen_s[a]) gl4es_glDisable(GL_TEXTURE_GEN_S);
            if (s->texgen_t[a]) gl4es_glDisable(GL_TEXTURE_GEN_T);
            if (s->texgen_r[a]) gl4es_glDisable(GL_TEXTURE_GEN_R);
            if (s->texgen_q[a]) gl4es_glDisable(GL_TEXTURE_GEN_Q);
            s->any_texgen = 1;
        }
    }
    if (glstate->texture.active != s->old_tex)
        gl4es_glActiveTexture(GL_TEXTURE0 + s->old_tex);

    s->fill_offset = glstate->enable.polyfill_offset;
    s->want_fill = from_polygon_mode && glstate->enable.polyline_offset;
    if (s->want_fill && !s->fill_offset)
        gl4es_glEnable(GL_POLYGON_OFFSET_FILL);
    else if (!s->want_fill && s->fill_offset)
        gl4es_glDisable(GL_POLYGON_OFFSET_FILL);

    s->old_array = glstate->bind_buffer.array;
    s->old_index = glstate->bind_buffer.want_index;
    bindBuffer(GL_ARRAY_BUFFER, 0);
    wantBufferIndex(0);
    realize_bufferIndex();
}

static void wide_draw_end(const wide_draw_save_t *s)
{
    if (s->want_fill && !s->fill_offset)
        gl4es_glDisable(GL_POLYGON_OFFSET_FILL);
    else if (!s->want_fill && s->fill_offset)
        gl4es_glEnable(GL_POLYGON_OFFSET_FILL);

    if (s->any_texgen) {
        for (int a = 0; a < hardext.maxtex; a++) {
            if (s->texgen_s[a] || s->texgen_t[a] || s->texgen_r[a] || s->texgen_q[a]) {
                if (glstate->texture.active != a)
                    gl4es_glActiveTexture(GL_TEXTURE0 + a);
                if (s->texgen_s[a]) gl4es_glEnable(GL_TEXTURE_GEN_S);
                if (s->texgen_t[a]) gl4es_glEnable(GL_TEXTURE_GEN_T);
                if (s->texgen_r[a]) gl4es_glEnable(GL_TEXTURE_GEN_R);
                if (s->texgen_q[a]) gl4es_glEnable(GL_TEXTURE_GEN_Q);
            }
        }
        if (glstate->texture.active != s->old_tex)
            gl4es_glActiveTexture(GL_TEXTURE0 + s->old_tex);
    }

    if (s->fog)
        gl4es_glEnable(GL_FOG);
    if (s->lighting)
        gl4es_glEnable(GL_LIGHTING);
    if (s->cull)
        gl4es_glEnable(GL_CULL_FACE);
    if (s->polygon_mode != GL_FILL)
        gl4es_glPolygonMode(GL_FRONT_AND_BACK, s->polygon_mode);

    bindBuffer(GL_ARRAY_BUFFER, s->old_array);
    wantBufferIndex(s->old_index);
    realize_bufferIndex();
    gl4es_mvp_restore(&s->mvp);
}

int gl4es_draw_wide_lines(
    GLenum mode,
    const GLfloat *vert, int vert_stride,
    const GLfloat *color, int color_stride,
    const GLfloat *secondary, int secondary_stride,
    const GLfloat *fogcoord, int fogcoord_stride,
    const GLfloat *normal, int normal_stride,
    GLfloat * const *tex, const int *tex_stride, int maxtex,
    const GLushort *indices, int count,
    int from_polygon_mode, int instance_count)
{
    if (!vert || count < 2)
        return GL4ES_WIDE_HANDLED;
    if (instance_count <= 0)
        return GL4ES_WIDE_HANDLED;

    GLfloat width = glstate->line_width;
    if (width > GL4ES_EMULATED_LINE_WIDTH_MAX)
        width = GL4ES_EMULATED_LINE_WIDTH_MAX;
    {
        int maxw = hardext.maxlinewidth;
        if (maxw < 1)
            maxw = 1;
        if (width <= (GLfloat)maxw)
            return GL4ES_WIDE_FALLBACK;
    }

    GLfloat vp_w = (GLfloat)glstate->raster.viewport.width;
    GLfloat vp_h = (GLfloat)glstate->raster.viewport.height;
    if (vp_w < 1.f || vp_h < 1.f)
        return GL4ES_WIDE_FALLBACK;

    int nseg;
    if (mode == GL_LINES)
        nseg = count / 2;
    else if (mode == GL_LINE_STRIP)
        nseg = count - 1;
    else if (mode == GL_LINE_LOOP)
        nseg = count;
    else
        return GL4ES_WIDE_FALLBACK;
    if (nseg <= 0)
        return GL4ES_WIDE_HANDLED;
    if (nseg > (INT_MAX / 6))
        return GL4ES_WIDE_FALLBACK;

    int have_color = color != NULL;
    int have_secondary = secondary != NULL;
    int have_fog = fogcoord != NULL;
    int have_normal = normal != NULL;
    int have_tex_mask = 0;
    if (maxtex > MAX_TEX)
        maxtex = MAX_TEX;
    for (int a = 0; a < maxtex; a++)
        if (tex && tex[a])
            have_tex_mask |= (1 << a);

    if (!wide_ensure(nseg * 6, have_color, have_secondary, have_fog,
                     have_normal, have_tex_mask))
        return GL4ES_WIDE_FALLBACK;

    int stipple_tmu = -1;
    if (glstate->enable.line_stipple)
        stipple_tmu = (get_target(glstate->enable.texture[0]) != -1) ? 1 : 0;

    int out = 0;
    if (mode == GL_LINES) {
        for (int i = 0; i + 1 < count; i += 2) {
            int i0 = indices ? indices[i] : i;
            int i1 = indices ? indices[i + 1] : i + 1;
            wide_end_t e0, e1;
            wide_load_end(&e0, i0, vert, vert_stride, color, color_stride,
                          secondary, secondary_stride, fogcoord, fogcoord_stride,
                          normal, normal_stride, tex, tex_stride, maxtex);
            wide_load_end(&e1, i1, vert, vert_stride, color, color_stride,
                          secondary, secondary_stride, fogcoord, fogcoord_stride,
                          normal, normal_stride, tex, tex_stride, maxtex);
            out = wide_emit_segment(out, e0, e1, width, vp_w, vp_h,
                                    have_color, have_secondary, have_fog,
                                    have_normal, maxtex, tex);
        }
    } else {
        for (int i = 0; i < count - 1; i++) {
            int i0 = indices ? indices[i] : i;
            int i1 = indices ? indices[i + 1] : i + 1;
            wide_end_t e0, e1;
            wide_load_end(&e0, i0, vert, vert_stride, color, color_stride,
                          secondary, secondary_stride, fogcoord, fogcoord_stride,
                          normal, normal_stride, tex, tex_stride, maxtex);
            wide_load_end(&e1, i1, vert, vert_stride, color, color_stride,
                          secondary, secondary_stride, fogcoord, fogcoord_stride,
                          normal, normal_stride, tex, tex_stride, maxtex);
            out = wide_emit_segment(out, e0, e1, width, vp_w, vp_h,
                                    have_color, have_secondary, have_fog,
                                    have_normal, maxtex, tex);
        }
        if (mode == GL_LINE_LOOP) {
            int i0 = indices ? indices[count - 1] : count - 1;
            int i1 = indices ? indices[0] : 0;
            wide_end_t e0, e1;
            wide_load_end(&e0, i0, vert, vert_stride, color, color_stride,
                          secondary, secondary_stride, fogcoord, fogcoord_stride,
                          normal, normal_stride, tex, tex_stride, maxtex);
            wide_load_end(&e1, i1, vert, vert_stride, color, color_stride,
                          secondary, secondary_stride, fogcoord, fogcoord_stride,
                          normal, normal_stride, tex, tex_stride, maxtex);
            if (stipple_tmu >= 0 && stipple_tmu < maxtex && tex && tex[stipple_tmu]) {
                GLfloat c0[4], c1[4];
                const GLfloat *mvp = getMVPMat();
                vector_matrix(wide_at(vert, vert_stride, 4, i0), mvp, c0);
                vector_matrix(wide_at(vert, vert_stride, 4, i1), mvp, c1);
                GLfloat x1, y1, x2, y2;
                if (c0[3] == 0.f) { x1 = c0[0] * vp_w * 0.5f; y1 = c0[1] * vp_h * 0.5f; }
                else { x1 = (c0[0] / c0[3]) * vp_w * 0.5f; y1 = (c0[1] / c0[3]) * vp_h * 0.5f; }
                if (c1[3] == 0.f) { x2 = c1[0] * vp_w * 0.5f; y2 = c1[1] * vp_h * 0.5f; }
                else { x2 = (c1[0] / c1[3]) * vp_w * 0.5f; y2 = (c1[1] / c1[3]) * vp_h * 0.5f; }
                GLfloat ds = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
                           / (glstate->linestipple.factor * 16.f);
                e1.tex[stipple_tmu][0] = e0.tex[stipple_tmu][0] + ds;
                e1.tex[stipple_tmu][1] = 0.f;
                e1.tex[stipple_tmu][2] = 0.f;
                e1.tex[stipple_tmu][3] = 1.f;
            }
            out = wide_emit_segment(out, e0, e1, width, vp_w, vp_h,
                                    have_color, have_secondary, have_fog,
                                    have_normal, maxtex, tex);
        }
    }

    if (out <= 0)
        return GL4ES_WIDE_HANDLED;

    wide_draw_save_t saved;
    wide_draw_begin(from_polygon_mode, &saved);

    LOAD_GLES_FPE(glDrawArrays);
    LOAD_GLES_FPE(glVertexPointer);
    LOAD_GLES_FPE(glColorPointer);
    LOAD_GLES_FPE(glNormalPointer);
    LOAD_GLES_FPE(glTexCoordPointer);

    fpe_glEnableClientState(GL_VERTEX_ARRAY);
    gles_glVertexPointer(4, GL_FLOAT, 0, g_wide.vert);
    if (have_color && g_wide.color) {
        fpe_glEnableClientState(GL_COLOR_ARRAY);
        gles_glColorPointer(4, GL_FLOAT, 0, g_wide.color);
    }
    if (have_normal && g_wide.normal) {
        fpe_glEnableClientState(GL_NORMAL_ARRAY);
        gles_glNormalPointer(GL_FLOAT, 0, g_wide.normal);
    }
    if (have_secondary && g_wide.secondary && hardext.esversion > 1) {
        fpe_glEnableClientState(GL_SECONDARY_COLOR_ARRAY);
        fpe_glSecondaryColorPointer(4, GL_FLOAT, 0, g_wide.secondary);
    }
    if (have_fog && g_wide.fogcoord && hardext.esversion > 1) {
        fpe_glEnableClientState(GL_FOG_COORD_ARRAY);
        fpe_glFogCoordPointer(GL_FLOAT, 0, g_wide.fogcoord);
    }
    int old_client = glstate->texture.client;
    for (int a = 0; a < maxtex; a++) {
        if (tex && tex[a] && g_wide.tex[a]) {
            if (glstate->texture.client != a)
                gl4es_glClientActiveTexture(GL_TEXTURE0 + a);
            fpe_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            gles_glTexCoordPointer(4, GL_FLOAT, 0, g_wide.tex[a]);
        }
    }
    if (glstate->texture.client != old_client)
        gl4es_glClientActiveTexture(GL_TEXTURE0 + old_client);

    if (instance_count == 1) {
        gles_glDrawArrays(GL_TRIANGLES, 0, out);
    } else {
        for (glstate->instanceID = 0; glstate->instanceID < instance_count;
                ++glstate->instanceID)
            gles_glDrawArrays(GL_TRIANGLES, 0, out);
        glstate->instanceID = 0;
    }

    wide_draw_end(&saved);
    return GL4ES_WIDE_HANDLED;
}
