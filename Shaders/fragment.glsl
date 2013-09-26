#version 140

in vec4 vertexColor;

uniform float windowWidth;
uniform float windowHeight;
float sightSize = 10;
vec4 sightColor = vec4(0,0,0,1);

out vec4 outputColor;

bool isOnSight(float x, float y) {
    if(abs(x - windowWidth / 2) < 1.0) {
        return abs(y - windowHeight/2) < sightSize;
    }
    if(abs(y - windowWidth / 2) < 1.0) {
        return abs(x - windowWidth/2) < sightSize;
    }
    return false;
}

void main()
{
    if(isOnSight(gl_FragCoord.x,gl_FragCoord.y)) {
        outputColor = sightColor;
    } else {
        outputColor = vertexColor;
    }
}
