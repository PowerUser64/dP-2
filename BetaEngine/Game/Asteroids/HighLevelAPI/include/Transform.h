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

#include "Component.h"
#include "Matrix2D.h"
#include "Shapes2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// An example of the structure to be defined in Transform.h.
	// You are free to change the contents of this structure as long as you do not
	//   change the public method declarations declared in the header.
	class Transform : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Transform constructor.
		// Params:
		//	 x = Initial world position on the x-axis.
		//	 y = Initial world position on the y-axis.
		BE_HL_API Transform(float x, float y);

		// Transform constructor.
		// Params:
		//	 translation = World position of the object.
		//   scale		 = Width and height of the object.
		//   rotation	 = Rotation of the object about the z-axis.
		BE_HL_API Transform(Vector2D translation = Vector2D(), Vector2D scale = Vector2D(1,1), float rotation = 0);

		// Get the transform matrix, based upon translation, rotation and scale settings.
		// Returns:
		//	 A reference to the transform's matrix.
		BE_HL_API const Matrix2D& GetMatrix() const;

		// Get the inverse of the transform matrix.
		// Returns:
		//	 A reference to the transform's inverse matrix.
		BE_HL_API const Matrix2D& GetInverseMatrix() const;

		// Set the translation of a transform component.
		// Params:
		//	 translation = Reference to a translation vector.
		BE_HL_API void SetTranslation(const Vector2D& translation);

		// Set the x-component of the translation.
		// Params:
		//	 x = The new value for the translation's x-component.
		BE_HL_API void SetTranslationX(float x);

		// Set the y-component of the translation.
		// Params:
		//	 y = The new value for the translation's y-component.
		BE_HL_API void SetTranslationY(float y);

		// Get the translation of a transform component.
		// Returns:
		//	 A reference to the component's translation structure.
		BE_HL_API const Vector2D& GetTranslation() const;

		// Set the rotation of a transform component.
		// Params:
		//	 rotation = The rotation value (in radians).
		BE_HL_API void SetRotation(float rotation);

		// Get the rotation value of a transform component.
		// Returns:
		//	 The component's rotation value (in radians).
		BE_HL_API float GetRotation() const;

		// Set the scale of a transform component.
		// Params:
		//	 scale = Reference to a scale vector.
		BE_HL_API void SetScale(const Vector2D& scale);

		// Set the x-component of the scale.
		// Params:
		//	 x = The new value for the scale's x-component.
		BE_HL_API void SetScaleX(float x);

		// Set the y-component of the scale.
		// Params:
		//	 y = The new value for the scale's y-component.
		BE_HL_API void SetScaleY(float y);

		// Get the scale of a transform component.
		// Returns:
		//	 A reference to the component's scale structure.
		BE_HL_API const Vector2D& GetScale() const;

		// Returns a bounding rectangle using translation and (half) scale.
		BE_HL_API virtual const BoundingRectangle GetBounds() const;

		// Tests whether the object is visible on screen.
		BE_HL_API bool IsOnScreen() const;

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
		// Private Functions:
		//------------------------------------------------------------------------------

		// Calculates the transform matrix and its inverse using translation, rotation, and scale.
		void CalculateMatrices() const;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The translation (or world position) of a game object.
		Vector2D	translation;

		// The rotation (or orientation) of a game object.
		float	rotation;

		// The scale (or size) of a game object.
		// This should be initialized to (1, 1).
		Vector2D	scale;

		// The transformation matrix resulting from concatenating translation, 
		// rotation, and scale matrices.
		mutable Matrix2D matrix;

		// The inverse of the transformation matrix. 
		mutable Matrix2D inverseMatrix;

		// True if the transformation matrix needs to be recalculated.
		// This should be initialized to true.
		mutable bool isDirty;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(Transform)
	};
}

//------------------------------------------------------------------------------
