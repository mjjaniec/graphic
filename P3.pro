CONFIG += console

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    Main/Controller.cpp \
    Engine/Vertex.cpp \
    World/Scene.cpp \
    Engine/Triangle.cpp \
    Main/Logger.cpp \
    Engine/Position.cpp \
    Engine/Color.cpp \
    Main/Uniform.cpp \
    Engine/Object.cpp \
    Engine/MatrixStack.cpp \
    World/Tree.cpp \
    World/Cube.cpp \
    World/ObjectBase.cpp

LIBS += -lfreeglutD -lglutilD -lglfwD -lglmeshD -lglimgD -lglloadD -lGL -lGLU -lX11 -lXrandr -lpthread

HEADERS += \
    Main/Config.hpp \
    Main/Controller.hpp \
    Main/Logger.hpp \
    Main/Commons.hpp \
    Engine/Triangle.hpp \
    Engine/Vertex.hpp \
    World/Scene.hpp \
    Engine/Color.hpp \
    Engine/Position.hpp \
    Main/Uniform.hpp \
    Engine/Object.hpp \
    Engine/MatrixStack.hpp \
    World/Tree.hpp \
    World/Cube.hpp \
    World/ObjectBase.hpp

OTHER_FILES += \
    Shaders/vertex.glsl \
    Shaders/fragment.glsl \
    Resources/axes \
    Resources/cube2 \
    Resources/grass \
    Resources/tree \
    Resources/skies
