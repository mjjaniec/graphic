#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <exception>
#include <stdexcept>

#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>

#include "Main/Logger.hpp"
#include "Main/Config.hpp"
#include "Main/Commons.hpp"
#include "Main/Uniform.hpp"
#include "Main/Controller.hpp"

using namespace Main;

static GLuint CreateShader(GLenum eShaderType, const char* shaderFileName) {
    GLuint shader = glCreateShader(eShaderType);
    std::ifstream input(shaderFileName);
    if(!input.is_open()) {
        Log_error << "can not open shader file\n";
        exit(-1);
    }
    std::string str((std::istreambuf_iterator<char>(input)),std::istreambuf_iterator<char>());
    const char* c_str = str.c_str();
    glShaderSource(shader, 1, &c_str, nullptr);

    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, nullptr, strInfoLog);

        const char *strShaderType = nullptr;
        switch (eShaderType) {
        case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
        case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
        case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
        }

        Log_error << "Compile failure in " << strShaderType << " shader:\n" << strInfoLog << "\n";
        delete[] strInfoLog;
        exit(-1);
    }

    return shader;
}

void init() {
    GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, Config::VERTEX_SHADER());
    GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, Config::FRAGMENT_SHADER());

    Controller::setProgram(glCreateProgram());

    glAttachShader(Controller::getProgram(), vertexShader);
    glAttachShader(Controller::getProgram(), fragmentShader);
    glLinkProgram(Controller::getProgram());

    GLint status;
    glGetProgramiv(Controller::getProgram(), GL_LINK_STATUS, &status);
    if(status == GL_FALSE) {
       GLint infoLogLength;
       glGetProgramiv(Controller::getProgram(), GL_INFO_LOG_LENGTH, & infoLogLength);
       GLchar* infoString = new GLchar[infoLogLength + 1];
       glGetProgramInfoLog(Controller::getProgram(), infoLogLength, nullptr, infoString);
       Log_error << "Link failure: " << infoString << "\n";
       delete[] infoString;
       exit(-1);
    }

    GLuint bufferID;
    GLuint vao;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &bufferID);
    Controller::setVertexBuffer(bufferID);


    Uniform::phase = glGetUniformLocation(Controller::getProgram(), "phase");
    Uniform::windowHeight = glGetUniformLocation(Controller::getProgram(), "windowHeight");
    Uniform::windowWidth = glGetUniformLocation(Controller::getProgram(), "windowWidth");
    Uniform::perspectiveMatrix = glGetUniformLocation(Controller::getProgram(), "perspectiveMatrix");
    Uniform::offset = glGetUniformLocation(Controller::getProgram(),"offset");

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 1.0f);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;

    glutInitDisplayMode(displayMode);
    glutInitContextVersion (3, 1);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutInitWindowSize (Config::WIDTH, Config::HEIGHT);
    glutCreateWindow (Config::TITLE());

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_EXIT);

    glload::LoadFunctions();

    init();

    glutDisplayFunc(Controller::renderFunc);
    glutReshapeFunc(Controller::reshapeFunc);
    glutKeyboardFunc(Controller::keyboardFunc);
    glutMainLoop();
    return 0;
}
