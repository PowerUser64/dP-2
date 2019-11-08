//------------------------------------------------------------------------------
//
// File Name:	TimedDeath.h
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

#include "Component.h" // base class

#include "Vector2D.h" // Vector2D

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class Transform;
	class RigidBody;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class TimedDeath : public Beta::Component
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Params:
	//   timeUntilDeath = Amount of time until the object self-destructs.
	TimedDeath(float timeUntilDeath = 1.0f);

	// Update function for this component.
	// Params:
	//   dt = The (fixed) change in time since the last step.
	void Update(float dt) override;

	// Write object data to file
	// Params:
	//   stream = The stream that is writing this object to a file.
	void Serialize(Beta::FileStream& stream) const override;

	// Read object data from a file
	// Params:
	//   stream = The stream that is reading this object's data from a file.
	void Deserialize(Beta::FileStream& stream) override;

private:
	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Amount of time until the object self-destructs.
	float timeUntilDeath;

	COMPONENT_SUBCLASS_DECLARATION(TimedDeath)
};

//------------------------------------------------------------------------------
