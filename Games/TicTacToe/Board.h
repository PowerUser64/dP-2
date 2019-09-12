//------------------------------------------------------------------------------
//
// File Name:	Board.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 1 - Tic Tac Toe
// Course:		CS170
//
// Copyright � 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#ifndef BOARD_H
#define BOARD_H

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
#include "TicTacToe.h"

namespace CS170
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	typedef struct Board Board;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// This is an example of the structure for the Tic Tac Toe board to be defined
	// in the Board.cpp file. You are free to modify this if you so choose, so long
	// as it still contains a dynamically allocated array.
#if 0
	struct Board
	{
		int *data; // The 2D game board represented as an array.
	};
#endif

	//------------------------------------------------------------------------------
	// Public Functions Declarations:
	//------------------------------------------------------------------------------

	// Allocate memory for a tic-tac-toe board.
	// Returns:
	//   A pointer to the created board struct.
	Board *BoardCreate();

	// Free memory for the tic-tac-toe board.
	// Params:
	//   theBoard = A reference to the pointer to the board.
	void BoardFree(Board*& theBoard);

	// Display the contents of the board using the standard output stream.
	// Params:
	//   theBoard = A reference to the game board.
	void BoardDisplay(const Board& board);

	// Place a token on the board at a specific position.
	// Params:
	//   theBoard = A reference to the game board.
	//   row = The row of the board on which to place the token.
	//   column = The column of the board on which to place the token.
	//   value = The value to place in the specified tile.
    // Returns:
	//   Whether the token was able to be placed.
	PlaceResult BoardPlaceToken(Board& board, unsigned row, unsigned column, TileState value);

	// Reset the board to an empty state.
	// Params:
	//   theBoard = A reference to the game board.
	void BoardReset(Board& board);

	// Get the current state of the board. (Is the game over?)
	// Params:
	//   theBoard = A reference to the game board.
	// Returns:
	//   The current state of the game - win, tie, or open (still going).
	BoardState BoardGetState(const Board& board);

}

#endif /* BOARD_H */
