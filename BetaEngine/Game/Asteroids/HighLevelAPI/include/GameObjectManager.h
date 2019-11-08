//------------------------------------------------------------------------------
//
// File Name:	GameObjectManager.h
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

#include "GameObject.h"
#include <Array.h>

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Quadtree;
	struct CastResult;
	class Vector2D;
	class Space;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// You are free to change the contents of this structure as long as you do not
	//   change the public functions declared in the header.
	class GameObjectManager : public BetaObject
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor(s)
		BE_HL_API GameObjectManager(Space* space);

		// Destructor
		BE_HL_API ~GameObjectManager();

		// Update all objects in the active game objects list.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		BE_HL_API void Update(float dt) override;

		// Draw all game objects in the active game object list.
		BE_HL_API void Draw(void) override;

		// Shutdown the game object manager, destroying all active objects.
		BE_HL_API void Shutdown(void) override;

		// Add a game object to the active game object list.
		// Params:
		//	 gameObject = Reference to the game object to be added to the list.
		BE_HL_API void AddObject(GameObject& gameObject);

		// Returns a pointer to the first active game object matching the specified name.
		// Params:
		//	 name = The name of the object to be returned, if found.
		// Returns:
		//   If the named object is found,
		//	   then return the pointer to the named game object,
		//	   else return nullptr.
		BE_HL_API GameObject* GetObjectByName(const std::string& name) const;

		// Returns the number of active objects with the given name.
		// Params:
		//   objectName = The name of the objects that should be counted.
		BE_HL_API unsigned GetObjectCount(const std::string& objectName) const;

		// Retrieves all objects that contain the given component.
		template<typename ComponentType>
		void GetAllObjectsWithComponent(Array<GameObject*>& results)
		{
			for (unsigned i = 0; i < objects.Size(); ++i)
			{
				if (objects[i]->GetComponent<ComponentType>() != nullptr)
					results.PushBack(objects[i]);
			}
		}

		// Test whether the quadtree is currently enabled for this object manager.
		BE_HL_API bool IsQuadtreeEnabled() const;

		// Enable or disable use of the quadtree data structure for collision detection.
		BE_HL_API void SetQuadtreeEnabled(bool enabled);

		// Perform a raycast and return all objects that intersect with the ray.
		// Params:
		//   start     = The starting point of the ray in world coordinates.
		//   direction = The direction of the ray.
		//   distance  = How far to check in the given direction.
		//   results   = The vector in which the results will be stored.
		//   filter    = Objects with this name are excluded.
		BE_HL_API void CastRay(const Vector2D& start, const Vector2D& direction, float distance,
			Array<CastResult>& results, const std::string& filter = "");

		// Perform a raycast and return the first object hit.
		// Params:
		//   start     = The starting point of the ray in world coordinates.
		//   direction = The direction of the ray.
		//   distance  = How far to check in the given direction.
		//   filter    = Objects with this name are excluded.
		// Returns:
		//   A pointer to the first object hit by the ray.
		BE_HL_API GameObject* CastRayClosest(const Vector2D& start, const Vector2D& direction,
			float distance, const std::string& filter = "");

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy constructor and assignment operator
		GameObjectManager(const GameObjectManager&) = delete;
		GameObjectManager& operator=(const GameObjectManager&) = delete;

		// Update object logic using variable timestep.
		void VariableUpdate(float dt);

		// Update object physics using fixed timestep.
		void FixedUpdate(float dt);

		// Check collisions between pairs of objects.
		void CheckCollisions();

		// Check collisions using the quadtree.
		void CheckCollisionsQuadtree();

		// Destroy any objects marked for destruction.
		void DestroyObjects();

		// Instantiate the quadtree using the current world size.
		void RemakeQuadtree();

		// Inserts objects into the quadtree
		void PopulateQuadtree();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		Array<GameObject*> objects;
		float timeAccumulator;
		const float fixedUpdateDt;

		Quadtree* quadtree;
		bool quadtreeEnabled;
		Array<GameObject*> collidableObjects;
	};
}

//------------------------------------------------------------------------------
