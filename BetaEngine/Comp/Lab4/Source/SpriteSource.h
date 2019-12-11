//------------------------------------------------------------------------------
//
// File Name:	SpriteSource.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class Vector2D;
	class Texture;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------


class SpriteSource
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor for SpriteSource
	// Params:
	//   texture = The texture that contains the frames that this sprite source will use.
	//   name = The name to use for this sprite source.
	//	 numCols = The number of total columns in the sprite sheet texture.
	//	 numRows = The number of total rows in the sprite sheet texture.
	//   frameCount = The number of frames in the sprite source (for animation).
	//   frameStart = The starting frame for the sprite source (for animation).
	SpriteSource(const Beta::Texture* texture = nullptr, std::string name = "", 
			unsigned numCols = 1, unsigned numRows = 1);

	// Activates the sprite source's texture and sets its UV offset based on the given frame index.
	// Params:
	//   frameIndex = The index of the frame of the texture that we want to use.
	//   flipX		= Whether to flip the sprite horizontally when rendering.
	//   flipY	    = Whether to flip the sprite vertically when rendering.
	void UseTexture(unsigned frameIndex, bool flipX = false, bool flipY = false) const;

	// Returns the maximum number of possible frames in the sprite source's texture (rows * cols).
	unsigned GetFrameCount() const;

	// Gets the name of the sprite source.
	const std::string& GetName() const;

	// Gets the dimensions of the texture (number of columns, rows)
	const Beta::Vector2D GetTextureDimensions() const;

private:
	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Returns the UV coordinates of the specified frame in a sprite sheet.
	// Params:
	//	 frameIndex = A frame index within a sprite sheet.
	// Returns:
	//   A vector containing the UV/texture coordinates.
	const Beta::Vector2D GetUV(unsigned int frameIndex) const;

	// The dimensions of the sprite sheet texture.
	unsigned numRows;
	unsigned numCols;

	// Pointer to a texture created using the Low Level API.
	const Beta::Texture* texture;

	// Name of sprite source
	std::string name;
};


//----------------------------------------------------------------------------
