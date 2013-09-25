#include "Position.hpp"

namespace Engine {

Position::Position(float _x, float _y, float _z, float _w) :
    x(_x), y(_y), z(_z), w(_w) {

}

std::istream& operator>>(std::istream&in, Position&self) {
    return in>>self.x>>self.y>>self.z>>self.w;
}

std::ostream& operator<<(std::ostream&out,Position&self) {
    return out<<"{ x: "<<self.x<<", y: "<<self.y<<", z: "<<self.z<<", w: "<<self.w<<" }";
}

void Position::transform(glm::mat4 transformation){
    glm::vec4 res = glm::vec4(x,y,z,w) * transformation;
    x = res.x;
    y = res.y;
    z = res.z;
    w = res.w;
}
}
