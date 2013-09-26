#include "Engine/Color.hpp"

namespace Engine {

Color::Color(float _r, float _g, float _b, float _a)
    :r(_r), g(_g), b(_b), a(_a) {

}

std::istream& operator>>(std::istream&in, Color&self) {
    return in>>self.r>>self.g>>self.b>>self.a;
}

std::ostream& operator<<(std::ostream&out, Color&self) {
    return out<<"{ r: "<<self.r<<", g: "<<self.g<<", b: "<<self.b<<", a: "<<self.a<<" }";
}

}
