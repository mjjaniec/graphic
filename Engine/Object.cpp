#include "Engine/Object.hpp"
#include <fstream>

namespace Engine{

Object::Object(const char *filename) {
    std::ifstream in(filename);

    Triangle t;
    while(in>>t){
        triangles.push_back(t);
    }
}

void Object::transform(glm::mat4 transformation) {
    for(Triangle&t:triangles){
        t.transform(transformation);
    }
}

std::vector<Triangle>& Object::getTriangles(){
    return triangles;
}
}
