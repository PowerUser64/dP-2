//------------------------------------------------------------------------------
//
// File Name:	Asteroid.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Asteroid.h"

//------------------------------------------------------------------------------

using namespace Beta;


// STUDENT CODE GOES HERE






//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(Asteroid)

Asteroid::Asteroid(float speedMin, float speedMax, unsigned basePointsValue, float sizePointsModifier, float spawnScaleModifier)
{
}

void Asteroid::Initialize()
{
}

unsigned Asteroid::GetPointValue() const
{
	return 0;
}

void Asteroid::OnCollisionStarted(const Beta::Event& event)
{
}

void Asteroid::SetPosition()
{
}

void Asteroid::SetVelocity()
{
}

void Asteroid::SpawnNewAsteroids()
{
}
