#version 330 core
layout (location = 0) in vec3 aPos;
// layout (location = 1) in vec3 aColor;
layout (location = 1) in vec2 aTexCoord;

out vec3 vertexColor;
out vec2 TexCoord;
uniform float offset;

uniform mat4 transform;


void main(){
    gl_Position = transform * vec4(aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
    // gl_Position = vec4(aPos.x + offset, aPos.y + offset, aPos.z , 1.0);
    // vertexColor = vec3(aPos.x, aPos.y, aPos.z);
    // TexCoord = aTexCoord;
}

