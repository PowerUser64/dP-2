//------------------------------------------------------------------------------
//
// File Name:	Interpolation.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Vector2D.h"
#include "Color.h"

//------------------------------------------------------------------------------

namespace Beta
{
	namespace Interpolation
	{
		//------------------------------------------------------------------------------
		// Public Consts:
		//------------------------------------------------------------------------------

		enum BE_API InterpolationMode
		{
			IM_Linear,
			IM_Spherical,
			IM_LinearNormalized
		};

		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Linearly interpolates between two floating point values.
		BE_API float Lerp(float start, float end, float percent);

		// Linearly interpolates between two colors.
		BE_API Color Lerp(const Color& start, const Color& end, float percent);

		// Interpolates between two vectors using the specified interpolation method (defaults to linear interpolation).
		BE_API Vector2D Interpolate(const Vector2D& start, const Vector2D& end, float percent, InterpolationMode mode = IM_Linear);
	}
}

//------------------------------------------------------------------------------
