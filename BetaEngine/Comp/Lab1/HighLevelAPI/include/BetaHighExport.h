//------------------------------------------------------------------------------
//
// File Name:	BetaHighExport.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once

// Easier declarations for DLL import/export
#ifndef BE_HL_API
	#ifdef _BE_HL_EXPORT
		#define BE_HL_API __declspec(dllexport)
	#else
		#define BE_HL_API __declspec(dllimport)
	#endif
#endif
