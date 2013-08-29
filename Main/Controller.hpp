#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

namespace Main {
    class Controller {
    public:
        static void renderFunc();
        static void mouseFunc(int button, int state, int x, int y);
        static void keyboardFunc(unsigned char key, int x, int y);
        static void reshapeFunc(int width, int height);
        static int getWidth();
        static int getHeight();
    private:
        static int width;
        static int height;
    };
}

#endif // CONTROLLER_HPP
