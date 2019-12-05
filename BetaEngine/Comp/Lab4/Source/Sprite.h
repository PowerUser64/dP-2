//------------------------------------------------------------------------------
//
// File Name:	Sprite.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <Color.h>

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

namespace Beta
{
	class Mesh;
	class Vector2D;
}

class SpriteSource;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// You are free to change the contents of this structure as long as you do not
//   change the public interface declared in the header.
class Sprite
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Create a new sprite object.
	Sprite(Beta::Mesh* mesh_, const SpriteSource* spriteSource_ = nullptr);

	// Draw a sprite (Sprite can be textured or untextured).
	void Draw();

	// Set a sprite's transparency (between 0.0f and 1.0f).
	// Params:
	//   alpha = New value for the sprite's 'alpha' value.
	void SetAlpha(float alpha);

	// Get the current value for a sprite's transparency.
	float GetAlpha() const;

	// Set the sprite's current frame.
	// Params:
	//   frameIndex = New frame index for the sprite (0 .. frame count).
	void SetFrame(unsigned int frameIndex);

	// Set the sprite's mesh.
	// (NOTE: This mesh may be textured or untextured.)
	// (NOTE: This mesh may contain any number of triangles.)
	// Params:
	//   mesh = Pointer to a mesh created using the Beta Framework.
	void SetMesh(Beta::Mesh* mesh);

	// Set a new SpriteSource for the specified sprite.
	// Params:
	//	 spriteSource = A new sprite source for the sprite.
	void SetSpriteSource(const SpriteSource* spriteSource);

	// Returns the current sprite source being used by the sprite.
	const SpriteSource* GetSpriteSource();

	// Set the blend color for the specified sprite.
	// Params:
	//	 color = A new color for the sprite.
	void SetColor(Beta::Color color);

	// Retrieves the blend color for the sprite.
	const Beta::Color& GetColor() const;

	// Set whether to flip the sprite horizontally when drawing
	void SetFlipX(bool flipX);

	// Set whether to flip the sprite vertically when drawing
	void SetFlipY(bool flipY);

private:
	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// The frame currently being displayed (for sprite sheets).
	unsigned int frameIndex;

	// The sprite source used when drawing (simple colored mesh will have no sprite source).
	const SpriteSource* spriteSource;

	// The mesh used to draw the sprite.
	Beta::Mesh* mesh;

	// Color used for blending/tint
	Beta::Color color;

	// Mirroring
	bool flipX;
	bool flipY;
};


//------------------------------------------------------------------------------
