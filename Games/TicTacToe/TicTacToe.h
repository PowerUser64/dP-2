//------------------------------------------------------------------------------
//
// File Name:	TicTacToe.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 1 - Tic Tac Toe
// Course:		CS170
//
// Copyright © 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#ifndef TICTACTOE_H
#define TICTACTOE_H

namespace CS170
{
	//------------------------------------------------------------------------------
	// Public Consts:
	//------------------------------------------------------------------------------

	const unsigned boardLength = 3;

	enum PlaceResult
	{
		prACCEPTED,
		prREJECTED_OUTOFBOUNDS,
		prREJECTED_OCCUPIED
	};

	enum TileState
	{
		tsEMPTY,
		tsPLAYER_ONE,
		tsPLAYER_TWO
	};

	enum BoardState
	{
		bsOPEN, // Board has at least one empty slot.
		bsWIN_ONE, // Player one has won.
		bsWIN_TWO, // Player two has won.
		bsTIE // Board is full and neither player has won.
	};
}

#endif
