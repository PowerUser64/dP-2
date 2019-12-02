//------------------------------------------------------------------------------
//
// File Name:	Level2.h
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

#include "Level.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

/* You'll need to implement the functions listed in Level1.h in a new Level1.cpp file:
 *    All functions aside from the constructor need to print out "Level2::" followed by the name of the function. For example, the Initialize function should print out "Level2::Initialize".
 *    In the constructor, initialize the base class, initialize lives to 2, and initialize maxHealth to 2
 *    In the Initialize function, set currentHealth to maxHealth.
 *    In the Update function,
 *        Decrease currentHealth by 1.
 *        When currentHealth reaches 0:
 *            Decrease lives by 1.
 *            If lives is now 0, quit the game (EngineCore::GetInstance().Stop()).
 *            Otherwise, restart the level.
 *
 */

namespace Levels
{
	class Level2 : public Level
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Creates an instance of Level 2.
		Level2();

		// Load the resources associated with Level 2.
		void Load();

		// Initialize the memory associated with Level 2.
		void Initialize();

		// Update Level 1.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		void Update(float dt);

		// Shutdown any memory associated with Level 2.
		void Shutdown();

		// Unload the resources associated with Level 2.
		void Unload();

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		unsigned lives;
		unsigned maxHealth;
		unsigned currentHealth;
	};
}

//----------------------------------------------------------------------------
