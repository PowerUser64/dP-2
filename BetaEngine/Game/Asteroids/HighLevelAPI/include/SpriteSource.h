//------------------------------------------------------------------------------
//
// File Name:	SpriteSource.h
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

#include "Serializable.h"
#include "ResourceManager.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Vector2D;
	class SpriteSource;
	typedef std::shared_ptr<SpriteSource> SpriteSourcePtr;
	typedef std::shared_ptr<const SpriteSource> ConstSpriteSourcePtr;
	class Texture;
	typedef std::shared_ptr<Texture> TexturePtr;
	typedef std::shared_ptr<const Texture> ConstTexturePtr;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class SpriteSourceManager : public ResourceManager<SpriteSource>
	{
	public:
		BE_HL_API SpriteSourceManager();
	private:
		SpriteSourcePtr Create(const std::string& name) override;
	};

	class TextureManager : public ResourceManager<Texture>
	{
	public:
		BE_HL_API TextureManager();
	private:
		TexturePtr Create(const std::string& name) override;
	};

	class SpriteSource : public Serializable
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
		BE_HL_API SpriteSource(ConstTexturePtr texture = nullptr, std::string name = "", unsigned numCols = 1, unsigned numRows = 1);

		// Activates the sprite source's texture and sets its UV offset based on the given frame index.
		// Params:
		//   frameIndex = The index of the frame of the texture that we want to use.
		//   flipX		= Whether to flip the sprite horizontally when rendering.
		//   flipY	    = Whether to flip the sprite vertically when rendering.
		BE_HL_API void UseTexture(unsigned frameIndex, bool flipX = false, bool flipY = false) const;

		// Returns the maximum number of possible frames in the sprite source's texture (rows * cols).
		BE_HL_API unsigned GetFrameCount() const;

		// Gets the name of the sprite source.
		BE_HL_API const std::string& GetName() const;

		// Gets the dimensions of the texture (number of columns, rows)
		BE_HL_API const Vector2D GetTextureDimensions() const;

		// Save object data to a stream.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from a stream.
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

		// Save this sprite source to a file in the default location. 
		BE_HL_API void SaveToFile() const;

		// Use this to manage sprite source resources!
		friend class SpriteSourceManager;
		BE_HL_API static SpriteSourceManager& GetSpriteSourceManager();

		// Use this to manage textures!
		BE_HL_API static TextureManager& GetTextureManager();

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Returns the UV coordinates of the specified frame in a sprite sheet.
		// Params:
		//	 frameIndex = A frame index within a sprite sheet.
		// Returns:
		//   A vector containing the UV/texture coordinates.
		const Vector2D GetUV(unsigned int frameIndex) const;

		// The dimensions of the sprite sheet texture.
		unsigned numRows;
		unsigned numCols;

		// Pointer to a texture created using the Low Level API.
		ConstTexturePtr texture;

		// Name of sprite source
		std::string name;

		// Name of texture (for serialization)
		std::string textureName;

		static SpriteSourceManager spriteSourceManager;
		static TextureManager textureManager;
	};

	#define ResourceGetSpriteSource(s) SpriteSource::GetSpriteSourceManager().GetResource(s)
	#define ResourceGetTexture(t) SpriteSource::GetTextureManager().GetResource(t)
}

//----------------------------------------------------------------------------
