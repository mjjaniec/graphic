#include "Cube.hpp"
#include "glm/gtc/matrix_transform.hpp"
namespace World{

Cube::Cube(glm::vec2 position)
    :ObjectBase(position)
{
    x = false;
    angle = 0;
}

void Cube::shoot(){
    x = !x;
    angle = 0;
}

glm::mat4 Cube::matrix() {
    glm::mat4 m();
    if(x) {
        angle++;
        return glm::rotate(glm::translate(glm::mat4(),glm::vec3(position.x,0.0f,position.y)),angle,glm::vec3(0.0f,1.0f,0.0f));

    }
    return glm::translate(glm::mat4(),glm::vec3(position.x,0,position.y));
}


}
