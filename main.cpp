#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>

#include "Main/Logger.hpp"
#include "Main/Config.hpp"
#include "Main/Commons.hpp"
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


    GLuint phase = glGetUniformLocation(Controller::getProgram(), "phase");
}
/*

void APIENTRY DebugFunc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                        const GLchar* message, const GLvoid* userParam)
{
    //suppres warning - begin
    id=length+(int)userParam;
    //suppres warning - end
    std::string srcName;
    switch(source)
    {
    case GL_DEBUG_SOURCE_API_ARB: srcName = "API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB: srcName = "Window System"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER_ARB: srcName = "Shader Compiler"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY_ARB: srcName = "Third Party"; break;
    case GL_DEBUG_SOURCE_APPLICATION_ARB: srcName = "Application"; break;
    case GL_DEBUG_SOURCE_OTHER_ARB: srcName = "Other"; break;
    }

    std::string errorType;
    switch(type)
    {
    case GL_DEBUG_TYPE_ERROR_ARB: errorType = "Error"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB: errorType = "Deprecated Functionality"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB: errorType = "Undefined Behavior"; break;
    case GL_DEBUG_TYPE_PORTABILITY_ARB: errorType = "Portability"; break;
    case GL_DEBUG_TYPE_PERFORMANCE_ARB: errorType = "Performance"; break;
    case GL_DEBUG_TYPE_OTHER_ARB: errorType = "Other"; break;
    }

    std::string typeSeverity;
    switch(severity)
    {
    case GL_DEBUG_SEVERITY_HIGH_ARB: typeSeverity = "High"; break;
    case GL_DEBUG_SEVERITY_MEDIUM_ARB: typeSeverity = "Medium"; break;
    case GL_DEBUG_SEVERITY_LOW_ARB: typeSeverity = "Low"; break;
    }

    printf("%s from %s,\t%s priority\nMessage: %s\n",
        errorType.c_str(), srcName.c_str(), typeSeverity.c_str(), message);
}*/

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

   /* if(Config::DEBUG_INFO_ON)
    {
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
        glDebugMessageCallbackARB(DebugFunc, (void*)15);
    }*/

    init();

    glutDisplayFunc(Controller::renderFunc);
    glutReshapeFunc(Controller::reshapeFunc);
    glutKeyboardFunc(Controller::keyboardFunc);
    glutMainLoop();
    return 0;
}
