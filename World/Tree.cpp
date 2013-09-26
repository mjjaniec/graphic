#include "Tree.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace World{

Tree::Tree(glm::vec2 position)
    :ObjectBase(position)
{
    x= false;
}

void Tree::shoot(){
    x = true;
}

glm::mat4 Tree::matrix() {
    if(x==true){
        return glm::rotate(glm::translate(glm::mat4(),glm::vec3(position.x,0.0f,position.y)),-90.0f,glm::vec3(0.0f,0.0f,1.0f));
    }
    return glm::translate(glm::mat4(),glm::vec3(position.x,0,position.y));
}

}
