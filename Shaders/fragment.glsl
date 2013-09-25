#version 140

in vec4 vertexColor;

uniform float windowWidth;
uniform float windowHeight;

out vec4 outputColor;

float dist(vec4 place) {
    float x = windowWidth/2;
    float y = windowHeight/2;
    return sqrt((x-place.x)*(x-place.x) + (y-place.y)*(y-place.y))/max(1,min(windowWidth,windowHeight))*20;

}

void main()
{
    outputColor = vertexColor;
}
