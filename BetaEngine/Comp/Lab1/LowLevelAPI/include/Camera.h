//------------------------------------------------------------------------------
//
// File Name:	Camera.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 7
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Shapes2D.h" // BoundingRectangle, Vector2D

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	struct Matrix3D;

	//------------------------------------------------------------------------------
	// Public Constants:
	//------------------------------------------------------------------------------

	enum BE_API ProjectionMode
	{
		PM_Orthographic,
		PM_Perspective,
	};

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class BE_API Camera
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		Camera();
		~Camera();

		// Set this camera as the active camera
		void Use() const;

		// Translation - use this to pan
		const Vector2D& GetTranslation() const;
		void SetTranslation(const Vector2D& translation);

		// FOV - use this to zoom in Perspective mode
		float GetFOV() const;
		void SetFOV(float angle);

		// Size - use this to zoom in Orthographic mode
		float GetVerticalSize() const;
		void SetVerticalSize(float size);

		// Projection mode used by this camera.
		ProjectionMode GetProjectionMode() const;
		void SetProjectionMode(ProjectionMode mode);

		// Sets camera properties to default values
		// (Translation of [0, 0], FOV of 90 degrees, size of 5)
		void Reset();

		// Gets the size of the viewport in world coordinates
		const BoundingRectangle GetScreenWorldDimensions() const;

		// Gets the world position of the specified screen position
		Vector2D ScreenToWorldPosition(const Vector2D& screenPosition) const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Deleted to prevent issues with pimpl.
		Camera(const Camera&) = delete;
		Camera& operator=(const Camera&) = delete;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Private implementation
		class Implementation;
		Implementation* pimpl;
	};
}

//------------------------------------------------------------------------------
