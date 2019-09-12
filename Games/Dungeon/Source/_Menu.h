//------------------------------------------------------------------------------
//
// File Name:	_Menu.h
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

// Initialize the memory associated with _Menu.
void _MenuInit(void);

// Update the _Menu game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void _MenuUpdate(float dt);

// Free any memory associated with _Menu.
void _MenuShutdown(void);
