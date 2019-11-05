//------------------------------------------------------------------------------
//
// File Name:	Color.h
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

#include <iostream>

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Pubic Structures:
	//------------------------------------------------------------------------------

	struct BE_API Color
	{
		//------------------------------------------------------------------------------
		// Pubic Functions:
		//------------------------------------------------------------------------------

		// Constructors
		Color(); // Defaults to white
		Color(float r, float g, float b, float a = 1.0f);

		// Operators
		Color operator*(const Color& other) const; // Multiplies two colors component-wise
		Color operator+(const Color& other) const; // Adds two colors together
		Color operator-(const Color& other) const; // Subtracts two colors
		Color operator*(float scalar) const; // Scales a color by the given value.

		// Other functions
		Color Clamp() const; // Returns a new color with RGBA values adjusted so they lie between 0 and 1.

		//------------------------------------------------------------------------------
		// Pubic Variables:
		//------------------------------------------------------------------------------

		float r;
		float g;
		float b;
		float a;
	};

	namespace Colors
	{
		const Color White = Color(1, 1, 1);
		const Color Black = Color(0, 0, 0);
		const Color Grey = Color(0.3f, 0.3f, 0.3f);

		const Color Red = Color(1, 0, 0);
		const Color Green = Color(0, 1, 0);
		const Color Blue = Color(0, 0, 1);

		const Color Yellow = Color(1, 1, 0);
		const Color Violet = Color(1, 0, 1);
		const Color Aqua = Color(0, 1, 1);

		const Color Orange = Color(1, 0.5f, 0);
		const Color LightBlue = Color(0, 0.5f, 1);
	}

	//------------------------------------------------------------------------------
	// Pubic Functions:
	//------------------------------------------------------------------------------

	// Scales a color by the given value.
	BE_API Color operator*(float scalar, const Color& color);

	// Output a color to a stream
	BE_API std::ostream& operator<<(std::ostream& os, const Color& color);

	// Read a color from a stream
	BE_API std::istream& operator>>(std::istream& is, Color& color);
}

//------------------------------------------------------------------------------
