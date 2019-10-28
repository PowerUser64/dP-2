//------------------------------------------------------------------------------
//
// File Name:	Animator.h
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

#include "Component.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Sprite;
	class Animation;
	typedef std::shared_ptr<const Animation> ConstAnimationPtr;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Animator : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Construct a new animation controller object.
		BE_HL_API Animator();

		// Initialize components.
		BE_HL_API void Initialize() override;

		// Update the animation.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		BE_HL_API void FixedUpdate(float dt);

		// Play an animation.
		// Params:
		//   animationIndex = The index of the animation to play.
		//	 playbackSpeed = The speed at which to play the animation.
		//	 loop = Whether the animation should go back to the beginning after it reaches the end.
		BE_HL_API void Play(size_t animationIndex = 0, float playbackSpeed = 1.0f, bool loop = true);

		// Add an animation to the controller.
		// Params:
		//   animation = The animation resource that will be added to the controller.
		// Returns:
		//   The index of the animation in the controller, for use with the Play function.
		BE_HL_API size_t AddAnimation(ConstAnimationPtr animation);

		// Get the index of the currently playing animation, for use with the Play function.
		BE_HL_API size_t GetCurrentAnimationIndex() const;

		// Get the index of the animation with the specified name
		// Params:
		//   name = The name of the animation for which the index was requested.
		// Returns:
		//   The index of the given animation if it was found, or 0.
		BE_HL_API size_t GetAnimationIndex(const std::string& name) const;

		// Determine if the animation has reached the end of its sequence.
		// Returns:
		//	 True if the animation is done, false otherwise.
		BE_HL_API bool IsDone() const;

		// Set the time to wait between frames for the currently playing animation.
		// Params:
		//	 duration = The amount of time to wait between frames (in seconds).
		BE_HL_API void SetPlaybackSpeed(float speed);

		// Save object data to a stream.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from a stream.
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

	private:
		// The current animation being played.
		size_t animationIndex;

		// The amount of time the current animation has been playing.
		float elapsedTime;

		// How fast animations will play.
		float playbackSpeed;

		// True if the animation is running; false if the animation has stopped.
		bool isRunning;

		// True if the animation loops back to the beginning.
		bool isLooping;

		// True if the end of the animation has been reached, false otherwise.
		bool isDone;

		// Components
		Sprite* sprite;

		// List of animations used by this controller
		Array<ConstAnimationPtr> animationList;

		// List of names of animations used by the controller (for serialization)
		mutable Array<std::string> animationNames;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(Animator)
	};
}

//----------------------------------------------------------------------------
