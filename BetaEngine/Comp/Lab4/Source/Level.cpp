#include "stdafx.h"
#include "Level.h"

	// Creates a game state.
	// Params:
	//   name = Name to use for this state.
/* Level (constructor)
 *     Initialize base class (BetaObject) with the provided name parameter.
 */
Level::Level(const std::string& name) : BetaObject("Level")
{
}

// Retrieve the space in which the level is running.
/* GetSpace
 *     Return the object that owns this object (usually a space). This function is actually very simple, only one line of code -- take a look at the pre-existing functions in BetaObject that this class inherits to help you out.
 */
Space* Level::GetSpace() const
{
	return (Space* )GetOwner();
}
