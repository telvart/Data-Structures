

#include <iostream>



#include "OpenHashTable.h"
#include "ClosedHashTable.h"
#include "Timer.h"
#include "Test.h"





int main(int argc, char** argv)
{
  Test tester;
  Timer timer;
  timer.printTime(tester.averageOpenHashing(5, 0.5, 600011));
  std::cout<<"\n";
  timer.printTime(tester.averageQuadraticProbing(5, 0.5, 600011));
  std::cout<<"\n";
  timer.printTime(tester.averageDoubleHashing(5, 0.5, 600011));

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
