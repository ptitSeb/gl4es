/* Accumulation buffer emulated with an internal FBO.
 *
 * Desktop GL's accumulation buffer does not exist on GLES/WebGL, so
 * glAccum was a stub. This implements the classic accumulate-in-a-texture
 * translation for the GLES2 backend:
 *
 *   glClear(GL_ACCUM_BUFFER_BIT)  -> clear the internal accum FBO
 *   glAccum(GL_ACCUM, w)          -> copy the read framebuffer into a
 *                                    scratch texture, then add it into the
 *                                    accum FBO as a fullscreen quad scaled
 *                                    by w (additive blending)
 *   glAccum(GL_LOAD, w)           -> same, blending off (replace)
 *   glAccum(GL_RETURN, s)         -> draw the accum texture into the
 *                                    current draw framebuffer scaled by s
 *   GL_ADD / GL_MULT              -> TODO (unused by fixed-function apps
 *                                    hosted so far)
 *
 * The accum target is RGBA16F when float renderbuffers are available
 * (probed once with a tiny FBO-completeness test), else RGBA8 — fine at
 * low pass counts, visibly banding at 8-16-pass accumulation. The getter
 * reports GL_ACCUM_*_BITS accordingly (16 / 8 / 0), so apps that probe
 * for a real accumulation buffer pick the emulation up automatically.
 *
 * Scissor semantics come for free: real glAccum operations are bounded by
 * the scissor box, and the emulation's quad draws inherit the live
 * scissor state. The quad draws follow gl4es_blitTexture's state-hygiene
 * pattern (blit.c): raw GLES draws under glPushAttrib, with the tracked
 * gleshard program/vertexattrib state updated so the next user draw
 * re-realizes cleanly.
 */
#include "accum.h"

#include <stdlib.h>
#include <string.h>

#include "../glx/hardext.h"
#include "blend.h"
#include "buffers.h"
#include "debug.h"
#include "depth.h"
#include "framebuffers.h"
#include "gl4es.h"
#include "glstate.h"
#include "init.h"
#include "loader.h"
#include "logs.h"
#include "stack.h"
#include "texture.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/html5.h>
#endif

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

// hacky viewport temporary changes (raster.c, same use as blit.c)
void pushViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void popViewport();

static const char accum_vsh[] = "#version 100                  \n" \
"attribute highp vec2 aPosition;                        \n" \
"attribute highp vec2 aTexCoord;                        \n" \
"varying mediump vec2 vTexCoord;                        \n" \
"void main(){                                           \n" \
"gl_Position = vec4(aPosition.x, aPosition.y, 0.0, 1.0);\n" \
"vTexCoord = aTexCoord;                                 \n" \
"}                                                      \n";

static const char accum_fsh[] = "#version 100            \n" \
"uniform sampler2D uTex;                                \n" \
"uniform mediump float uScale;                          \n" \
"varying mediump vec2 vTexCoord;                        \n" \
"void main(){                                           \n" \
"gl_FragColor = texture2D(uTex, vTexCoord) * uScale;    \n" \
"}                                                      \n";

static glesaccum_t* accum_state() {
    if(!glstate->accum) {
        glstate->accum = (glesaccum_t*)calloc(1, sizeof(glesaccum_t));
        // fullscreen quad in clip space; the viewport is set to cover the
        // whole target around each draw, so no per-draw vertex math
        GLfloat *vert = glstate->accum->vert;
        GLfloat *tex = glstate->accum->tex;
        vert[0] = -1.f; vert[1] = -1.f;
        vert[2] =  1.f; vert[3] = -1.f;
        vert[4] =  1.f; vert[5] =  1.f;
        vert[6] = -1.f; vert[7] =  1.f;
        tex[0] = 0.f; tex[1] = 0.f;
        tex[2] = 1.f; tex[3] = 0.f;
        tex[4] = 1.f; tex[5] = 1.f;
        tex[6] = 0.f; tex[7] = 1.f;
        // accum clear value defaults to (0,0,0,0), calloc covers it
    }
    return glstate->accum;
}

// force the GLES-side active texture unit to 0; tracked, so the next user
// draw re-realizes (same dance as gl4es_blitTexture)
static void realize_accumenv(glesaccum_t *a, GLfloat scale);
static int accum_create_program(glesaccum_t *a);

