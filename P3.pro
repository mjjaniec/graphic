CONFIG += console

SOURCES += main.cpp \
    Main/Controller.cpp
LIBS += -lglut

HEADERS += \
    Main/Config.hpp \
    Main/Controller.hpp \
    Main/Logger.hpp

OTHER_FILES += \
    Shaders/fragmet.glsl \
    Shaders/vertex.glsl
