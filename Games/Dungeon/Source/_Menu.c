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

void _MenuInit(void)
{
}
/*
*/
void _MenuUpdate(float dt)
{
	EngineDrawText(" __  __   ___         __.....__        _..._               ");
	EngineDrawText("|  |/  `.'   `.   .-''         '.    .'     '.             ");
	EngineDrawText("|   .-.  .-.   ' /     .-''"'-.  `. .   .-.   .            ");
	EngineDrawText("|  |  |  |  |  |/     /________\\   \\|  '   '  |          ");
	EngineDrawText("|  |  |  |  |  ||                  ||  |   |  |   _    _   ");
	EngineDrawText("|  |  |  |  |  |\\    .-------------'|  |   |  |  | '  / | ");
	EngineDrawText("|  |  |  |  |  | \\    '-.____...---.|  |   |  | .' | .' | ");
	EngineDrawText("|__|  |__|  |__|  `.             .' |  |   |  | /  | /  |  ");
	EngineDrawText("					`''-...... -'    |  |   |  ||   `'.  | ");
	EngineDrawText("									 |  |   |  |'   .'|  '/");
	EngineDrawText("									 '--'   '--' `-'  `--' ");
}

void _MenuShutdown(void)
{
}
