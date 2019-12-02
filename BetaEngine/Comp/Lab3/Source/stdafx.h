//------------------------------------------------------------------------------
//
// File Name:	stdafx.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

// Disable warnings for externals
#pragma warning(push, 0)

// Windows
#define WIN32_LEAN_AND_MEAN // Exclude less common Windows headers
#include <windows.h>		// Windows messages, virtual key codes

// C/C++
#define _USE_MATH_DEFINES
#include <cmath>			// M_PI
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

// Used to track memory leaks to specific files and line numbers
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>

	#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#ifdef max
	#undef max
	#undef min
#endif

// Beta Engine
#include <BetaLow.h>

// Used to clean /W4 unused parameters for functions that must match a function-pointer type 
// NOTE: copied from winnt.h, but we don't want to include that here, otherwise 
#define UNREFERENCED_PARAMETER(P) (P)

// Re-enable warnings
#pragma warning(pop)
