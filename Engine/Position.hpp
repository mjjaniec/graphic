#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>
#include <glm/glm.hpp>

namespace Engine {

class Position
{
public:
    float x, y, z, w;
    Position(float x=0.0f, float y=0.0f, float z=1.0f, float w=1.0f);
    void transform(glm::mat4 transformation);
    friend std::istream& operator>>(std::istream&in, Position&self);
    friend std::ostream& operator<<(std::ostream&out,Position&self);
};

}

#endif // POSITION_HPP
