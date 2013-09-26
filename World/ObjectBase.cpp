#include "World/ObjectBase.hpp"

static float abs(float f){
    return f<0?-f:f;
}

namespace World{
ObjectBase::ObjectBase(glm::vec2 _position)
    :position(_position)
{
}

std::ostream& operator<<(std::ostream&out,ObjectBase&self) {
    return out<<"[ "<<self.position.x<<", "<<self.position.y<<" ]";
}

float ObjectBase::dist(glm::vec2 camera) {
    glm::vec2 diff = position - camera;
    return sqrt(diff.x*diff.x + diff.y*diff.y);
}

bool ObjectBase::isOnSight(float yaw, glm::vec2 camera) {
    yaw = M_PI * yaw / 180.0;
    glm::vec2 look = glm::vec2(sin(yaw),-cos(yaw));
    glm::vec2 obj  = position - camera;

    float vectorProd = look.x*obj.y - look.y*obj.x;
    float scalarProd = look.x*obj.x + look.y*obj.y;

    if((-1 < vectorProd && vectorProd < 1) && scalarProd > 0)
    std::cout<<"obj: ["<<obj.x<<", "<<obj.y<<"]\t look: ["<<look.x<<", "<<look.y<<"] "<<"vectorProd: "<<vectorProd<<" scalarP:"<<scalarProd<<"\n";

    /*glm::vec2 pos = position;
    pos.y = -pos.y;
    glm::vec2 a = glm::vec2(-sin(M_PI * yaw / 180.0), cos(M_PI * yaw / 180.0));
    glm::vec2 b = glm::normalize(camera-pos);

    if(!(a.x*b.x + a.y*b.y < 0)) {
        return false;
    }

    float product = a.x*b.y-a.y*b.x;

    if(abs(product * dist(camera)) > 0.5) {
        return false;
    }
    std::cout<<"o: ["<<pos.x<<", "<<pos.y<<"]\t a: ["<<a.x<<", "<<a.y<<"] \t b: ["<<b.x<<", "<<b.y<<"]"
            <<"\t prod: "<<product<<"\t dist: "<<dist(camera)<<"xx: "<<abs(product * dist(camera))<<"\n";
    return true;*/
    return false;

}
}
