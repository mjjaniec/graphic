
#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>

#include "Main/Logger.hpp"
#include "Main/Commons.hpp"
#include "Main/Uniform.hpp"
#include "Main/Controller.hpp"
#include "World/Scene.hpp"

namespace Main {

void Controller::renderFunc() {

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(Controller::getProgram());

    World::Scene::getInstance()->render();

    bufferTriangles();

    glDrawArrays(GL_TRIANGLES, 0, 3*triangles.size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glUseProgram(nullobj);

    glutSwapBuffers();
    glutPostRedisplay();
}

void Controller::bufferTriangles() {
    static int oldSize = -1;

    glBindBuffer(GL_ARRAY_BUFFER, getVertexBuffer());

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 32, (GLvoid*)0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 32, (GLvoid*)16);

    int newSize = triangles.size()*sizeof(Engine::Triangle);
    if(newSize != oldSize) {
        glBufferData(GL_ARRAY_BUFFER, newSize, triangles.data(), GL_STREAM_DRAW);
    } else {
        glBufferSubData(GL_ARRAY_BUFFER, 0, newSize, triangles.data() );
    }
    oldSize=newSize;
}

void Controller::keyboardFunc(unsigned char key, int x, int y) {
    x = y;
    y = x;
    switch (key)
    {
    case 27:
        glutLeaveMainLoop();
        break;
    }
}

void Controller::mouseFunc(int button, int state, int x, int y) {
    int supperes_warning = button + state + x + y;
    supperes_warning += 1;
}

void Controller::reshapeFunc(int width, int height) {
    Controller::width = width;
    Controller::height = height;
    glUseProgram(getProgram());
    glUniform1f(Uniform::windowHeight, height);
    glUniform1f(Uniform::windowWidth, width);
    glUseProgram(nullobj);
    glViewport(0, 0, width, height);
}

int Controller::getWidth() {
    return Controller::width;
}

int Controller::getHeight() {
    return Controller::height;
}

std::vector<Engine::Triangle>* Controller::getTriangles() {
    return &triangles;
}

void Controller::setProgram(GLuint program) {
    Controller::program = program;
}

GLuint Controller::getProgram() {
    return Controller::program;
}

GLuint Controller::getVertexBuffer() {
    return Controller::vertexBuffer;
}

void Controller::setVertexBuffer(GLuint vertexBuffer) {
    Controller::vertexBuffer = vertexBuffer;
}

int Controller::width;
int Controller::height;
std::vector<Engine::Triangle> Controller::triangles;
GLuint Controller::program;
GLuint Controller::vertexBuffer;

}
