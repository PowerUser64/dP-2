//------------------------------------------------------------------------------
//
// File Name:	StartupSettings.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Includes:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	struct BE_API StartupSettings
	{
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Default Constructor
		StartupSettings();

		//------------------------------------------------------------------------------
		// Public Variables:
		//------------------------------------------------------------------------------

		// Width of the window. Defaults to 800. Set to 0 to use native resolution.
		unsigned windowWidth;
		// Height of the window. Defaults to 600. Set to 0 to use native resolution.
		unsigned windowHeight;
		// Maximum framerate. Defaults to 60. Has no effect if vSync is enabled.
		unsigned framerateCap;
		// Whether to show the window immediately when the engine starts. Defaults to true.
		bool showWindow;
		// Whether to create a debug console in Debug mode. Defaults to true.
		bool debugConsole;
		// Whether to start in fullscreen mode. Defaults to false.
		bool fullscreen;
		// Whether the user is allowed to maximize the window. Defaults to false.
		bool allowMaximize;
		// Whether to close the application when escape is pressed. Defaults to true.
		bool closeOnEscape;
		// Whether to synchronize sync the frame rate with the refresh rate. Defaults to true.
		bool vSync;
	};
}

//------------------------------------------------------------------------------
