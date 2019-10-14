#include <iostream>
#include <cmath>
#include "linalg.h"
#include "vectmath.h"

#define pi M_PIf64
#define filler "💢" // "🌠" "🐱‍🐉"
#define pr std::cout

int main()
{
   pr
      << " 4"
      << std::endl;
   pr
      << "  a- "
      << std::endl;
   pr << "  b- "
      << 3 - -8 << ',' << 3 - 15
      << std::endl
      << std::endl;
   pr << " 8 - "
      // (-2, 3), (2, -4), [5, -4]
      << "  a- "
      << sqrt((2 - -3) + (5 - 1))
      << std::endl;
   pr << "  b- "
      << 2 - 5 << ',' << -3 - 1
      << std::endl;
   pr << "  c- "
      << (2 + 7) + (-3 + -5)
      << std::endl;
   pr << "  d- "
      << (5 + 7) + (1 + -5)
      << std::endl;
   pr << "  e- "
      << filler
      << std::endl
      << std::endl;
   pr << "12"
      << "  a- "
      << filler
      << std::endl;
   pr << "  e- "
      << filler
      << std::endl;
   pr << "16e- "
      << filler
      << std::endl;
   pr << "20 - "
      << filler
      << std::endl;
   pr << "24 - "
      << filler
      << std::endl;
   pr << "36 - "
      << filler
      << std::endl;
   pr << "40"
      << "  c- "
      << filler
      << std::endl;
   pr << "  b- "
      << filler
      << std::endl;
   pr << "53 - "
      << "  a- "
      << filler
      << std::endl;
   pr << "  c- "
      << filler
      << std::endl;
}