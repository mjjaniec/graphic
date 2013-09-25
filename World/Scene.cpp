#include "World/Scene.hpp"

#include <math.h>
#include <iostream>

#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "Main/Logger.hpp"
#include "Main/Uniform.hpp"
#include "Main/Commons.hpp"
#include "Main/Controller.hpp"

#include "Engine/Vertex.hpp"
#include "Engine/Triangle.hpp"
#include "Engine/Object.hpp"

using namespace Engine;

namespace World{
bool inited = false;

Scene* Scene::instance = new Scene;

Scene* Scene::getInstance() {
    return Scene::instance;
}

static float sin2(float x) {
    return 0.5f + sin(x) / 2.0f;
}

void Scene::render() {
    auto triangles = Main::Controller::getTriangles();
    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

    if(!inited) {
       /*std::ifstream in("../P3/Resurces/cube2");

        triangles->clear();

        Triangle t;
        while(in>>t){
            triangles->push_back(t);
            std::cout<<t<<"\n\n";
        }
        inited = true;*/
        Object cube("../P3/Resources/cube2");
        Object cube2("../P3/Resources/cube2");

        cube2.transform(glm::mat4(
                            1,0,0,0,
                            0,1,0,0,
                            0,0,1,2,
                            0,0,0,1));

        triangles->insert(triangles->end(),cube.getTriangles().begin(),cube.getTriangles().end());
        triangles->insert(triangles->end(),cube2.getTriangles().begin(),cube2.getTriangles().end());
    }
}

}
