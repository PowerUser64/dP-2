//------------------------------------------------------------------------------
//
// File Name:	Input.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Vector2D.h"
#include "Array.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Input
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Initialize keyboard and cursor data to clean state
		BE_API Input();

		// Update keyboard and cursor data
		BE_API void Update();

		// Test if key was down before and is still down
		BE_API bool CheckHeld(unsigned key) const;
		// Test if key was not down before but is down now
		BE_API bool CheckTriggered(unsigned key) const;
		// Test if key was down before but is not down now
		BE_API bool CheckReleased(unsigned key) const;

		// Test if key is currently down 
		BE_API bool IsKeyDown(unsigned key) const;
		// Test if key was down a number of frames before the current frame
		BE_API bool WasKeyDown(unsigned key, unsigned framesBefore = 1) const;

		// Get the current location of the mouse in screen coordinates
		BE_API Vector2D GetCursorPosition() const;
		// Sets the current location of the cursor this frame.
		BE_API void SetCursorPosition(const Vector2D& position);

		// Get the amount that the mouse has scrolled this frame
		BE_API float GetMouseScrollAmount() const;
		// Set the scroll amount that occurred this frame.
		BE_API void SetMouseScrollAmount(float amount);

		// Set the number of frames to store past the current frame.
		// Params:
		//   size = Number of previous frames to store (should be > 1).
		BE_API void SetBufferSize(unsigned size);

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		// Helper functions
		void UpdateKeyboard();
		void UpdateMouse();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Mouse information
		Vector2D mousePosition;
		long cursorPosX;
		long cursorPosY;

		long cursorDeltaX;
		long cursorDeltaY;

		float scrollAmountCurrent;
		float scrollAmountPrevious;

		// Keys data from current and previous frames.
		static const unsigned inputKeyNum;
		// Current frame is first vector, previous frames are subsequent vectors
		Array<Array<unsigned char>> inputKeyBuffer;
	};
}

//------------------------------------------------------------------------------
