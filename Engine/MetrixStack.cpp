#include "Engine/MatrixStack.hpp"

namespace Engine {
static inline float Clamp(float fValue, float fMinValue, float fMaxValue)
{
    if(fValue < fMinValue)
        return fMinValue;

    if(fValue > fMaxValue)
        return fMaxValue;

    return fValue;
}

static inline float DegToRad(float fAngDeg)
{
    const float fDegToRad = 3.14159f * 2.0f / 360.0f;
    return fAngDeg * fDegToRad;
}


static glm::mat3 RotateX(float fAngDeg)
{
    float fAngRad = DegToRad(fAngDeg);
    float fCos = cosf(fAngRad);
    float fSin = sinf(fAngRad);

    glm::mat3 theMat(1.0f);
    theMat[1].y = fCos; theMat[2].y = -fSin;
    theMat[1].z = fSin; theMat[2].z = fCos;
    return theMat;
}

static glm::mat3 RotateY(float fAngDeg)
{
    float fAngRad = DegToRad(fAngDeg);
    float fCos = cosf(fAngRad);
    float fSin = sinf(fAngRad);

    glm::mat3 theMat(1.0f);
    theMat[0].x = fCos; theMat[2].x = fSin;
    theMat[0].z = -fSin; theMat[2].z = fCos;
    return theMat;
}

static glm::mat3 RotateZ(float fAngDeg)
{
    float fAngRad = DegToRad(fAngDeg);
    float fCos = cosf(fAngRad);
    float fSin = sinf(fAngRad);

    glm::mat3 theMat(1.0f);
    theMat[0].x = fCos; theMat[1].x = -fSin;
    theMat[0].y = fSin; theMat[1].y = fCos;
    return theMat;
}

    MatrixStack::MatrixStack()
        : m_currMat(1.0f)
    {
    }

    const glm::mat4& MatrixStack::Top()
    {
        return m_currMat;
    }

    void MatrixStack::rotateX(float fAngDeg)
    {
        m_currMat = m_currMat * glm::mat4(Engine::RotateX(fAngDeg));
    }

    void MatrixStack::rotateY(float fAngDeg)
    {
        m_currMat = m_currMat * glm::mat4(Engine::RotateY(fAngDeg));
    }

    void MatrixStack::rotateZ(float fAngDeg)
    {
        m_currMat = m_currMat * glm::mat4(Engine::RotateZ(fAngDeg));
    }

    void MatrixStack::scale(const glm::vec3 &scaleVec)
    {
        glm::mat4 scaleMat(1.0f);
        scaleMat[0].x = scaleVec.x;
        scaleMat[1].y = scaleVec.y;
        scaleMat[2].z = scaleVec.z;

        m_currMat = m_currMat * scaleMat;
    }

    void MatrixStack::translate(const glm::vec3 &offsetVec)
    {
        glm::mat4 translateMat(1.0f);
        translateMat[3] = glm::vec4(offsetVec, 1.0f);

        m_currMat = m_currMat * translateMat;
    }

    void MatrixStack::push()
    {
        m_matrices.push(m_currMat);
    }

    void MatrixStack::pop()
    {
        m_currMat = m_matrices.top();
        m_matrices.pop();
    }

}
