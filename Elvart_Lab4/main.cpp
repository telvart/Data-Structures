

#include <iostream>



#include "OpenHashTable.h"
#include "ClosedHashTable.h"
#include "Timer.h"
#include "Test.h"





int main(int argc, char** argv)
{
  Test tester;
  //tester.averageTest(5, 0.9, 600011);
  tester.runTestSuite(5, 600011);
//  std::cout<<"Exiting...\n";
  return 0;

}
