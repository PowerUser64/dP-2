//------------------------------------------------------------------------------
//
// File Name:	Animator.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Lab2
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Includes:
//------------------------------------------------------------------------------

#include "BetaObject.h" // BetaObject
#include "Vector2D.h"   // Vector2D

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Animator : public Beta::BetaObject
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor
	Animator();

	// Update the Lab1 game state.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt);

	// Retrieve the current value of point P
	static const Beta::Vector2D& GetPointP();

	// Retrieve the current value of vector V
	static const Beta::Vector2D& GetVectorV();

	// Retrieve the current value of Vector U
	static const Beta::Vector2D& GetVectorU();

	// Set the speed of the animator.
	static const void SetSpeed(float speed);

private:
	//------------------------------------------------------------------------------
	// Private Consts:
	//------------------------------------------------------------------------------

	// Speed of random movement
	static float speed;

	// Size of vectors
	const float size;

	// Offset for point P
	const Beta::Vector2D offset;

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Points and vectors
	static Beta::Vector2D pointP;
	static Beta::Vector2D vectorV;
	static Beta::Vector2D vectorU;

	// Other values for random movement
	float alpha;
	float dAlpha;
	float beta;
	float dBeta;
	float gamma;
	float dGamma;
	float delta;
	float dDelta;
	float epsilon;
	float dEpsilon;
	float zeta;
	float dZeta;
};
