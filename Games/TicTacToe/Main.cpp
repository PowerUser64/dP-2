//------------------------------------------------------------------------------
//
// File Name:	Main.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 1 - Tic Tac Toe
// Course:		CS170
//
// Copyright � 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#define MULTI_THREADED 0

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
#include <iostream> // cout, endl
#include <cstdlib>  // atoi
#include <ctime>	// ???
#include "PRNG.h"   // srand, random
#include "Board.h"
#include "TicTacToe.h"

//------------------------------------------------------------------------------
// Private Typedefs:
//------------------------------------------------------------------------------

typedef bool (*TestFunction)(void);

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

// Test functions. These return true if the test was successful, false otherwise.
bool TestCreateFree();
bool TestDisplay();
bool TestPlaceToken();
bool TestClear();
bool TestGetState();
bool TestRandom();
bool TestStress();
void ExecuteTest(TestFunction test, int number);

//------------------------------------------------------------------------------
// Main Function:
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	// Choose all tests unless second argument is specified
	int testNum = 0;
	if (argc > 1)
		testNum = std::atoi(argv[1]);

	// Create array of tests
	TestFunction tests[] = {
		TestCreateFree, // Test 1
		TestDisplay,	// Test 2
		TestPlaceToken, // Test 3
		TestClear,		// Test 4
		TestGetState,   // Test 5
		TestRandom,		// Test 6
		TestStress,		// Test 7
	};

	// Seed random number generator - same result every time
	CS170::Utils::srand(0, 0);

	// Run tests
	int num = sizeof(tests) / sizeof(*tests);
	if (testNum == 0)
	{
		for (int i = 0; i < num; i++)
			ExecuteTest(tests[i], i + 1);
	}
	else if (testNum > 0 && testNum <= num)
	{
		ExecuteTest(tests[testNum - 1], testNum);
	}

	return 0;
}

void ExecuteTest(TestFunction test, int number)
{
	std::cout << "////////////////////////////////////////////////" << std::endl;
	bool result = test();
	if (result == false)
		std::cout << "Test " << number << " failed.";
	std::cout << std::endl;
}

bool TestCreateFree()
{
	std::cout << "Testing CS170::BoardCreate..." << std::endl;
	CS170::Board *theBoard = nullptr;
	theBoard = CS170::BoardCreate();
	if (theBoard == nullptr)
		return false;
	std::cout << "Success." << std::endl;
	std::cout << "Testing CS170::BoardFree..." << std::endl;
	CS170::BoardFree(theBoard);
	if (theBoard != nullptr)
		return false;
	std::cout << "Success." << std::endl;
	return true;
}

bool TestDisplay()
{
	std::cout << "Testing CS170::BoardDisplay with empty board." << std::endl;
	CS170::Board *theBoard = CS170::BoardCreate();
	CS170::BoardDisplay(*theBoard);
	CS170::BoardFree(theBoard);
	return true;
}

