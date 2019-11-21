//------------------------------------------------------------------------------
//
// File Name:	Animator.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		Lab2
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Animator.h"

#include "Vector2D.h" // Vector2D
#include "Random.h" // 

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Static Variables:
//------------------------------------------------------------------------------

Vector2D Animator::pointP;
Vector2D Animator::vectorV;
Vector2D Animator::vectorU;
float Animator::speed = 1.0f;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

Animator::Animator()
	: BetaObject("Animator"), alpha(270.0f), dAlpha(0.0f), beta(270.0f),
	dBeta(0.0f), gamma(30.0f), dGamma(0.0f), delta(0.0f), dDelta(0.0f), epsilon(14.5f),
	dEpsilon(0.0f), zeta(25.7f), dZeta(0.0f), size(0.75f), offset(Vector2D(0.0f, -0.25f))
{
}

// Update the Lab 2 animator.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Animator::Update(float dt)
{
	dAlpha = 360.0f * 0.001f * Random::Range(0.0f, 1.0f) * 100.0f;
	dBeta = 360.0f * 0.001f * Random::Range(0.0f, 1.0f) * 100.0f;
	dGamma = 360.0f * 0.001f * Random::Range(0.0f, 1.0f) * 100.0f;
	dDelta = 360.0f * 0.001f * Random::Range(0.0f, 1.0f) * 100.0f;
	dEpsilon = 360.0f * 0.001f * Random::Range(0.0f, 1.0f) * 100.0f;
	dZeta = 360.0f * 0.001f * Random::Range(0.0f, 1.0f) * 100.0f;

	pointP.x = 0.5f * sinf(alpha); pointP.y = 0.5f * sinf(beta);
	alpha += 0.01f * speed * dt * dAlpha;
	beta += 0.01f * speed * dt * dBeta;
	pointP *= size;
	pointP += offset;

	vectorU.x = 2.0f * sinf(gamma); vectorU.y = 2.0f * sinf(delta);
	gamma += 0.01f * speed * dt * dGamma;
	delta += 0.01f * speed * dt * dDelta;
	vectorU *= size;

	vectorV.x = 2.0f * sinf(epsilon); vectorV.y = 2.0f * sinf(zeta);
	epsilon += 0.01f * speed * dt * dEpsilon;
	zeta += 0.01f * speed * dt * dZeta;
	vectorV *= size;

}

// Get the current value of point P.
const Vector2D& Animator::GetPointP()
{
	return pointP;
}

// Get the current value of vector V.
const Vector2D& Animator::GetVectorV()
{
	return vectorV;
}

// Get the current value of vector U.
const Vector2D& Animator::GetVectorU()
{
	return vectorU;
}

const void Animator::SetSpeed(float speed_)
{
	speed = speed_;
}

/*----------------------------------------------------------------------------*/
