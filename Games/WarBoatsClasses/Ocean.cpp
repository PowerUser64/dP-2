#include "WarBoats.h"
#include "Ocean.h"

namespace CS175
{
    namespace WarBoats
    {  
        /*
        * ALL STUDENT IMPLEMENTATION GOES HERE
        */

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