static void accum_force_tmu0() {
    if(glstate->gleshard->active) {
        LOAD_GLES(glActiveTexture);
        glstate->gleshard->active = 0;
        gles_glActiveTexture(GL_TEXTURE0);
    }
}

static void accum_restore_tmu(GLuint tmu) {
    LOAD_GLES(glActiveTexture);
    glstate->gleshard->active = tmu;
    gles_glActiveTexture(GL_TEXTURE0 + tmu);
}

// The format probe uses raw GLES so it does not compile into a display
// list or flush a begin/end. Restore both the driver and the gl4es
// mirrors: state-aware wrappers would see the still-unmodified tracked
// blend/program values and skip the GLES restore, leaving later draws
// on GL_ONE,GL_ONE.
static void accum_restore_probe_blend(GLboolean enable,
                                      GLenum srgb, GLenum drgb,
                                      GLenum salpha, GLenum dalpha,
                                      GLenum eqrgb, GLenum eqalpha)
{
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    LOAD_GLES(glBlendFunc);
    LOAD_GLES(glBlendEquation);
    LOAD_GLES2_OR_OES(glBlendFuncSeparate);
    LOAD_GLES2_OR_OES(glBlendEquationSeparate);
    if(enable)
        gles_glEnable(GL_BLEND);
    else
        gles_glDisable(GL_BLEND);
    if(gles_glBlendFuncSeparate)
        gles_glBlendFuncSeparate(srgb, drgb, salpha, dalpha);
    else
        gles_glBlendFunc(srgb, drgb);
    if(!eqrgb) eqrgb = GL_FUNC_ADD;
    if(!eqalpha) eqalpha = GL_FUNC_ADD;
    if(gles_glBlendEquationSeparate)
        gles_glBlendEquationSeparate(eqrgb, eqalpha);
    else if(gles_glBlendEquation)
        gles_glBlendEquation(eqrgb);
}

static void accum_restore_probe_gleshard(const gleshard_t *saved, GLuint saved_array)
{
    LOAD_GLES2(glUseProgram);
    LOAD_GLES2(glEnableVertexAttribArray);
    LOAD_GLES2(glDisableVertexAttribArray);
    LOAD_GLES2(glVertexAttribPointer);
    if(gles_glUseProgram)
        gles_glUseProgram(saved->program);
    for(int i=0; i<hardext.maxvattrib; i++) {
        const vertexattrib_t *v = &saved->vertexattrib[i];
        if(v->enabled) {
            gles_glEnableVertexAttribArray(i);
            if(v->size>0) {
                bindBuffer(GL_ARRAY_BUFFER, v->real_buffer);
                gles_glVertexAttribPointer(i, v->size, v->type, v->normalized,
                                           v->stride,
                                           v->real_buffer ? v->real_pointer : v->pointer);
            }
        } else {
            gles_glDisableVertexAttribArray(i);
        }
    }
    bindBuffer(GL_ARRAY_BUFFER, saved_array);
    memcpy(glstate->gleshard, saved, sizeof(*saved));
    accum_restore_tmu(saved->active);
}

// COLOR_BUFFER_BIT saves blend factors, not the blend equation. Immediate
// GL_ACCUM forces FUNC_ADD through the state-aware wrapper; restore after
// PopAttrib or a prior FUNC_SUBTRACT leaks.
static void accum_restore_blend_equation(GLenum eqrgb, GLenum eqalpha)
{
    if(!eqrgb) eqrgb = GL_FUNC_ADD;
    if(!eqalpha) eqalpha = GL_FUNC_ADD;
    if(eqrgb==eqalpha)
        gl4es_glBlendEquation(eqrgb);
    else
        gl4es_glBlendEquationSeparate(eqrgb, eqalpha);
}

