//------------------------------------------------------------------------------
//
// File Name:	Vector3D.h
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
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Vector2D;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	struct BE_API Vector3D
	{
	public:
		Vector3D();
		Vector3D(const Vector3D& other);
		Vector3D(float value);
		Vector3D(float x, float y, float z);
		Vector3D(const Vector2D& v, float z = 0.0f);
		~Vector3D();

		void* data;

	private:
		// Deleted to prevent issues with pimpl.
		Vector3D& operator=(const Vector3D& rhs) = delete;
	};
}

//------------------------------------------------------------------------------
