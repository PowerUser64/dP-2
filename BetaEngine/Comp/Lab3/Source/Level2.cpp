#include "stdafx.h"
#include "Level2.h"

#include "Space.h"
// print what function (fn) it's in (with less code)
#define fn(str) std::cout << "Level2::" << str

/* You'll need to implement the functions listed in Level1.h in a new Level1.cpp file:
 *    All functions aside from the constructor need to print out "Level2::" followed by the name of the function. For example, the Initialize function should print out "Level2::Initialize".
 */

using namespace Beta;

// Creates an instance of Level 2.
/*    In the constructor, initialize the base class, initialize lives to 2, and initialize maxHealth to 2
 */
Levels::Level2::Level2() : Level(Level2())
{
    /* unsigned lives;
	 * unsigned maxHealth;
     */
    lives = 2;
    maxHealth = 2;
}

// Load the resources associated with Level 2.
void Levels::Level2::Load()
{
    fn("Load");
}

// Initialize the memory associated with Level 2.
/*    In the Initialize function, set currentHealth to maxHealth.
 */
void Levels::Level2::Initialize()
{
    fn("Intialize");
    currentHealth = maxHealth;
}

// Update Level 1.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
/* Decrease currentHealth by 1.
 * When currentHealth reaches 0:
 *     Decrease lives by 1.
 *     If lives is now 0, quit the game (EngineCore::GetInstance().Stop()).
 *     Otherwise, restart the level.
 */
void Levels::Level2::Update(float dt)
{
    fn("Update");
    Space *space = GetSpace();
    -- currentHealth;
    if (!currentHealth)
        --lives;
    if (!lives)
        EngineCore::GetInstance().Stop();
    space->RestartLevel();
}

// Shutdown any memory associated with Level 2.
void Levels::Level2::Shutdown()
{
    fn("Shutdown");
}

// Unload the resources associated with Level 2.
void Levels::Level2::Unload()
{
    fn("Unload");
}
