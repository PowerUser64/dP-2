#include "stdafx.h"
#include "Level1.h"

Level1::Level1()
{
}

void Level1::Load()
{
	// Create a sprite component and set its mesh and sprite source
	TexturePtr texture = ResourceGetTexture("Ship.png");
	SpriteSourcePtr spriteSource = std::make_shared<SpriteSource>(texture, "Ship", 3, 5);
	Sprite *sprite = new Sprite();
	sprite->SetColor(Colors::Green);
	sprite->SetSpriteSource(spriteSource);
	GetOwner()->AddComponent(sprite);
}

void Level1::Initialize()
{
}

void Level1::Update(float dt)
{
}

void Level1::Shutdown()
{
}

void Level1::Unload()
{
}

Beta::GameObject* Level1::CreateMonkey(void)
{
	return nullptr;
}
