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

// Initial level
#include "Level1.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Main function
int WINAPI WinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prevInstance, 
	_In_ LPSTR command_line, _In_ int show)
{
	// Mark parameters as unused to avoid warnings
	UNREFERENCED_PARAMETER(instance);
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(command_line);
	UNREFERENCED_PARAMETER(show);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	// Add additional modules to engine
	using namespace Beta;
	EngineCore& engine = EngineCore::GetInstance();
	engine.AddModule<GameObjectFactory>();
	engine.AddModule<SoundManager>();
	engine.AddModule<EventManager>();
	SpaceManager* spaceManager = engine.AddModule<SpaceManager>();

	// Set initial game state to the second level.
	spaceManager->GetDefaultSpace().SetLevel<Level1>();

	// Set engine startup settings
	StartupSettings settings;
	settings.windowWidth = 800;
	settings.windowHeight = 600;

	// Game engine goes!
	engine.Start(settings);

	return 0;
}
