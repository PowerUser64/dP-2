#include <iostream> // cout, endl
#include <iomanip>  // setw

#include "WarBoats.h"
#include "PRNG.h"

void PrintShotResult(const CS175::WarBoats::ShotResult &sr)
{
  const char *strings[] = {"HIT", "MISS", "DUPLICATE", "SUNK", "ILLEGAL"};
  std::cout << strings[static_cast<int>(sr)] << std::endl;
  //if (sr == CS175::WarBoats::srSUNK)
  //  std::cout << "*************************************************\n";
}

void PrintStats(const CS175::WarBoats::ShotStats &stats)
{
  std::cout << "      Hits: " << std::setw(3) << stats.hits << std::endl;
  std::cout << "    Misses: " << std::setw(3) << stats.misses << std::endl;
  std::cout << "Duplicates: " << std::setw(3) << stats.duplicates << std::endl;
  std::cout << "Boats Sunk: " << std::setw(3) << stats.sunk << std::endl;
}

void TakeAShot(CS175::WarBoats::Ocean &ocean, const CS175::WarBoats::Point& pt)
{
  CS175::WarBoats::ShotResult sr;
  std::cout << "Shot: " << pt.x << ", " << pt.y << "  ";
  sr = CS175::WarBoats::TakeShot(ocean, pt);
  PrintShotResult(sr);
  PrintStats(GetShotStats(ocean));
  CS175::WarBoats::DumpOcean(ocean);
  std::cout << std::endl;
}

void test_rect(int num_boats, int xsize, int ysize, 
               bool show_sunk = true, bool show_all = false)
{
    // Initialize the pseudo-random number generator
  CS175::Utils::srand(0, 0);

  CS175::WarBoats::Ocean *theOcean;
  theOcean = CS175::WarBoats::CreateOcean(num_boats, xsize, ysize);
  CS175::WarBoats::Ocean &ocean = *theOcean;

    // Place the boats randomly in the ocean
  int boats_placed = 0;
  while (boats_placed < num_boats)
  {
    CS175::WarBoats::Boat boat;

    //boat.hits = 0;
    boat.ID = boats_placed + 1;
    CS175::WarBoats::BoatPlacement bp;
    do
    {
        // Pick a random orientation
      boat.orientation = CS175::Utils::Random(0, 1)
                                 ? CS175::WarBoats::oHORIZONTAL
                                 : CS175::WarBoats::oVERTICAL;

        // Pick a random location
      CS175::WarBoats::Point location;
      location.x = CS175::Utils::Random(0, xsize - 1);
      location.y = CS175::Utils::Random(0, ysize - 1);
      boat.position = location;

        // Place the boat
      bp = CS175::WarBoats::PlaceBoat(ocean, boat);

    }while (bp == CS175::WarBoats::bpREJECTED);

    //CS175::WarBoats::DumpOcean(ocean);
    //std::cout << std::endl;
    boats_placed++;
  }
  std::cout << "Boats placed:\n";
  CS175::WarBoats::DumpOcean(ocean);
  std::cout << std::endl;

    // Try to sink the boats with random shots
  while (num_boats > 0)
  {
    CS175::WarBoats::ShotResult sr;
    do
    {
      CS175::WarBoats::Point coordinate;
      coordinate.x = CS175::Utils::Random(0, xsize - 1);
      coordinate.y = CS175::Utils::Random(0, ysize - 1);
      //std::cout << "target: " << coordinate.x << ", " 
      //          << coordinate.y << std::endl;

      sr = CS175::WarBoats::TakeShot(ocean, coordinate);
    } while (sr == CS175::WarBoats::srDUPLICATE);

      // Sunk a boat
    if (sr == CS175::WarBoats::srSUNK)
      num_boats--;

    if (show_all)
    {
      PrintShotResult(sr);
      PrintStats(GetShotStats(ocean));
      CS175::WarBoats::DumpOcean(ocean, 4, false);
      std::cout << std::endl;
    }
    else if ( (sr == CS175::WarBoats::srSUNK) && show_sunk)
    {
      PrintShotResult(sr);
      PrintStats(GetShotStats(ocean));
      CS175::WarBoats::DumpOcean(ocean, 4, false);
      std::cout << std::endl;
    }
  }
  std::cout << "Final board:\n";
  PrintStats(GetShotStats(ocean));
  CS175::WarBoats::DumpOcean(ocean, 4, false);
  std::cout << std::endl;
  CS175::WarBoats::DestroyOcean(theOcean);
}

int main(void)
{
  // usage: test_rect(boats, xsize, ysize, show_sunk, show_all)

  test_rect(5, 10, 10, false, false);
  //test_rect(5, 10, 10, true, false);
  //test_rect(5, 10, 10, true, true);

  //test_rect(5, 8, 12, false, false);
  //test_rect(5, 8, 12, true, false);
  //test_rect(5, 8, 12, true, true);
  
  //test_rect(99, 30, 30, false, false);
  //test_rect(99, 30, 30, true, false);
  //test_rect(99, 30, 30, true, true);
  
  return 0;
}
