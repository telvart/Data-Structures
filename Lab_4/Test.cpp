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

double Test::averageOpenHashing(int iterations, double desiredLoadFactor, int tableSize)
{
  double totaltime = 0;
  for(int i=0; i<iterations; i++)
  {
    totaltime += openHashingTest(desiredLoadFactor, tableSize);
  }
  return totaltime / iterations;
}
double Test::averageQuadraticProbing(int iterations, double desiredLoadFactor, int tableSize)
{
  double totaltime = 0;
  for(int i=0; i<iterations; i++)
  {
    totaltime += quadraticProbingTest(desiredLoadFactor, tableSize);
  }
  return totaltime / iterations;
}
double Test::averageDoubleHashing(int iterations, double desiredLoadFactor, int tableSize)
{
  double totaltime = 0;
  for(int i=0; i<iterations; i++)
  {
    totaltime += doubleHashingTest(desiredLoadFactor, tableSize);
  }
  return totaltime / iterations;
}
