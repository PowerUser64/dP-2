//------------------------------------------------------------------------------
//
// File Name:	Level.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 7
// Course:		CS230
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "BetaObject.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

class Space;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// You are free to change the contents of this structure as long as you do not
//   change the public interface (functions) declared in the header.
class Level : public Beta::BetaObject
{
public:

/* Level (constructor)
 *     Initialize base class (BetaObject) with the provided name parameter.
 */
	// Creates a game state.
	// Params:
	//   name = Name to use for this state.
	Level(const std::string& name);

/* GetSpace
 *     Return the object that owns this object (usually a space). This function is actually very simple, only one line of code -- take a look at the pre-existing functions in BetaObject that this class inherits to help you out.
 */
	// Retrieve the space in which the level is running.
	Space* GetSpace() const;
};

//------------------------------------------------------------------------------
