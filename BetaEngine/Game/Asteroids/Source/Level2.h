//------------------------------------------------------------------------------
//
// File Name:	Level2.h
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

#include "Vector2D.h"
#include "Level.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class GameObject;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Level2 : public Beta::Level
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Creates an instance of Level 2.
	Level2();

	// Load the resources associated with Level 2.
	void Load();

	// Initialize the memory associated with the Level 2.
	void Initialize();

	// Update the Level 2.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt);

private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Create a game object that uses the Ship sprite source.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::GameObject* CreateShip(void);

	// Create a game object archetype that uses the Bullet sprite source.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::GameObject* CreateBulletArchetype(void);
};


//----------------------------------------------------------------------------
