#include "World/Scene.hpp"

#include <math.h>
#include <iostream>

#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Main/Logger.hpp"
#include "Main/Uniform.hpp"
#include "Main/Commons.hpp"
#include "Main/Controller.hpp"

#include "Engine/MatrixStack.hpp"
#include "Engine/Vertex.hpp"
#include "Engine/Triangle.hpp"
#include "Engine/Object.hpp"

using namespace Engine;

namespace World{

const int amount = 70;

Scene::Scene():
        cube("../P3/Resources/cube2"),
        grass("../P3/Resources/grass"),
        tree("../P3/Resources/tree"),
        skies("../P3/Resources/skies"){
    cube.transform(glm::mat4(1,0,0,0,   0,1,0,0,    0,0,0.333333333333333,0.666666666666667, 0,0,0,1));
    cube.transform(glm::mat4(2,0,0,0,   0,2,0,0,    0,0,2,0,    0,0,0,1));

    positions = new glm::vec2[amount];
    for(int i = 0; i<amount; ++i) {
        positions[i] = glm::vec2(random()%100-50.0,random()%100-50.0);
    }

}

Scene* Scene::instance = new Scene;

Scene* Scene::getInstance() {
    return Scene::instance;
}

void scale(MatrixStack& stack, float scale) {
    stack.scale(glm::vec3(scale/4,scale/4,scale));
}

void trans(MatrixStack& stack, float z) {
    stack.translate(glm::vec3(0,0,z));
}


void Scene::render() {
    Main::Controller::initObject(&skies);
    Main::Controller::drawObject();
    Main::Controller::initObject(&grass);
    Main::Controller::drawObject();

    Main::Controller::initObject(&cube);

    for(int i =0; i<amount/2; ++i) {
        glUniformMatrix4fv(Main::Uniform::modelToWorldMatrix,1,GL_FALSE,
                           glm::value_ptr(glm::translate(glm::mat4(),glm::vec3(positions[i].x,0.0f,positions[i].y))));
        Main::Controller::drawObject();
    }

    Main::Controller::initObject(&tree);
    for(int i =amount/2; i<amount; ++i) {
        glUniformMatrix4fv(Main::Uniform::modelToWorldMatrix,1,GL_FALSE,
                           glm::value_ptr(glm::translate(glm::mat4(),glm::vec3(positions[i].x,0.0f,positions[i].y))));
        Main::Controller::drawObject();
    }

    glutPostRedisplay();
}

}
