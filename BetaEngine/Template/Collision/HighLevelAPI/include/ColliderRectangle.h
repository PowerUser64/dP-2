//------------------------------------------------------------------------------
//
// File Name:	ColliderRectangle.h
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

#include "Collider.h"
#include "Vector2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class ColliderRectangle : public Collider
	{
	public:
		//------------------------------------------------------------------------------
		// Public Variables:
		//------------------------------------------------------------------------------

		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor for rectangle collider.
		// Params:
		//   extents = The rectangle's extents (half-width, half-height).
		BE_HL_API ColliderRectangle(const Vector2D& extents = Vector2D(0.5f, 1.0f));

		// Debug drawing for colliders.
		BE_HL_API void Draw() override;

		// Get the rectangle collider's extents (half-width, half-height).
		// Returns:
		//	 The extents of the rectangle.
		BE_HL_API const Vector2D& GetExtents() const;

		// Set the rectangle collider's extents (half-width, half-height).
		// Params:
		//   extents = The new extents of the rectangle.
		BE_HL_API void SetExtents(const Vector2D& extents);

		// Check for collision between a rectangle and another arbitrary collider.
		// Params:
		//	 other = Reference to the second collider component.
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

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Extents of the rectangle collider.
		Vector2D extents;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(ColliderRectangle)
	};
}

//------------------------------------------------------------------------------
