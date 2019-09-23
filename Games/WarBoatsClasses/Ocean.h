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
        
          /*
           * Other public methods
          */
        
           // Provided
        const int *GetGrid(void) const;
        Point GetDimensions(void) const;

      private:
        int *grid;        // The 2D ocean
        int x_quadrants;  // Ocean size along x-axis
        int y_quadrants;  // Ocean size along y-axis
        
        /*
         * Other private data
        */
        
    }; // class Ocean

  } // namespace WarBoats

} // namespace CS175
