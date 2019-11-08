//------------------------------------------------------------------------------
//
// File Name:	MapObjectSpawner.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework Map Editor
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <Component.h>
#include <EventManager.h>

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Transform;
	class Tilemap;
	typedef std::shared_ptr<const Tilemap> ConstTilemapPtr;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class MapObjectSpawner : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor
		BE_HL_API MapObjectSpawner();

		// Initialize this component (happens at object creation).
		BE_HL_API void Initialize() override;

		// Sets the tilemap data that will be used by this component.
		// Params:
		//   map = A pointer to the tilemap resource.
		BE_HL_API void SetTilemap(ConstTilemapPtr map);

		// Loads object data from a file.
		// Params:
		//   stream = The stream for the file we want to read from.
		BE_HL_API virtual void Deserialize(FileStream& stream) override;

		// Saves object data to a file.
		// Params:
		//   stream = The stream for the file we want to write to.
		BE_HL_API virtual void Serialize(FileStream& stream) const override;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Actual object placement function
		void PlaceObject(GameObject* object, int x, int y);

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Components
		Transform* transform;

		// Resources
		ConstTilemapPtr map;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(MapObjectSpawner)
	};
}

//------------------------------------------------------------------------------
