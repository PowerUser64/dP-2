//------------------------------------------------------------------------------
//
// File Name:	Wall.h
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
// Public Function Declarations:
//------------------------------------------------------------------------------

// Create a wall object.
// Params:
//   positionX = X component of the wall's center.
//   positionY = Y component of the wall's center.
//   width = Width of the wall.
//   height = Height of the wall.
// Returns:
//   A pointer to the new wall object.
GameObject* WallCreate(float centerX, float centerY, float width, float height);

// Handle collision logic when something collides with a wall.
// Params:
//	 other = The other game object.
//   wall = The wall game object.
void WallCollision(GameObject* other, GameObject* wall);
