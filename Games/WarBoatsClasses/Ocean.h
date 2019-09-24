#pragma once

#include "WarBoats.h"

namespace CS175
{
namespace WarBoats
{
const int BOAT_LENGTH = 4;  // Length of a boat
const int HIT_OFFSET = 100; // Add this to the boat ID

class Ocean
{
public:
  // My functions :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  /* Constructor - The client calls this to create an ocean(game board)
   * Client specifies the dimensions of the ocean and the number of boats that will be placed in it
   * All private fields are initialized
   * No return value
   */
  Ocean(int num_boats_, int x_quadrants_, int y_quadrants_);

  /* Destructor-This method is responsible for deallocating anything that was allocated in the constructor
   * No return value
   */
  ~Ocean(void);

  /* The client calls this to place boats in the ocean
   * The client will create a boat and pass it to the method
   * The method must ensure that the boat will "fit" in the ocean
   * Do this by checking the location where it is to be placed, the orientation (horizontal/vertical),
   * and whether or not it will overlap with another boat or stick outside of the ocean
   * The return value indicates whether or not the boat could be placed in the ocean
   */
  BoatPlacement PlaceBoat(const Boat &boat_);

  /* Client calls this in an attempt to hit one of the boats
   * The coordinate parameter indicates where the client is attempting to strike
   * 
   * There are several possible results : Hit, Miss, Sunk, Duplicate, or Illegal
   * Hit, Miss, and Duplicate are obvious
   * Sunk is returned when a shot hits the last undamaged part of a boat
   * Sunk implies Hit
   * Illegal is any coordinate that is outside of the ocean(e.g. x / y less than 0 or outside the range)
   */
  ShotResult TakeShot(const Point &coordinate_);
  
  /* Returns data about the board that has bneen collected over time
   */
  const ShotStats &GetShotStats() const;

  // End my functions :::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  // Provided
  const int *GetGrid(void) const;
  Point GetDimensions(void) const;

private:
  int *grid; // The 2D ocean
  int *hits; // The hits that the boats have
  int x_quadrants; // Ocean size along x-axis
  int y_quadrants; // Ocean size along y-axis
  int num_boats; // The number of boats in the ocean
  ShotStats stats;

  /* Other private data
   */

}; // class Ocean

} // namespace WarBoats

} // namespace CS175
