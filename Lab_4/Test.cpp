#include "Test.h"

double Test::openHashingTest(double desiredLoadFactor, int tableSize)
{
  double entriesToInsert = desiredLoadFactor * tableSize;
  OpenHashTable table = OpenHashTable(tableSize);
  Timer timer;
  srand(time(NULL));
  timer.start();
  for(int i=0; i<entriesToInsert; i++)
  {
    table.insert(rand() % 2147483647 + 1);
  }
  return timer.stop();

}

double Test::quadraticProbingTest(double desiredLoadFactor, int tableSize)
{
  double entriesToInsert = desiredLoadFactor * tableSize;
  ClosedHashTable table = ClosedHashTable(tableSize);
  Timer timer;
  srand(time(NULL));
  timer.start();
  for(int i=0; i< entriesToInsert; i++)
  {
    table.insert(rand() % 2147483647 + 1);
  }
  return timer.stop();
}

double Test::doubleHashingTest(double desiredLoadFactor, int tableSize)
{
  double entriesToInsert = desiredLoadFactor * tableSize;
  ClosedHashTable table = ClosedHashTable(tableSize);
  Timer timer;
  srand(time(NULL));
  timer.start();
  for(int i=0; i< entriesToInsert; i++)
  {
    table.insert(rand() % 2147483647 + 1);;
  }
  return timer.stop();
}
