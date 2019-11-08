//------------------------------------------------------------------------------
//
// File Name:	SpaceManager.h
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

#include <BetaObject.h>
#include <Array.h>
#include "Space.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class SpaceManager : public BetaObject
	{
	public:
		// Constructor - creates the default game space.
		BE_HL_API SpaceManager();

		// Destructor - deletes all spaces.
		BE_HL_API ~SpaceManager();

		// Initialize the space manager.
		BE_HL_API void Initialize() override;

		// Updates all spaces and destroys those that are ready for destruction.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		BE_HL_API void Update(float dt) override;

		// Draw objects in all spaces
		BE_HL_API void Draw() override;

		// Shuts down the space manager, destroying all spaces.
		BE_HL_API void Shutdown() override;

		// Creates a new space with the given name
		// Params:
		//   name = The name of the newly created space.
		//   useCustomCamera = Whether this space should have its own camera.
		BE_HL_API Space* AddSpace(const std::string& name, bool useCustomCamera);

		// Returns a pointer to the space with the given name.
		// Returns nullptr if no such space exists.
		BE_HL_API Space* GetSpaceByName(const std::string& name) const;

		// Returns the default space for game objects
		BE_HL_API Space& GetDefaultSpace();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		SpaceManager(const SpaceManager&) = delete;
		SpaceManager& operator=(const SpaceManager&) = delete;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Pointers to all spaces
		Array<Space*> spaces;

		// Default space for game objects
		Space* gameSpace;
	};
}
