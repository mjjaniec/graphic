#include "Cube.hpp"
#include "glm/gtc/matrix_transform.hpp"
namespace World{

Cube::Cube(glm::vec2 position)
    :ObjectBase(position)
{
}

void Cube::shoot(){

}

glm::mat4 Cube::matrix() {
    return glm::translate(glm::mat4(),glm::vec3(position.x,0,position.y));
}


}
