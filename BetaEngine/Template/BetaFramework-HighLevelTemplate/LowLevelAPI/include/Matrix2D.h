//------------------------------------------------------------------------------
//
// File Name:	Matrix2D.h
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

#include "Vector2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// Frequently, vector and matrix structures are declared publicly.  While an
	// interface is typically provided with these structures, these are two common
	// exceptions to the coding best practice of "hiding information".

	// WARNING: Do not modify the declaration of this structure, as it is a part
	// of the public interface.

	class BE_API Matrix2D
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor for matrix. Sets all data in matrix to 0.
		Matrix2D();

		// This function creates an identity matrix and returns it.
		static Matrix2D IdentityMatrix();

		// This function calculates the transpose matrix of Mtx and saves it in the result matrix.
		// (NOTE: Care must be taken when pResult = pMtx.)
		Matrix2D Transposed() const;

		// This function creates a translation matrix from x & y and returns it.
		static Matrix2D TranslationMatrix(float x, float y);

		// This function creates a scaling matrix from x & y and returns it.
		static Matrix2D ScalingMatrix(float x, float y);

		// This matrix creates a rotation matrix from "Angle" whose value is in degrees.
		// Return the resulting matrix.
		// Converting from degrees to radians can be performed as follows:
		//	 radians = (angle * M_PI) / 180.0f
		static Matrix2D RotationMatrixDegrees(float angle);

		// This matrix creates a rotation matrix from "Angle" whose value is in radians.
		// Return the resulting matrix.
		static Matrix2D RotationMatrixRadians(float angle);

		// This function multiplies the current matrix with another and returns the result as a new matrix.
		// HINT: Use the RowColumnMultiply function to help write this function.
		Matrix2D operator*(const Matrix2D& other) const;

		// This function multiplies the current matrix with another, storing the result in the current matrix.
		// HINT: Use the RowColumnMultiply function to help write this function.
		Matrix2D& operator*=(const Matrix2D& other);

		// This function multiplies a matrix with a vector and returns the result as a new vector.
		// Result = Mtx * Vec.
		Vector2D operator*(const Vector2D& vec) const;

		//------------------------------------------------------------------------------
		// Public Data
		//------------------------------------------------------------------------------

		// The matrix is stored in column-major format, meaning 
		// the consecutive elements of column are contiguous.
		//   m[row][column]
		float m[3][3];

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Multiplies a row of the current matrix by a column in another and returns the result.
		float RowColumnMultiply(const Matrix2D& other, unsigned row, unsigned col) const;
	};

	//------------------------------------------------------------------------------
	// Global Functions:
	//------------------------------------------------------------------------------

	// Prints the contents of the matrix to an output stream.
	BE_API std::ostream& operator<<(std::ostream& os, const Matrix2D& matrix);
}

//------------------------------------------------------------------------------
