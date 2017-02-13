

#include <iostream>



#include "OpenHashTable.h"
#include "ClosedHashTable.h"
#include "Timer.h"
#include "Test.h"





int main(int argc, char** argv)
{
  Test tester;
  Timer timer;
  timer.printTime(tester.openHashingTest(0.9, 600011));
  std::cout<<"\n";
  timer.printTime(tester.quadraticProbingTest(0.9, 600011));
  std::cout<<"\n";
  timer.printTime(tester.doubleHashingTest(0.9, 600011));

  //Timer timer;
  // OpenHashTable openTable = OpenHashTable(600011);
  // ClosedHashTable quadTable = ClosedHashTable(600011);
  // ClosedHashTable doubleTable = ClosedHashTable(600011);
  // doubleTable.setDoubleHashing();


  // timer.start();
  // usleep(1000000);
  // double dur = timer.stop();
  //timer.printTime(dur);
}
