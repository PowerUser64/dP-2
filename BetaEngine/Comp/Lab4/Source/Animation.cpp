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
/* 2.  GetCurrentFrameIndex
 *  *   Use the _GetVirtualIndex_ function to determine which frame of the animation we should be on based on the current time and playback speed. 
 *  *   If the animation is looping
 *      *   Make sure the frame index goes back to 0 if it reaches the last frame.
 *  *   Otherwise
 *      *   Make sure the frame index does not go past the last frame.
 *  *   If the _isDone _param is not null
 *      *   Set its value based on the current frame index. (Should be **true** if the current frame is the last frame.)
 *  *   Return the actual frame index the sprite should use by using by adding the starting frame to the frame index.  
 */
unsigned Animation::GetCurrentFrameIndex(float dt, float playbackSpeed, bool looping, bool *isDone) const
{
	int indx = GetVirtualIndex(dt, playbackSpeed);
	if (looping && indx)
		indx = 0;
	else
		indx = indx % frameCount;
	if (isDone != nullptr && indx == frameCount-1)
		*isDone = true;
	// std::cout << "index is "<< indx << '\n';
	return indx;
}

// Get the name of the animation.
const std::string &Animation::GetName() const
{
	return name;
}

// Get the sprite source used by this animation.
const SpriteSource *Animation::GetSpriteSource() const
{
	return spriteSource;
}

/* 3.  GetVirtualIndex
    *   _\[NOTE: The goal of this function is to figure out which frame we should be on based on how much time has passed. We will do this by adding the change in
	* 	time to an accumulator. If the accumulator accumulates enough time, we advance the frame.\]_
    *   Add time to the accumulator (_dt _times _playbackSpeed)._
    *   While the accumulator meets or exceeds the frame duration
        *   Increase the current frame index.
        *   Decrease the accumulator using _dt._
    *   Return the current frame.
*/
unsigned Animation::GetVirtualIndex(float dt, float playbackSpeed) const
{
	accumulator += dt * playbackSpeed;
	if(frameDuration == 0)
		++currentVirtualFrame;
	else
	while (accumulator >= frameDuration)
		++currentVirtualFrame, accumulator -= frameDuration;
	return currentVirtualFrame;
}
