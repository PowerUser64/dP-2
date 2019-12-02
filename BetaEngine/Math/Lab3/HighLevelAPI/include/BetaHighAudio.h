//------------------------------------------------------------------------------
//
// File Name:	BetaHighAudio.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

// Dependencies
#ifdef _M_IX86
	#ifdef _DEBUG
		#pragma comment(lib, "fmodL_vc.lib")	
		#pragma comment(lib, "fmodstudioL_vc.lib")
	#else
		#pragma comment(lib, "fmod_vc.lib")
		#pragma comment(lib, "fmodstudio_vc.lib")
	#endif
#else
	#ifdef _DEBUG
		#pragma comment(lib, "fmodL64_vc.lib")
		#pragma comment(lib, "fmodstudioL64_vc.lib")
	#else
		#pragma comment(lib, "fmod64_vc.lib")
		#pragma comment(lib, "fmodstudio64_vc.lib")
	#endif
#endif

// System
#include <SoundManager.h>
#include <SoundEvent.h>

//------------------------------------------------------------------------------
