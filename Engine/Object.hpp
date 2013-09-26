#ifndef ENGINE_OBJECT_HPP
#define ENGINE_OBJECT_HPP

#include "Engine/Triangle.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

namespace Engine {

class Object {
private:
    std::vector<Triangle> triangles;
public:
    std::vector<Triangle>& getTriangles();
    Object(const char* filename);
    void transform(glm::mat4 transformation);
    friend std::ostream& operator<<(std::ostream& out, Object& self);
};
}

#endif // OBJECT_HPP
