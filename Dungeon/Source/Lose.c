//------------------------------------------------------------------------------
//
// File Name:	Level3.c
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
#include "Level3.h"

#include "curses.h" // Colors

#include "GameObject.h" // GameObject
#include "Vector2D.h" // Vector2D

#include "Player.h" // Update, Collisions
#include "Enemy.h" // Update
#include "Wall.h" // Collisions
#include "Engine.h" // DrawText
#include "ObjectManager.h" // AddObject, DestroyAllObjects
#include "Lose.h"

static const Vector2D levelCenter = { 35.0f, 15.0f };

void LoseUpdate(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	// Draw ASCII Art
	EngineDrawText(" __     __           _                        ", COLOR_BLUE, levelCenter.x - 23.0f, levelCenter.y - 12.0f);
	EngineDrawText(" \\ \\   / /          | |                       ", COLOR_BLUE, levelCenter.x - 23.0f, levelCenter.y - 13.0f);
	EngineDrawText("  \\ \\_/ /__  _   _  | | ___  ___  ___         ", COLOR_BLUE, levelCenter.x - 23.0f, levelCenter.y - 14.0f);
	EngineDrawText("   \\   / _ \\| | | | | |/ _ \\/ __|/ _ \\        ", COLOR_BLUE, levelCenter.x - 23.0f, levelCenter.y - 15.0f);
	EngineDrawText("    | | (_) | |_| | | | (_) \\__ \\  __/  _ _ _ ", COLOR_BLUE, levelCenter.x - 23.0f, levelCenter.y - 16.0f);
	EngineDrawText("    |_|\\___/ \\__,_| |_|\\___/|___/\\___| (_|_|_)", COLOR_BLUE, levelCenter.x - 23.0f, levelCenter.y - 17.0f);
}

void LoseInit(void)
{
}

void LoseShutdown(void)
{
}
