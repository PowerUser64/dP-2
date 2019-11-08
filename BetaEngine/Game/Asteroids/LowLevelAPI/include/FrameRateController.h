//------------------------------------------------------------------------------
//
// File Name:	FrameRateController.h
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

namespace Beta
{
	class GraphicsEngine;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class BE_API FrameRateController
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor
		FrameRateController();

		// Grabs the initial time stamp and sets the maximum frame rate for the 
		// frame rate controller.
		// Params:
		//   framerateCap = Maximum frames per second.
		void Initialize(unsigned framerateCap = 200);

		// End the current frame, updating the delta time and frame count. Frame 
		// rate controller will wait until enough time has passed if an individual
		// frame does not take enough time.
		void FrameEnd();

		// Get the change in time from the previous frame to the current
		// Use this to make sure things such as movement and physics happen at a
		// consistent speed across multiple devices or framerates. It should be used to set a
		// dt variable for use in physics and other time-sensitive calculations and computations.
		// Return:
		//   The time between the start of the previous frame and the start of the current frame.
		float GetFrameTime() const;

		// Gets the number of frames that have elapsed since the engine started running.
		// Returns:
		//   The total frames that have elapsed.
		unsigned long GetFrameCount() const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		FrameRateController(const FrameRateController&) = delete;
		FrameRateController& operator=(const FrameRateController&) = delete;
	
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Time stamp from current frame.
		double currTime;
		// Time stamp from previous frame.
		double prevTime;

		// Number of frames since game start.
		unsigned long frameCount;

		// Minimum frame time in milliseconds
		double minDeltaTime;

		// Time passed between frames.
		double deltaTime;

		// Test for vsync
		GraphicsEngine* graphics; 
	};
}

//------------------------------------------------------------------------------
