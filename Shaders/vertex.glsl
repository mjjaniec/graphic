#version 140

in vec4 color;
in vec4 position;

out vec4 vertexColor;


uniform mat4 modelToWorldMatrix;
uniform mat4 worldToCameraMatrix;
uniform mat4 cameraToClipMatrix;

void main()
{
    gl_Position = cameraToClipMatrix * ( worldToCameraMatrix * (modelToWorldMatrix * position));
    vertexColor = color;
}