bool TestPlaceToken()
{
	// Setup phase
	CS170::Board *theBoard = CS170::BoardCreate();
	// Testing valid placements
	CS170::PlaceResult result;
	std::cout << "Testing valid placements." << std::endl;
	for (unsigned i = 0; i < CS170::boardLength * CS170::boardLength; ++i)
	{
		result = CS170::BoardPlaceToken(*theBoard, i / CS170::boardLength, i % CS170::boardLength, (CS170::TileState)(i % 2 + 1));
		if (result != CS170::prACCEPTED)
		{
			CS170::BoardFree(theBoard);
			return false;
		}
	}
	std::cout << "Board after valid placements: " << std::endl;
	CS170::BoardDisplay(*theBoard);
	// Testing invalid placements
	std::cout << "Testing out of bounds placements." << std::endl;
	result = CS170::BoardPlaceToken(*theBoard, 3, 0, CS170::tsPLAYER_ONE);
	if (result != CS170::prREJECTED_OUTOFBOUNDS)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	result = CS170::BoardPlaceToken(*theBoard, 0, 4, CS170::tsPLAYER_ONE);
	if (result != CS170::prREJECTED_OUTOFBOUNDS)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	result = CS170::BoardPlaceToken(*theBoard, 5, 5, CS170::tsPLAYER_TWO);
	if (result != CS170::prREJECTED_OUTOFBOUNDS)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	result = CS170::BoardPlaceToken(*theBoard, (unsigned)-1, (unsigned)-1, CS170::tsPLAYER_TWO);
	if (result != CS170::prREJECTED_OUTOFBOUNDS)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	std::cout << "Board after out-of-bounds placements: " << std::endl;
	CS170::BoardDisplay(*theBoard);
	// More invalid placement testing
	std::cout << "Testing occupied placement." << std::endl;
	for (unsigned i = 0; i < CS170::boardLength * CS170::boardLength; ++i)
	{
		result = CS170::BoardPlaceToken(*theBoard, i / CS170::boardLength, i % CS170::boardLength, (CS170::TileState)((i + 1) % 2 + 1));
		if (result != CS170::prREJECTED_OCCUPIED)
		{
			CS170::BoardFree(theBoard);
			return false;
		}
	}
	std::cout << "Board after occupied placements: " << std::endl;
	CS170::BoardDisplay(*theBoard);
	// Free memory
	CS170::BoardFree(theBoard);
	return true;
}
bool TestClear()
{
	// Allocate memory
	CS170::Board *theBoard = CS170::BoardCreate();
	std::cout << "Testing BoardClear." << std::endl;
	// Place tokens
	for (unsigned i = 0; i < CS170::boardLength * CS170::boardLength; ++i)
		CS170::BoardPlaceToken(*theBoard, i / CS170::boardLength, i % CS170::boardLength, (CS170::TileState)(i % 2 + 1));
	std::cout << "Board after valid placements: " << std::endl;
	CS170::BoardDisplay(*theBoard);
	// Clear the board.
	BoardReset(*theBoard);
	std::cout << "Board after BoardClear: " << std::endl;
	CS170::BoardDisplay(*theBoard);
	// Free the board.
	CS170::BoardFree(theBoard);
	return true;
}
// Helper for TestGetState
bool TestGetStatePlayerWin(CS170::Board &theBoard, CS170::TileState player)
{
	CS170::BoardState state;
	// Test horizontal wins
	std::cout << "Testing win conditions for Player " << player << std::endl;
	std::cout << "1. Horizontal" << std::endl;
	for (unsigned r = 0; r < CS170::boardLength; ++r)
	{
		for (unsigned c = 0; c < CS170::boardLength; ++c)
			CS170::BoardPlaceToken(theBoard, r, c, player);
		CS170::BoardDisplay(theBoard);
		state = CS170::BoardGetState(theBoard);
		if (state != CS170::bsWIN_ONE + player - 1)
			return false;
		BoardReset(theBoard);
		std::cout << "Player " << player << " wins." << std::endl;
	}
	// Test vertical wins
	std::cout << "2. Vertical" << std::endl;
	for (unsigned c = 0; c < CS170::boardLength; ++c)
	{
		for (unsigned r = 0; r < CS170::boardLength; ++r)
			CS170::BoardPlaceToken(theBoard, r, c, player);
		CS170::BoardDisplay(theBoard);
		state = CS170::BoardGetState(theBoard);
		if (state != CS170::bsWIN_ONE + player - 1)
			return false;
		BoardReset(theBoard);
		std::cout << "Player " << player << " wins." << std::endl;
	}
	// Test diagonal wins
	std::cout << "3. Diagonals" << std::endl;
	for (unsigned i = 0; i < CS170::boardLength; ++i)
		CS170::BoardPlaceToken(theBoard, i, i, player);
	CS170::BoardDisplay(theBoard);
	state = CS170::BoardGetState(theBoard);
	if (state != CS170::bsWIN_ONE + player - 1)
		return false;
	BoardReset(theBoard);
	std::cout << "Player " << player << " wins." << std::endl;
	for (unsigned i = 0; i < CS170::boardLength; ++i)
		CS170::BoardPlaceToken(theBoard, i, CS170::boardLength - 1 - i, player);
	CS170::BoardDisplay(theBoard);
	state = CS170::BoardGetState(theBoard);
	if (state != CS170::bsWIN_ONE + player - 1)
		return false;
	BoardReset(theBoard);
	std::cout << "Player " << player << " wins." << std::endl;
	std::cout << "Success!" << std::endl
			  << std::endl;
	// All wins passed!
	return true;
}
bool TestGetState()
{
	// Setup phase
	CS170::Board *theBoard = CS170::BoardCreate();
	CS170::BoardState state;
	// Test empty
	std::cout << "Testing empty board." << std::endl;
	CS170::BoardDisplay(*theBoard);
	state = CS170::BoardGetState(*theBoard);
	if (state != CS170::bsOPEN)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	std::cout << "Board is open. Success!" << std::endl
			  << std::endl;
	// Test open
	std::cout << "Testing board with some tokens, no win." << std::endl;
	CS170::BoardPlaceToken(*theBoard, 0, 0, CS170::tsPLAYER_ONE);
	CS170::BoardPlaceToken(*theBoard, 0, 1, CS170::tsPLAYER_ONE);
	CS170::BoardDisplay(*theBoard);
	state = CS170::BoardGetState(*theBoard);
	if (state != CS170::bsOPEN)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	BoardReset(*theBoard);
	std::cout << "Board is open. Success!" << std::endl
			  << std::endl;
	// Test wins
	if (!TestGetStatePlayerWin(*theBoard, CS170::tsPLAYER_ONE) || !TestGetStatePlayerWin(*theBoard, CS170::tsPLAYER_TWO))
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	// Test tie
	std::cout << "Testing tie." << std::endl;
	CS170::BoardPlaceToken(*theBoard, 0, 0, CS170::tsPLAYER_ONE);
	CS170::BoardPlaceToken(*theBoard, 0, 1, CS170::tsPLAYER_ONE);
	CS170::BoardPlaceToken(*theBoard, 0, 2, CS170::tsPLAYER_TWO);
	CS170::BoardPlaceToken(*theBoard, 1, 0, CS170::tsPLAYER_TWO);
	CS170::BoardPlaceToken(*theBoard, 1, 1, CS170::tsPLAYER_TWO);
	CS170::BoardPlaceToken(*theBoard, 1, 2, CS170::tsPLAYER_ONE);
	CS170::BoardPlaceToken(*theBoard, 2, 0, CS170::tsPLAYER_ONE);
	CS170::BoardPlaceToken(*theBoard, 2, 1, CS170::tsPLAYER_ONE);
	CS170::BoardPlaceToken(*theBoard, 2, 2, CS170::tsPLAYER_TWO);
	CS170::BoardDisplay(*theBoard);
	state = CS170::BoardGetState(*theBoard);
	if (state != CS170::bsTIE)
	{
		CS170::BoardFree(theBoard);
		return false;
	}
	std::cout << "Tie game. Success!" << std::endl
			  << std::endl;
	CS170::BoardFree(theBoard);
	return true;
}
// Helper function for random test
enum OutputLevel
{
	olNONE,
	olMINIMAL,
	olNORMAL,
	olVERBOSE
};
void TestRandomHelper(OutputLevel level = olMINIMAL)
{
	// Setup phase
	CS170::Board *theBoard = CS170::BoardCreate();
	// Choose starting player
	unsigned i = CS170::Utils::rand() % 2;
	// Make random moves until game is over
	CS170::BoardState state;
	do
	{
		// Keep trying until the placement is valid
		CS170::PlaceResult result;
		unsigned row, col;
		do
		{
			row = CS170::Utils::rand() % CS170::boardLength;
			col = CS170::Utils::rand() % CS170::boardLength;
			result = CS170::BoardPlaceToken(*theBoard, row, col, (CS170::TileState)(CS170::tsPLAYER_ONE + (i % 2)));
		} while (result != CS170::prACCEPTED);

		// Verbose - display board after each placement.
		if (level == olVERBOSE)
			CS170::BoardDisplay(*theBoard);
		state = CS170::BoardGetState(*theBoard);
		// Switch players
		++i;
	} while (state == CS170::bsOPEN);
	// Normal output - display end board.
	if (level == olNORMAL)
		CS170::BoardDisplay(*theBoard);
	// Always print out end state
	if (level != olNONE)
	{
		if (state == CS170::bsWIN_ONE)
			std::cout << "Player 1 wins." << std::endl;
		else if (state == CS170::bsWIN_TWO)
			std::cout << "Player 2 wins." << std::endl;
		else
			std::cout << "Tie." << std::endl;
	}
	// Deallocate memory
	CS170::BoardFree(theBoard);
}
bool TestRandom()
{
	std::cout << "Testing random placement." << std::endl;
	TestRandomHelper(olVERBOSE);
	return true;
}
bool TestStress()
{
	// For performance measurements
	time_t startTime = time(nullptr);
	const int numRandomTests = 10000;
	std::cout << "Testing random placement for " << numRandomTests << " games." << std::endl;
	for (unsigned i = 0; i < numRandomTests; ++i)
		TestRandomHelper(olNONE);
	// Determine how long tests took
	time_t finishTime = time(nullptr);
	double difference = difftime(finishTime, startTime);
	std::cout << "Stress test finished in " << difference << " seconds." << std::endl;
	return true;
}
