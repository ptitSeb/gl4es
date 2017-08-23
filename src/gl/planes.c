#include "planes.h"
#include "../glx/hardext.h"
#include "matrix.h"
#include "matvec.h"

void gl4es_glClipPlanef(GLenum plane, const GLfloat *equation)
{
    /*
        When glClipPlane is called, 
        equation is transformed by the inverse of the modelview matrix and stored in the resulting eye coordinates. 
        Subsequent changes to the modelview matrix have no effect on the stored plane-equation components. 
        If the dot product of the eye coordinates of a vertex with the stored plane equation components is positive or zero, 
        the vertex is in with respect to that clipping plane. Otherwise, it is out.
    */
    PUSH_IF_COMPILING(glClipPlanef);    //TODO: fix that, equation is an array and should be copied before beeing put in the stack
    if(plane<GL_CLIP_PLANE0 || plane>=GL_CLIP_PLANE0+hardext.maxplanes) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    LOAD_GLES(glClipPlanef);
    if(gles_glClipPlanef) {
        errorGL();
        gles_glClipPlanef(plane, equation);
    } else {
        int p = plane-GL_CLIP_PLANE0;
        GLfloat ModelviewMatrix[16], InvModelview[16];
        gl4es_glGetFloatv(GL_MODELVIEW_MATRIX, InvModelview);
        // column major -> row major
        matrix_transpose(InvModelview, ModelviewMatrix);
        // And get the inverse
        matrix_inverse(ModelviewMatrix, InvModelview);
        matrix_vector(ModelviewMatrix, equation, glstate->planes[p]);
        noerrorShim();
    }
}

void glClipPlanef(GLenum pname, const GLfloat* params) AliasExport("gl4es_glClipPlanef");