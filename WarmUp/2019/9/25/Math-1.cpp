#include <iostream>
#include <cmath>

#define pi M_PIf64
#define filler "💢" // "🌠" "🐱‍🐉"

int main()
{
    std::cout

        // 2b- ✅
        << " 2b- "
        << 27.0f / 180.0f * pi
        << std::endl

        // 3d- ✅
        << " 3d- "
        << (318.0f / 180.0f) * pi
        << std::endl

        // 5c- ✅
        << " 5c- "
        << (7.0f / 36.0f) * pi
        << std::endl

        // 6e- ✅
        << " 6e- "
        << (5.0f / 3.0f) * pi
        << std::endl

        // 10a- ✅
        << "10a- "         // 1  3/2 1/2 1/2  0  1/2 1/2
        <<  sin(225.0f) - (1/sqrt(2)) // 90 120 135 150 180 210 225
        << std::endl

        // 12f- ❌
        << "12f- "
        << (tan((13.0f / 4.0f) * pi) + 1.0f)
        << std::endl

        // 14-
        << "14 ~ "
        << std::endl
            // a-
            << "  a- "
            << 0 - sqrt(1 - (cos(-0.8))
            << std::endl
            // b-
            << "  b- "
            << filler
            << std::endl
            // c-
            << "  c- "
            << filler
            << std::endl
            // d-
            << "  d- "
            << filler
            << std::endl
            // e-
            << "  e- "
            << filler
            << std::endl
            // f-
            << "  f- "
            << filler
            << std::endl
            // g-
            << "  g- "
            << atan2()
            << std::endl

        // 18f-
        << "18f- "
        << filler
        << std::endl

        // 20-
        << "20 ~ "
        << std::endl
            // a-
            << "  a- "
            << filler
            << std::endl
            // b-
            << "  b- "
            << filler
            << std::endl
            // c-
            << "  c- "
            << filler
            << std::endl
            // d-
            << "  d- "
            << filler
            << std::endl
            // e-
            << "  e- "
            << filler
            << std::endl
            // f-
            << "  f- "
            << filler
            << std::endl
            // g-
            << "  g- "
            << filler
            << std::endl

        // 33a-
        << "33a- "
        << filler
        << std::endl;
}