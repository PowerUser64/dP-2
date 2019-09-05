//------------------------------------------------------------------------------
//
// File Name:	Level3.h
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

// Initialize the memory associated with Level3.
void Level3Init(void);

// Update the Level3 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level3Update(float dt);

// Free any memory associated with Level3.
void Level3Shutdown(void);
