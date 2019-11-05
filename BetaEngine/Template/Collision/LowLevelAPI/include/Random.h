//------------------------------------------------------------------------------
//
// File Name:	Random.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

namespace Beta
{
	namespace Random
	{
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Initialize the random number generator (RNG).
		BE_API void Init();

		// Generate a random number in the interval [rangeMin, rangeMax] (inclusive)
		// Params:
		//	 rangeMin = The lowest possible number generated.
		//	 rangeMax = The highest possible number generated.
		// Returns:
		//   A random number in the interval [rangeMin, rangeMax].
		BE_API int Range(int rangeMin, int rangeMax);

		// Generate a random floating-point number in the interval [rangeMin, rangeMax] (inclusive).
		// Params:
		//	 rangeMin = The lowest possible number generated.
		//	 rangeMax = The highest possible number generated.
		BE_API float Range(float rangeMin, float rangeMax);
	}
}

//------------------------------------------------------------------------------
