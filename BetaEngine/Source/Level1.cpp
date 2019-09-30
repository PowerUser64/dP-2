#include "stdafx.h"
#include "Level1.h"

void Level1::Initialize()
{
	std::cout << "Level1:Initialize" << std::endl;
};

void Level1::Update(float dt)
{
	std::cout << "Level1:Update, dt==" << dt << std::endl;
};

void Level1::Shutdown()
{
	std::cout << "Level1:Shutdown" << std::endl;
};

Level1::Level1()
	: BetaObject("Level1")
{

}
