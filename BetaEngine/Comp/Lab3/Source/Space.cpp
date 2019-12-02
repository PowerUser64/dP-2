#include "stdafx.h"
#include "Space.h"

/*  Space (constructor)
 	 *     Initialize base class (BetaObject) with the provided name parameter.
 	 *     Initialize other class variables.
 	 */
Space::Space(const std::string& name)
{
}

/*  ~Space (destructor)
	 *     Shut down the space
	 */
Space::~Space()
{
}

/*  Update
	 *     Print "Space::Update"
	 *     If there is a next level, change levels
	 *     If there is a current level and the space is not paused, update the level
	 */
void Space::Update(float dt)
{
}

/*  Shutdown
	 *     If there is a current level, shutdown and unload the level.
	 *     Delete the current level and set the pointer to the current level to nullptr.
	 */
void Space::Shutdown()
{
}

/*  IsPaused
	 *     Simple get/set functions. Self-explanatory.
	 */
bool Space::IsPaused() const
{
	return false;
}

/* GetLevelName
	 *     Simple get/set functions. Self-explanatory.
	 */
const std::string& Space::GetLevelName() const
{
	// TODO: insert return statement here
}

/* SetPaused
	 *     Simple get/set functions. Self-explanatory.
	 */
void Space::SetPaused(bool value)
{
}

/*  SetLevel
	 *     Set the next level to the given parameter.
	 *     Set the level's owner to the space (ensures the level's GetSpace function works correctly).
	 */
void Space::SetLevel(Level* level)
{
}

/*  RestartLevel
	 *     Set the next level to the current level.
	 */
void Space::RestartLevel()
{
}

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
void Space::ChangeLevel()
{
}
