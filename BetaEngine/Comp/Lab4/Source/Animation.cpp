#include "stdafx.h"
#include "Animation.h"

/*  Construct a new animation resource.
 *  Params:
 *    name = The name of the animation.
 *    spriteSource = The sprite source used by this animation.
 *    frameCount = The number of frames in this animation.
 *    frameStart = The starting frame in the sprite source for this animation.
 *    duration = The time that each frame will be displayed.
 */
Animation::Animation(const std::string &_name, const SpriteSource *_spriteSource, unsigned _frameCount, unsigned _frameStart, float _frameDuration)
{
	// Time accumulated between last call to GetCurrentFrameIndex and current call
	//mutable float 
	accumulator = 0;

	// Current frame of the animation (from 0 to frameCount)
	//mutable unsigned 
	currentVirtualFrame = 0;

	// The amount of time to display each frame.
	//float
	frameDuration = _frameDuration;

	// Animation attributes
	//unsigned 
	frameCount = _frameCount;
	//unsigned
	frameStart = _frameStart;

	// Name of animation
	//std::string
	name = _name;

	// Sprite source used for this animation.
	//const SpriteSource *
	spriteSource = _spriteSource;
}

/* Get the current frame of the animation based on time.
 *  Params:
 *    dt = The change in time since the last update.
 *    playbackSpeed = How fast the animation is playing (1.0 = normal speed).
 *    loop = Whether the animation should loop.
 *    isDone = Output param. True if animation is on its last frame, false otherwise.
 *  Returns:
 *    The frame in the sprite source for the current frame of the animation.
 */
unsigned Animation::GetCurrentFrameIndex(float dt, float playbackSpeed, bool looping, bool *isDone) const
{
	return 0;
}

// Get the name of the animation.
const std::string &Animation::GetName() const
{
	return name;
}

// Get the sprite source used by this animation.
const SpriteSource *Animation::GetSpriteSource() const
{
	return nullptr;
}

unsigned Animation::GetVirtualIndex(float dt, float playbackSpeed) const
{
	return 0;
}
