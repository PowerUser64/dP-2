#version 330 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;

layout (location = 0) in vec4 positionAttribute;
layout (location = 1) in vec4 vertexColorAttribute;
layout (location = 2) in vec2 textureCoordinateAttribute;

out vec4 vertexColor;
out vec2 textureCoordinate;

void main()										
{						
	vertexColor = vertexColorAttribute;
	textureCoordinate = textureCoordinateAttribute;
	gl_Position = projectionMatrix * viewMatrix * worldMatrix * positionAttribute;
}
