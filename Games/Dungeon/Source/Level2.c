//------------------------------------------------------------------------------
//
// File Name:	Level2.c
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
#include "Level2.h"

#include "curses.h" // Colors

#include "GameObject.h" // GameObject
#include "Vector2D.h" // Vector2D

#include "Player.h" // Update, Collisions
#include "Enemy.h" // Update
#include "Wall.h" // Collisions
#include "Engine.h" // DrawText
#include "ObjectManager.h" // AddObject, DestroyAllObjects

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

#define NUM_WALLS 5

static const float levelWidth = 49.0f;
static const float levelHeight = 19.0f;

static const Vector2D levelCenter = { 35.0f, 15.0f };

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

void Level2CreateWalls(GameObject** walls);

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Initialize the memory associated with the Level2 game state.
void Level2Init(void)
{
	// Create the player object
	Vector2D startPosition;
	startPosition.x = levelCenter.x - 10.0f;
	startPosition.y = levelCenter.y - 5.0f;
	GameObject* player = GameObjectCreate(startPosition.x, startPosition.y, 'o', COLOR_YELLOW, PlayerUpdate, NULL);

	// Create other game objects
	GameObject* door = GameObjectCreate(levelCenter.x + 5.0f, levelCenter.y + 5.0f, 'G', COLOR_GREEN, NULL, NULL);
	GameObject* enemy = GameObjectCreate(levelCenter.x - 5.0f, levelCenter.y - 5.0f, 'X', COLOR_RED, EnemyUpdate, NULL);
	GameObject* enemy2 = GameObjectCreate(levelCenter.x - 7.0f, levelCenter.y - 7.0f, 'X', COLOR_RED, EnemyUpdate, NULL);
	GameObject* walls[NUM_WALLS];
	Level2CreateWalls(walls);

	// Check for player collision with walls
	for (int i = 0; i < NUM_WALLS; ++i)
		GameObjectAddCollisionPair(player, walls[i], WallCollision);

	// Check other collisions
	GameObjectAddCollisionPair(player, door, PlayerCollisionGoal);
	GameObjectAddCollisionPair(player, enemy, PlayerCollisionEnemy);
	GameObjectAddCollisionPair(player, enemy2, PlayerCollisionEnemy);

	// Register objects with Object Manager to ensure they are updated
	ObjectManagerAddObject(player);
	ObjectManagerAddObject(door);
	ObjectManagerAddObject(enemy);
	ObjectManagerAddObject(enemy2);

	// Create a color pair to use later
	EngineSetColorPair(0, COLOR_WHITE, COLOR_RED);
}

// Update the Level2 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level2Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	// Draw level title
	EngineDrawTextColorPair("DUNGEON", 0, levelCenter.x - 3.0f, levelCenter.y - 14.0f);
	EngineDrawText("LEVEL ", COLOR_GREEN, levelCenter.x - 3.0f, levelCenter.y - 12.0f);
}

// Free any memory associated with the Level2 game state.
void Level2Shutdown(void)
{
	ObjectManagerDestroyAllObjects();
}

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

void Level2CreateWalls(GameObject * *walls)
{
	// Top
	walls[0] = WallCreate(levelCenter.x, levelCenter.y - levelHeight / 2.0f, levelWidth, 1.0f);

	// Bottom
	walls[1] = WallCreate(levelCenter.x, levelCenter.y + levelHeight / 2.0f, levelWidth, 1.0f);

	// Left
	walls[2] = WallCreate(levelCenter.x - levelWidth / 2.0f, levelCenter.y, 1.0f, levelHeight + 1.0f);

	// Right
	walls[3] = WallCreate(levelCenter.x + levelWidth / 2.0f, levelCenter.y, 1.0f, levelHeight);

	// Near goal
	walls[4] = WallCreate(levelCenter.x, levelCenter.y, 20.0f, 3.0f);

	// Register objects with Object Manager to ensure they are updated
	for (int i = 0; i < NUM_WALLS; ++i)
		ObjectManagerAddObject(walls[i]);
}
