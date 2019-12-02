//------------------------------------------------------------------------------
//
// File Name:	Level1.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Level.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

/*     All functions aside from the constructor need to print out "Level1::" followed by the name of the function. For example, the Initialize function should print out "Level1::Initialize".
 *     In the constructor, initialize the base class, and initialize lives to 3.
 *     In the Update function, decrease lives by 1. When lives reaches 0, switch to Level 2. If you haven't implemented Level 2 yet, you can quit the game instead (EngineCore::GetInstance().Stop()) but you'll need to remember to go back and change this later.
 */
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

namespace Levels
{
	class Level1 : public Level
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Creates an instance of Level 1.
		Level1();

		// Load the resources associated with Level 1.
		void Load();

		// Initialize the memory associated with Level 1.
		void Initialize();

		// Update Level 1.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		void Update(float dt);

		// Shutdown any memory associated with Level 1.
		void Shutdown();

		// Unload the resources associated with Level 1.
		void Unload();

	private:

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		unsigned lives;
	};
}

//----------------------------------------------------------------------------
