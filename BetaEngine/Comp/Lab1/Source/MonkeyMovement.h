//------------------------------------------------------------------------------
//
// File Name:	MonkeyMovement.h
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
	struct Event;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class MonkeyMovement : public Beta::Component
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor
	MonkeyMovement();

	// Initialize this component (happens at object creation).
	void Initialize() override;

	// Fixed update function for this component.
	// Params:
	//   dt = The (fixed) change in time since the last step.
	void Update(float dt) override;

private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Moves horizontally based on input
	void MoveHorizontal() const;

	// Moves vertically based on input
	void MoveVertical() const;

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Movement properties
	float monkeyWalkSpeed;
	float monkeyJumpSpeed;
	float groundHeight;
	Beta::Vector2D gravity;

	// Components
	Beta::Transform* transform;
	Beta::RigidBody* rigidBody;

	// Create extra component functions
	COMPONENT_SUBCLASS_DECLARATION(MonkeyMovement)
};

//------------------------------------------------------------------------------
