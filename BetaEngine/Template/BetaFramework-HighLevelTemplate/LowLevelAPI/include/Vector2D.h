//------------------------------------------------------------------------------
//
// File Name:	Vector2D.h
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

#define FP_EPSILON 0.0001f

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// WARNING: Do not modify the declaration of this structure, as it is a part
	// of the public interface.

	class BE_API Vector2D
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions
		//------------------------------------------------------------------------------

		// Constructors (3)
		Vector2D();
		Vector2D(float value);
		Vector2D(float x, float y);

		// Other functions (7)
		float MagnitudeSquared() const;
		float Magnitude() const;
		Vector2D Normalized() const;
		float DistanceSquared(const Vector2D& other) const;
		float Distance(const Vector2D& other) const;
		Vector2D Midpoint(const Vector2D& other) const;
		float DotProduct(const Vector2D& other) const;
		Vector2D Rotate(float angle) const;

		// Static functions (2)
		static Vector2D FromAngleDegrees(float angle);
		static Vector2D FromAngleRadians(float angle);

		// Overloaded operators (7 member functions)
		Vector2D operator+(const Vector2D& other) const;
		Vector2D operator-(const Vector2D& other) const;
		Vector2D operator*(float scalar) const;
		Vector2D operator/(float scalar) const;
		Vector2D operator-() const;
		Vector2D& operator+=(const Vector2D& other);
		Vector2D& operator-=(const Vector2D& other);
		Vector2D& operator*=(float scalar);
		Vector2D& operator/=(float scalar);

		//------------------------------------------------------------------------------
		// Public Data
		//------------------------------------------------------------------------------

		// Frequently, vector and matrix structures are declared publicly.  While an
		// interface is typically provided with these structures, these are two common
		// exceptions to the coding best practice of "hiding information".

		float x; // The x-coordinate of a Vector2D
		float y; // The y-coordinate of a Vector2D
	};

	//------------------------------------------------------------------------------
	// Public Functions (non-member, non-friend)
	//------------------------------------------------------------------------------

	// Overloaded operators (2 non-member, non-friend function)
	BE_API std::ostream& operator<<(std::ostream& os, const Vector2D& vector);
	BE_API std::istream& operator>>(std::istream& is, Vector2D& vector);
	BE_API Vector2D operator*(float scalar, const Vector2D& vector);

	// Utility functions for floating point comparisons
	BE_API bool AlmostEqual(float first, float second, float epsilon = FP_EPSILON);
	BE_API bool AlmostEqual(Vector2D first, Vector2D second, float epsilon = FP_EPSILON);
}

//------------------------------------------------------------------------------
