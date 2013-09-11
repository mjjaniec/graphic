#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace Main {
    class Config {
    public:
        static const bool DEBUG_INFO_ON = false;
        static const int WIDTH = 600;
        static const int HEIGHT = 600;
        static const char* TITLE() {
            return "Kocham Pycze";
        }
        static const char* VERTEX_SHADER() {
            return "../P3/Shaders/vertex.glsl";
        }
        static const char* FRAGMENT_SHADER() {
            return "../P3/Shaders/fragment.glsl";
        }
    };
}

#endif // CONFIG_HPP
