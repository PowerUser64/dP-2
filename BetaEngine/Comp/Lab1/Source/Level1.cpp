#include "stdafx.h"
#include "Level1.h"

Level1::Level1()
{
	//------------------------------------------------------------------------------
	// Private Function Declarations:
	//------------------------------------------------------------------------------
	
	// Create a game object that uses the Monkey sprite source.
	// Returns:
	//	 A pointer to the newly constructed game object
	Beta::GameObject* CreateMonkey(void);

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	Beta::TexturePtr textureMonkey;
	Beta::SpriteSourcePtr spriteSourceMonkey;

	Beta::AnimationPtr animationWalk;
	Beta::AnimationPtr animationJump;
	Beta::AnimationPtr animationIdle;

}

void Level1::Load()
{
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
