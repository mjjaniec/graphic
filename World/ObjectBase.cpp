#include "World/ObjectBase.hpp"
#include <cmath>

namespace World{
ObjectBase::ObjectBase(glm::vec2 _position)
    :position(_position)
{
}

float ObjectBase::dist(glm::vec2 camera) {
    glm::vec2 diff = position - camera;
    return sqrt(diff.x*diff.x + diff.y*diff.y);
}

bool ObjectBase::isOnSight(float yaw, glm::vec2 camera) {
    glm::vec2 a = -glm::vec2(-sin(M_PI * yaw / 180.0), cos(M_PI * yaw / 180.0));
    glm::vec2 b = glm::normalize(position - camera);
    float product = a.x*b.y-a.y*b.x;
    if(product * dist(camera) > 1) {
        return false;
    }
    return a.x*b.x + a.y*b.y > 0;
}
}
