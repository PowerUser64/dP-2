#include <iostream> // cout, endl
#include <iomanip>  // setw

#include "WarBoats.h"
#include "PRNG.h"

void PrintShotResult(const CS175::WarBoats::ShotResult &sr)
{
    const char *strings[] = { "HIT", "MISS", "DUPLICATE", "SUNK", "ILLEGAL" };
    std::cout << strings[static_cast<int>(sr)] << std::endl;
}

void PrintStats(const CS175::WarBoats::ShotStats &stats)
{
    std::cout << "      Hits: " << std::setw(3) << stats.hits;
    std::cout << std::endl;
    std::cout << "    Misses: " << std::setw(3) << stats.misses;
    std::cout << std::endl;
    std::cout << "Duplicates: " << std::setw(3) << stats.duplicates;
    std::cout << std::endl;
    std::cout << "Boats Sunk: " << std::setw(3) << stats.sunk;
    std::cout << std::endl;
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

void test0(void)
{
    // Initialize the pseudo-random number generator
    CS175::Utils::srand(0, 0);

    // Setup the ocean
    int num_boats = 3;
    int xsize = 8;
    int ysize = 8;
    CS175::WarBoats::Ocean *theOcean;
    theOcean = CS175::WarBoats::CreateOcean(num_boats, xsize, ysize);
    CS175::WarBoats::Ocean &ocean = *theOcean;

    std::cout << "The empty board" << std::endl;
    CS175::WarBoats::DumpOcean(ocean);
    std::cout << std::endl;

    CS175::WarBoats::Boat boat;
    CS175::WarBoats::Point location;
    CS175::WarBoats::BoatPlacement bp;

    // Boat #1
    boat.ID = 1;
    location.x = 1;
    location.y = 3;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    bp = CS175::WarBoats::PlaceBoat(ocean, boat);
    if (bp == CS175::WarBoats::bpREJECTED)
        std::cout << "Boat placement is rejected." << std::endl;
    else
        std::cout << "Boat placement is accepted." << std::endl;

    // Boat #2
    boat.ID = 2;
    location.x = 5;
    location.y = 1;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oVERTICAL;
    bp = CS175::WarBoats::PlaceBoat(ocean, boat);
    if (bp == CS175::WarBoats::bpREJECTED)
        std::cout << "Boat placement is rejected." << std::endl;
    else
        std::cout << "Boat placement is accepted." << std::endl;

    // Boat #3
    boat.ID = 3;
    location.x = 0;
    location.y = 5;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    bp = CS175::WarBoats::PlaceBoat(ocean, boat);
    if (bp == CS175::WarBoats::bpREJECTED)
        std::cout << "Boat placement is rejected." << std::endl;
    else
        std::cout << "Boat placement is accepted." << std::endl;

    // Illegal placement
    boat.ID = 4;
    location.x = 10;
    location.y = 5;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    bp = CS175::WarBoats::PlaceBoat(ocean, boat);
    if (bp == CS175::WarBoats::bpREJECTED)
        std::cout << "Boat placement is rejected." << std::endl;
    else
        std::cout << "Boat placement is accepted." << std::endl;

    // Illegal placement
    boat.ID = 4;
    location.x = 2;
    location.y = 0;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oVERTICAL;
    bp = CS175::WarBoats::PlaceBoat(ocean, boat);
    if (bp == CS175::WarBoats::bpREJECTED)
        std::cout << "Boat placement is rejected." << std::endl;
    else
        std::cout << "Boat placement is accepted." << std::endl;

    // Illegal placement
    boat.ID = 4;
    location.x = 5;
    location.y = 6;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    bp = CS175::WarBoats::PlaceBoat(ocean, boat);
    if (bp == CS175::WarBoats::bpREJECTED)
        std::cout << "Boat placement is rejected." << std::endl;
    else
        std::cout << "Boat placement is accepted." << std::endl;

    std::cout << "The board with " << num_boats << " boats" << std::endl;
    CS175::WarBoats::DumpOcean(ocean, 4, true);
    std::cout << std::endl;
    CS175::WarBoats::DestroyOcean(theOcean);
}

void test1(void)
{
    // Initialize the pseudo-random number generator
    CS175::Utils::srand(0, 0);

    // Setup the ocean
    int num_boats = 3;
    int xsize = 8;
    int ysize = 8;
    CS175::WarBoats::Ocean *theOcean;
    theOcean = CS175::WarBoats::CreateOcean(num_boats, xsize, ysize);
    CS175::WarBoats::Ocean &ocean = *theOcean;

    std::cout << "The empty board" << std::endl;
    CS175::WarBoats::DumpOcean(ocean);
    std::cout << std::endl;

    CS175::WarBoats::Boat boat;
    CS175::WarBoats::Point location;

    // Boat #1
    boat.ID = 1;
    location.x = 1;
    location.y = 3;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    // Boat #2
    boat.ID = 2;
    location.x = 5;
    location.y = 1;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oVERTICAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    // Boat #3
    boat.ID = 3;
    location.x = 0;
    location.y = 5;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    std::cout << "The board with " << num_boats << " boats" << std::endl;
    CS175::WarBoats::DumpOcean(ocean);
    std::cout << std::endl;

    CS175::WarBoats::Point coordinate;

    // Illegal coordinate
    coordinate.x = 10;
    coordinate.y = 5;
    TakeAShot(ocean, coordinate);

    // HIT
    coordinate.x = 1;
    coordinate.y = 3;
    TakeAShot(ocean, coordinate);

    // MISS
    coordinate.x = 5;
    coordinate.y = 7;
    TakeAShot(ocean, coordinate);

    // DUPLICATE
    coordinate.x = 1;
    coordinate.y = 3;
    TakeAShot(ocean, coordinate);

    // HIT
    coordinate.x = 2;
    coordinate.y = 3;
    TakeAShot(ocean, coordinate);

    // HIT
    coordinate.x = 3;
    coordinate.y = 3;
    TakeAShot(ocean, coordinate);

    // SUNK
    coordinate.x = 4;
    coordinate.y = 3;
    TakeAShot(ocean, coordinate);
    CS175::WarBoats::DestroyOcean(theOcean);
}

void test2(void)
{
    // Initialize the pseudo-random number generator
    CS175::Utils::srand(0, 0);

    // Setup the ocean (check 100, 30x30)
    int num_boats = 5;
    int xsize = 10;
    int ysize = 10;
    CS175::WarBoats::Ocean *theOcean;
    theOcean = CS175::WarBoats::CreateOcean(num_boats, xsize, ysize);
    CS175::WarBoats::Ocean &ocean = *theOcean;

    std::cout << "The empty board" << std::endl;
    CS175::WarBoats::DumpOcean(ocean);
    std::cout << std::endl;

    CS175::WarBoats::Boat boat;
    CS175::WarBoats::Point location;

    // Boat #1
    boat.ID = 1;
    location.x = 1;
    location.y = 3;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    // Boat #2
    boat.ID = 2;
    location.x = 5;
    location.y = 1;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oVERTICAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    // Boat #3
    boat.ID = 3;
    location.x = 0;
    location.y = 5;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    // Boat #4
    boat.ID = 4;
    location.x = 3;
    location.y = 8;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oHORIZONTAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    // Boat #5
    boat.ID = 5;
    location.x = 9;
    location.y = 6;
    boat.position = location;
    boat.orientation = CS175::WarBoats::oVERTICAL;
    CS175::WarBoats::PlaceBoat(ocean, boat);

    std::cout << "The board with " << num_boats << " boats" << std::endl;
    CS175::WarBoats::DumpOcean(ocean);
    std::cout << std::endl;

    // Try to sink the boats with random shots
    int shots = 0;
    while (num_boats > 0)
    {
        CS175::WarBoats::ShotResult sr;
        do
        {
            CS175::WarBoats::Point coordinate;
            coordinate.x = CS175::Utils::Random(0, xsize - 1);
            coordinate.y = CS175::Utils::Random(0, ysize - 1);
            std::cout << "Shot #"
                << ++shots
                << " at coordinate "
                << coordinate.x
                << ", "
                << coordinate.y
                << "  ";

            sr = CS175::WarBoats::TakeShot(ocean, coordinate);
            PrintShotResult(sr);
        } while (sr == CS175::WarBoats::srDUPLICATE);

        // Sunk a boat
        if (sr == CS175::WarBoats::srSUNK)
            num_boats--;

        //if (sr == CS175::WarBoats::srSUNK)
        {
            //PrintShotResult(sr);
            PrintStats(GetShotStats(ocean));
            CS175::WarBoats::DumpOcean(ocean);
            std::cout << std::endl;
        }
    }
    CS175::WarBoats::DestroyOcean(theOcean);
}

int main(void)
{
    // test0();
    test1();
    //test2();

    return 0;
}
