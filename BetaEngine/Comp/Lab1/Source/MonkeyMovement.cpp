//------------------------------------------------------------------------------
//
// File Name:	MonkeyMovement.cpp
// Author(s):	Student name here
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"         // Precompiled header
#include "MonkeyMovement.h" // Class file

using namespace Beta;

// STUDENT CODE GOES HERE
/*  monkeyWalkSpeed(3.0f) 
 *  monkeyJumpSpeed(8.0f) 
 *  groundHeight(-1.5f) 
 *  gravity(0.0f, -12.0f)
 */

// Constructor
MonkeyMovement::MonkeyMovement()
    : Component("Component"),
      monkeyWalkSpeed(3.0f),
      monkeyJumpSpeed(8.0f),
      groundHeight(-1.5f),
      gravity(0.0f, -12.0f)
{
}

/* Set pointers to Transform and RigidBody using GetOwner()->GetComponent<ComponentType>() where ComponentType is the component you want to access, such as Transform
 * Set translation.y on transform to ground height
 * 
 * Initialize this component (happens at object creation).
 */
void MonkeyMovement::Initialize()
{
  transform = GetOwner()->GetComponent<Transform>();
  rigidBody = GetOwner()->GetComponent<RigidBody>();
  transform->SetTranslationY(groundHeight);
}

// Fixed update function for this component.
// Params:
//   dt = The (fixed) change in time since the last step.
void MonkeyMovement::Update(float dt)
{
  UNREFERENCED_PARAMETER(dt);
  Input *input = EngineGetModule(Input);
  MoveVertical();
  MoveHorizontal();
}

// Moves horizontally based on input
void MonkeyMovement::MoveHorizontal() const
{
  Input *input = EngineGetModule(Input);
  if ((transform->GetTranslation().y <= groundHeight) && (rigidBody->GetVelocity().y <= 0))
  {
    if (input->CheckHeld(VK_RIGHT))
      rigidBody->SetVelocityX(monkeyWalkSpeed);
    if (input->CheckHeld(VK_LEFT))
      rigidBody->SetVelocityX(-1 * monkeyWalkSpeed);
  }
}

// Moves vertically based on input
void MonkeyMovement::MoveVertical() const
{
  Input *input = EngineGetModule(Input);
  if ((transform->GetTranslation().y <= groundHeight) && (rigidBody->GetVelocity().y <= 0))
  {
    if (input->CheckHeld(' '))
      rigidBody->SetVelocityX(monkeyJumpSpeed);
  }
}

// Create extra component functions - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(MonkeyMovement)
