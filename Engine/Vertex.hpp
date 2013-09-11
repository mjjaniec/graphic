#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "Engine/Position.hpp"
#include "Engine/Color.hpp"

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
};
#pragma pack(pop)

}

#endif // VERTEX_HPP
