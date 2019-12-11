#include "stdafx.h"
#include "Animator.h"
#include "Animation.h"

/* 1.  Animation (constructor)
 *     *   Same procedure as for other constructors. The only exception to the usual sane defaults is _playbackSpeed, _which should be set to 1.0f.
 */
Animator::Animator(Sprite *sprite_)
{
	// The current animation being played.
	// size_t
	animationIndex = 0;

	// How fast animations will play.
	// float
	playbackSpeed = 0.01667;

	// True if the animation is running; false if the animation has stopped.
	// bool
	isRunning = true;

	// True if the animation loops back to the beginning.
	// bool
	isLooping = 0;

	// True if the end of the animation has been reached, false otherwise.
	// bool
	isDone = 0;

	// Components
	// Sprite *
	sprite = nullptr;

	// List of animations used by this controller
	// Beta::Array<const Animation *>
	animationList = 0;
}

/* 3.  Update
 *     *   Print out "Animation::Update" to the console.
 *     *   Animation code details:
 *         *   If an animation is not currently running, return. Otherwise, increase the elapsed time using _dt._
 *         *   Set the sprite's frame to the current frame index of the animation. Make sure to pass in the address of _isDone_ for the last param, or else we won't know when the animation is finished playing.
 */
void Animator::Update(float dt)
{
}

/* 2.  Play
 *     *   If the given animation index is invalid (i.e. at or beyond the number of animations in the animation list), return.
 *     *   Set the matching class variables (_isLooping, playbackSpeed,_ etc.) using the given parameters.
 *     *   _isRunning_ is whether the animation is currently playing, _isDone _is whether the animation is finished, and _elapsedTime_ is how much time has passed since the animation started playing. You've just started playing an animation; knowing that, use your best judgment on what these should be set to.
 *     *   Get the animation in the animation list at the given index and use it to do the following:
 *         *   Set the sprite's sprite source to the animation's sprite source
 *         *   Set the sprite's frame to the current frame index of the animation.
 */
void Animator::Play(size_t _animationIndex, float _playbackSpeed, bool _loop)
{
	if (_animationIndex < animationList.Size())
		return;
	animationIndex = _animationIndex;
	playbackSpeed = _playbackSpeed;
	isLooping = _loop;
}

/* 4.  AddAnimation
 *     *   Add the given animation to the animation list using the _PushBack_ function.
 *     *   Return the index used for the animation (size of the list - 1).
 */
size_t Animator::AddAnimation(const Animation *animation)
{
	animationList.PushBack(animation);
	return animationList.Size() - 1;
}

/* 5.  GetAnimationIndex
 *     *   For each of the animations in the animation list
 *         *   Check if the animation matches the given name. If so, return it.
 *     *   If no animations matched the name, return 0. _(NOTE: This would be a place where we might consider throwing an exception, if we knew what an exception was...)_
 */
size_t Animator::GetAnimationIndex(const std::string &name) const
{
	for (int i = 0; i < animationList.Size; ++i)
		if (animationList[i]->GetName() == name)
			;
	return i;
	return 0;
}

/* 6.  GetCurrentAnimationIndex, IsDone, SetPlaybackSpeed
 *     *   Simple accessors/mutators. Implement them.
 */
size_t Animator::GetCurrentAnimationIndex() const
{
	return animationIndex;
}

/* 6.  GetCurrentAnimationIndex, IsDone, SetPlaybackSpeed
 *     *   Simple accessors/mutators. Implement them.
 */
bool Animator::IsDone() const
{
	return isDone;
}

/* 6.  GetCurrentAnimationIndex, IsDone, SetPlaybackSpeed
 *     *   Simple accessors/mutators. Implement them.
 */
void Animator::SetPlaybackSpeed(float speed)
{
	playbackSpeed = speed;
}
