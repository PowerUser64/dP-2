#include "WarBoats.h"
#include "Ocean.h"
#include <iostream> // cout, endl
#include <iomanip>  // setw

namespace CS175
{
namespace WarBoats
{

const int BOAT_LENGTH = 4;  // Length of a boat
const int HIT_OFFSET = 100; // Add this to the boat ID

/*
        * ALL STUDENT IMPLEMENTATION GOES HERE
        */

// Builds an ocean based on a specified number of boats, width and height
Ocean *CreateOcean(int num_boats, int x_quadrants, int y_quadrants)
{
    Ocean *ocean = new Ocean;
    ocean->grid = new int *[y_quadrants];
    int j = 0;
    for (size_t i = 0; i < y_quadrants; i++)
    {
        ocean->grid[i] = new int[x_quadrants];
        for (j = 0; j < x_quadrants; ocean->grid[i][j++] = 0)
            ;
    }
    return ocean;
}

// deallocates the ocean array
void DestroyOcean(Ocean *theOcean)
{
    for (int i = 0; i < theOcean->y_quadrants; ++i)
    {
        delete[] theOcean->grid[i];
    }
    delete[] theOcean->grid;
    delete theOcean;
}

// takes shots and applies damage to the ocean
ShotResult TakeShot(Ocean &ocean, const Point &coordinate)
{
    // check if it's in bounds
    if (coordinate.x > ocean.x_quadrants || coordinate.x < 0)
        return srILLEGAL;
    if (coordinate.y > ocean.y_quadrants || coordinate.y < 0)
        return srILLEGAL;
    // check if it's on the water or on a boat
    if (ocean.grid[coordinate.x][coordinate.y] == 0)
    {
        ocean.grid[coordinate.x][coordinate.y]--;
        ocean.stats.misses++;
    }
    else if (ocean.grid[coordinate.x][coordinate.y] > 0)
    {
        ocean.grid[coordinate.x][coordinate.y] += 100;
        ocean.stats.hits++;
    }
}

// asks the user where to put boats
BoatPlacement PlaceBoat(Ocean &ocean, const Boat &boat)
{
    // check for verticle oreintation
        if (boat.orientation == oHORIZONTAL);
}

// says wether someone has won
ShotStats GetShotStats(const Ocean &ocean)
{
    return;
}

/*********************************************************************/
/*!
        \brief
        Prints the grid (ocean) to the screen.

        \param ocean
        The Ocean to print

        \param field_width
        How much space each position takes when printed.

        \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.

        \param showboats
        If true, the boats are shown in the output. (Debugging feature)
        */
/*********************************************************************/
void DumpOcean(const CS175::WarBoats::Ocean &ocean,
               int field_width,
               bool extraline,
               bool showboats)
{
    // For each row
    for (int y = 0; y < ocean.y_quadrants; y++)
    {
        // For each column
        for (int x = 0; x < ocean.x_quadrants; x++)
        {
            int value = ocean.grid[y * ocean.x_quadrants + x];

            // Is it a boat?
            if ((value > 0) && (value < HIT_OFFSET) &&
                (showboats == false))
            {
                value = 0;
            }

            std::cout << std::setw(field_width) << value;
        }
        std::cout << std::endl;
        if (extraline)
        {
            std::cout << std::endl;
        }
    }
}

} // namespace WarBoats
} // namespace CS175
