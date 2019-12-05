#include "stdafx.h"
#include "Sprite.h"



Sprite::Sprite(Beta::Mesh* mesh_, const SpriteSource* spriteSource_)
{
	// The frame currently being displayed (for sprite sheets).
	/* unsigned int */ frameIndex = 0;

	// The sprite source used when drawing (simple colored mesh will have no sprite source).
	/* const SpriteSource */ *spriteSource = nullptr;

	// The mesh used to draw the sprite.
	/* Beta::Mesh **/ mesh;

	// Color used for blending/tint
	/* Beta::Color */ color = Beta::Colors::Green;

	// Mirroring
	/* bool */ flipX = 1;
	/* bool */ flipY = 1;
}

void Sprite::Draw()
{
}

void Sprite::SetAlpha(float alpha)
{
}

float Sprite::GetAlpha() const
{
	return 0.0f;
}

void Sprite::SetFrame(unsigned int frameIndex)
{
}

void Sprite::SetMesh(Beta::Mesh* mesh)
{
}

void Sprite::SetSpriteSource(const SpriteSource* spriteSource)
{
}

const SpriteSource* Sprite::GetSpriteSource()
{
	return nullptr;
}

void Sprite::SetColor(Beta::Color color)
{
}

const Beta::Color& Sprite::GetColor() const
{
	// TODO: insert return statement here
}

void Sprite::SetFlipX(bool flipX)
{
}

void Sprite::SetFlipY(bool flipY)
{
}
