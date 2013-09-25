#include "Engine/Object.hpp"
#include <fstream>
#include "Main/Logger.hpp"

namespace Engine{

Object::Object(const char *filename) {
    std::ifstream in(filename);

    if(!in.good()) {
        Log_error << "cannot open file: "<<filename<<"\n\n";
        exit(-1);
    }

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

std::ostream& operator<<(std::ostream& out, Object&self) {
    out<<" { triangles: [ ";
    for(Triangle& triangle : self.getTriangles()) {
        out << triangle << ", ";
    }
    out<<" ] }";
}
}
