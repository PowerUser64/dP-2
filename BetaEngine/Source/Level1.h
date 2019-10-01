#pragma once
#include <BetaObject.h>

class Level1 : public Beta::BetaObject
{
public:
	Level1();
	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;

private:
	// half speed
	float rad_pos1 = 0;
	// normal speed
	float rad_pos2 = 0;
	// double speed
	float rad_pos3 = 0;
	//cool mode
	bool cool_mode = false;
};