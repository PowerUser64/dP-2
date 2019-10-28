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

	void Serialize(Beta::FileStream& stream) const override;
	void Deserialize(Beta::FileStream& stream) override;

		private :
		// Component dependencies
		Beta::Transform *transform;
	float speed = 2.0f;
	// Extra engine stuff - DO NOT REMOVE
	COMPONENT_SUBCLASS_DECLARATION(PlayerController)
};