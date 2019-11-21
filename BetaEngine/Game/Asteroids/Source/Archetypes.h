//------------------------------------------------------------------------------
//
// File Name:	Archetypes.h
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

namespace Archetypes
{
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------
		
	// Create a game object that uses the Ship texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::GameObject* CreateShip();

	// Create a game object archetype that uses the Bullet texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::Archetype CreateBulletArchetype();

	// Create a game object archetype that uses the Asteroid texture.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::Archetype CreateAsteroidArchetype();
}

//----------------------------------------------------------------------------