// one-time renderability test: can we create a small texture of this
// format and attach it to a complete FBO? test_blend also draws with
// GL_ONE,GL_ONE — WebGL2 can complete an RGBA16F FBO and still reject
// blending into it without EXT_float_blend.
static int accum_try_format(glesaccum_t *a, GLenum intformat, GLenum format,
                            GLenum type, int test_blend) {
    LOAD_GLES(glGetError);
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glDeleteTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glTexParameteri);
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    LOAD_GLES(glBlendFunc);
    LOAD_GLES(glDrawArrays);
    LOAD_GLES(glBlendEquation);
    LOAD_GLES2_OR_OES(glGenFramebuffers);
    LOAD_GLES2_OR_OES(glDeleteFramebuffers);
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    LOAD_GLES2_OR_OES(glFramebufferTexture2D);
    LOAD_GLES2_OR_OES(glCheckFramebufferStatus);

    while(gles_glGetError()!=GL_NO_ERROR);
    GLuint tex = 0, fbo = 0;
    gles_glGenTextures(1, &tex);
    gles_glBindTexture(GL_TEXTURE_2D, tex);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gles_glTexImage2D(GL_TEXTURE_2D, 0, intformat, 4, 4, 0, format, type, NULL);
    int ok = (gles_glGetError()==GL_NO_ERROR);
    if(ok) {
        gles_glGenFramebuffers(1, &fbo);
        gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        gles_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0);
        ok = (gles_glCheckFramebufferStatus(GL_FRAMEBUFFER)==GL_FRAMEBUFFER_COMPLETE);
        if(ok && test_blend && a->program) {
            GLboolean saved_blend = glstate->enable.blend;
            GLenum saved_srgb = glstate->blendsfactorrgb;
            GLenum saved_drgb = glstate->blenddfactorrgb;
            GLenum saved_salpha = glstate->blendsfactoralpha;
            GLenum saved_dalpha = glstate->blenddfactoralpha;
            GLenum saved_eqrgb = glstate->blendeqrgb;
            GLenum saved_eqalpha = glstate->blendeqalpha;
            GLuint saved_array = glstate->bind_buffer.array;
            gleshard_t saved_hard;
            memcpy(&saved_hard, glstate->gleshard, sizeof(saved_hard));
            gles_glEnable(GL_BLEND);
            gles_glBlendFunc(GL_ONE, GL_ONE);
            if(gles_glBlendEquation)
                gles_glBlendEquation(GL_FUNC_ADD);
            realize_accumenv(a, 0.f);
            gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            ok = (gles_glGetError()==GL_NO_ERROR);
            accum_restore_probe_blend(saved_blend, saved_srgb, saved_drgb,
                                      saved_salpha, saved_dalpha,
                                      saved_eqrgb, saved_eqalpha);
            accum_restore_probe_gleshard(&saved_hard, saved_array);
        }
        gles_glDeleteFramebuffers(1, &fbo);
    }
    gles_glDeleteTextures(1, &tex);
    gles_glBindTexture(GL_TEXTURE_2D, glstate->actual_tex2d[0]);
    gl4es_setCurrentFBO();
    while(gles_glGetError()!=GL_NO_ERROR);
    return ok;
}

static void accum_probe(glesaccum_t *a) {
    if(a->probed) return;
    a->probed = 1;
    a->bits = 0;
    if(hardext.esversion<2) return; // the scaled-quad path needs the GLES2 backend
    GLuint saved_tmu = glstate->gleshard->active;
    accum_force_tmu0();
    if(!accum_create_program(a)) {
        SHUT_LOGD("Accum buffer emulation unavailable\n");
        accum_restore_tmu(saved_tmu);
        return;
    }
    // Each format is attempted outright and judged by the FBO-completeness
    // test -- the hardext floatfbo/halffloattex flags stay 0 on backends
    // that run GetHardwareExtensions with notest (e.g. Emscripten, where
    // no gles_getProcAddress hook is installed), so they can't gate this.
    if(accum_try_format(a, GL_RGBA16F, GL_RGBA, GL_HALF_FLOAT, 1)) {
        // GLES3/WebGL2 sized half-float, renderable per EXT_color_buffer_(half_)float
        a->intformat = GL_RGBA16F;
        a->format = GL_RGBA;
        a->type = GL_HALF_FLOAT;
        a->bits = 16;
    } else if(accum_try_format(a, GL_RGBA, GL_RGBA, GL_HALF_FLOAT_OES, 1)) {
        // GLES2 unsized half-float (OES_texture_half_float)
        a->intformat = GL_RGBA;
        a->format = GL_RGBA;
        a->type = GL_HALF_FLOAT_OES;
        a->bits = 16;
    } else if(accum_try_format(a, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 0)) {
        a->intformat = GL_RGBA;
        a->format = GL_RGBA;
        a->type = GL_UNSIGNED_BYTE;
        a->bits = 8;
    }
    if(a->bits) {
        SHUT_LOGD("Accum buffer emulation active (%d bits per channel)\n", a->bits);
    } else {
        SHUT_LOGD("Accum buffer emulation unavailable\n");
    }
    accum_restore_tmu(saved_tmu);
}

