//------------------------------------------------------------------------------
//
// File Name:	ColliderTilemap.h
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

#include "Collider.h"
#include "Vector2D.h"

//------------------------------------------------------------------------------

namespace Beta
{

	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Tilemap;
	typedef std::shared_ptr<const Tilemap> ConstTilemapPtr;
	struct BoundingRectangle;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

		// Enum for sides of bounding rectangle
	enum RectangleSide
	{
		SideBottom,
		SideTop,
		SideLeft,
		SideRight,

		// Number of sides
		SideCount,
	};

	// Booleans determining collision state for each side of the object.
	struct BE_HL_API MapCollision
	{
		MapCollision(bool bottom, bool top, bool left, bool right);
		bool bottom;
		bool top;
		bool left;
		bool right;
	};

	// Map collision event - Generated when object collides with tilemap
	struct MapCollisionEvent : public Event
	{
		BE_HL_API MapCollisionEvent(const MapCollision& collisions);
		MapCollision collisions;
	};

	// Tilemap collider class - goes on Tilemap object
	class ColliderTilemap : public Collider
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor for Tilemap collider.
		BE_HL_API ColliderTilemap();

		// Get pointer to event manager
		BE_HL_API void Initialize() override;

		// Debug drawing for colliders.
		BE_HL_API void Draw() override;

		// Check for collision between a tilemap and another arbitrary collider.
		// Params:
		//	 other = Reference to the second collider component.
		// Returns:
		//	 Return the results of the collision check.
		BE_HL_API bool IsCollidingWith(const Collider& other) const override;

		// Perform intersection test with ray. [NOT CURRENTLY IMPLEMENTED]
		// Params:
		//   ray = The ray with which to test intersection.
		//   t   = The t value for the intersection.
		BE_HL_API bool IsIntersectingWith(const LineSegment& ray, float& t) const override;

		// Sets the tilemap to use for this collider.
		// Params:
		//   map = A pointer to the tilemap resource.
		BE_HL_API void SetTilemap(ConstTilemapPtr map);

		// Loads object data from a file.
		// Params:
		//   stream = The stream for the file we want to read from.
		BE_HL_API virtual void Deserialize(FileStream& stream);

		// Saves object data to a file.
		// Params:
		//   stream = The stream for the file we want to write to.
		BE_HL_API virtual void Serialize(FileStream& stream) const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Checks whether the specified side of a given rectangle is colliding with the tilemap.
		// Params:
		//   rectangle = The bounding rectangle for an object.
		//   side = The side that needs to be tested for collision.
		// Returns:
		//   True if there is a collision, false otherwise.
		bool IsSideColliding(const BoundingRectangle& rectangle, RectangleSide side) const;

		// Determines whether a point is within a collidable cell in the tilemap.
		// Params:
		//   x = The x component of the point, in world coordinates.
		//   y = The y component of the point, in world coordinates.
		// Returns:
		//   False if the point is outside the map or the map is empty at that position, 
		//   or true if there is a tile at that position.
		bool IsCollidingAtPosition(float x, float y) const;

		// Moves an object and sets its velocity based on where it collided with the tilemap.
		// Params:
		//   objectRectangle = A bounding rectangle that encompasses the object.
		//   objectTransform = Pointer to the object's transform component.
		//   objectPhysics = Pointer to the object's physics component.
		//   collisions = True/false values from map collision checks.
		void ResolveCollisions(const BoundingRectangle& objectRectangle, Transform* objectTransform,
			RigidBody* objectPhysics, const MapCollision& collisions) const;

		// Returns the center of the next tile on the x-axis or y-axis.
		// Used for assisting in collision resolution on a particular side.
		// Params:
		//   side = Which side the collision is occurring on.
		//   sidePosition = The x or y value of that side.
		// Returns:
		//   The center of the next tile for the given position on the given side.
		float GetNextTileCenter(RectangleSide side, float sidePosition) const;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The tilemap
		ConstTilemapPtr map;

		// Event manager
		EventManager* eventManager;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(ColliderTilemap)
	};
}

//------------------------------------------------------------------------------
