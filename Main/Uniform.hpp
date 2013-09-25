#ifndef UNIFORM_HPP
#define UNIFORM_HPP

#include <GL/freeglut.h>

namespace Main {
    namespace Uniform {
        extern GLuint windowWidth;
        extern GLuint windowHeight;
        extern GLuint modelToWorldMatrix;
        extern GLuint worldToCameraMatrix;
        extern GLuint cameraToClipMatrix;
    }
}

#endif // UNIFORM_HPP
