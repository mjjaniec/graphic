#ifndef POSITION_HPP
#define POSITION_HPP

namespace Engine {

class Position
{
public:
    float x, y, z, w;
    Position(float x=0.0f, float y=0.0f, float z=1.0f, float w=1.0f);
};

}

#endif // POSITION_HPP
