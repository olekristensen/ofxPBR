#version 400

#define MAX_LIGHTS 8

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform vec4 globalColor;
uniform mat4 viewMatrix;

uniform bool renderForDepthMap;

in vec4  position;
in vec3  normal;
in vec2  texcoord;
in vec4  color;

out vec4  geomPosition;
out vec3  geomNormal;
out vec2  geomTexcoord;
out vec4  geomColor;


subroutine void renderType();
subroutine uniform renderType renderModel;

subroutine(renderType)
void shadow(){
    gl_Position = (inverse(viewMatrix) * modelViewMatrix) * position;
}

subroutine(renderType)
void render(){
    geomPosition = position;
    geomNormal = normal;
    geomTexcoord = texcoord;
    geomColor = color;
    gl_Position = modelViewProjectionMatrix * position;
}

void main() {
    renderModel();
}