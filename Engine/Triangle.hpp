#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Engine/Vertex.hpp"

namespace Engine {

class Triangle {
public:
    Vertex v1, v2, v3;
    Triangle(Vertex v1, Vertex _v2, Vertex _v3);
};

}

#endif // TRIANGLE_HPP
