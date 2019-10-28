//------------------------------------------------------------------------------
//
// File Name:	RigidBody.h
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

#include "Component.h"
#include "Vector2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Transform;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

		// An example of the structure to be defined in RigidBody.c.
	class RigidBody : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a new physics component.
		BE_HL_API RigidBody();

		// Get the acceleration of a physics component.
		// Returns:
		//	 A reference to the component's acceleration structure.
		BE_HL_API const Vector2D& GetAcceleration() const;

		// Get the velocity of a physics component.
		// Returns:
		//   A reference to the component's velocity structure.
		BE_HL_API const Vector2D& GetVelocity() const;

		// Get the old translation (position) of a physics component.
		// Returns: 
		//   A reference to the component's oldTranslation variable.
		BE_HL_API const Vector2D& GetOldTranslation() const;

		// Get the angular velocity of a physics component.
		// Returns:
		//	 A float representing the new angular velocity.
		BE_HL_API float GetAngularVelocity() const;

		// Add a force to the object.
		// Params:
		//	 force = A force vector with direction and magnitude.
		BE_HL_API void AddForce(const Vector2D& force);

		// Set the velocity of a physics component.
		// Params:
		//	 velocity = Pointer to a velocity vector.
		BE_HL_API void SetVelocity(const Vector2D& velocity);

		// Set the x-component of the rigid body's velocity.
		// Params:
		//	 x = The new value for the velocity's x-component.
		BE_HL_API void SetVelocityX(float x);

		// Set the y-component of the rigid body's velocity.
		// Params:
		//	 y = The new value for the velocity's y-component.
		BE_HL_API void SetVelocityY(float y);

		// Set the angular velocity of a physics component.
		// Params:
		//	 velocity = New value for the rotational velocity.
		BE_HL_API void SetAngularVelocity(float velocity);

		// Moves an object to the specified location, syncing
		// its old, current, and new translations to that position.
		// Params:
		//   position = The position that the object should be in after this function call.
		BE_HL_API void MovePosition(const Vector2D& position);

		// Initialize data, grab component dependencies.
		BE_HL_API void Initialize() override;

		// Reset acceleration.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		BE_HL_API void Update(float dt) override;

		// Update velocity and translation.
		// Params:
		//	 dt = Change in time (in seconds) since the last fixed update.
		BE_HL_API void FixedUpdate(float dt) override;

		// Save object data to file.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const override;

		// Load object data from file
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream) override;

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Previous position.  May be used for resolving collisions.
		Vector2D	oldTranslation;

		// Acceleration = inverseMass * (sum of forces)
		Vector2D	acceleration;

		// Goal velocity
		Vector2D	velocity;

		// Angular velocity, the speed and direction that the object rotates.
		float	angularVelocity;

		// Used when calculating acceleration due to forces.
		// Used when resolving collision between two dynamic objects.
		float	inverseMass;

		// The sum of all forces acting on an object
		Vector2D	forcesSum;

		// Components
		Transform* transform;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(RigidBody)
	};
}

//------------------------------------------------------------------------------
