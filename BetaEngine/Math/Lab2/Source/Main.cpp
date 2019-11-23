//------------------------------------------------------------------------------
//
// File Name:	Main.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"

// BetaFramework Engine
#include "EngineCore.h"

// Levels
#include "Animator.h"
#include "Lab2.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Main function
int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR command_line, int show)
{
	// Enable memory leak checking
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	// Mark parameters as unused to avoid warnings
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(command_line);
	UNREFERENCED_PARAMETER(show);
	UNREFERENCED_PARAMETER(instance);
	
	Beta::EngineCore& engine = Beta::EngineCore::GetInstance();
	engine.AddModule<Animator>();
	// TO DO: Add Lab2 to engine
	engine.AddModule<Lab2>();

	// Game engine goes!
	Beta::StartupSettings settings;
	settings.windowWidth = 800;
	settings.windowHeight = 600;
	engine.Start(settings);

	return 0;
}
