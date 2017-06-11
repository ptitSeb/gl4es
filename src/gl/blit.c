/* Blit utility function */

#include "blit.h"
#include "../glx/hardext.h"

// hacky viewport temporary changes
void pushViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void popViewport();

/* TODO, implement glDrawTexi path
    gles_glDrawTexi(0, 0, 0, mainfbo_width, mainfbo_height);
or
    gl4es_glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
    
    gltexture_t *old_bind = glstate->texture.bound[0][ENABLED_TEX2D];
    gl4es_glEnable(GL_TEXTURE_2D);
    gles_glBindTexture(GL_TEXTURE_2D, rast->texture);

    if (rast->bitmap) {
        gl4es_glEnable(GL_ALPHA_TEST);
        gl4es_glAlphaFunc(GL_GREATER, 0.0f);
    } else {
        gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    }
    
    gles_glDrawTexf(glstate->raster.rPos.x-rast->xorig, glstate->raster.rPos.y-rast->yorig, glstate->raster.rPos.z, rast->width * rast->zoomx, rast->height * rast->zoomy);
    if (!IS_TEX2D(glstate->enable.texture[0])) gl4es_glDisable(GL_TEXTURE_2D);
    if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0+old_tex);
    if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0+old_cli);
    if (old_bind == NULL) 
        gles_glBindTexture(GL_TEXTURE_2D, 0);
    else
        gles_glBindTexture(GL_TEXTURE_2D, old_bind->glname);

*/

