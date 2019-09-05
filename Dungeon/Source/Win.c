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
#include "Win.h"

static const Vector2D levelCenter = { 35.0f, 15.0f };

void Level2Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	// Draw ASCII Art
	EngineDrawText(" /$$     /$$                        /$$      /$$ /$$           /$$", COLOR_BLUE, levelCenter.x - 3.0f, levelCenter.y - 12.0f);
	EngineDrawText("|  $$   /$$/                       | $$  /$ | $$|__/          | $$", COLOR_BLUE, levelCenter.x - 4.0f, levelCenter.y - 13.0f);
	EngineDrawText(" \\  $$ /$$//$$$$$$  /$$   /$$      | $$ /$$$| $$ /$$ /$$$$$$$ | $$", COLOR_BLUE, levelCenter.x - 5.0f, levelCenter.y - 14.0f);
	EngineDrawText("  \\  $$$$//$$__  $$| $$  | $$      | $$/$$ $$ $$| $$| $$__  $$| $$", COLOR_BLUE, levelCenter.x - 6.0f, levelCenter.y - 15.0f);
	EngineDrawText("   \\  $$/| $$  \\ $$| $$  | $$      | $$$$_  $$$$| $$| $$  \\ $$|__/", COLOR_BLUE, levelCenter.x - 7.0f, levelCenter.y - 16.0f);
	EngineDrawText("	| $$ | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$| $$  | $$    ", COLOR_BLUE, levelCenter.x - 8.0f, levelCenter.y - 17.0f);
	EngineDrawText("	| $$ |  $$$$$$/|  $$$$$$/      | $$/   \\  $$| $$| $$  | $$ /$$", COLOR_BLUE, levelCenter.x - 8.0f, levelCenter.y - 18.0f);
	EngineDrawText("	|__/  \\______/  \\______/       |__/     \\__/|__/|__/  |__/|__/", COLOR_BLUE, levelCenter.x - 8.0f, levelCenter.y - 19.0f);
}

void WinInit(void)
{
}

void WinShutdown(void)
{
}
