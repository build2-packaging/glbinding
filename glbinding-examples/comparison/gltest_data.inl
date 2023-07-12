
struct vec2 {
  float x;
  float y;
};

const vec2 vertices[4] = {
    {+1.f, -1.f}, {+1.f, +1.f}, {-1.f, -1.f}, {-1.f, +1.f}};

const GLchar *vert = "#version 150\n"
                     "#extension GL_ARB_explicit_attrib_location : require\n"
                     "\n"
                     "layout (location = 0) in vec2 a_vertex;\n"
                     "\n"
                     "out vec4 color;\n"
                     "\n"
                     "void main()\n"
                     "{\n"
                     "    gl_Position = vec4(a_vertex, 0.0, 1.0);\n"
                     "    color = vec4(a_vertex * 0.5 + 0.5, 0.0, 1.0);\n"
                     "}\n";

const GLchar *frag = "#version 150\n"
                     "#extension GL_ARB_explicit_attrib_location : require\n"
                     "\n"
                     "layout (location = 0) out vec4 fragColor;\n"
                     "\n"
                     "in vec4 color;\n"
                     "\n"
                     "void main()\n"
                     "{\n"
                     "    fragColor = color;\n"
                     "}\n";

GLuint vao;
GLuint quad;
GLuint program;
GLuint vs;
GLuint fs;
GLuint a_vertex;
