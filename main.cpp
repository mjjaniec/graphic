#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>

#include "Main/Logger.hpp"
#include "Main/Config.hpp"
#include "Main/Controller.hpp"

using namespace Main;

static GLuint CreateShader(GLenum eShaderType, const char* shaderFileName)
{
    GLuint shader = glCreateShader(eShaderType);
    std::ifstream input(shaderFileName);
    if(!input.is_open()){
        Log_error << "can not open shader file\n";
        exit(-1);
    }
    std::string str((std::istreambuf_iterato.r<char>(input)),std::istreambuf_iterator<char>());
    char* c_str = str.c_str();
    glShaderSource(shader, 1, &c_str , NULL);

    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

        const char *strShaderType = NULL;
        switch(eShaderType)
        {
        case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
        case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
        case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
        }

        Log_error << "Compile failure in " << strShaderType << " shader:\n" << strInfoLog << "\n";
        delete[] strInfoLog;
    }

    return shader;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;

    glutInitDisplayMode (displayMode);
    glutInitContextVersion (3, 1);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInitWindowSize (Config::WIDTH, Config::HEIGHT);
    int window = glutCreateWindow (argv[0]);

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_EXIT);

    glutDisplayFunc(Controller::renderFunc);
    glutReshapeFunc(Controller::reshapeFunc);
    glutKeyboardFunc(Controller::keyboardFunc);
    glutMouseFunc(Controller::mouseFunc);

    glutMainLoop();
    return 0;
}
