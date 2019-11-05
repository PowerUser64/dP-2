//------------------------------------------------------------------------------
//
// File Name:	ColliderLine.h
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

#include <Array.h>
#include "Collider.h"
#include "Intersection2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Vector2D;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class ColliderLine : public Collider
	{
	public:
		//------------------------------------------------------------------------------
		// Public Variables:
		//------------------------------------------------------------------------------

		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a new (line) collider component.
		BE_HL_API ColliderLine(bool reflection = true);

		// Debug drawing for colliders.
		BE_HL_API void Draw() override;

		// Add a line segment to the line collider's line segment list.
		// Params:
		//	 collider = Pointer to the line collider component.
		//	 p0 = The line segment's starting position.
		//	 p1 = The line segment's ending position.
		BE_HL_API void AddLineSegment(const Vector2D& p0, const Vector2D& p1);

		// Check for collision between a line collider and another arbitrary collider.
		// Params:
		//	 other = Reference to the other collider component.
		// Returns:
		//	 Return the results of the collision check.
		BE_HL_API bool IsCollidingWith(const Collider& other) const override;

		// Perform intersection test with ray.
		// Params:
		//   ray = The ray with which to test intersection.
		//   t   = The t value for the intersection.
		BE_HL_API bool IsIntersectingWith(const LineSegment& ray, float& t) const override;

		// Save object data to file.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from file
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

		// Gets a line segment that incorporates the transform of the object
		// Params:
		//   index = The index of the line within the array of line segments.
		BE_HL_API LineSegment GetLineWithTransform(unsigned index) const;

	private:

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The individual line segments.
		Array<LineSegment> lineSegments;

		// Should the collider perform reflection
		bool reflection;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(ColliderLine)
	};
}

//------------------------------------------------------------------------------
