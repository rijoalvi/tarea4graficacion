    #ifndef ESCENA_H
    #define ESCENA_H
    #include "axis.h"
    class Escena {
    private:
    Axis ejes;
    GLuint Draw_type;
    GLfloat vertices[8][3];
    public:
    Escena();
    void setDrawType(GLuint drawtype);
    void draw();
    };
    #endif
