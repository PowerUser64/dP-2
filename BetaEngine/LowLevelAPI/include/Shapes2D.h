//------------------------------------------------------------------------------
//
// File Name:	Shapes2D.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
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

//------------------------------------------------------------------------------

namespace Beta
{
	struct BE_API LineSegment
	{
		// Constructors
		LineSegment();
		LineSegment(const Vector2D& start, const Vector2D& end);

		// Points marking each end of a single line segment.
		Vector2D start;
		Vector2D end;

		// Direction of the line segment, precomputed from start and end.
		Vector2D direction;

		// Normal of the line segment, precomputed from start and end.
		Vector2D normal;
	};

	BE_API std::ostream& operator<<(std::ostream& os, const LineSegment& line);
	BE_API std::istream& operator>>(std::istream& is, LineSegment& line);

	struct BE_API BoundingRectangle
	{
		// Constructor
		BoundingRectangle();
		BoundingRectangle(const Vector2D& center, const Vector2D& extents);

		Vector2D center;  // Center of the rectangle.
		Vector2D extents; // HALF the width and height of the rectangle.
		float left;		  // X-coord of the left side of the rectangle
		float right;	  // X-coord of the right side of the rectangle
		float top;		  // Y-coord of the top side of the rectangle
		float bottom;	  // Y-coord of the bottom side of the rectangle
	};

	struct BE_API Circle
	{
		// Constructor
		Circle();
		Circle(const Vector2D& center, float radius);

		Vector2D center; // Center point of circle.
		float radius;    // Radius of circle.
	};
}

//------------------------------------------------------------------------------
