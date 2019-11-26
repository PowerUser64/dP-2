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
#define velocity physics->GetVelocity
#define scale transform->GetScale

using namespace Beta;

/*  MonkeyAnimation (constructor)
 *      Initialize base class (Component) with name of class as string
 *      Initialize other variables with the suggested values:
 *          walkAnimation, jumpAnimation, idleAnimation should all be initialized to 0
 *          currentState(StateIdle)
 *          nextState(StateIdle)
 */
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

/*  Initialize
 *      Set pointers to Animator, RigidBody, and Transform using GetOwner()->GetComponent<ComponentType>()
 *      Set the indices of each animation using animator->GetAnimationIndex("AnimationName") where "AnimationName" is the name of the animation you want to retrieve (these should match the names you gave them in Level1::Load)
 *      Play the idle animation by using the Play function on the animation component and passing it idleAnimation as the chosen animation
 *      Store the original scale of the object (found in the transform) in the appropriate member variable
 */
// Initialize this component (happens at object creation).
void MonkeyAnimation::Initialize()
{
    animator = GetOwner()->GetComponent<Animator>();
    physics = GetOwner()->GetComponent<RigidBody>();
    transform = GetOwner()->GetComponent<Transform>();

    walkAnimation = animator->GetAnimationIndex("MonkeyWalk");
}

/*  Update
 *      Call the ChooseNextState function
 *      Call the ChangeCurrentState function
 *      Call the FlipSprite function
 */
// Fixed update function for this component.
// Params:
//   dt = The (fixed) change in time since the last step.
void MonkeyAnimation::Update(float dt)
{
    ChooseNextState();
    ChangeCurrentState();
    FlipSprite();
}

/*  ChooseNextState
 *      If velocity.y is not zero
 *          Set the next state to the jump state
 *      Else if velocity.x is not zero
 *          Set the next state to the walk state
 *      Else
 *          Set the next state to the idle state
 */
// Choose the correct state based on velocity.
void MonkeyAnimation::ChooseNextState()
{
    if (velocity.y != 0)
        nextState = StateJump;
    else if (velocity.x == 0)
        nextState = walkAnimation;
    else
        nextState = idleAnimation;
}

/*  ChangeCurrentState
 *      If we are changing states (current and next states are not equal)
 *          Set currentState to nextState
 *          Use a switch statement on currentState:
 *              In StateIdle, play the idle animation
 *              In StateWalk, play the walk animation
 *              In StateJump, play the jump animation
 */
// Change states and start the appropriate animation.
void MonkeyAnimation::ChangeCurrentState()
{
    if (nextState != currentState)
    {
        currentState = nextState;
        switch (currentState)
        {
        case StateIdle:
            animator->Play(walkAnimation);
            break;

        case StateWalk:
            playWalk;
            break;

        case StateJump:
            playJump;
            break;

        default:
            break;
        }
    }
}

/*  FlipSprite
 *      Note: The easiest way to "flip" a 2D sprite, is to make the corresponding component (x or y) of its scale negative.
 *      If we are not in the idle state
 *          If velocity.x is less than 0
 *              Change scale.x (on transform) to the opposite of the original scale.x
 *          Else if velocity.x is greater than 0
 *              Change scale.x to the original scale.x
 */
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
    if (currentState != idleAnimation)
    {
        if (velocity.x < 0)
            scale.x = 0 - scale.x;
        else
        if (velocity.x > 0)
            scale.x = 0 - scale.x;
    }
}
// Create extra component functions - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(MonkeyAnimation)
