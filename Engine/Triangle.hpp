#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Engine/Vertex.hpp"
#include <iostream>
#include <glm/glm.hpp>

namespace Engine {

class Triangle {
public:
    Vertex v1, v2, v3;
    Triangle();
    Triangle(Vertex v1, Vertex _v2, Vertex _v3);
    void transform(glm::mat4 transformation);
    friend std::istream& operator>>(std::istream& in, Triangle&v);
    friend std::ostream& operator<<(std::ostream& out, Triangle&v);
};

}

#endif // TRIANGLE_HPP
