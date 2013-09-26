
#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Main/Logger.hpp"
#include "Main/Commons.hpp"
#include "Main/Uniform.hpp"
#include "Main/Controller.hpp"
#include "World/Scene.hpp"

namespace Main {



void Controller::init() {
    glUseProgram(Controller::getProgram());
    updateCameraToClipMatrix();
    updateWorldToCameraMatrix();
    glUniformMatrix4fv(Uniform::modelToWorldMatrix,1,GL_FALSE,glm::value_ptr(glm::mat4()));
    glUseProgram(nullobj);
}

void Controller::drawAxes() {
    glUniformMatrix4fv(Uniform::modelToWorldMatrix,1,GL_FALSE,glm::value_ptr(glm::mat4()));
    glDisable(GL_CULL_FACE);
    initObject(&axes);
    drawObject();
    glEnable(GL_CULL_FACE);
}

void Controller::renderFunc() {

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(Controller::getProgram());

    drawAxes();

    World::Scene::getInstance()->render();

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glUseProgram(nullobj);

    glutSwapBuffers();
}

void Controller::initObject(Engine::Object* object){
    Controller::object = object;
    glBindBuffer(GL_ARRAY_BUFFER, getVertexBuffer());

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 32, (GLvoid*)0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 32, (GLvoid*)16);

    int newSize = object->getTriangles().size()*sizeof(Engine::Triangle);
    if(newSize == 0) {
        Log_error << "empty model\n";
        exit(-1);
    }

   glBufferData(GL_ARRAY_BUFFER, newSize, object->getTriangles().data(), GL_STREAM_DRAW);
}

void Controller::drawObject() {
    glDrawArrays(GL_TRIANGLES, 0, 3*object->getTriangles().size());
}

void Controller::updateCameraToClipMatrix() {
    const float fovy = M_PI / 6.0;
    const float n = 1, f = 3;
    float frustum = 1.0 / (tan(fovy/2.0));
    glUniformMatrix4fv(Main::Uniform::cameraToClipMatrix,1,GL_FALSE,glm::value_ptr(glm::mat4(
        frustum / Controller::getWidth() * Controller::getHeight(), 0, 0, 0,
        0, frustum, 0, 0,
        0, 0, (n+f)/(n-f), 2*n*f/(n-f),
        0, 0, -1, 0 )));
}

float yRotation = 0;
float xRotation = 0;

void Controller::updateWorldToCameraMatrix() {
    glUseProgram(getProgram());
    glm::mat4 worldToCamera = glm::mat4(1.0f);
    worldToCamera = glm::translate(worldToCamera,glm::vec3(0.0f, 0.0f, -4.0f));
    worldToCamera = glm::rotate(worldToCamera,xRotation,glm::vec3(-1.0f, 0.0f, 0.0f));
    worldToCamera = glm::rotate(worldToCamera,yRotation,glm::vec3(-0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(Uniform::worldToCameraMatrix,1,GL_FALSE,glm::value_ptr(worldToCamera));
}

void Controller::keyboardFunc(unsigned char key, int x, int y) {
    x = y;
    y = x;
    const float step = 5;
    switch (key)
    {
    case 'a': yRotation += step; break;
    case 'd': yRotation -= step; break;

    case 'w': xRotation += step; break;
    case 's': xRotation -= step; break;

    case 27:
        glutLeaveMainLoop();
        break;
    }
    Controller::updateWorldToCameraMatrix();
    glutPostRedisplay();
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
    updateCameraToClipMatrix();
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

int Controller::width = 1;
int Controller::height = 1;
std::vector<Engine::Triangle> Controller::triangles;
GLuint Controller::program;
GLuint Controller::vertexBuffer;
Engine::Object Controller::axes("../P3/Resources/axes");
Engine::Object* Controller::object;

}
