//------------------------------------------------------------------------------
//
// File Name:	ObjectManager.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

typedef struct GameObject GameObject;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Add to master list of objects
void ObjectManagerAddObject(GameObject* object);

// Destroy a specific object managed by the object manager.
// Params:
//   id = The id of the object thet needs to be destroyed.
void ObjectManagerDestroyObject(unsigned id);

// Destroy all game objects managed by the object manager.
void ObjectManagerDestroyAllObjects(void);

// Retrieve an object using its ID.
// Params:
//   id = The id of the object thet needs to be destroyed.
GameObject* ObjectManagerGetObjectById(unsigned id);

// Test whether two objects are colliding.
// Params:
//   firstId = id of the first object
//   secondId = id of the second object
// Return:
//   True if the objects are currently colliding, false otherwise.
bool ObjectManagerCheckCollision(unsigned firstId, unsigned secondId);
