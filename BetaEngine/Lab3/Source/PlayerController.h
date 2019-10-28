#pragma once

#include <Component.h>

class PlayerController : public Beta::Component
{
public:
	// Constructor
	PlayerController();

	// Game loop functions
	void Initialize() override;
	void Update(float dt) override;

private:
	// Component dependencies
	Beta::Transform* transform;

	// Extra engine stuff - DO NOT REMOVE
	COMPONENT_SUBCLASS_DECLARATION(PlayerController)
};