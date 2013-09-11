#include "World/Scene.hpp"

#include <math.h>

#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>

#include "Main/Logger.hpp"
#include "Main/Uniform.hpp"
#include "Main/Commons.hpp"
#include "Main/Controller.hpp"

#include "Engine/Vertex.hpp"
#include "Engine/Triangle.hpp"

namespace World{

Scene* Scene::instance = new Scene;

Scene* Scene::getInstance() {
    return Scene::instance;
}

static float sin2(float x) {
    return 0.5f + sin(x) / 2.0f;
}

void Scene::render() {
    auto triangles = Main::Controller::getTriangles();
    triangles->clear();
    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    glUniform1f(Main::Uniform::phase,elapsedTime);
    triangles->push_back(Engine::Triangle(
                             Engine::Vertex(Engine::Position(-0.75, -0.75), Engine::Color(sin2(10+elapsedTime), sin2(9-elapsedTime), sin2(9+elapsedTime))),
                            Engine::Vertex(Engine::Position(+0.75, -0.75), Engine::Color(sin2(2-elapsedTime), sin2(3+elapsedTime), sin2(3-elapsedTime))),
                            Engine::Vertex(Engine::Position(-0.75, +0.75), Engine::Color(sin2(3+elapsedTime), sin2(1+elapsedTime), sin2(6+elapsedTime)))));
    triangles->push_back(Engine::Triangle(
                             Engine::Vertex(Engine::Position(+0.75, +0.75), Engine::Color(sin2(3+elapsedTime), sin2(25+elapsedTime), sin2(0+elapsedTime))),
                            Engine::Vertex(Engine::Position(+0.75, -0.75), Engine::Color(sin2(2-elapsedTime), sin2(3+elapsedTime), sin2(3-elapsedTime))),
                            Engine::Vertex(Engine::Position(-0.75, +0.75), Engine::Color(sin2(3+elapsedTime), sin2(1+elapsedTime), sin2(6+elapsedTime)))));

}

}
