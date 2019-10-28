#version 330 core

layout (location = 0) in vec2 positionAttribute;
layout (location = 1) in vec2 textureCoordinateAttribute;

out vec2 textureCoordinate;

void main()										
{
	textureCoordinate = textureCoordinateAttribute;
	gl_Position = vec4(positionAttribute, 0, 1);
}