// size the accum target to the framebuffer glAccum reads from / returns to
static int accum_target_size(int *w, int *h) {
    if(glstate->fbo.current_fb && glstate->fbo.current_fb->id) {
        *w = glstate->fbo.current_fb->width;
        *h = glstate->fbo.current_fb->height;
        return (*w>0 && *h>0);
    }
    if(gl4es_getMainFBSize) {
        GLint ww = 0, hh = 0;
        gl4es_getMainFBSize(&ww, &hh);
        if(ww>0 && hh>0) { *w = ww; *h = hh; return 1; }
    }
#ifdef __EMSCRIPTEN__
    {
        EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx = emscripten_webgl_get_current_context();
        if(ctx) {
            int ww = 0, hh = 0;
            emscripten_webgl_get_drawing_buffer_size(ctx, &ww, &hh);
            if(ww>0 && hh>0) { *w = ww; *h = hh; return 1; }
        }
    }
#endif
    if(glstate->fbo.mainfbo_width>0 && glstate->fbo.mainfbo_height>0) {
        *w = glstate->fbo.mainfbo_width;
        *h = glstate->fbo.mainfbo_height;
        return 1;
    }
    // last resort: the tracked viewport extent
    *w = glstate->raster.viewport.x + glstate->raster.viewport.width;
    *h = glstate->raster.viewport.y + glstate->raster.viewport.height;
    return (*w>0 && *h>0);
}

static int accum_create_program(glesaccum_t *a) {
    LOAD_GLES2(glCreateShader);
    LOAD_GLES2(glShaderSource);
    LOAD_GLES2(glCompileShader);
    LOAD_GLES2(glGetShaderiv);
    LOAD_GLES2(glBindAttribLocation);
    LOAD_GLES2(glAttachShader);
    LOAD_GLES2(glCreateProgram);
    LOAD_GLES2(glLinkProgram);
    LOAD_GLES2(glGetProgramiv);
    LOAD_GLES(glGetUniformLocation);
    LOAD_GLES2(glUniform1i);
    LOAD_GLES2(glUseProgram);

    GLint success;
    const char *src[1];
    src[0] = accum_fsh;
    a->pixelshader = gles_glCreateShader(GL_FRAGMENT_SHADER);
    gles_glShaderSource(a->pixelshader, 1, (const char**)src, NULL);
    gles_glCompileShader(a->pixelshader);
    gles_glGetShaderiv(a->pixelshader, GL_COMPILE_STATUS, &success);
    if(!success) {
        LOAD_GLES(glGetShaderInfoLog);
        LOAD_GLES2(glDeleteShader);
        char log[400];
        gles_glGetShaderInfoLog(a->pixelshader, 399, NULL, log);
        SHUT_LOGE("Failed to produce accum fragment shader.\n%s", log);
        if(gles_glDeleteShader) gles_glDeleteShader(a->pixelshader);
        a->pixelshader = 0;
        return 0;
    }
    src[0] = accum_vsh;
    a->vertexshader = gles_glCreateShader(GL_VERTEX_SHADER);
    gles_glShaderSource(a->vertexshader, 1, (const char**)src, NULL);
    gles_glCompileShader(a->vertexshader);
    gles_glGetShaderiv(a->vertexshader, GL_COMPILE_STATUS, &success);
    if(!success) {
        LOAD_GLES(glGetShaderInfoLog);
        LOAD_GLES2(glDeleteShader);
        char log[400];
        gles_glGetShaderInfoLog(a->vertexshader, 399, NULL, log);
        SHUT_LOGE("Failed to produce accum vertex shader.\n%s", log);
        if(gles_glDeleteShader) {
            gles_glDeleteShader(a->vertexshader);
            if(a->pixelshader) gles_glDeleteShader(a->pixelshader);
        }
        a->vertexshader = 0;
        a->pixelshader = 0;
        return 0;
    }
    a->program = gles_glCreateProgram();
    gles_glBindAttribLocation(a->program, 0, "aPosition");
    gles_glBindAttribLocation(a->program, 1, "aTexCoord");
    gles_glAttachShader(a->program, a->pixelshader);
    gles_glAttachShader(a->program, a->vertexshader);
    gles_glLinkProgram(a->program);
    gles_glGetProgramiv(a->program, GL_LINK_STATUS, &success);
    if(!success) {
        LOAD_GLES2(glDeleteProgram);
        SHUT_LOGE("Failed to link accum program.\n");
        if(gles_glDeleteProgram && a->program)
            gles_glDeleteProgram(a->program);
        a->program = 0;
        return 0;
    }
    GLuint oldprog = glstate->gleshard->program;
    gles_glUseProgram(a->program);
    gles_glUniform1i(gles_glGetUniformLocation(a->program, "uTex"), 0);
    a->uscale = gles_glGetUniformLocation(a->program, "uScale");
    gles_glUseProgram(oldprog);
    return 1;
}

