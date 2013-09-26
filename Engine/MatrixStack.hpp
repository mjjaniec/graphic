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
    void RotateX(float fAngDeg);

    void RotateY(float fAngDeg);

    void RotateZ(float fAngDeg);

    void Scale(const glm::vec3 &scaleVec);

    void Translate(const glm::vec3 &offsetVec);
    void Push();
    void Pop();
private:
    glm::mat4 m_currMat;
    std::stack<glm::mat4> m_matrices;
};
}

#endif // MATRIXSTACK_HPP
