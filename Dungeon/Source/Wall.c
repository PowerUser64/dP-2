//------------------------------------------------------------------------------
//
// File Name:	Wall.c
// Author(s):	Jeremy Kings (j.kings)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Wall.h"

#include "GameObject.h" // GetPosition
#include "Vector2D.h" // Vector2D
#include "curses.h" // COLOR_WHITE

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Create a wall object.
// Params:
//   positionX = X component of the wall's center.
//   positionY = Y component of the wall's center.
//   width = Width of the wall.
//   height = Height of the wall.
// Returns:
//   A pointer to the new wall object.
GameObject* WallCreate(float centerX, float centerY, float width, float height)
{
	GameObject* wall = GameObjectCreate(centerX, centerY, '/', COLOR_WHITE, NULL, NULL);

	Vector2D scale; 
	scale.x = width;
	scale.y = height;
	GameObjectSetScale(wall, &scale);

	return wall;
}

// Handle collision logic when something collides with a wall.
// Params:
//	 other = The other game object.
//   wall = The wall game object.
void WallCollision(GameObject* other, GameObject* wall)
{
	UNREFERENCED_PARAMETER(wall);
	UNREFERENCED_PARAMETER(other);

	const Vector2D* positionWall = GameObjectGetPosition(wall);

	Vector2D velocityOther = *GameObjectGetVelocity(other);
	Vector2D positionOther = *GameObjectGetPosition(other);
	const Vector2D* scaleOther = GameObjectGetScale(other);

	// Adjust object position based on current velocity and position
	if (velocityOther.x > 0.0f && positionOther.x < positionWall->x)
		positionOther.x -= scaleOther->x * 0.5f;
	else if (velocityOther.x < 0.0f && positionOther.x > positionWall->x)
		positionOther.x += scaleOther->x * 0.5f;

	if (velocityOther.y > 0.0f && positionOther.y < positionWall->y)
		positionOther.y -= scaleOther->y * 0.5f;
	else if (velocityOther.y < 0.0f && positionOther.y > positionWall->y)
		positionOther.y += scaleOther->y * 0.5f;

	// Reset velocity and set new position
	Vector2D zero = { 0.0f, 0.0f };
	GameObjectSetVelocity(other, &zero);
	GameObjectSetPosition(other, &positionOther);
}
