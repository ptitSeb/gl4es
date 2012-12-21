#include <GLES/gl.h>
#include <math.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846

void gluPerspective(double fovy, double aspect, double near, double far) {
    printf("gluPerspective(%.1f, %.1f, %.1f, %.1f);\n", fovy, aspect, near, far);
    GLfloat m[16];
    double si, co, dz;
    double rad = fovy / 2 * M_PI / 180;
    double a, b, c, d;

    dz = far - near;
    si = sin(rad);
    if (dz == 0 || si == 0 || aspect == 0)
        return;
    co = cos(rad) / si;

    a = co / aspect;
    b = co;
    c = -(far + near) / dz;
    d = -2 * near * far / dz;

    # define M(X,Y)  m[Y * 4 + X]
    M(0,0) = a; M(0,1) = 0; M(0,2) = 0;  M(0,3) = 0;
    M(1,0) = 0; M(1,1) = b; M(1,2) = 0;  M(1,3) = 0;
    M(2,0) = 0; M(2,1) = 0; M(2,2) = c;  M(2,3) = d;
    M(3,0) = 0; M(3,1) = 0; M(3,2) = -1; M(3,3) = 0;
    # undef M

    glMultMatrixf (m);
}
