#version 330 core

uniform vec4 blendColor;
uniform vec4 tintColor;
uniform sampler2D diffuse;

in vec4 vertexColor;
in vec2 textureCoordinate;

out vec4 fragColor;

void main()
{
	vec4 texel = vec4(1.0, 1.0, 1.0, texture2D(diffuse, textureCoordinate).r);

	// Don't bother drawing if pixel is mostly transparent
	if(texel.a < 0.4)
		discard;

    fragColor = texel * vertexColor * blendColor * tintColor;
}
