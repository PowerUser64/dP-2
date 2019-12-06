#include "stdafx.h"
#include "Level1.h"
#include "Level2.h"
#include "Space.h"
#include "MeshHelper.h"
#include "Sprite.h"

/* All functions aside from the constructor need to print out "Level1::" followed by the name of the function. For example, the Initialize function should print out "Level1::Initialize".
 */
// print what function (fn) it's in (with less code)
#define fn(str) ;// std::cout << "Level1::" << str <<std::endl

using namespace Beta;
/*
 *
// Lab 4 stuff:
 * 
 * 
//  We're going to use Level 1 to test drawing a sprite without a texture/sprite source. The following changes need to be made to the Level1.cpp file (taken from CS230 Lab 3):
 *
 *  1.  In the **constructor**, initialize any new class variables to sane values. Change the value of _lives_ from 3 to 256.
 *  2.  In the **Load** function, add code to create a triangle mesh (using three distinct colors such as red, green, and blue) and store it in the mesh pointer (you wrote a function for this earlier in _Part 2_ of this assignment).
 *  3.  In the **Initialize** function, create a new Sprite, store it in the appropriate variable, and make sure it's using the mesh you created in Load.
 *  4.  In the **Update** function, draw the sprite.
 *  5.  The **Shutdown** and **Unload** functions should be deleting what you created in _Initialize_ and _Load, _respectively.
 * 
 * 
 * 
 * 
 */

// Creates an instance of Level 1.
/*     In the constructor, initialize the base class, and initialize lives to 3.
 */
//  1.  In the **constructor**, initialize any new class variables to sane values. Change the value of _lives_ from 3 to 256.
Levels::Level1::Level1() : Level("Level1")
{
    // Beta::Mesh *
    mesh = nullptr;

    // Sprite *
    sprite = nullptr;

    // unsigned
    lives = 3;
}

// Load the resources associated with Level 1.
//  2.  In the **Load** function, add code to create a triangle mesh (using three distinct colors such as red, green, and blue) and store it in the mesh pointer (you wrote a function for this earlier in _Part 2_ of this assignment).
void Levels::Level1::Load()
{
    fn("Load");
    mesh = CreateTriangleMesh(Beta::Colors::LightBlue, Beta::Colors::Yellow, Beta::Color::Color(1,0,1));
}

// Initialize the memory associated with Level 1.
//  3.  In the **Initialize** function, create a new Sprite, store it in the appropriate variable, and make sure it's using the mesh you created in Load.
void Levels::Level1::Initialize()
{
    fn("Initalize");
    sprite = new Sprite(mesh);
}		

// Update Level 1.		
// Params:		
//	 dt = Change in time (in seconds) since the last game loop.
/* In the Update function, decrease lives by 1
 *     When lives reaches 0, switch to Level 2. (If you haven't implemented Level 2 yet, quit the game instead (`EngineCore::GetInstance().Stop()`))
 */
//  4.  In the **Update** function, draw the sprite.
void Levels::Level1::Update(float dt)
{
    fn("Update");
    --lives;
    std::cout << "  lives = " << lives << std::endl;
    if(lives == 0)
        GetSpace()->SetLevel(new Levels::Level2());
    sprite->Draw();
}

// Shutdown any memeary associated with Level 1.
//  5.  The **Shutdown** and **Unload** functions should be deleting what you created in _Initialize_ and _Load, _respectively.
void Levels::Level1::Shutdown()
{
    fn("Shutdown");
    delete sprite;
}

// Unload the resources associated with Level 1.
void Levels::Level1::Unload()
{
    fn("Unload");
    delete mesh;
}

/* Now, we'll need to modify the main function in Main.cpp files to actually test the level: 
 * 
 *     Follow the TO-DO comments in WinMain to add the space to the engine, and set the first level on the space to Level1.
 *     In order to check that your output matches the traceMaster.txt, I recommend redirecting std::cout to a file. To redirect std::cout, you can use these lines of code before the engine starts:
 * 
 *     std::streambuf* coutBuff = std::cout.rdbuf();
 *     std::ofstream fileOutput("trace.txt");
 *     std::cout.rdbuf(fileOutput.rdbuf());
 * 
 *     You should also redirect std::cout back to the console after the engine stops (after engine.Start()) to ensure it doesn't crash upon exit:
 * 
 *     std::cout.rdbuf(coutBuff);
 * 
 * Once you've written this code, you can test to see if Level1 is working and is writing to the trace.txt file.
 */
