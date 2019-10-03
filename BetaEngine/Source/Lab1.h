#pragma once
#include <BetaObject.h>

class Lab1 : public Beta::BetaObject
{
public:
	Lab1();
	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

private:
	// length of one second relative to the simulation
	float pi = (float)M_PI;
	// half speed
	float rad_pos1 = 0;
	// normal speed
	float rad_pos2 = 0;
	// double speed
	float rad_pos3 = 0;
	//cool mode
	bool cool_mode = false;
};