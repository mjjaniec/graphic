#include "Engine/Vertex.hpp"

namespace Engine {

Vertex::Vertex(float x, float y, float z, float w) :
    position(x,y,z,w) {

}

Vertex::Vertex(Position _position, Color _color) :
    position(_position), color(_color) {

}

void Vertex::transform(glm::mat4 transformation){
    position.transform(transformation);
}

std::istream& operator>>(std::istream&in, Vertex&v) {
    return in>>v.position>>v.color;
}

std::ostream& operator<<(std::ostream&out, Vertex&v){
    return out<<"{ position: "<<v.position<<", color: "<<v.color<<" }";
}

}
