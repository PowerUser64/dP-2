//------------------------------------------------------------------------------
//
// File Name:	GameObject.h
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
typedef struct Vector2D Vector2D;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// Pointer to function used to update objects. 
// Example: void PlayerUpdate(GameObject* player, float dt);
typedef void (*UpdateFunctionPtr)(GameObject*, float);

// Pointer to function used to handle collision events. 
// Example: void PlayerEnemyCollision(GameObject* player, GameObject* enemy);
typedef void(*CollisionFunctionPtr)(GameObject*, GameObject*);

//------------------------------------------------------------------------------
// Public Function Declarations:
//------------------------------------------------------------------------------

// Allocate memory for a new game object.
// Params:
//   x = Starting x coordinate of the object.
//   y = Starting y coordinate of the object.
//   tile = The character that will be used to represent the object on screen.
//   color = The color to use when drawing this object.
//	 behavior = Pointer to a function that executes special behavior for this object.
//	 extraData = Any additional data needed for advanced behavior. Usually NULL.
// Returns:
//	 A pointer to the newly created object.
GameObject* GameObjectCreate(float x, float y, char tile, short color, UpdateFunctionPtr behavior, void* extraData);

// Get the position of a game object.
// Params:
//	 object = Pointer to the object whose position we are retrieving.
// Returns:
//	 The current position of the object as a vector.
const Vector2D* GameObjectGetPosition(const GameObject* object);

// Set the position of a game object.
// Params:
//	 object = Pointer to the object whose position we are setting.
//   position = New position of the object.
void GameObjectSetPosition(GameObject* object, const Vector2D* position);

// Get the scale of a game object.
// Params:
//	 object = Pointer to the object whose scale we are retrieving.
// Returns:
//	 The current scale of the object as a vector.
const Vector2D* GameObjectGetScale(const GameObject* object);

// Set the scale of a game object.
// Params:
//	 object = Pointer to the object whose scale we are setting.
//   scale = New scale of the object.
void GameObjectSetScale(GameObject* object, const Vector2D* scale);

// Get the velocity of a game object.
// Params:
//	 object = Pointer to the object whose velocity we are retrieving.
// Returns:
//	 The current velocity of the object as a vector.
const Vector2D* GameObjectGetVelocity(const GameObject* object);

// Set the velocity of a game object.
// Params:
//	 object = Pointer to the object whose velocity we are setting.
//   velocity = New velocity of the object.
void GameObjectSetVelocity(GameObject* object, const Vector2D* velocity);

// Grab the extra data for a given object, if any. User will need to
// cast the result to the appropriate pointer type in order to use the data.
// Params:
//	 object = Pointer to the object whose data we are retrieving.
// Returns:
//	 A void pointer to extra data associated with an object,
//   or NULL if none exists.
void* GameObjectGetExtraData(const GameObject* object);

// Detect collisions between two objects by checking to see whether
// their positions on screen would be equal. If they collide,
// call a collision handling function provided by the user.
// Params:
//	 first = First game object.
//   second = Second game object.
//   handler = Function to call if objects are colliding.
void GameObjectAddCollisionPair(GameObject* first, GameObject* second, CollisionFunctionPtr handler);

// Retrieve a game object's id.
// Params:
//	 object = Pointer to the object whose id we are retrieving.
// Returns:
//   The id of the object.
unsigned GameObjectGetId(GameObject* object);

// Retrieve a game object's current color
// Params:
//	 object = The object whose color we want to change
// Returns:
//   The color of the object as a short
short GameObjectGetColor(const GameObject* object);

// Set a game object's color
// Params:
//	 object = The object whose color we want to change
//   color = The color of the object as a short
void GameObjectSetColor(GameObject* object, short color);

// Retrieve the character used to represent the object when drawing
// Params:
//	 object = The object whose tile we want to change
// Returns:
//   The character that will be used to represent the object on screen
char GameObjectGetTile(const GameObject* object);

// Sets the character used to represent the object when drawing
// Params:
//	 object = The object whose tile we want to change
//   tile = The character that will be used to represent the object on screen
void GameObjectSetTile(GameObject* object, char tile);
