#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Engine/Triangle.hpp"
#include <glm/glm.hpp>
#include <vector>

namespace Engine {

class Object {
private:
    std::vector<Triangle> triangles;
public:
    std::vector<Triangle>& getTriangles();
    Object(const char* filename);
    void transform(glm::mat4 transformation);
};
}

#endif // OBJECT_HPP
