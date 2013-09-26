#ifndef TREE_HPP
#define TREE_HPP

#include "World/ObjectBase.hpp"

namespace World {
class Tree : public ObjectBase
{
public:
    Tree(glm::vec2 position);
    void shoot();
    glm::mat4 matrix();
};

}

#endif // TREE_HPP
