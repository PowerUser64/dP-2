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
    ocean->grid = new int *[x_quadrants];
    int j = 0;
    for (int i = 0; i < x_quadrants; i++)
    {
        ocean->grid[i] = new int[y_quadrants];
        for (j = 0; j < y_quadrants; ocean->grid[i][j++] = 0)
            ;
    }
    ocean->boats = new Boat[num_boats];
    ocean->num_boats = num_boats;
    ocean->x_quadrants = x_quadrants;
    ocean->y_quadrants = y_quadrants;
    return ocean;
}

// deallocates the ocean array
void DestroyOcean(Ocean *theOcean)
{
    for (int i = 0; i < theOcean->x_quadrants; ++i)
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

    // is it on the water or on a boat or another hit
    // duplicate?
    if (ocean.grid[coordinate.x][coordinate.y] < 0 && ocean.grid[coordinate.x][coordinate.y] > 100)
        return srDUPLICATE;
    // miss?
    else if (ocean.grid[coordinate.x][coordinate.y] == 0)
    {
        ocean.grid[coordinate.x][coordinate.y]--;
        ocean.stats.misses++;
        return srMISS;
    }
    // hit?
    else if (ocean.grid[coordinate.x][coordinate.y] > 0 && ocean.grid[coordinate.x][coordinate.y] < 100)
    {
        ocean.boats[ocean.grid[coordinate.x][coordinate.y] - 1].hits += 1;
        if (ocean.boats[ocean.grid[coordinate.x][coordinate.y]].hits == BOAT_LENGTH)
            return srSUNK;
        ocean.grid[coordinate.x][coordinate.y] += 100;
        ocean.stats.hits++;
        return srHIT;
    }
    return srILLEGAL;
}

// asks the user where to put boats
BoatPlacement PlaceBoat(Ocean &ocean, const Boat &boat)
{
    // Bounds check
    if (boat.orientation == oHORIZONTAL)
    {
        if ( // check first end
            // left edge
            boat.position.x >= 0 && boat.position.y >= 0 &&
            // right edge
            boat.position.x < ocean.x_quadrants && boat.position.y < ocean.y_quadrants &&
            // check second end
            boat.position.x + BOAT_LENGTH < ocean.x_quadrants)
        {
            // Check for things beneath it
            for (int i = 0; i < BOAT_LENGTH; ++i)
            {
                if (ocean.grid[boat.position.x + i][boat.position.y] != 0)
                    // couldn't be placed
                    return bpREJECTED;
            }
            // set the boat's spaces to the boat's id's
            for (int i = 0; i < BOAT_LENGTH; ++i)
            {
                ocean.grid[boat.position.x + i][boat.position.y] = boat.ID;
            }
            // could be placed
            return bpACCEPTED;
        }
    }

    // check for vertical oreintation
    else if (boat.orientation == oVERTICAL)
    {
        if ( // check first end
            // left edge
            boat.position.x >= 0 && boat.position.y >= 0 &&
            // right edge
            boat.position.x < ocean.x_quadrants && boat.position.y < ocean.y_quadrants &&
            // check second end
            boat.position.y + BOAT_LENGTH < ocean.y_quadrants)
        {
            // Check for things beneath it
            for (int i = 0; i < BOAT_LENGTH; ++i)
            {
                if (ocean.grid[boat.position.x][boat.position.y + i] != 0)
                    // couldn't be placed
                    return bpREJECTED;
            }
            for (int i = 0; i < BOAT_LENGTH; ++i)
                // set the boat's spaces to the boat's id's
                ocean.grid[boat.position.x][boat.position.y + i] = boat.ID;
            // could be placed
            return bpACCEPTED;
        }
    }
    return bpREJECTED;
}

// says wether someone has won
ShotStats GetShotStats(const Ocean &ocean)
{
    return ocean.stats;
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
            int value = ocean.grid[x][y];

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
