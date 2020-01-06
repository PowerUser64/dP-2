//------------------------------------------------------------------------------
//
// File Name:	Animation.h
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

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

class SpriteSource;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Animation
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Construct a new animation resource.
	// Params:
	//   name = The name of the animation.
	//   spriteSource = The sprite source used by this animation.
	//   frameCount = The number of frames in this animation.
	//   frameStart = The starting frame in the sprite source for this animation.
	//   duration = The time that each frame will be displayed.
	Animation(const std::string& name = "", const SpriteSource* spriteSource = nullptr,
		unsigned frameCount = 1, unsigned frameStart = 0, float frameDuration = 0.0f);

	// Get the current frame of the animation based on time.
	// Params:
	//   dt = The change in time since the last update.
	//   playbackSpeed = How fast the animation is playing (1.0 = normal speed).
	//   loop = Whether the animation should loop.
	//   isDone = Output param. True if animation is on its last frame, false otherwise.
	// Returns:
	//    The frame in the sprite source for the current frame of the animation.
	unsigned GetCurrentFrameIndex(float dt, float playbackSpeed, bool looping, bool* isDone = nullptr) const;

	// Get the name of the animation.
	const std::string& GetName() const;

	// Get the sprite source used by this animation.
	const SpriteSource* GetSpriteSource() const;

private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Calculate the current frame in the animation based on the amount of time
	// that has passed.
	// Params:
	//   dt = The change in time since the last update.
	//   playbackSpeed = How fast the animation is playing (1.0 = normal speed).
	unsigned GetVirtualIndex(float dt, float playbackSpeed) const;

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Time accumulated between last call to GetCurrentFrameIndex and current call
	mutable float accumulator;

	// Current frame of the animation (from 0 to frameCount)
	mutable unsigned currentVirtualFrame;

	// The amount of time to display each frame.
	float frameDuration;

	// Animation attributes
	unsigned frameCount;
	unsigned frameStart;

	// Name of animation
	std::string name;

	// Sprite source used for this animation.
	const SpriteSource* spriteSource;
};

//----------------------------------------------------------------------------
