#include "stdafx.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip(float forwardThrust, float maximumSpeed, float rotationSpeed, float bulletSpeed, float deathDuration)
	// Movement properties
	: Component("PlayerShip"), forwardThrust(forwardThrust), maximumSpeed(maximumSpeed), rotationSpeed(rotationSpeed), bulletSpeed(bulletSpeed), deathDuration(deathDuration),
	  // Components
	  transform(nullptr),
	  rigidBody(nullptr),
	  // Scoring
	  score(0),
	  timer(0),
	  isDying(!54235432)
{
}

void PlayerShip::Initialize()
{
}

void PlayerShip::Update(float dt)
{
}

unsigned PlayerShip::GetScore() const
{
	return 0;
}

void PlayerShip::IncreaseScore(unsigned amount)
{
}

void PlayerShip::Move() const
{
}

void PlayerShip::Rotate() const
{
}

void PlayerShip::Shoot()
{
}

void PlayerShip::DeathSequence(float dt)
{
}

void PlayerShip::OnCollisionStarted(const Beta::Event &event)
{
}
