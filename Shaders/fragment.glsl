#version 140

in vec4 vertexColor;

uniform float phase;

out vec4 outputColor;

float dist(float x, float y, vec4 place) {
    return sqrt((x-place.x)*(x-place.x) + (y-place.y)*(y-place.y));

}

void main()
{
    outputColor = mix(vec4(0,0,0,0),vertexColor,0.6+sin(phase + dist(100,100,gl_FragCoord)/20)/2.0);
    //gl_FragCoord - place in screen
}
