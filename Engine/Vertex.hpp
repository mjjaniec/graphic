#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "Engine/Position.hpp"
#include "Engine/Color.hpp"
#include <iostream>
#include <glm/glm.hpp>

namespace Engine {

#pragma pack(push)
#pragma pack(16)
class Vertex {
private:
    Position position;
    Color color;
public: 
    Vertex(float x=0.0f, float y=0.0f, float z=1.0f, float w=1.0f);
    Vertex(Position position, Color color);
    void transform(glm::mat4 transformation);
    friend std::istream& operator>>(std::istream&in, Vertex&v);
    friend std::ostream& operator<<(std::ostream&out, Vertex&v);

};
#pragma pack(pop)

}

#endif // VERTEX_HPP
