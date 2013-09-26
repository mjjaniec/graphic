#ifndef MATRIXSTACK_HPP
#define MATRIXSTACK_HPP

#include <stack>
#include <glm/glm.hpp>

namespace Engine {
class MatrixStack
{
public:
    MatrixStack();

    const glm::mat4 &Top();
    void rotateX(float fAngDeg);
    void rotateY(float fAngDeg);
    void rotateZ(float fAngDeg);
    void scale(const glm::vec3 &scaleVec);
    void translate(const glm::vec3 &offsetVec);
    void applayMatrix(const glm::mat4 & matrix);
    void push();
    void pop();
private:
    glm::mat4 m_currMat;
    std::stack<glm::mat4> m_matrices;
};
}

#endif // MATRIXSTACK_HPP
