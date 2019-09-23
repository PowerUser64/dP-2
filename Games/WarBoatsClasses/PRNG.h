#pragma once

namespace CS175
{
  namespace Utils
  {
    unsigned rand(void);              // returns a random 32-bit integer
    void srand(unsigned, unsigned);   // seed the generator
    int Random(int low, int high);    // range
  }
}
