
#include "Main/Controller.hpp"
#include <GL/gl.h>
#include <GL/freeglut.h>

namespace Main {

void Controller::renderFunc() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();

}

void Controller::keyboardFunc(unsigned char key, int x, int y) {

}

void Controller::mouseFunc(int button, int state, int x, int y) {

}

void Controller::reshapeFunc(int width, int height) {
    Controller::width = width;
    Controller::height = height;
}

int Controller::getWidth() {
    return Controller::width;
}

int Controller::getHeight() {
    return Controller::height;
}

int Controller::width;
int Controller::height;
}
