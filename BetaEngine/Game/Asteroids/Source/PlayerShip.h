//------------------------------------------------------------------------------
//
// File Name:	PlayerShip.h
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
	class GameObject;
	struct Event;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class PlayerShip : public Beta::Component
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Default constructor
	// Params:
	//   forwardThrust = Amount of force added to the ship when thrusters are activated.
	//   maximumSpeed  = Maximum attainable speed of the ship.
	//   rotationSpeed = Speed at which the ship rotates.
	//   bulletSpeed   = Speed at which bullets move when fired by ship.
	//   deathDuration = The amount of time the death "animation" will last.
	PlayerShip(float forwardThrust = 3.0f, float maximumSpeed = 2.0f, float rotationSpeed = 3.14159f,
		float bulletSpeed = 4.0f, float deathDuration = 2.0f);

	// Initialize this component (happens at object creation).
	void Initialize() override;

	// Update function for this component.
	// Params:
	//   dt = The (fixed) change in time since the last step.
	void Update(float dt) override;

	// Return the player's current score.
	unsigned GetScore() const;

	// Increase the player's score by the given amount.
	void IncreaseScore(unsigned amount);

private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Move forward when up arrow is pressed
	void Move() const;

	// Rotate when left or right arrow key is pressed
	void Rotate() const;

	// Shoot projectiles when space is pressed
	void Shoot();

	// Execute the death "animation" for the ship.
	// Params:
	//   dt = Change in time since the last frame.
	void DeathSequence(float dt);

	// Respond to collision events.
	void OnCollisionStarted(const Beta::Event& event);

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Movement properties
	float forwardThrust;
	float maximumSpeed;
	float rotationSpeed;
	float bulletSpeed;

	// Bullet archetype
	Beta::Archetype bulletArchetype;

	// Components
	Beta::Transform* transform;
	Beta::RigidBody* rigidBody;

	// Scoring
	unsigned score;

	// Death
	float deathDuration;
	float timer;
	bool isDying;

	COMPONENT_SUBCLASS_DECLARATION(PlayerShip)
};

//------------------------------------------------------------------------------
