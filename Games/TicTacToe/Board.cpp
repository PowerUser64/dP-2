/* 
 * Blake North (PowerUser64)
 * Board.cpp
 * 9-11-19
 */
#include <stddef.h>
#include "board.h"
#include <iostream>

#define board_h 3
#define board_w 3
// printed board height
#define lines 7
// printed board width (treating " | " as one character)
#define parts 7

namespace CS170
{
struct Board
{
    TileState **data; // The 2D game board represented as an array.
};

//------------------------------------------------------------------------------
// My functions
//------------------------------------------------------------------------------

// Allocate memory for a tic-tac-toe board.
// Returns:
//   A pointer to the created board struct.
Board *BoardCreate()
{
    Board *board = new Board;
    board->data = new TileState *[board_h];
    int j = 0;
    for (size_t i = 0; i < board_h; i++)
    {
        board->data[i] = new TileState[board_w];
        for (j = 0; j < board_w; board->data[i][j++])
            ;
    }
    return board;
}
// Free memory for the tic-tac-toe board.
// Params:
//   theBoard = A reference to the pointer to the board.
void BoardFree(Board *&theBoard)
{
    for (int i = 0; i < board_h; ++i)
    {
        delete[] theBoard->data[i];
    }
    delete[] theBoard->data;
    delete theBoard;
}
// Display the contents of the board using the standard output stream.
// Params:
//   theBoard = A reference to the game board.
void BoardDisplay(const Board &board)
{
    // Print loop --------------------
    std::cout << " -------------\n";
    for (int i = 0, j; i < lines; ++i)
    {
        // lines with player moves
        for (j = 0; j < parts; ++j)
        {
            std::cout << " | ";
            if (board.data[i][j] == tsEMPTY)
                std::cout << " ";
            else if (board.data[i][j] == tsPLAYER_ONE)
                std::cout << "X";
            else
                std::cout << "O";
        }
        std::cout << "\n-------------\n";
    }

    /* 
         * Sample output:
         * -------------
         * | X | O | X |
         * -------------
         * | O | X | O |
         * -------------
         * | X | O | X |
         * -------------
         */
}

// Place a token on the board at a specific position.
// Params:
//   theBoard = A reference to the game board.
//   row = The row of the board on which to place the token.
//   column = The column of the board on which to place the token.
//   value = The value to place in the specified tile.
// Returns:
//   Whether the token was able to be placed.
PlaceResult BoardPlaceToken(Board &board, unsigned row, unsigned column, TileState value)
{
    board.data[row][column] = value;
    if (board.data[row][column] == value)
        return (PlaceResult)1;
    else
        return (PlaceResult)0;
}
// Reset the board to an empty state.
// Params:
//   theBoard = A reference to the game board.
void BoardReset(Board &board)
{
    for (int i = 0, j; i < board_h; i++)
        for (j = 0; j < board_w; j++)
            board.data[i][j] = tsEMPTY;
}
// Get the current state of the board. (Is the game over?)
// Params:
//   theBoard = A reference to the game board.
// Returns:
//   The current state of the game - win, tie, or open (still going).
BoardState BoardGetState(const Board &board)
{
    int i, j;

    // horizontal loop through all on one row
    for (i = 0; i < 3; i++)
        if (board.data[i][0] != tsEMPTY && board.data[i][0] == board.data[i][1] && board.data[i][1] == board.data[i][2])
        {
            if (board.data[i][0] == tsPLAYER_ONE)
                return bsWIN_ONE;
            if (board.data[i][0] == tsPLAYER_TWO)
                return bsWIN_TWO;
        }
    // verticle loop through all on one column
    for (j = 0; j < 3; j++)
        if (board.data[0][j] != -1 && board.data[0][j] == board.data[1][j] && board.data[1][j] == board.data[2][j])
        {
            if (board.data[0][j] == tsPLAYER_ONE)
                return bsWIN_ONE;
            if (board.data[0][j] == tsPLAYER_TWO)
                return bsWIN_TWO;
        }
    // diagonals check all at once

    if (board.data[0][0] != -1 && board.data[0][0] == board.data[1][1] && board.data[1][1] == board.data[2][2])
    {
        if (board.data[0][0] == tsPLAYER_ONE)
            return bsWIN_ONE;
        if (board.data[0][0] == tsPLAYER_TWO)
            return bsWIN_TWO;
    }

    // other diagonal
    if (board.data[0][2] != -1 && board.data[0][2] == board.data[1][1] && board.data[1][1] == board.data[2][0])
    {
        if (board.data[0][2] == tsPLAYER_ONE)
            return bsWIN_ONE;
        if (board.data[0][2] == tsPLAYER_TWO)
            return bsWIN_TWO;
    }

    // make sure not tie
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            /* -1 means the game isn't done */
            if (board.data[i][j] == -1)
            {
                if (board.data[i][j] == tsPLAYER_ONE)
                    return bsWIN_ONE;
                if (board.data[i][j] == tsPLAYER_TWO)
                    return bsWIN_TWO;
            }

    // it is a tie if it gets here
    return (BoardState) bsTIE;
}
} // namespace CS170