// (re)create the accum FBO + textures at the current target size.
// Returns 0 (op becomes a no-op) when the target size is unknown or
// creation fails; a->bits is only zeroed on hard shader failure.
static int accum_ensure(glesaccum_t *a) {
    int w = 0, h = 0;
    if(!accum_target_size(&w, &h)) return 0;
    if(a->fbo && a->width==w && a->height==h) return 1;

    if(!a->program && !accum_create_program(a)) {
        a->bits = 0;    // no scaled-quad path -> emulation off for good
        return 0;
    }

    LOAD_GLES(glGetError);
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glDeleteTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glTexParameteri);
    LOAD_GLES(glClearColor);
    LOAD_GLES(glClear);
    LOAD_GLES2_OR_OES(glGenFramebuffers);
    LOAD_GLES2_OR_OES(glDeleteFramebuffers);
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    LOAD_GLES2_OR_OES(glFramebufferTexture2D);
    LOAD_GLES2_OR_OES(glCheckFramebufferStatus);

    if(a->fbo) {
        gles_glDeleteFramebuffers(1, &a->fbo);
        a->fbo = 0;
    }
    if(a->accum_tex) {
        gles_glDeleteTextures(1, &a->accum_tex);
        a->accum_tex = 0;
    }
    if(a->scratch_tex) {
        gles_glDeleteTextures(1, &a->scratch_tex);
        a->scratch_tex = 0;
    }

    accum_force_tmu0();
    while(gles_glGetError()!=GL_NO_ERROR);
    // the accum target (16F or 8-bit, per the probe)
    gles_glGenTextures(1, &a->accum_tex);
    gles_glBindTexture(GL_TEXTURE_2D, a->accum_tex);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gles_glTexImage2D(GL_TEXTURE_2D, 0, a->intformat, w, h, 0, a->format, a->type, NULL);
    // The scratch framebuffer snapshot is GL_RGB, not RGBA: GLES3/WebGL2's
    // glCopyTexSubImage2D compatibility rule requires the destination's
    // components to be a subset of the read buffer's, and a WebGL canvas
    // without an alpha channel (GLUT never requests one) is effectively
    // RGB8 -- an RGBA destination raises GL_INVALID_OPERATION and the copy
    // silently drops. RGB works against both RGB8 and RGBA8 sources; the
    // sampled alpha is then 1.0, matching an opaque native backbuffer.
    gles_glGenTextures(1, &a->scratch_tex);
    gles_glBindTexture(GL_TEXTURE_2D, a->scratch_tex);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    gles_glBindTexture(GL_TEXTURE_2D, glstate->actual_tex2d[0]);

    gles_glGenFramebuffers(1, &a->fbo);
    gles_glBindFramebuffer(GL_FRAMEBUFFER, a->fbo);
    gles_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, a->accum_tex, 0);
    int ok = (gles_glCheckFramebufferStatus(GL_FRAMEBUFFER)==GL_FRAMEBUFFER_COMPLETE)
             && (gles_glGetError()==GL_NO_ERROR);
    if(ok) {
        // give the fresh buffer defined content (the accum clear value),
        // whole-surface: glClear honors the scissor box, mask it out
        GLboolean scissor = gl4es_glIsEnabled(GL_SCISSOR_TEST);
        if(scissor) gl4es_glDisable(GL_SCISSOR_TEST);
        gles_glClearColor(a->clear[0], a->clear[1], a->clear[2], a->clear[3]);
        gles_glClear(GL_COLOR_BUFFER_BIT);
        gles_glClearColor(glstate->clear_color[0], glstate->clear_color[1],
                          glstate->clear_color[2], glstate->clear_color[3]);
        if(scissor) gl4es_glEnable(GL_SCISSOR_TEST);
        a->width = w;
        a->height = h;
    } else {
        SHUT_LOGE("Accum buffer emulation: %dx%d FBO incomplete\n", w, h);
        gles_glDeleteFramebuffers(1, &a->fbo);
        gles_glDeleteTextures(1, &a->accum_tex);
        gles_glDeleteTextures(1, &a->scratch_tex);
        a->fbo = a->accum_tex = a->scratch_tex = 0;
        a->width = a->height = 0;
        while(gles_glGetError()!=GL_NO_ERROR);
    }
    gl4es_setCurrentFBO();
    return ok;
}

