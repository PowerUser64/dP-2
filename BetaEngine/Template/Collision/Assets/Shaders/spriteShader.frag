#version 330 core

uniform vec4 blendColor;
uniform vec4 tintColor;
uniform sampler2D diffuse;

in vec4 vertexColor;
in vec2 textureCoordinate;

uniform bool flipX;
uniform bool flipY;

out vec4 fragColor;

void main()
{
	vec2 offsetTexCoord = textureCoordinate;

	if(flipX)
		offsetTexCoord.x = 1.0 - offsetTexCoord.x;
	if(flipY)
		offsetTexCoord.y = 1.0 - offsetTexCoord.y;
	
	vec4 texel = texture2D(diffuse, offsetTexCoord);

	// Don't bother drawing if pixel is mostly transparent
	if(texel.a < 0.4)
		discard;

	fragColor = texel * vertexColor * blendColor * tintColor;
}
