//------------------------------------------------------------------------------
//
// File Name:	Texture.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Array.h"
#include "Color.h"
#include "Vector2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declaration:
	//------------------------------------------------------------------------------

	class GraphicsEngine;
	class ShaderProgram;

	//------------------------------------------------------------------------------
	// Public Constants:
	//------------------------------------------------------------------------------

	enum BE_API TextureFilterMode
	{
		TM_Nearest,
		TM_Bilinear,
		TM_Trilinear
	};

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Texture
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions
		//------------------------------------------------------------------------------

		// Creates a 1x1 white texture
		BE_API Texture();

		// Loads a texture from an array
		BE_API Texture(const Array<Color>& colors, size_t width, size_t height, const std::string& name = "");

		// Loads a red-channel texture from an array of unsigned chars. Used for fonts.
		BE_API Texture(const unsigned char* buffer, size_t width, size_t height, const std::string& name = "");

		// Destroys texture data via OpenGL
		BE_API ~Texture();

		// Set this as the active texture.
		// Params:
		//   uvOffset = The texture coordinate offset to use when rendering.
		//   shader = The shader that will be using this texture. Defaults to sprite shader if parameter is null.
		BE_API void Use(const Vector2D& uvOffset = Vector2D(), const ShaderProgram* shader = nullptr) const;

		// Set this as the active texture.
		// Params:
		//   spriteColumns	= The number of columns in the sprite texture.
		//   spriteRows		= The number of rows in the sprite texture.
		//	 flipX			= Whether to flip the texture horizontally when drawing.
		//	 flipY			= Whether to flip the texture vertically when drawing.
		//   uvOffset		= The texture coordinate offset to use when rendering.
		//   shader			= The shader that will be using this texture. Defaults to sprite shader if parameter is null.
		BE_API void Use(unsigned spriteColumns, unsigned spriteRows, bool flipX, bool flipY, 
			const Vector2D& uvOffset, const ShaderProgram* shader = nullptr) const;

		// Returns the name of the texture.
		BE_API const std::string& GetName() const;
		// Returns the ID of the texture buffer in OpenGL.
		BE_API unsigned GetBufferID() const;

		// Loads a texture from a file
		BE_API static Texture* CreateTextureFromFile(const std::string& filename,
			TextureFilterMode mode = TM_Nearest);

		// The current relative path for loading textures
		static std::string texturePath;

	private:
		//------------------------------------------------------------------------------
		// Private Functions
		//------------------------------------------------------------------------------

		// Deleted to prevent issues with copying.
		Texture(const Texture& rhs) = delete;
		Texture& operator=(const Texture& rhs) = delete;

		// Creates a texture with the given buffer ID and name
		Texture(unsigned buffer, const std::string& name);

		// Loads a texture from an array
		void CreateTextureFromArray(const Array<Color>& colors, size_t width,
			size_t height, TextureFilterMode mode = TM_Nearest);

		// Loads a red-channel texture from an array of unsigned chars.
		void CreateRedTextureFromArray(const unsigned char* buffer, size_t width,
			size_t height, TextureFilterMode mode = TM_Nearest);

		//------------------------------------------------------------------------------
		// Private Variables
		//------------------------------------------------------------------------------

		unsigned bufferID;
		std::string name;
		GraphicsEngine& graphics;
	};
}

//------------------------------------------------------------------------------
