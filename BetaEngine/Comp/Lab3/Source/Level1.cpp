#include "stdafx.h"
#include "Level1.h"
#include "Space.h"

/*     All functions aside from the constructor need to print out "Level1::" followed by the name of the function. For example, the Initialize function should print out "Level1::Initialize".
 */
// print what function (fn) it's in (with less code)
#define fn(str) std::cout << "Level1::" << str

using namespace Beta;

// Creates an instance of Level 1.
/*     In the constructor, initialize the base class, and initialize lives to 3.
 */
Levels::Level1::Level1() : Level(Level1())
{
    // unsigned lives;
    lives = 3;
}		

// Load the resources associated with Level 1.
void Levels::Level1::Load()
{
    fn("Load");
}

// Initialize the memory associated with Level 1.
void Levels::Level1::Initialize()
{
    fn("Initalize");
}		

// Update Level 1.		
// Params:		
//	 dt = Change in time (in seconds) since the last game loop.
/* In the Update function, decrease lives by 1
 *     When lives reaches 0, switch to Level 2. (If you haven't implemented Level 2 yet, quit the game instead (`EngineCore::GetInstance().Stop()`))
 */
void Levels::Level1::Update(float dt)
{
    fn("Update");
    --lives;
    std::cout << "  lives = " << lives << std::endl;
    if(lives == 0)
        EngineCore::GetInstance().Stop();
        // Space.SetLevel(Level2);
}		

// Shutdown any memeary associated with Level 1.
void Levels::Level1::Shutdown()
{
    fn("Shutdown");
}		

// Unload the resources associated with Level 1.
void Levels::Level1::Unload()
{
    fn("Unload");
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
