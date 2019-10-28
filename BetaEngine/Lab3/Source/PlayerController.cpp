#include "stdafx.h"
#include "PlayerController.h"

PlayerController::PlayerController()
	: Component("PlayerController"), transform(nullptr)
{
}

void PlayerController::Initialize()
{
	// Grab pointer(s) to component(s)
	transform = GetOwner()->GetComponent<Beta::Transform>();
}

void PlayerController::Update(float dt)
{
	using namespace Beta;
	Input& input = *EngineGetModule(Input);

	Vector2D position = transform->GetTranslation();
	float speed = 2.0f;

	if (input.CheckHeld(VK_LEFT))
	{
		position.x -= speed * dt;
	}

	if (input.CheckHeld(VK_RIGHT))
	{
		position.x += speed * dt;
	}

	if (input.CheckHeld(VK_UP))
	{
		position.y += speed * dt;
	}

	if (input.CheckHeld(VK_DOWN))
	{
		position.y -= speed * dt;
	}

	transform->SetTranslation(position);
}

COMPONENT_SUBCLASS_DEFINITION(PlayerController)