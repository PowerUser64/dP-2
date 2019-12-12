#include "stdafx.h"
#include "Level2.h"
#include "MeshHelper.h"
#include "Space.h"
#include "Animation.h"
#include "Animator.h"
#include "SpriteSource.h"

// print what function (fn) it's in (with less code)
#define fn(str) ;//std::cout << "Level2::" << str << std::endl

using namespace Beta;

// Creates an instance of Level 2.
/*    In the constructor, initialize the base class, initialize lives to 2, and initialize maxHealth to 2
 */
/* 1.  In the **constructor**, initialize any new class variables to sane values. No changes need to be made to health or lives.
 */
/* 1.  In the **constructor,** initialize the animation frame count to 8 and duration to 0.2f.
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
    animFrameCount = 8;
    animFrameDuration = 0.02f;
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

/* 2.  In the **Load** function, create an _Animation_ using the appropriate class variables as parameters for its constructor.
 */
void Levels::Level2::Load()
{
    fn("Load");
    mesh = CreateQuadMesh(Vector2D(1/columns, 1/rows), Vector2D(0.5, 0.5));
    // load the png
    texture = Texture::CreateTextureFromFile("Monkey.png");
    // create animation
    animation = new Animation("Monkey", nullptr, animFrameCount, animFrameStart, animFrameDuration);
    // create sprite src
    spriteSource = new SpriteSource(texture, "Monkey", columns, rows);
}

// Initialize the memory associated with Level 2.
/*    In the Initialize function, set currentHealth to maxHealth.
 */
/* 3.  In the **Initialize** function, 
 *  - create a new Sprite, making sure it uses the mesh and sprite source you created in the Load function.
 */

/* 3.  In the **Initialize** function, create an _Animator_, add the animation you created in the load function, and play it. Use the default playback speed and make sure it loops.
 */
/* 1.  In the **Initialize** function, change the frame duration to 0.0f. This will ensure frame time won't affect your program's output when compared with mine.
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

/* 4.  In the **Update** function,
 *     *   Update the animator using _dt_.
*/
/* 2.  In the **Update** function,
 *     *   Uncomment the code that deals with health and lives.
 *     *   Add the following if statement before that code:
 *         *   if the animation is not done, return
 *     *   (Every time the animation finishes a loop, health goes down by 1.)
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
/* 5.  Make sure you delete the proper things in the **Shutdown**, **Unload**.
 * * Test to make sure the animation plays and loops correctly. Once you've done that, you're almost ready to test against the expected output in _traceMaster.log. _First, make the following changes:
 */
void Levels::Level2::Shutdown()
{
    fn("Shutdown");
}

// Unload the resources associated with Level 2.
/* 5.  In the **Update** function, draw the sprite. Also comment out the code that deals with health, lives, and shutting down the game. We'll restore that code later.
 */
/* 5.  Make sure you delete the proper things in the **Shutdown**, **Unload**.
 * * Test to make sure the animation plays and loops correctly. Once you've done that, you're almost ready to test against the expected output in _traceMaster.log. _First, make the following changes:
 */
void Levels::Level2::Unload()
{
    fn("Unload");
}

/* Now your program will run extremely quickly on Level 2. To redirect output to a text file, follow these procedures (different from last time):
 * 
 * *   In Main.cpp, add code to redirect the output of std::cout to a file called _trace.txt. _You can refer to your previous lab for how to do this.
 */

/* You'll need to implement the functions listed in Level1.h in a new Level1.cpp file:
 *    All functions aside from the constructor need to print out "Level2::" followed by the name of the function. For example, the Initialize function should print out "Level2::Initialize".
 */