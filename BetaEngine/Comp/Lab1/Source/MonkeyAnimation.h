//------------------------------------------------------------------------------
//
// File Name:	MonkeyAnimation.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
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
	class Animator;
	class Animation;
	class RigidBody;
	class Transform;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class MonkeyAnimation : public Beta::Component
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor
	// MonkeyAnimation();

	// // Initialize this component (happens at object creation).
	// void Initialize() override;

	// // Fixed update function for this component.
	// // Params:
	// //   dt = The (fixed) change in time since the last step.
	// void Update(float dt) override;

private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Choose the correct state based on velocity.
	void ChooseNextState();

	// Change states and start the appropriate animation.
	void ChangeCurrentState();

	// Flip the sprite based on velocity and current state.
	void FlipSprite() const;

	//------------------------------------------------------------------------------
	// Private Structures:
	//------------------------------------------------------------------------------

	enum State
	{
		StateIdle,
		StateWalk,
		StateJump,
	};

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Animation variables
	size_t walkAnimation;
	size_t jumpAnimation;
	size_t idleAnimation;

	// Animation state
	State currentState;
	State nextState;

	// Components
	Beta::Animator* animator;
	Beta::RigidBody* physics;
	Beta::Transform* transform;

	// Flip
	Beta::Vector2D originalScale;

	// Create extra component functions
	COMPONENT_SUBCLASS_DECLARATION(MonkeyAnimation)
};


//------------------------------------------------------------------------------
