#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <vector>
#include <map>

#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Engine/Triangle.hpp>
#include <Engine/Object.hpp>

namespace Main {
    class Controller {
    public:
        static void renderFunc();
        static void mouseFunc(int button, int state, int x, int y);
        static void keyboardFunc(unsigned char key, int x, int y);
        static void reshapeFunc(int width, int height);
        static int getWidth();
        static int getHeight();
        static std::vector<Engine::Triangle>* getTriangles();
        static GLuint getProgram();
        static void setProgram(GLuint program);
        static GLuint getVertexBuffer();
        static void setVertexBuffer(GLuint vertexBuffer);
        static void init();
        static void initObject(Engine::Object* object);
        static void drawObject();
        static void drawAxes();

    private:
        static int width;
        static int height;
        static GLuint program;
        static GLuint vertexBuffer;

        static glm::fquat orientation;
        static std::vector<Engine::Triangle> triangles;
        static Engine::Object axes;
        static Engine::Object*object;
        static float pitch;
        static float yaw;
        static float roll;
        static glm::vec2 position;
    private:
        static void updateWorldToCameraMatrix();
        static void updateCameraToClipMatrix();
        static void bufferTriangles();
    };
}

#endif // CONTROLLER_HPP
