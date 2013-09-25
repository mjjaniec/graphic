#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <vector>
#include <map>

#include <GL/freeglut.h>

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

    private:
        static int width;
        static int height;
        static GLuint program;
        static GLuint vertexBuffer;

        static std::vector<Engine::Triangle> triangles;
        static Engine::Object axes;
    private:
        static void updateWorldToCameraMatrix();
        static void updateCameraToClipMatrix();
        static void drawAxes();
        static void bufferTriangles();
    };
}

#endif // CONTROLLER_HPP
