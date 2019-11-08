//------------------------------------------------------------------------------
//
// File Name:	Level.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 7
// Course:		CS230
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "BetaObject.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Space;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// You are free to change the contents of this structure as long as you do not
	//   change the public interface (functions) declared in the header.
	class Level : public BetaObject
	{
	public:
		// Creates a game state.
		// Params:
		//   name = Name to use for this state.
		BE_HL_API Level(const std::string& name);

		// Retrieve the space in which the level is running.
		BE_HL_API Space* GetSpace() const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		Level(const Level&) = delete;
		Level& operator=(const Level&) = delete;
	};
}

//------------------------------------------------------------------------------
