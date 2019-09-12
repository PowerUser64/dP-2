//------------------------------------------------------------------------------
//
// File Name:	Enemy.c
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
#include "Enemy.h"

#include "GameObject.h" // GameObjectGetPosition
#include "Vector2D.h" // Vector2D
#include "Player.h" // GetPosition

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

// Speed of enemy movement.
static const float enemySpeed = 3.0f;

// When player is at least this close, chase the player.
static const float chaseDistance = 10.0f;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Update the _Menu game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void EnemyUpdate(GameObject* enemy, float dt)
{
	UNREFERENCED_PARAMETER(dt);

	// Grab my position
	const Vector2D* positionEnemy = GameObjectGetPosition(enemy);

	// Grab player position
	const Vector2D* positionPlayer = PlayerGetPosition();

	// Calculate distance
	float distance = Vector2DDistance(positionPlayer, positionEnemy);

	Vector2D velocity = { 0.0f, 0.0f };

	// Chase player if player is close enough.
	if (distance <= chaseDistance)
	{
		// Find direction from enemy to player.
		Vector2DSub(&velocity, positionPlayer, positionEnemy);

		// Normalize direction vector.
		Vector2DNormalize(&velocity, &velocity);

		// Scale direction vector using speed.
		Vector2DScale(&velocity, &velocity, enemySpeed);
	}

	// Set velocity
	GameObjectSetVelocity(enemy, &velocity);
}
