/* 
 * Blake North (PowerUser64)
 * Board.cpp
 * 9-11-19
 */
#include <stddef.h>
#include "board.h"

#define board_h 3
#define board_w 3

namespace CS170
{
struct Board
{
    int **data; // The 2D game board represented as an array.
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
    board->data = new int *[board_h];
    int j = 0;
    for (size_t i = 0; i < board_h; i++)
    {
        board->data[i] = new int[board_w];
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
    for (int i = 0; i < board_h;)
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
}
// Reset the board to an empty state.
// Params:
//   theBoard = A reference to the game board.
void BoardReset(Board &board)
{
}
// Get the current state of the board. (Is the game over?)
// Params:
//   theBoard = A reference to the game board.
// Returns:
//   The current state of the game - win, tie, or open (still going).
BoardState BoardGetState(const Board &board)
{
}
} // namespace CS170