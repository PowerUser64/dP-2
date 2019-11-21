#version 330 core

in vec2 textureCoordinate;

out vec4 fragColor;

uniform sampler2D renderedTexture;

void main()
{
    fragColor = vec4(texture2D(renderedTexture, textureCoordinate).rgb, 1);
}
