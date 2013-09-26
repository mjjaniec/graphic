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


namespace World{

Scene::Scene():
        cube("../P3/Resources/cube2"),
        grass("../P3/Resources/grass"),
        tree("../P3/Resources/tree"),
        skies("../P3/Resources/skies"){
    cube.transform(glm::mat4(1,0,0,0,   0,1,0,0,    0,0,0.333333333333333,0.666666666666667, 0,0,0,1));
    cube.transform(glm::mat4(2,0,0,0,   0,2,0,0,    0,0,2,0,    0,0,0,1));

    int nTrees = 60;
    int nCubes = 25;

    for(int i = 0; i< nCubes; ++i) {
        Cube* cube = new Cube(glm::vec2(random()%100-50,random()%100-50));
        cubes.push_back(cube);
        objects.push_back(cube);
    }

    for(int i = 0; i< nTrees; ++i) {
        Tree* tree = new Tree(glm::vec2(random()%100-50,random()%100-50));
        trees.push_back(tree);
        objects.push_back(tree);
    }

}

Scene* Scene::instance = new Scene;

Scene* Scene::getInstance() {
    return Scene::instance;
}

void Scene::fire(glm::vec2 position, float yaw){

}


void Scene::render() {
    Main::Controller::initObject(&skies);
    Main::Controller::drawObject();
    Main::Controller::initObject(&grass);
    Main::Controller::drawObject();

    Main::Controller::initObject(&cube);
    for(Cube* cube:cubes) {
        glUniformMatrix4fv(Main::Uniform::modelToWorldMatrix,1,GL_FALSE,glm::value_ptr(cube->matrix()));
        Main::Controller::drawObject();
    }

    Main::Controller::initObject(&tree);
    for(Tree* tree:trees) {
        glUniformMatrix4fv(Main::Uniform::modelToWorldMatrix,1,GL_FALSE,glm::value_ptr(tree->matrix()));
        Main::Controller::drawObject();
    }

    glutPostRedisplay();
}

}
