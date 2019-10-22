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
	TexturePtr texture = ResourceGetTexture("Monkey.png");
	SpriteSourcePtr spriteSource = std::make_shared<SpriteSource>(texture, "Monkey", 3, 5);
	Sprite* sprite = new Sprite();
	sprite->SetColor(Colors::Green);
	sprite->SetSpriteSource(spriteSource);
	testObject->AddComponent(sprite);

	Animator* animator = new Animator();
	testObject->AddComponent(animator);
	AnimationPtr walkAnim = std::make_shared<Animation>("MonkeyWalk", spriteSource, 8, 0, 0.01);

	// add amins to animator
	size_t walkIndex = animator->AddAnimation(walkAnim);

	// Initialize the object
	// testObject->Initialize();
	// OR...
	GetSpace()->GetObjectManager().AddObject(*testObject);

	// play walk anims
	animator->Play(walkIndex);
	
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
	// if (input->CheckTriggered('D'))
	// {
	// 	testObject->Destroy();
	// 	testObject = nullptr;
	// }

	// handled by obj manager
	// If the object exists
	// if (testObject)
	// {
		// Update and draw
		// testObject->Update(dt);
		// testObject->Draw();
	// }
	
	Transform* transform = testObject->GetComponent<Transform>();
	Vector2D position = transform->GetTranslation();
	float rot = transform->GetRotation();

	if (input->CheckHeld(VK_RIGHT))
		position.x += 2.0f * dt;
	if (input->CheckHeld(VK_UP))
		position.y += 2.0f * dt;
	if (input->CheckHeld(VK_DOWN))
		position.y -= 2.0f * dt;
	if (input->CheckHeld(VK_LEFT))
		position.x -= 2.0f * dt;
	transform->SetTranslation(position);

	if (input->CheckHeld('.'))
		rot += 2.0f * dt;
	if (input->CheckHeld(','))
		rot -= 2.0f * dt;
	transform->SetRotation(rot);
}

// Shutdown any memory associated with the Level1 game state.
void Level1::Shutdown()
{
	std::cout << "Level1::Shutdown" << std::endl;
	
	// handled by obj manager
	// delete testObject;
}
