#include "Tree.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace World{

Tree::Tree(glm::vec2 position)
    :ObjectBase(position)
{
}

void Tree::shoot(){

}

glm::mat4 Tree::matrix() {
    return glm::translate(glm::mat4(),glm::vec3(position.x,0,position.y));
}

}
