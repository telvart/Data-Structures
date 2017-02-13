
#ifndef TEST_H
#define TEST_H

#include <time.h>

#include "OpenHashTable.h"
#include "ClosedHashTable.h"
#include "Timer.h"

class Test
{
public:

  double averageOpenHashing(double desiredLoadFactor, int tableSize);
  double averageQuadraticProbing(double desiredLoadFactor, int tableSize);
  double averageDoubleHashing(double desiredLoadFactor, int tableSize);

  double openHashingTest(double desiredLoadFactor, int tableSize);
  double quadraticProbingTest(double desiredLoadFactor, int tableSize);
  double doubleHashingTest(double desiredLoadFactor, int tableSize);
};
#endif
