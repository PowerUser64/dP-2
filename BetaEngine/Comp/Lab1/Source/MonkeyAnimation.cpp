//------------------------------------------------------------------------------
//
// File Name:	MonkeyAnimation.cpp
// Author(s):	Student name here
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"          // Precompiled header
#include "MonkeyAnimation.h" // Class file
#define right true
#define left false

using namespace Beta;

// STUDENT CODE GOES HERE

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Constructor
MonkeyAnimation::MonkeyAnimation()
    : // Animation variables
      walkAnimation(0),
      jumpAnimation(0),
      idleAnimation(0),

      // Components
      animator(nullptr),
      physics(nullptr),
      transform(nullptr),

{
    /*
     * // Animation state
     * State currentState;
     * State nextState;
     * // Flip
     * Beta::Vector2D originalScale;
     */
}

// Initialize this component (happens at object creation).
void MonkeyAnimation::Initialize()
{
    animator->AddAnimation(0);
}

// Fixed update function for this component.
// Params:
//   dt = The (fixed) change in time since the last step.
void MonkeyAnimation::Update(float dt)
{
}
//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Choose the correct state based on velocity.
void MonkeyAnimation::ChooseNextState()
{
}
// Change states and start the appropriate animation.
void MonkeyAnimation::ChangeCurrentState()
{
}

// Flip the sprite based on velocity and current state.
void MonkeyAnimation::FlipSprite() const
{
    /* checks for one of two patterns (based on points)
       * either
       *  this    or   this
       *   x      \      x
       *    x     \     x
       *   x      \      x
       * (changed \ (changed
       * to left) \ to right)
       */
    /*  // based on velocity 
     *  if ((point1X > point2X && point2X < point3X) || (point1X < point2X && point2X > point3X))
     *      spr_dir = !spr_dir;
     */
}
// Create extra component functions - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(MonkeyAnimation)
