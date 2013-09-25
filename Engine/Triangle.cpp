#include "Engine/Triangle.hpp"

namespace Engine {

Triangle::Triangle(Vertex _v1, Vertex _v2, Vertex _v3)
    :v1(_v1), v2(_v2), v3(_v3) {

}

Triangle::Triangle(){

}

void Triangle::transform(glm::mat4 transformation) {
    v1.transform(transformation);
    v2.transform(transformation);
    v3.transform(transformation);
}

std::istream& operator>>(std::istream&in, Triangle&t) {
    return in>>t.v1>>t.v2>>t.v3;
}
std::ostream& operator<<(std::ostream&out, Triangle&t){
    return out<<"{ \nv1: "<<t.v1<<",\nv2: "<<t.v2<<",\nv3: "<<t.v3<<"\n}";
}
}
