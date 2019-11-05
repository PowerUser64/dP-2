//------------------------------------------------------------------------------
//
// File Name:	SpriteTilemap.h
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

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Tilemap;
	typedef std::shared_ptr<const Tilemap> ConstTilemapPtr;
	class Area;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// You are free to change the contents of this structure as long as you do not
	//   change the public interface declared in the header.
	class SpriteTilemap : public Sprite
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a new sprite for use with a tilemap.
		BE_HL_API SpriteTilemap();

		// Get component dependencies.
		BE_HL_API void Initialize() override;

		// Update area data.
		BE_HL_API void Update(float dt) override;

		// Draw the tilemap
		BE_HL_API void Draw() override;

		// Sets the tilemap data that will be used by the sprite.
		// Params:
		//   map = A pointer to the tilemap resource.
		BE_HL_API void SetTilemap(ConstTilemapPtr map);

		// Loads object data from a file.
		// Params:
		//   stream = The stream for the file we want to read from.
		BE_HL_API virtual void Deserialize(FileStream& stream);

		// Saves object data to a file.
		// Params:
		//   stream = The stream for the file we want to write to.
		BE_HL_API virtual void Serialize(FileStream& stream) const;

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The tilemap
		ConstTilemapPtr map;

		// Area component
		Area* area;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(SpriteTilemap)
	};
}

//------------------------------------------------------------------------------
