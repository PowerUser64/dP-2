#pragma once
#include <BetaObject.h>

class Level1 : public Beta::BetaObject
{
public:
	Level1();


	void Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;
};