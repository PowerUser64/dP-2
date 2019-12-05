//------------------------------------------------------------------------------
//
// File Name:	Font.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

// Un-Windows
#ifdef DrawText
#undef DrawText
#endif

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

struct FT_FaceRec_;

namespace Beta
{
	class GraphicsEngine;
	typedef FT_FaceRec_ FontFace;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Font
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions
		//------------------------------------------------------------------------------

		// Destroys font data via FreeType
		BE_API ~Font();

		// Draw text to the screen using this font.
		// (NOTE: Use SetTransform to define where the
		// text should appear on screen, as well as its world scale.)
		// Params:
		//   text = The string of text that should be drawn.
		BE_API void DrawText(const std::string& text) const;

		// Return the filename of the font.
		BE_API const std::string& GetName() const;

		// Return the size of the font.
		BE_API unsigned GetSize() const;

		// Load a font from a file
		BE_API static Font* CreateFontFromFile(const std::string& filename, unsigned size);

		// The current relative path for loading fonts
		static std::string fontPath;

	private:
		//------------------------------------------------------------------------------
		// Private Functions
		//------------------------------------------------------------------------------

		// Private to prevent issues when loading files.
		Font(const std::string& filename, unsigned size, FontFace* face);

		// Deleted to prevent issues with copying.
		Font(const Font& rhs) = delete;
		Font& operator=(const Font& rhs) = delete;

		//------------------------------------------------------------------------------
		// Private Variables
		//------------------------------------------------------------------------------

		class Implementation;
		Implementation* pimpl;
	};
}

//------------------------------------------------------------------------------