// realize_blitenv's twin for the private scaled-copy program: update the
// tracked gleshard program/attrib state so user draws re-realize after us
static void realize_accumenv(glesaccum_t *a, GLfloat scale) {
    LOAD_GLES2(glUseProgram);
    LOAD_GLES2(glUniform1f);
    if(glstate->gleshard->program != a->program) {
        glstate->gleshard->program = a->program;
        gles_glUseProgram(a->program);
    }
    gles_glUniform1f(a->uscale, scale);
    unboundBuffers();
    for(int i=0; i<hardext.maxvattrib; i++) {
        vertexattrib_t *v = &glstate->gleshard->vertexattrib[i];
        if(v->enabled != ((i<2)?1:0)) {
            LOAD_GLES2(glEnableVertexAttribArray)
            LOAD_GLES2(glDisableVertexAttribArray);
            v->enabled = ((i<2)?1:0);
            if(v->enabled)
                gles_glEnableVertexAttribArray(i);
            else
                gles_glDisableVertexAttribArray(i);
        }
        if(i<2) {
            if(v->size!=2 || v->type!=GL_FLOAT || v->normalized!=0
                || v->stride!=0 || v->pointer!=((i==0)?a->vert:a->tex)
                || v->buffer!=0) {
                v->size = 2;
                v->type = GL_FLOAT;
                v->normalized = 0;
                v->stride = 0;
                v->pointer = (i==0)?a->vert:a->tex;
                v->buffer = 0;
                v->real_buffer = 0;
                LOAD_GLES2(glVertexAttribPointer);
                gles_glVertexAttribPointer(i, v->size, v->type, v->normalized, v->stride, v->pointer);
            }
        }
    }
}

// draw `texture` as a quad covering the whole bound framebuffer (the
// caller sets the viewport); scissor state is deliberately left live
static void accum_draw_quad(glesaccum_t *a, GLuint texture, GLfloat scale) {
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glDrawArrays);
    accum_force_tmu0();
    gles_glBindTexture(GL_TEXTURE_2D, texture);
    realize_accumenv(a, scale);
    gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    gles_glBindTexture(GL_TEXTURE_2D, glstate->actual_tex2d[0]);
}

int gl4es_accum_get_bits() {
    glesaccum_t *a = accum_state();
    accum_probe(a);
    return a->bits;
}

void gl4es_accum_get_clear(GLfloat *params) {
    glesaccum_t *a = accum_state();
    memcpy(params, a->clear, 4 * sizeof(GLfloat));
}

void gl4es_accum_dispose(void *accum) {
    glesaccum_t *a = (glesaccum_t *)accum;
    if(!a)
        return;
    {
        LOAD_GLES(glDeleteTextures);
        LOAD_GLES2(glDeleteProgram);
        LOAD_GLES2(glDeleteShader);
        LOAD_GLES2_OR_OES(glDeleteFramebuffers);
        if(a->fbo && gles_glDeleteFramebuffers)
            gles_glDeleteFramebuffers(1, &a->fbo);
        if(a->accum_tex && gles_glDeleteTextures)
            gles_glDeleteTextures(1, &a->accum_tex);
        if(a->scratch_tex && gles_glDeleteTextures)
            gles_glDeleteTextures(1, &a->scratch_tex);
        if(a->program && gles_glDeleteProgram)
            gles_glDeleteProgram(a->program);
        if(a->pixelshader && gles_glDeleteShader)
            gles_glDeleteShader(a->pixelshader);
        if(a->vertexshader && gles_glDeleteShader)
            gles_glDeleteShader(a->vertexshader);
    }
    free(a);
}

