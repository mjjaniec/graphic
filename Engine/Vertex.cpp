#include "Engine/Vertex.hpp"

namespace Engine {

Vertex::Vertex(float x, float y, float z, float w) :
    position(x,y,z,w) {

}

Vertex::Vertex(Position _position, Color _color) :
    position(_position), color(_color) {

}

}
