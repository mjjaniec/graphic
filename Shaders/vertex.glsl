#version 140

in vec4 color;
in vec4 position;

out vec4 vertexColor;

uniform vec2 offset;
uniform mat4 perspectiveMatrix;
void main()
{
    vec4 cameraPos = position + vec4(offset.x, offset.y, 0.0, 0.0);
    gl_Position = perspectiveMatrix * cameraPos;
    vertexColor = color;
}
