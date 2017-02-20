
#ifndef TEST_H
#define TEST_H

#include <time.h>

#include "OpenHashTable.h"
#include "ClosedHashTable.h"
#include "Timer.h"

class Test
{

public:
  void runTestSuite(int numAvgs, int tableSize);

  double* singleTest(double desiredLoadFactor, int tableSize);
  double* averageTest(int iterations, double desiredLoadFactor, int tableSize);

};
#endif
