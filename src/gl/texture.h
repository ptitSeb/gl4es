#include "gl.h"

#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

void glshim_glTexImage2D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data);

void glshim_glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data);

void glshim_glTexImage3D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLsizei depth,
                  GLint border, GLenum format, GLenum type, const GLvoid *data);

void glshim_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLenum format, GLenum type,
                     const GLvoid *data);
                     
void glshim_glTexSubImage1D(GLenum target, GLint level, GLint xoffset,
                     GLsizei width, GLenum format, GLenum type,
                     const GLvoid *data);
                     
void glshim_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, 
                     GLsizei width, GLsizei height, GLsizei depth, GLenum format,
                     GLenum type, const GLvoid *data);

void glshim_glBindTexture(GLenum target, GLuint texture);
void glshim_glGenTextures(GLsizei n, GLuint * textures);
void glshim_glDeleteTextures(GLsizei n, const GLuint * textures);
void glshim_glTexParameteri(GLenum target, GLenum pname, GLint param);
void glshim_glTexParameterf(GLenum target, GLenum pname, GLfloat param);
GLboolean glshim_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences);
void glshim_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
void glshim_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img);
void glshim_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data);

void glshim_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLint border,
							GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLint border,
							GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLsizei depth, GLint border,
							GLsizei imageSize, const GLvoid *data);
							
void glshim_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
							   GLsizei width, GLsizei height, GLenum format, 
							   GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset,
							   GLsizei width, GLenum format, 
							   GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
							   GLsizei width, GLsizei height, GLsizei depth, GLenum format, 
							   GLsizei imageSize, const GLvoid *data);
                               
void glshim_glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img);

                               
void glshim_glCopyTexImage1D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  
								GLsizei width,  GLint border);

void glshim_glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  
								GLsizei width,  GLsizei height,  GLint border);

void glshim_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height);
                                
void glshim_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y,
                                GLsizei width);

void glshim_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height);
                                
                               
void tex_coord_rect_arb(GLfloat *tex, GLsizei len,
                        GLsizei width, GLsizei height);
void tex_coord_npot(GLfloat *tex, GLsizei len,
                    GLsizei width, GLsizei height,
                    GLsizei nwidth, GLsizei nheight);
int npot(int n);

typedef struct {
    GLuint texture;
    GLuint glname;
    GLenum target;
    GLsizei width;
    GLsizei height;
    GLsizei nwidth;
    GLsizei nheight;
    GLenum  format;
    GLenum  type;
    GLenum  orig_internal;
    GLenum  internalformat;
    int shrink;
    GLboolean mipmap_auto;
    GLboolean mipmap_need;
	GLenum min_filter;
	GLenum mag_filter;
    GLboolean uploaded;
    GLboolean alpha;
    GLboolean compressed;
	GLboolean streamed;
	int	streamingID;
    GLvoid *data;	// in case we want to keep a copy of it (it that case, always RGBA/GL_UNSIGNED_BYTE
} gltexture_t;

KHASH_MAP_INIT_INT(tex, gltexture_t *)

static inline GLenum map_tex_target(GLenum target) {
    switch (target) {
        case GL_TEXTURE_1D:
        case GL_TEXTURE_3D:
        case GL_TEXTURE_RECTANGLE_ARB:
            target = GL_TEXTURE_2D;
            break;
        case GL_PROXY_TEXTURE_1D:
        case GL_PROXY_TEXTURE_3D:
            target = GL_PROXY_TEXTURE_2D;
            break;
    }
    return target;
}
gltexture_t* glshim_getTexture(GLenum target, GLuint texture);

void glshim_glActiveTexture( GLenum texture );
void glshim_glClientActiveTexture( GLenum texture );
void glshim_glMultiTexCoord2f( GLenum target, GLfloat s, GLfloat t );
GLboolean glshim_glIsTexture( GLuint texture );

void tex_setup_texcoord(GLuint texunit, GLuint len);

#endif
