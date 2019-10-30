//------------------------------------------------------------------------------
//
// File Name:	Level1.h
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

#include "Vector2D.h"
#include "Level.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

namespace Beta
{
	class Texture;
	class SpriteSource;
	class GameObject;
	class Animation;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Level1 : public Beta::Level
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Creates an instance of Level 1.
	Level1();

	// Load the resources associated with the Level1 game state.
	void Load();

	// Initialize the memory associated with the Level1 game state.
	void Initialize();

	// Update the Level1 game state.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt);

	// Shutdown any memory associated with the Level1 game state.
	void Shutdown();

	// Unload the resources associated with the Level1 game state.
	void Unload();

private:
	//------------------------------------------------------------------------------
	// Private Function Declarations:
	//------------------------------------------------------------------------------

	// Create a game object that uses the Monkey sprite source.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::GameObject* CreateMonkey(void);

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	Beta::TexturePtr textureMonkey;
	Beta::SpriteSourcePtr spriteSourceMonkey;

	Beta::AnimationPtr animationWalk;
	Beta::AnimationPtr animationJump;
	Beta::AnimationPtr animationIdle;
};

//----------------------------------------------------------------------------
