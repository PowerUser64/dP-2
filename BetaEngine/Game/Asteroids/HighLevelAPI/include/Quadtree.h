//------------------------------------------------------------------------------
//
// File Name:	Quadtree.h
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

#include "Vector2D.h"
#include "Shapes2D.h"
#include <Array.h>

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class GameObject;

	typedef enum Quadrants : short Quadrants;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// Object that intersects with ray
	struct BE_HL_API CastResult
	{
		// Constructors
		CastResult();
		CastResult(GameObject* object, float t);

		// Public variables
		GameObject* object;
		float t;
	};

	// Binary space partitioning data structure that allows for
	// retrieval of objects near other objects.
	class Quadtree
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Default constructor. Initializes all variables to 0.
		BE_HL_API Quadtree();

		// Constructor for quadtree.
		// Params:
		//   bounds   = The area encompassed by this node.
		//   level    = The level of this node in the tree. Child nodes will have a level of one less.
		//   maxObjectsPerNode = The maximum number of game objects in this node before it will be split.
		BE_HL_API Quadtree(const BoundingRectangle& bounds, int level, int maxObjects);

		// Destructor for quadtree. Calls Clear function.
		BE_HL_API ~Quadtree();

		// Draws each of the nodes in the tree (for debug purposes only).
		BE_HL_API void Draw() const;

		// Adds an object to the tree
		// Params:
		//   object = The game object being added to the tree.
		BE_HL_API void AddObject(GameObject* object);

		// Retrieve all objects from the tree that could collide with a given object.
		// Params:
		//   object  = The object for which we want to retrieve nearby objects.
		//   results = The list that stores the nearby objects.
		BE_HL_API void RetrieveNearbyObjects(GameObject* object, Array<GameObject*>& results);

		// Retrieve all objects from the tree that intersect with a given ray.
		// Params:
		//   object  = The object for which we want to retrieve nearby objects.
		//   results = Intersecting objects and their distance from the ray's origin.
		//   filter = Objects with this name are excluded.
		BE_HL_API void CastRay(const LineSegment& ray, Array<CastResult>& results, const std::string& filter);

		// Remove all objects from the tree.
		BE_HL_API void Clear();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		Quadtree(const Quadtree&) = delete;
		Quadtree& operator=(const Quadtree&) = delete;

		// Splits the contents of a node into four child nodes.
		void Split();

		// Determines which of the four child nodes that an object belongs in.
		// Params:
		//   object = The object for which we need to find the index.
		Quadrants GetIndex(const BoundingRectangle& object);

		// Determines whether this node can contain objects.
		bool IsLeafNode() const;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		Quadtree* nodes[4]; // The four branching nodes of this tree.
		Array<GameObject*> objects; // List of objects contained in this node.
		BoundingRectangle bounds;   // Bounding rectangle that defines the area of the node in world space.
		int level;		    // Level of this node in the tree.
	};
}

//------------------------------------------------------------------------------
