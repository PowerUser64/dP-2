//------------------------------------------------------------------------------
//
// File Name:	ColliderCircle.h
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

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class ColliderCircle : public Collider
	{
	public:
		//------------------------------------------------------------------------------
		// Public Variables:
		//------------------------------------------------------------------------------

		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor for circle collider.
		BE_HL_API ColliderCircle(float radius = 0.5f);

		// Debug drawing for colliders.
		BE_HL_API void Draw() override;

		// Get the circle collider's radius.
		// Returns:
		//	 The circle collider's radius.
		BE_HL_API float GetRadius() const;

		// Set the circle collider's radius.
		// Params:
		//   radius = The circle collider's new radius.
		BE_HL_API void SetRadius(float radius);

		// Check for collision between a circle and another arbitrary collider.
		// Params:
		//	 other = Reference to the second circle collider component.
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

		// Radius of the circle collider.
		float radius;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(ColliderCircle)
	};
}

//------------------------------------------------------------------------------
