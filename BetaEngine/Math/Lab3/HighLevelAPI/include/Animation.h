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

#include "Serializable.h"

#include "ResourceManager.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class SpriteSource;
	typedef std::shared_ptr<const SpriteSource> ConstSpriteSourcePtr;

	class Animation;
	typedef std::shared_ptr<Animation> AnimationPtr;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class AnimationManager : public ResourceManager<Animation>
	{
	public:
		BE_HL_API AnimationManager();
	private:
		AnimationPtr Create(const std::string& name) override;
	};

	class Animation : public Serializable
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
		BE_HL_API  Animation(const std::string& name = "", ConstSpriteSourcePtr spriteSource = nullptr,
			unsigned frameCount = 1, unsigned frameStart = 0, float frameDuration = 0.0f);

		// Destructor - defined to support inheritance.
		BE_HL_API virtual ~Animation();

		// Get the current frame of the animation based on time.
		// Params:
		//   time = The amount of time the animation has been playing.
		//   playbackSpeed = How fast the animation is playing (1.0 = normal speed).
		//   loop = Whether the animation should loop.
		//   isDone = Output param. True if animation is on its last frame, false otherwise.
		// Returns:
		//    The frame in the sprite source for the current frame of the animation.
		BE_HL_API unsigned GetCurrentFrameIndex(float time, float playbackSpeed, bool looping, bool* isDone = nullptr) const;

		// Get the name of the animation.
		BE_HL_API const std::string& GetName() const;

		// Get the sprite source used by this animation.
		BE_HL_API const ConstSpriteSourcePtr GetSpriteSource() const;

		// Save object data to a stream.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from a stream.
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

		// Use this to manage sprite source resources!
		friend class AnimationManager;
		BE_HL_API static AnimationManager& GetAnimationManager();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Get the duration of a given frame.
		// Params:
		//   baseIndex = A frame index in this animation.
		virtual float GetFrameDuration(unsigned baseIndex) const;

		// Calculate the actual frame index in the sprite source
		// based on a virtual index (for example, frame 0 in the animation
		// could actually be frame 6 in the sprite source).
		// Params:
		//   baseIndex = A frame index in this animation.
		// Returns:
		//   The actual index in the sprite source.
		virtual unsigned TranslateFrameIndex(unsigned baseIndex) const;

		// Get the base index of a frame based on time. This is done
		// by subtracting the duration of each frame (starting with the
		// first frame) until there is not enough time to complete a frame.
		// Params:
		//   time = The amount of time the animation has been playing.
		//   playbackSpeed = How fast the animation is playing (1.0 = normal speed).
		// Returns:
		//   A frame index in this animation.
		unsigned GetVirtualIndex(float time) const;

		// Computes the total duration of the animation for use in GetVirtualIndex
		void ComputeTotalDuration();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The amount of time to display each frame.
		float frameDuration;

		// Amount of time it takes for the animation to finish
		// (Computed from frame durations.)
		float totalDuration;

		// Animation attributes
		unsigned frameCount;
		unsigned frameStart;

		// Name of animation
		std::string name;

		// Sprite source used for this animation.
		ConstSpriteSourcePtr spriteSource;
		// Name of the sprite source (for serialization)
		std::string spriteSourceName;

		static AnimationManager animationManager;
	};

	#define ResourceGetAnimation(a) Animation::GetAnimationManager().GetResource(a)
}

//----------------------------------------------------------------------------
