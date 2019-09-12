//------------------------------------------------------------------------------
//
// File Name:	Vector2D.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

typedef struct Vector2D
{
	float x;
	float y;
}Vector2D;

//------------------------------------------------------------------------------
// Public Function Declarations:
//------------------------------------------------------------------------------

// Add two vectors and store the result in a third vector.
// result = op1 + op2
// Params:
//	 result = Where the result will be stored.
//   op1 = First operand.
//   op2 = Second operand.
void Vector2DAdd(Vector2D* result, const Vector2D* op1, const Vector2D* op2);

// Subtract two vectors and store the result in a third vector.
// result = op1 - op2.
// Params:
//	 result = Where the result will be stored.
//   op1 = First operand.
//   op2 = Second operand.
void Vector2DSub(Vector2D* result, const Vector2D* op1, const Vector2D* op2);

// Scales a vector by a floating point number.
// Params:
//	 result = Where the result will be stored.
//   vector = First operand - the vector.
//   scalar = Second operand - the scalar.
void Vector2DScale(Vector2D* result, const Vector2D* vector, float scalar);

// Normalizes a vector and stores the result.
// Params:
//	 result = Where the resulting unit vector will be stored.
//   vector = Vector to be normalized.
void Vector2DNormalize(Vector2D* result, const Vector2D* vector);

// Calculates the distance between two points.
// Params:
//   point1 = First point.
//   point2 = Second point.
// Returns:
//   The distance between the two points.
float Vector2DDistance(const Vector2D* point1, const Vector2D* point2);
