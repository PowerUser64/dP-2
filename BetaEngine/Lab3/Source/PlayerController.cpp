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

void Serialize(Beta::FileStream &stream) const
{
	stream.WriteVariable
}
void Deserialize(Beta::FileStream &stream);

void PlayerController::Update(float dt)
{
	using namespace Beta;
	Input& input = *EngineGetModule(Input);

	Vector2D position = transform->GetTranslation();

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