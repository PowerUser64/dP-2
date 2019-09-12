//------------------------------------------------------------------------------
//
// File Name:	Lose.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Function Declarations:
//------------------------------------------------------------------------------

// Initialize the memory associated with Lose.
void LoseInit(void);

// Update the Lose game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void LoseUpdate(float dt);

// Free any memory associated with Lose.
void LoseShutdown(void);
