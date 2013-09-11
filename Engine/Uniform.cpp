#include "Uniform.hpp"

Uniform::Uniform(char* name)
    :handle(glGetUniformLocation())
{
}
