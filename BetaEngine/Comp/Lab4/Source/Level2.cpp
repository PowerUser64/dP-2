#include "stdafx.h"
#include "Level2.h"

#include "Space.h"
// print what function (fn) it's in (with less code)
#define fn(str) ;//std::cout << "Level2::" << str << std::endl

/* You'll need to implement the functions listed in Level1.h in a new Level1.cpp file:
 *    All functions aside from the constructor need to print out "Level2::" followed by the name of the function. For example, the Initialize function should print out "Level2::Initialize".
 */

using namespace Beta;

// Creates an instance of Level 2.
/*    In the constructor, initialize the base class, initialize lives to 2, and initialize maxHealth to 2
 */
/*1.  In the **constructor**, initialize any new class variables to sane values. No changes need to be made to health or lives.
 */
Levels::Level2::Level2() : Level("Level2")
{
    /* 	// Mesh and texture for sprite source
	 *	Beta::Mesh* mesh;
	 *	Beta::Texture* texture;
     *
	 *	// Sprite source variables
	 *	SpriteSource* spriteSource;
	 *	unsigned columns;
	 *	unsigned rows;
     *
	 *	// Sprite
	 *	Sprite* sprite;
     *
	 *	// Animation variables
	 *	Animator* animator;
	 *	Animation* animation;
	 *	unsigned animFrameStart;
	 *	unsigned animFrameCount;
	 *	float animFrameDuration;
     *
	 *	// Level data
	 *	unsigned lives;
	 *	unsigned maxHealth;
	 *	unsigned currentHealth;
     */
    // Mesh and texture for sprite source
    mesh = nullptr;
    texture = nullptr;
    // Sprite source variables
    spriteSource = nullptr;
    columns = 3;
    rows = 2;
    // Sprite
    sprite = nullptr;
    // Animation variables
    animator = nullptr;
    animation = nullptr;
    animFrameStart = 0;
    animFrameCount = 6;
    animFrameDuration = 0.01667f;
    // Level data
    lives = 3;
    maxHealth = 10;
    currentHealth = 9;
}

// Load the resources associated with Level 2.
/* 
 * 2.  In the **Load** function, add code to 
 *  - create a quad mesh and store it in the mesh pointer,
 *  - load the Monkey.png texture,
 *  - and create a sprite source that uses that texture (refer to the image to find the number of columns and rows).
 */
void Levels::Level2::Load()
{
    fn("Load");
    mesh = new Mesh;
    // load the png
    // ????????????
}

// Initialize the memory associated with Level 2.
/*    In the Initialize function, set currentHealth to maxHealth.
 */
/* 3.  In the **Initialize** function, 
 *  - create a new Sprite, making sure it uses the mesh and sprite source you created in the Load function.
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
    --currentHealth;
    if (!currentHealth)
        --lives;
    if (!lives)
        EngineCore::GetInstance().Stop();
	if (currentHealth == 0) space->RestartLevel();
}

// Shutdown any memory associated with Level 2.
/* 4.  The **Shutdown** and **Unload** functions should be deleting what you created in _Initialize_ and _Load_.
 */
void Levels::Level2::Shutdown()
{
    fn("Shutdown");
}

// Unload the resources associated with Level 2.
/* 5.  In the **Update** function, draw the sprite. Also comment out the code that deals with health, lives, and shutting down the game. We'll restore that code later.
 */
void Levels::Level2::Unload()
{
    fn("Unload");
}
