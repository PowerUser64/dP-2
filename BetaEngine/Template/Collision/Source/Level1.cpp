//------------------------------------------------------------------------------
//
// File Name:	Level1.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"
#include "DestroyOnCollide.h"

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
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(2.0f, 2.0f));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	Sprite* sprite = new Sprite();
	sprite->SetColor(Colors::White);
	testObject->AddComponent(sprite);

	// add circle collider
	// ColliderCircle* collider = new ColliderCircle();
	ColliderRectangle* collider = new ColliderRectangle();
	collider->SetExtents(transform->GetScale() / 2.0f);
	testObject->AddComponent(collider);

	// Initialize the object
	// testObject->Initialize();
	DestroyOnCollide* destroy = new DestroyOnCollide();
	testObject->AddComponent(destroy);

	// use obj manager to update/draw, etc
	GetSpace()-> GetObjectManager().AddObject(*testObject);

	////// Make second obj with transform
	// Create a new game object
	testObject = new GameObject("TestObject");

	// Create a transform component at 0,0 with scale 300,300
	transform = new Transform(1.5f, 1.5f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(2.0f, 2.0f));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	sprite = new Sprite();
	sprite->SetColor(Colors::LightBlue);
	testObject->AddComponent(sprite);

	// add circle collider
	// ColliderCircle* collider = new ColliderCircle();
	collider = new ColliderRectangle();
	collider->SetExtents(transform->GetScale() / 2.0f);
	testObject->AddComponent(collider);

	// Initialize the object
	// testObject->Initialize();

	// use obj manager to update/draw, etc
	GetSpace()->GetObjectManager().AddObject(*testObject);
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
}

// Shutdown any memory associated with the Level1 game state.
void Level1::Shutdown()
{
	std::cout << "Level1::Shutdown" << std::endl;

	delete testObject;
}
