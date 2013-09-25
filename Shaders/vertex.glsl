#version 140

in vec4 color;
in vec4 position;

out vec4 vertexColor;


uniform mat4 cameraToClipMatrix;

void main()
{
    //gl_Position = cameraToClipMatrix * position;
    gl_Position = position;
    vertexColor = color;
}
