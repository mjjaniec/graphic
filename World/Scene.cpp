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

void scale(MatrixStack& stack, float scale) {
    stack.scale(glm::vec3(scale/4,scale/4,scale));
}

void trans(MatrixStack& stack, float z) {
    stack.translate(glm::vec3(0,0,z));
}


void Scene::render() {
    Main::Controller::initObject(&cube);

    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    MatrixStack stack;

    const float factor = 4.0f;
    float baseLength = 4.0f;
    float arm1Angle = -45.0f + 15 * sin(elapsedTime);
    float arm1Length = 4.0f;
    float arm2Length = 2.0f + cos(elapsedTime*2);
    float arm2Angle = 15 + 30 * sin(elapsedTime*4);


    stack.push();
    {
        stack.push();
        {
            stack.translate(glm::vec3(0.5,0,0));
            scale(stack,baseLength);
            draw(stack);
        }
        stack.pop();
        stack.push();
        {
            stack.translate(glm::vec3(-0.5,0,0));
            scale(stack,baseLength);
            draw(stack);
        }
        stack.pop();

        trans(stack,-baseLength/factor);

        stack.push();
        {
            stack.rotateX(arm1Angle);
            trans(stack,arm1Length/factor);
            stack.push();
            {
                scale(stack,arm1Length);
                draw(stack);
            }
            stack.pop();

            trans(stack,0.9*arm1Length/factor);

            stack.push();
            {
                stack.rotateX(arm2Angle);
                trans(stack,arm2Length/factor);
                stack.push();
                {
                    scale(stack,arm2Length);
                    draw(stack);
                }
                stack.pop();
            }
            stack.pop();
        }
        stack.pop();

    }
    stack.pop();

    glutPostRedisplay();
}

}
