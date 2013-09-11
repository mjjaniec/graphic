#version 140

in vec4 color;
in vec4 position;

out vec4 vertexColor;

bool compare(vec4 a, vec4 b) {
    return abs(a.x - b.x) < 0.001 &&
            abs(a.y - b.y) < 0.001 &&
            abs(a.z - b.z) < 0.001 &&
            abs(a.w - b.w) < 0.001;
}

void main()
{
    vertexColor = color;
    gl_Position = position;

}