void gl4es_accum_clear() {
    glesaccum_t *a = accum_state();
    accum_probe(a);
    if(!a->bits) return;
    if(!accum_ensure(a)) return;
    LOAD_GLES(glClearColor);
    LOAD_GLES(glClear);
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    gles_glBindFramebuffer(GL_FRAMEBUFFER, a->fbo);
    gles_glClearColor(a->clear[0], a->clear[1], a->clear[2], a->clear[3]);
    // like the real thing, bounded by the live scissor box
    gles_glClear(GL_COLOR_BUFFER_BIT);
    gles_glClearColor(glstate->clear_color[0], glstate->clear_color[1],
                      glstate->clear_color[2], glstate->clear_color[3]);
    gl4es_setCurrentFBO();
}

void APIENTRY_GL4ES gl4es_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glesaccum_t *a = accum_state();
    const GLfloat c[4] = {red, green, blue, alpha};
    // GL clamps the accumulation clear value to [-1, 1]
    for(int i=0; i<4; i++)
        a->clear[i] = (c[i]<-1.f)?-1.f:((c[i]>1.f)?1.f:c[i]);
    noerrorShim();
}
AliasExport(void,glClearAccum,,(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha));

void APIENTRY_GL4ES gl4es_glAccum(GLenum op, GLfloat value) {
    DBG(printf("glAccum(%s, %f)\n", PrintEnum(op), value);)
    FLUSH_BEGINEND;
    // no display-list recording: executed immediately (was a stub upstream)
    switch(op) {
        case GL_ACCUM:
        case GL_LOAD:
        case GL_RETURN:
            break;
        case GL_ADD:
        case GL_MULT: {
            // TODO: unused by the fixed-function apps hosted so far
            static int warned = 0;
            if(!warned) {
                warned = 1;
                SHUT_LOGD("Accum buffer emulation: GL_ADD/GL_MULT not implemented\n");
            }
            noerrorShim();
            return;
        }
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    glesaccum_t *a = accum_state();
    accum_probe(a);
    if(!a->bits) {      // no emulation support: keep the old stub behavior
        noerrorShim();
        return;
    }
    if(!accum_ensure(a)) {
        noerrorShim();
        return;
    }

    realize_textures(1);

    gl4es_glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT);
    GLenum saved_eqrgb = glstate->blendeqrgb;
    GLenum saved_eqalpha = glstate->blendeqalpha;
    GLint depthwrite = glstate->depth.mask;
    if(depthwrite)
        gl4es_glDepthMask(GL_FALSE);
    gl4es_glDisable(GL_DEPTH_TEST);
    gl4es_glDisable(GL_CULL_FACE);
    gl4es_glDisable(GL_STENCIL_TEST);
    // scissor left untouched: real glAccum is bounded by the scissor box

    if(op==GL_RETURN) {
        // accum texture -> current draw framebuffer, modulated by value
        gl4es_glDisable(GL_BLEND);
        pushViewport(0, 0, a->width, a->height);
        accum_draw_quad(a, a->accum_tex, value);
        popViewport();
    } else {
        // GL_ACCUM / GL_LOAD: snapshot the read framebuffer...
        LOAD_GLES(glBindTexture);
        LOAD_GLES(glCopyTexSubImage2D);
        LOAD_GLES2_OR_OES(glBindFramebuffer);
        readfboBegin();
        accum_force_tmu0();
        gles_glBindTexture(GL_TEXTURE_2D, a->scratch_tex);
        gles_glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, a->width, a->height);
        gles_glBindTexture(GL_TEXTURE_2D, glstate->actual_tex2d[0]);
        readfboEnd();
        // ...then add (or load) it into the accum FBO, scaled by value
        gles_glBindFramebuffer(GL_FRAMEBUFFER, a->fbo);
        gl4es_glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        if(op==GL_ACCUM) {
            gl4es_glEnable(GL_BLEND);
            gl4es_glBlendFunc(GL_ONE, GL_ONE);
            gl4es_glBlendEquation(GL_FUNC_ADD);
            gl4es_glDisable(GL_COLOR_LOGIC_OP);
        } else
            gl4es_glDisable(GL_BLEND);
        pushViewport(0, 0, a->width, a->height);
        accum_draw_quad(a, a->scratch_tex, value);
        popViewport();
        gl4es_setCurrentFBO();
    }

    if(depthwrite)
        gl4es_glDepthMask(GL_TRUE);
    gl4es_glPopAttrib();
    accum_restore_blend_equation(saved_eqrgb, saved_eqalpha);
    noerrorShim();
}
AliasExport(void,glAccum,,(GLenum op, GLfloat value));