void gl4es_blitTexture(GLuint texture, 
    float width, float height, 
    float nwidth, float nheight, 
    float zoomx, float zoomy, 
    float vpwidth, float vpheight, 
    float x, float y, int mode) {
//printf("blitTexture(%d, %f, %f, %f, %f, %f, %f, %f, %f, %d) customvp=%d, vp=%d/%d/%d/%d\n", texture, width, height, nwidth, nheight, vpwidth, vpheight, x, y, mode, (vpwidth>0.0), glstate->raster.viewport.x, glstate->raster.viewport.y, glstate->raster.viewport.width, glstate->raster.viewport.height);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glClientActiveTexture);
    gl4es_glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
    GLfloat old_projection[16], old_modelview[16], old_texture[16];

    int customvp = (vpwidth>0.0);
    int drawtexok = (hardext.drawtex) && (zoomx==1.0f) && (zoomy==1.0f);

    GLuint old_tex = glstate->texture.active;
    if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0);
    GLuint old_cli = glstate->texture.client;
    if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0);

    gl4es_glDisable(GL_DEPTH_TEST);
    gl4es_glDisable(GL_LIGHTING);
    gl4es_glDisable(GL_CULL_FACE);
    switch (mode) {
        case BLIT_OPAQUE:
            gl4es_glDisable(GL_ALPHA_TEST);
            gl4es_glDisable(GL_BLEND);
            gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            break;
        case BLIT_ALPHA:
			gl4es_glEnable(GL_ALPHA_TEST);
			gl4es_glAlphaFunc(GL_GREATER, 0.0f);
            break;
        case BLIT_COLOR:
            gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            break;
    }

    gltexture_t *old_bind = glstate->texture.bound[0][ENABLED_TEX2D];
    gl4es_glEnable(GL_TEXTURE_2D);
    gles_glBindTexture(GL_TEXTURE_2D, texture);
    gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    if(drawtexok) {
        LOAD_GLES_OES(glDrawTexf);
        LOAD_GLES(glTexParameteriv);
        // setup texture first
        int sourceRect[4] = {0, 0, width, height};
        gles_glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, sourceRect);
        // take x/y of ViewPort into account
        float dx = (customvp)?0.0f:glstate->raster.viewport.x;
        float dy = (customvp)?0.0f:glstate->raster.viewport.y;
        //TODO: do something with width / height of ViewPort?
        // then draw it
        gles_glDrawTexf(x+dx, y+dy, 0.0f, width, height);
    } else {
        LOAD_GLES(glEnableClientState);
        LOAD_GLES(glDisableClientState);
        LOAD_GLES(glVertexPointer);
        LOAD_GLES(glTexCoordPointer);
        LOAD_GLES(glDrawArrays);

        float w2 = 2.0f / (customvp?vpwidth:glstate->raster.viewport.width);
        float h2 = 2.0f / (customvp?vpheight:glstate->raster.viewport.height);
        float blit_x1=x;
        float blit_x2=x+width*zoomx;
        float blit_y1=y;
        float blit_y2=y+height*zoomy;
        GLfloat blit_vert[] = {
            blit_x1*w2-1.0f, blit_y1*h2-1.0f,
            blit_x2*w2-1.0f, blit_y1*h2-1.0f,
            blit_x2*w2-1.0f, blit_y2*h2-1.0f,
            blit_x1*w2-1.0f, blit_y2*h2-1.0f
        };
        GLfloat rw = width/nwidth;
        GLfloat rh = height/nheight;
        GLfloat blit_tex[] = {
            0,  0,
            rw, 0,
            rw, rh,
            0,  rh
        };

        gl4es_glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT | GL_CLIENT_PIXEL_STORE_BIT);
        gl4es_glGetFloatv(GL_TEXTURE_MATRIX, old_texture);
        gl4es_glGetFloatv(GL_PROJECTION_MATRIX, old_projection);
        gl4es_glGetFloatv(GL_MODELVIEW_MATRIX, old_modelview);
        gl4es_glMatrixMode(GL_TEXTURE);
        gl4es_glLoadIdentity();
        gl4es_glMatrixMode(GL_PROJECTION);
        gl4es_glLoadIdentity();
        gl4es_glMatrixMode(GL_MODELVIEW);
        gl4es_glLoadIdentity();

        if(customvp)
            pushViewport(0,0,vpwidth, vpheight);
        
        if(!glstate->clientstate.vertex_array) 
        {
            gles_glEnableClientState(GL_VERTEX_ARRAY);
            glstate->clientstate.vertex_array = 1;
        }
        gles_glVertexPointer(2, GL_FLOAT, 0, blit_vert);
        if(!glstate->clientstate.tex_coord_array[0]) 
        {
            gles_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glstate->clientstate.tex_coord_array[0] = 1;
        }
        gles_glTexCoordPointer(2, GL_FLOAT, 0, blit_tex);
        for (int a=1; a <hardext.maxtex; a++)
            if(glstate->clientstate.tex_coord_array[a]) {
                gles_glClientActiveTexture(GL_TEXTURE0 + a);
                gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                glstate->clientstate.tex_coord_array[a] = 0;
                gles_glClientActiveTexture(GL_TEXTURE0);
            }
        if(glstate->clientstate.color_array) {
            gles_glDisableClientState(GL_COLOR_ARRAY);
            glstate->clientstate.color_array = 0;
        }
        if(glstate->clientstate.normal_array) {
            gles_glDisableClientState(GL_NORMAL_ARRAY);
            glstate->clientstate.normal_array = 0;
        }
        gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        if(customvp)
            popViewport();

        gl4es_glPopClientAttrib();
        gl4es_glMatrixMode(GL_TEXTURE);
        gl4es_glLoadMatrixf(old_texture);
        gl4es_glMatrixMode(GL_MODELVIEW);
        gl4es_glLoadMatrixf(old_modelview);
        gl4es_glMatrixMode(GL_PROJECTION);
        gl4es_glLoadMatrixf(old_projection);
    }
    // All the previous states are Pushed / Poped anyway...
    if (old_bind == NULL) 
        gles_glBindTexture(GL_TEXTURE_2D, 0);
    else
        gles_glBindTexture(GL_TEXTURE_2D, old_bind->glname);

    if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0+old_tex);
    if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0+old_cli);

    gl4es_glPopAttrib();
}