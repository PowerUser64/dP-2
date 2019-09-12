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
#include "_Menu.h"

#include "curses.h" // Colors

#include "GameObject.h" // GameObject
#include "Vector2D.h" // Vector2D
#include "Player.h" // Update, Collisions
#include "Enemy.h" // Update
#include "Wall.h" // Collisions
#include "Engine.h" // DrawText
#include "ObjectManager.h" // AddObject, DestroyAllObjects

static const Vector2D levelCenter = { 35.0f, 15.0f };

void _MenuInit(void)
{
	EngineDrawText(" __  __   ___         __.....__        _..._               ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 12.0f);
	EngineDrawText("|  |/  `.'   `.   .-''         '.    .'     '.             ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 13.0f);
	EngineDrawText("|   .-.  .-.   ' /     .-''\"'-.  `. .   .-.   .            ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 14.0f);
	EngineDrawText("|  |  |  |  |  |/     /________\\   \\|  '   '  |          ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 15.0f);
	EngineDrawText("|  |  |  |  |  ||                  ||  |   |  |   _    _   ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 16.0f);
	EngineDrawText("|  |  |  |  |  |\\    .-------------'|  |   |  |  | '  / | ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 17.0f);
	EngineDrawText("|  |  |  |  |  | \\    '-.____...---.|  |   |  | .' | .' | ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 18.0f);
	EngineDrawText("|__|  |__|  |__|  `.             .' |  |   |  | /  | /  |  ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 19.0f);
	EngineDrawText("					`''-...... -'    |  |   |  ||   `'.  | ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 20.0f);
	EngineDrawText("									 |  |   |  |'   .'|  '/", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 21.0f);
	EngineDrawText("									 '--'   '--' `-'  `--' ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 22.0f);
}

void _MenuUpdate(float dt)
{
	EngineDrawText(" __  __   ___         __.....__        _..._               ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 12.0f);
	EngineDrawText("|  |/  `.'   `.   .-''         '.    .'     '.             ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 13.0f);
	EngineDrawText("|   .-.  .-.   ' /     .-''\"'-.  `. .   .-.   .            ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 14.0f);
	EngineDrawText("|  |  |  |  |  |/     /________\\   \\|  '   '  |          ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 15.0f);
	EngineDrawText("|  |  |  |  |  ||                  ||  |   |  |   _    _   ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 16.0f);
	EngineDrawText("|  |  |  |  |  |\\    .-------------'|  |   |  |  | '  / | ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 17.0f);
	EngineDrawText("|  |  |  |  |  | \\    '-.____...---.|  |   |  | .' | .' | ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 18.0f);
	EngineDrawText("|__|  |__|  |__|  `.             .' |  |   |  | /  | /  |  ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 19.0f);
	EngineDrawText("					`''-...... -'    |  |   |  ||   `'.  | ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 20.0f);
	EngineDrawText("									 |  |   |  |'   .'|  '/", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 21.0f);
	EngineDrawText("									 '--'   '--' `-'  `--' ", COLOR_BLUE, levelCenter.x - 25.0f, levelCenter.y - 22.0f);
	UNREFERENCED_PARAMETER(dt);
}

void _MenuShutdown(void)
{
	ObjectManagerDestroyAllObjects();
}
