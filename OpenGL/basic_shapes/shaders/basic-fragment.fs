#version 330 core
out vec4 FragColor;
in vec3 vertexColor;
in vec2 TexCoord;

uniform vec4 ourColor;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main(){
    // FragColor = vec4(vertexColor, 1.0); // -> this one is for the triangle with different colors.
    // FragColor = ourColor;
    // FragColor = texture(ourTexture, TexCoord);
    // FragColor = texture(ourTexture, TexCoord) * vec4(vertexColor, 1.0);  
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}