#version 330 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;
uniform vec2 uvOffset;
uniform vec2 uvStride;

uniform bool flipX;
uniform bool flipY;

layout (location = 0) in vec4 positionAttribute;
layout (location = 1) in vec4 vertexColorAttribute;
layout (location = 2) in vec2 textureCoordinateAttribute;

out vec4 vertexColor;
out vec2 textureCoordinate;

void main()										
{
	// Interpolate vertex colors
	vertexColor = vertexColorAttribute;

	// Calculate appropriate UV based on sprite rows, cols
	textureCoordinate = textureCoordinateAttribute;
	textureCoordinate *= uvStride;

	// Sprite mirroring
	if(flipX)
		textureCoordinate.x = uvStride.x - textureCoordinate.x;
	if(flipY)
		textureCoordinate.y = uvStride.y - textureCoordinate.y;

	// Add offset for desired frame
	textureCoordinate += uvOffset;

	// Calculate vertex position using transform matrices
	gl_Position = projectionMatrix * viewMatrix * worldMatrix * positionAttribute;
}
