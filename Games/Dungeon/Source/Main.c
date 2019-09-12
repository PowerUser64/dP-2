//------------------------------------------------------------------------------
//
// File Name:	Main.c
// Author(s):	Jeremy Kings (j.kings)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Engine.h" // AddLevel, Start

// Level Functions
#include "_Menu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Lose.h"
#include "Win.h"

//------------------------------------------------------------------------------
// Libraries
//------------------------------------------------------------------------------

#pragma comment(lib, "TextEngine.lib")

//------------------------------------------------------------------------------
// Main Function:
//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	// We are not using these params, but let's pretend we are
	// so that the compiler won't issue a warning.
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	// Add levels to the game
	EngineAddLevel(_MenuInit,  _MenuUpdate,  _MenuShutdown);
	EngineAddLevel(Level1Init, Level1Update, Level1Shutdown);
	EngineAddLevel(Level2Init, Level2Update, Level2Shutdown);
	EngineAddLevel(Level3Init, Level3Update, Level3Shutdown);

	// Set starting level
	EngineSetLevel(0);

	// Get the game loop up and running
	EngineStart(30.0f);

	// Check for memory leaks
	_CrtDumpMemoryLeaks(); 

	return 0;
}
