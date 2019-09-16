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
