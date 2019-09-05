//------------------------------------------------------------------------------
//
// File Name:	Win.h
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

// Initialize the memory associated with Win.
void WinInit(void);

// Update the Win game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void WinUpdate(float dt);

// Free any memory associated with Win.
void WinShutdown(void);
