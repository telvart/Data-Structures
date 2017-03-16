#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "SkewHeap.h"
#include "LeftistHeap.h"
#include "Timer.h"
class Test
{
public:
  double** buildTest();
  double** operationsTest();
  void runTests();
};

#endif
