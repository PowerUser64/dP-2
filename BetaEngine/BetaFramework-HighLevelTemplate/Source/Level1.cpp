//------------------------------------------------------------------------------
//
// File Name:	Level1.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Creates an instance of Level 1.
Level1::Level1()
	: Level("Level 1"), testObject(nullptr)
{
}

// Initialize the memory associated with the Level1 game state.
void Level1::Initialize()
{
	std::cout << "Level1: Initialize" << std::endl;

	// Create a new game object
	testObject = new GameObject("TestObject");

	// Create a transform component at 0,0 with scale 300,300
	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(2222.0f);
	transform->SetScale(Vector2D(2.0f, M_PI));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	Sprite* sprite = new Sprite();
	sprite->SetColor(Colors::Green);
	testObject->AddComponent(sprite);

	// Initialize the object
	testObject->Initialize();
}

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	Input* input = EngineGetModule(Input);

	// If the user presses the '1' key, restart the current level
	if (input->CheckTriggered('1'))
		GetSpace()->RestartLevel();

	// If the user presses the 'D' key, delete the object
	if (input->CheckTriggered('D'))
	{
		delete testObject;
		testObject = nullptr;
	}

	// If the object exists
	if (testObject)
	{
		// Update and draw
		testObject->Update(dt);
		testObject->Draw();
	}
	
	Transform* transform = testObject->GetComponent<Transform>();
	Vector2D position = transform->GetTranslation();

	if (input->CheckHeld(VK_RIGHT))
		position.x += 2.0f * dt;
	if (input->CheckHeld(VK_UP))
		position.y += 2.0f * dt;
	if (input->CheckHeld(VK_DOWN))
		position.y -= 2.0f * dt;
	if (input->CheckHeld(VK_LEFT))
		position.x -= 2.0f * dt;
	transform->SetTranslation(position);
}

// Shutdown any memory associated with the Level1 game state.
void Level1::Shutdown()
{
	std::cout << "Level1::Shutdown" << std::endl;

	delete testObject;
}
