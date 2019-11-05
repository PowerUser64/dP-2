//------------------------------------------------------------------------------
//
// File Name:	Collider.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h"

#include "EventManager.h" // Event
#include <set>	// std::set

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Transform;
	class Sprite;
	struct LineSegment;
	class RigidBody;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// Collision event - Generated when two objects collide
	struct CollisionEvent : public Event
	{
		BE_HL_API CollisionEvent(GameObject& otherObject, const std::string& type = "CollisionPersisted");
		GameObject& otherObject;
	};
	typedef enum ColliderType
	{
		ColliderTypeCircle,
		ColliderTypeLine,
		ColliderTypeRectangle,
		ColliderTypeTilemap,
	} ColliderType;

	// Collider class - Detects collisions between objects
	class Collider : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Allocate a new collider component.
		// Params:
		//   type = The type of collision shape represented by this collider.
		BE_HL_API Collider(ColliderType type);

		// Set component pointers.
		BE_HL_API void Initialize() override;

		// Logic update for this component with fixed timestep.
		BE_HL_API void FixedUpdate(float dt) override;

		// Check if two objects are colliding and send collision events.
		// Params:
		//	 other = Reference to the second collider component.
		BE_HL_API void CheckCollision(const Collider& other);

		// Perform intersection test between two arbitrary colliders.
		// Params:
		//	 other = Reference to the second collider component.
		BE_HL_API virtual bool IsCollidingWith(const Collider& other) const = 0;

		// Perform intersection test with ray.
		// Params:
		//   ray = The ray with which to test intersection.
		//   t   = The t value for the intersection.
		BE_HL_API virtual bool IsIntersectingWith(const LineSegment& ray, float& t) const = 0;

		// Get the type of this component.
		BE_HL_API ColliderType GetColliderType() const;

		// Has this component been checked for collisons?
		BE_HL_API bool WasProcesed() const;

		// Set this collider's processed bool.
		BE_HL_API void SetProcessed(bool value);

	protected:
		// Component pointers
		Transform* transform;
		RigidBody* physics;
		Sprite* sprite;

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The type of collider used by this component.
		// (Currently, Circle or Line).
		ColliderType cType;

		// Whether the collider has been checked for collisions this frame.
		bool processed;

		// IDs of objects this collider is colliding with
		std::set<BetaObject::IDType> collidersPrevious;
		std::set<BetaObject::IDType> collidersCurrent;

		// Systems
		EventManager* eventManager;

		// RTTI
		COMPONENT_ABSTRACT_DECLARATION(Collider)
	};
}

//------------------------------------------------------------------------------
