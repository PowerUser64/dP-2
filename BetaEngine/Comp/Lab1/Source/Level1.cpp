#include "stdafx.h"
#include "Level1.h"

using namespace Beta;
Level1::Level1() : Level("Leve1")
{

}

void Level1::Load()
{
	// Create a sprite component and set its mesh and sprite source
	textureMonkey = ResourceGetTexture("Monkey.png");
	spriteSourceMonkey = std::make_shared<SpriteSource>(textureMonkey, "Monkey", 3, 5);
	// animations
	//"MonkeyWalk" (8 frames, starts from frame 0, frame duration of 0.15f seconds)
	animationWalk = std::make_shared<Animation>("MonkeyWalk", spriteSourceMonkey, 8, 0, 0.01f);
	//"MonkeyJump" (1 frame, starts from frame 9)
	animationJump = std::make_shared<Animation>("MonkeyJump", spriteSourceMonkey, 1, 9, 0.0f);
	//"MonkeyIdle" (1 frame, starts from frame 12)
	animationIdle = std::make_shared<Animation>("MonkeyIdle", spriteSourceMonkey, 1, 12, 0.0f);
}

void Level1::Initialize()
{
	std::cout << "Level1::Initialize" << std::endl;
	// set bkgnd color
	GraphicsEngine *graphix = EngineGetModule(GraphicsEngine);
	graphix->SetBackgroundColor(Colors::Grey);
	GetSpace()->GetObjectManager().AddObject(*CreateMonkey());
	
}

void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
}

void Level1::Shutdown()
{
}

void Level1::Unload()
{
}

Beta::GameObject* Level1::CreateMonkey(void)
{
	GameObject* Monkey = new GameObject("Monkey");
	Sprite *sprite = new Sprite();
	sprite->SetColor(Colors::Green);
	sprite->SetSpriteSource(spriteSourceMonkey);
	Monkey->AddComponent(sprite);
	return nullptr;
}
