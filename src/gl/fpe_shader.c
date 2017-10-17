#include "fpe_shader.h"

const char* dummy_vertex = \
"varying vec4 Color; \n"
"void main() {\n"
"Color = gl_Color;\n"
"gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
"}";

const char* dummy_frag = \
"varying vec4 Color; \n"
"void main() {\n"
"gl_FragColor = Color;\n"
"}\n";

const char* const* fpe_VertexShader() {
    return &dummy_vertex;
}

const char* const* fpe_FragmentShader() {
    return &dummy_frag;
}

