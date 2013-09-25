#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

namespace Engine {

class Color {
public:
    float r, g, b, a;
public:
    Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
    friend std::istream& operator>>(std::istream&in, Color&v);
    friend std::ostream& operator<<(std::ostream&out, Color&v);
};

}

#endif // COLOR_HPP
