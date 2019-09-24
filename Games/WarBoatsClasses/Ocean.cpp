#include "WarBoats.h"
#include "Ocean.h"

namespace CS175
{
namespace WarBoats
{
// My functions :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/* Constructor - The client calls this to create an ocean(game board)
 * Client specifies the dimensions of the ocean and the number of boats that will be placed in it
 * All private fields are initialized
 * No return value
 */
Ocean::Ocean(int num_boats_, int x_quadrants_, int y_quadrants_)
{
    grid = new int[x_quadrants * y_quadrants];
    hits = new int[num_boats_];
    num_boats = num_boats_;
    x_quadrants = x_quadrants_;
    y_quadrants = y_quadrants_;
    stats.hits = 0;
    stats.duplicates = 0;
    stats.misses = 0;
    stats.sunk = 0;
}

/* Destructor-This method is responsible for deallocating anything that was allocated in the constructor
 * No return value
 */
Ocean::~Ocean(void)
{
    delete[] hits;
    delete[] grid;
    return;
}

/* The client calls this to place boats in the ocean
 * The client will create a boat and pass it to the method
 * The method must ensure that the boat will "fit" in the ocean
 * Do this by checking the location where it is to be placed, the orientation (horizontal/vertical),
 * and whether or not it will overlap with another boat or stick outside of the ocean
 * The return value indicates whether or not the boat could be placed in the ocean
 */
BoatPlacement Ocean::PlaceBoat(const Boat &boat_)
{
    // Bounds check
    if (boat_.orientation == oHORIZONTAL)
    {
        if ( // check first end
            // left edge
            boat_.position.x >= 0 && boat_.position.y >= 0 &&
            // right edge
            boat_.position.x < x_quadrants && boat_.position.y < y_quadrants &&
            // check second end
            boat_.position.x + BOAT_LENGTH - 1 < x_quadrants)
        {
            // Check for things beneath it
            for (int i = 0; i < BOAT_LENGTH; ++i)
            {
                if (grid[boat_.position.x + x_quadrants * (boat_.position.y + i)] != 0)
                    // couldn't be placed
                    return bpREJECTED;
            }
            // set the boat's spaces to the boat's id's
            for (int i = 0; i < BOAT_LENGTH; ++i)
            {
                grid[boat_.position.x + x_quadrants * (boat_.position.y + i)] = boat_.ID;
            }
            // could be placed
            return bpACCEPTED;
        }
    }

    // check for vertical oreintation
    else if (boat_.orientation == oVERTICAL)
    {
        if ( // check first end
            // left edge
            boat_.position.x >= 0 && boat_.position.y >= 0 &&
            // right edge
            boat_.position.x < x_quadrants && boat_.position.y < y_quadrants &&
            // check second end
            boat_.position.y + BOAT_LENGTH - 1 < y_quadrants)
        {
            // Check for things beneath it
            for (int i = 0; i < BOAT_LENGTH; ++i)
            {
                if (grid[boat_.position.x + x_quadrants * (boat_.position.y + i)] != 0)
                    // couldn't be placed
                    return bpREJECTED;
            }
            for (int i = 0; i < BOAT_LENGTH; ++i)
                // set the boat's spaces to the boat's id's
                grid[boat_.position.x + x_quadrants * (boat_.position.y + i)] = boat_.ID;
            // could be placed
            return bpACCEPTED;
        }
    }
    return bpREJECTED;
}

/* Client calls this in an attempt to hit one of the boats
 * The coordinate parameter indicates where the client is attempting to strike
 * 
 * There are several possible results : Hit, Miss, Sunk, Duplicate, or Illegal
 * Hit, Miss, and Duplicate are obvious
 * Sunk is returned when a shot hits the last undamaged part of a boat
 * Sunk implies Hit
 * Illegal is any coordinate that is outside of the ocean(e.g. x / y less than 0 or outside the range)
 */
ShotResult Ocean::TakeShot(const Point &coordinate_)
{
    // check if it's in bounds
    if (coordinate_.x > x_quadrants || coordinate_.x < 0)
        return srILLEGAL;
    if (coordinate_.y > y_quadrants || coordinate_.y < 0)
        return srILLEGAL;

    // debug
    int &dataAtLocation = grid[coordinate_.x + x_quadrants * coordinate_.y];

    // is it on the water or on a boat or another hit
    // miss?
    if (dataAtLocation == 0)
    {
        --dataAtLocation;
        ++stats.misses;
        // duplicate?
        return srMISS;
    }
    else if (dataAtLocation < 0 || dataAtLocation > 100)
    {
        ++stats.duplicates;
        return srDUPLICATE;
    }
    // hit?
    else if (dataAtLocation > 0 && dataAtLocation < 100)
    {
        ++stats.hits;
        ++hits[dataAtLocation];
        grid[dataAtLocation - 1] += 1;
        if (hits[dataAtLocation - 1] == BOAT_LENGTH)
        {
            dataAtLocation += 100;
            ++stats.sunk;
            return srSUNK;
        }
        dataAtLocation += 100;
        return srHIT;
    }
    return srILLEGAL;
}

/* Returns data about the board that has bneen collected over time
 */
const ShotStats &Ocean::GetShotStats(void) const
{
    return stats;
}

// End my functions :::::::::::::::::::::::::::::::::::::::::::::::::::::::::

const int *Ocean::GetGrid(void) const
{
    return grid;
}

Point Ocean::GetDimensions(void) const
{
    Point pt = {x_quadrants, y_quadrants};
    return pt;
}

} // namespace WarBoats

} // namespace CS175
