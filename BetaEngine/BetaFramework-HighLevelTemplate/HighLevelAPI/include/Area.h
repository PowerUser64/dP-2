//------------------------------------------------------------------------------
//
// File Name:	Transform.h
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

#include "Transform.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// An example of the structure to be defined in Transform.h.
	// You are free to change the contents of this structure as long as you do not
	//   change the public method declarations declared in the header.
	class Area : public Transform
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Area constructor.
		// Params:
		//	 x = Initial world position on the x-axis.
		//	 y = Initial world position on the y-axis.
		BE_HL_API Area(float x, float y);

		// Area constructor.
		// Params:
		//	 translation = World position of the object.
		//   scale		 = Width and height of the object.
		//   rotation	 = Rotation of the object about the z-axis.
		BE_HL_API Area(Vector2D translation = Vector2D(),
			Vector2D scale = Vector2D(1, 1), float rotation = 0);

		// Draw the bounding rectangle of the area.
		BE_HL_API void Draw() override;

		// Set the size, which is multiplied by the scale to find the bounding area.
		// Params:
		//	 size = The size vector.
		BE_HL_API void SetSize(const Vector2D& size);

		// Set the offset of the area center from the object's translation.
		// Params:
		//	 offset = The offset vector.
		BE_HL_API void SetOffset(const Vector2D& offset);

		// Set the zDepth used for debug drawing.
		// Params:
		//   depth = The z depth that will be used.
		BE_HL_API void SetZDepth(float depth);

		// Returns a bounding rectangle using translation and (half) scale.
		BE_HL_API const BoundingRectangle GetBounds() const override;

	private:
		// The offset from the world position of the area's center.
		Vector2D	offset;

		// The size of the area. Multiplied by the scale to find the bounding area.
		Vector2D	size;

		// zDepth for debug drawing.
		float zDepth;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(Area)
	};
}

//------------------------------------------------------------------------------
