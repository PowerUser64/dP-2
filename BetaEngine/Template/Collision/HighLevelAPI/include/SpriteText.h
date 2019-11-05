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

#include "Sprite.h"
#include "Color.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Area;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Font;
	typedef std::shared_ptr<Font> FontPtr;

	class FontManager : public ResourceManager<Font>
	{
	public:
		BE_HL_API FontManager();
	private:
		FontPtr Create(const std::string& name) override;
	};

	class SpriteText : public Sprite
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a new sprite text object.
		// Params:
		//   text = The text to display.
		//   font = The font to use for this text. If null, will attempt
		//      to use a bitmap font via the sprite's SpriteSource.
		//   wrap = Whether to wrap text onto multiple lines
		//   rowLength = Characters to print before wrapping.
		BE_HL_API SpriteText(const std::string& text = "", FontPtr font = nullptr, bool wrap = false,
			unsigned rowLength = 10);

		// Get component dependencies.
		BE_HL_API void Initialize() override;

		// Update function
		BE_HL_API void Update(float dt) override;

		// Draw sprite text.
		BE_HL_API void Draw() override;

		// Sets the text that will be displayed by the sprite.
		BE_HL_API void SetText(const std::string& text);

		// Gets the text being displayed by the sprite.
		BE_HL_API const std::string& GetText() const;

		// Sets the font used to draw this text
		// Passing nullptr to this function will cause the
		// text to be drawn using the sprite's SpriteSource.
		BE_HL_API void SetFont(FontPtr font);

		// Save object data to file.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from file
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

		// Use this to manage font resources!
		BE_HL_API static FontManager& GetFontManager();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Draws text using a bitmap (sprite source).
		void DrawTextBitmap();

		// Draws text using a font file.
		void DrawTextFont();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The text that will be displayed.
		std::string text;

		// Wrap text?
		bool wrap;

		// Number of characters per row (for wrapping)
		unsigned rowLength;

		// Number of rows
		unsigned numRows;

		// Number of columns in the longest row
		unsigned maxColumns;

		// Area component
		Area* area;

		// Font
		FontPtr font;

		static FontManager fontManager;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(SpriteText)
	};

	#define ResourceGetFont(faceAndSize) SpriteText::GetFontManager().GetResource(faceAndSize)
}

//------------------------------------------------------------------------------
