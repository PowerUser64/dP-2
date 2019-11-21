//------------------------------------------------------------------------------
//
// File Name:	ScreenWrap.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h" // base class

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class Transform;
	class RigidBody;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class ScreenWrap : public Beta::Component
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Default constructor
	ScreenWrap();

	// Initialize this component (happens at object creation).
	void Initialize() override;

	// Update function for this component.
	// Params:
	//   dt = The (fixed) change in time since the last step.
	void Update(float dt) override;

private:

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Components
	Beta::Transform* transform;
	Beta::RigidBody* rigidBody;

	COMPONENT_SUBCLASS_DECLARATION(ScreenWrap)
};

//------------------------------------------------------------------------------
