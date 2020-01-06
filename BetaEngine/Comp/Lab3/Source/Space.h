//------------------------------------------------------------------------------
//
// File Name:	Space.h
// Author(s):	Jeremy Kings
// Project:		BetaEngine
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
// Forward Declarations:
//------------------------------------------------------------------------------

class Level;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------


class Space : public Beta::BetaObject
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor(s)
	/*  Space (constructor)
 	 *     Initialize base class (BetaObject) with the provided name parameter.
 	 *     Initialize other class variables.
 	 */

	Space(const std::string &name = "no name");

	// Destructor
	/*  ~Space (destructor)
	 *     Shut down the space
	 */

	~Space();

	// Updates the state manager and object manager.
	// Params:
	//   dt = The change in time since the last call to this function.
	/*  Update
	 *     Print "Space::Update"
	 *     If there is a next level, change levels
	 *     If there is a current level and the space is not paused, update the level
	 */

	void Update(float dt);

	// Shuts down the object manager
	/*  Shutdown
	 *     If there is a current level, shutdown and unload the level.
	 *     Delete the current level and set the pointer to the current level to nullptr.
	 */

	void Shutdown();

	// Returns a boolean indicating whether objects in this space are paused.
	// Returns:
	//   True if the space is paused, false otherwise.
	/*  IsPaused
	 *     Simple get/set functions. Self-explanatory.
	 */
	bool IsPaused() const;

	// Returns the name of the level currently running in this space.
	/* GetLevelName
	 *     Simple get/set functions. Self-explanatory.
	 */
	const std::string &GetLevelName() const;

	// Pauses the space, preventing objects from being updated, but objects are still drawn.
	// Params:
	//   value = A true/false value that indicates whether the space should be paused.
	/* SetPaused
	 *     Simple get/set functions. Self-explanatory.
	 */
	void SetPaused(bool value);

	// Sets the level that the space is using after unloading the current level.
	// Params:
	//   level = The next level that the space will be using.
	/*  SetLevel
	 *     Set the next level to the given parameter.
	 *     Set the level's owner to the space (ensures the level's GetSpace function works correctly).
	 */
	void SetLevel(Level *level);
	

	// Restarts the current level (next level = current)
	/*  RestartLevel
	 *     Set the next level to the current level.
	 */
	void RestartLevel();


private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Updates current/next level pointers and calls shutdown/unload/load/init
	/*  ChangeLevel
 	 *     This is the only non-trivial function in this class. I'm not going to give you specific instructions on what to write for every line, but I will give you  some general rules about how things should behave:
 	 *         The values of currentLevel and nextLevel together determine what behavior should occur when changing levels. How to determine whether you're restarting or switching levels:
 	 *             If currentLevel and nextLevel are the same, the current level is restarting.
 	 *             If currentLevel and nextLevel are different, the space is switching from the current level to the next level.
 	 *         What functions should be called:
 	 *             When restarting, the current level needs to shutdown, and then initialize.
 	 *             When switching levels, the current level needs to shutdown and unload. The next level needs to load and initialize.
 	 *             There's a lot of shared code between these two procedures, so think about how you can minimize the amount of duplicate lines.
 	 *         After you've finished switching levels, currentLevel should be equal to what the nextLevel was, and nextLevel should be null.
 	 *     Also, make sure you print "Space::ChangeLevel" in this function.
 	 */

	void ChangeLevel();

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	bool paused;
	Level *currentLevel;
	Level *nextLevel;
};

//------------------------------------------------------------------------------
