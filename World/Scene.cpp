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

Scene::Scene():cube("../P3/Resources/cube2"){
    cube.transform(glm::mat4(1,0,0,0, 0,1,0,0, 0,0,0.333333333333333,0.666666666666667, 0,0,0,1));
}

Scene* Scene::instance = new Scene;

Scene* Scene::getInstance() {
    return Scene::instance;
}

void draw(MatrixStack& matrixStack) {
    glUniformMatrix4fv(Main::Uniform::modelToWorldMatrix,1,GL_FALSE,glm::value_ptr(matrixStack.Top()));
    Main::Controller::drawObject();
}

void Scene::render() {
    Main::Controller::initObject(&cube);

    MatrixStack stack;


    stack.Push();
    {
        stack.Translate(glm::vec3(0.5,0,0));
        stack.Scale(glm::vec3(1,1,4));
        draw(stack);
    }
    stack.Pop();
    stack.Push();
    {
        stack.Translate(glm::vec3(-0.5,0,0));
        stack.Scale(glm::vec3(1,1,4));
        draw(stack);
    }
    stack.Pop();
    stack.Push();
    {
        stack.Translate(glm::vec3(0,0,-1));
        stack.RotateX(-45);
        stack.Translate(glm::vec3(0,0,1));
        stack.Push();
        {
            stack.Scale(glm::vec3(1,1,4));
            draw(stack);
        }
        stack.Pop();
        stack.Push();
        {
        //    stack.Translate(glm::vec3(0,0,0.6));
            stack.Scale(glm::vec3(0.75,0.75,2));
            stack.RotateX(+105);
            draw(stack);
        }
        stack.Pop();
    }
    stack.Pop();
}

}
