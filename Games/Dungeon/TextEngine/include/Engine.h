//------------------------------------------------------------------------------
//
// File Name:	Engine.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

typedef struct GameObject GameObject;

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

// Used as an argument for EngineSetLevel to quit the game.
extern const int gEngineLevelQuit;
// Used as an argument for EngineSetLevel to restart the current level.
extern const int gEngineLevelRestart;
// Used as an argument for EngineSetLevel to advance to the next level.
extern const int gEngineLevelNext;

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// Pointer to function used to init/shutdown a level.
// Example: void _MenuInit(void);
// Example: void _MenuShutdown(void);
typedef void(*LevelVoidFunctionPtr)(void);

// Pointer to function used to update a level. 
// Example: void _MenuUpdate(float dt);
typedef void(*LevelDtFunctionPtr)(float dt);

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Start the game loop. Try changing the framerate cap value
// if you experience "blinking" on your machine.
// Params:
//  framerateCap = Maximum framerate.
void EngineStart(float framerateCap);

// Add functions for a new level.
// Params:
//   init = Pointer to the level's init function.
//   update = Pointer to the level's update function.
//   shutdown = Pointer to the level's shutdown function.
void EngineAddLevel(LevelVoidFunctionPtr init, LevelDtFunctionPtr update, LevelVoidFunctionPtr shutdown);

// Get the current level being played.
// Returns:
//   The current level.
int EngineGetLevel(void);

// Switch to a different level.
// Params:
//   level = Level number of the desired level.
void EngineSetLevel(int level);

// Check if a key is being held down.
// Params:
//   key = The key to check.
bool EngineIsKeyDown(int key);

// Check if a key was pressed and then released.
// Params:
//   key = The key to check.
bool EngineIsKeyPressed(int key);

// Draw some text on the screen.
// Params:
//   text = The string of text to output.
//   color = The color of the text.
//	 x = The x position of the start of the text.
//   y = The y position of the start of the text.
void EngineDrawText(const char* text, short color, float x, float y);

// Draw some text on the screen using a pair of colors.
// Params:
//   text = The string of text to output.
//   colorPairIndex = The specific pair of colors desired for this text.
//	 x = The x position of the start of the text.
//   y = The y position of the start of the text.
void EngineDrawTextColorPair(const char* text, short colorPairIndex, float x, float y);

// Create a pair of colors to use with EngineDrawTextColorPair.
// Params:
//   index = The number used to reference this pair.
//   textColor = The color used to draw the characters themselves.
//   backgroundColor = The color drawn behind each character.
void EngineSetColorPair(short index, short textColor, short backgroundColor);

// Write some text to a log.txt file in the project directory.
// Use it just like printf.
// Params:
//   formatString = The string of text to output to a file.
//   ... = Variables to insert into the string.
void EngineLogMessage(const char * formatString, ...);

/*----------------------------------------------------------------------------*/
