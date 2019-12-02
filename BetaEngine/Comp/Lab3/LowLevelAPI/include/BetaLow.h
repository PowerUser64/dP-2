//------------------------------------------------------------------------------
//
// File Name:	BetaLow.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Libraries:
//------------------------------------------------------------------------------

// Dependencies
#ifdef _M_IX86
	#ifdef _DEBUG
		#pragma comment(lib, "BetaLow_x86_D.lib")
	#else
		#pragma comment(lib, "BetaLow_x86.lib")
	#endif
#else
	#ifdef _DEBUG
		#pragma comment(lib, "BetaLow_x64_D.lib")
	#else
		#pragma comment(lib, "BetaLow_x64.lib")
	#endif
#endif

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

// Exports
#include <BetaLowExport.h>

// Systems and Resources
#include <BetaLowCore.h>
#include <BetaLowGraphics.h>
#include <BetaLowWindows.h>

// Utility
#include <BetaLowMath.h>

//------------------------------------------------------------------------------
