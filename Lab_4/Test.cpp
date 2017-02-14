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
  double lastTime = 0;
  for(int i=1; i<=iterations; i++)
  {
    lastTime = openHashingTest(desiredLoadFactor, tableSize);
    totaltime += lastTime;
    std::cout<<"Trial "<<i<<": "<<lastTime<<" seconds\n";
  }
  std::cout<<"Average time after "<<iterations<<" trials: "<< totaltime / iterations <<" seconds\n";
  return totaltime / iterations;
}
double Test::averageQuadraticProbing(int iterations, double desiredLoadFactor, int tableSize)
{
  double totaltime = 0;
  double lastTime = 0;
  for(int i=1; i<=iterations; i++)
  {
    lastTime = quadraticProbingTest(desiredLoadFactor, tableSize);
    totaltime += lastTime;
    std::cout<<"Trial "<<i<<": "<<lastTime<<" seconds\n";
  }
  std::cout<<"Average time after "<<iterations<<" trials: "<< totaltime / iterations <<" seconds\n";
  return totaltime / iterations;
}
double Test::averageDoubleHashing(int iterations, double desiredLoadFactor, int tableSize)
{
  double totaltime = 0;
  double lastTime = 0;
  for(int i=1; i<=iterations; i++)
  {
    lastTime = doubleHashingTest(desiredLoadFactor, tableSize);
    totaltime += lastTime;
    std::cout<<"Trial "<<i<<": "<<lastTime<<" seconds\n";
  }
  std::cout<<"Average time after "<<iterations<<" trials: "<< totaltime / iterations <<" seconds\n";
  return totaltime / iterations;
}

void Test::runTestSuite(int numAvgs, int tableSize)
{
  double* results = new double[30];
  Timer timer;
  timer.start();

  std::cout<<"OPEN HASHING:\n";
  for(int i=1; i<10; i++)
  {
    std::cout<<"Test with load factor = "<<0.1*i<<"\n";
    results[i-1]=averageOpenHashing(numAvgs, 0.1 * i, tableSize);
    std::cout<<"\n";
  }

  std::cout<<"QUADRATIC PROBING:\n";
  for(int i=1; i<10; i++)
  {
    std::cout<<"Test with load factor = "<<0.1*i<<"\n";
    results[i+9]=averageQuadraticProbing(numAvgs, 0.1 * i, tableSize);
    std::cout<<"\n";
  }

  std::cout<<"DOUBLE HASHING:\n";
  for(int i=1; i<10; i++)
  {
    std::cout<<"Test with load factor = "<<0.1*i<<"\n";
    results[i+19]=averageDoubleHashing(numAvgs, 0.1 * i, tableSize);
    std::cout<<"\n";
  }

  std::cout<<"FINAL RESULTS:\n";
  std::cout<<"Open Hashing:\n";
  double start = 0.1;
  for(int i=0; i<9; i++)
  {
    std::cout<<"Load Factor: "<<start<<" Average Time: "<<results[i]<<"\n";
    start+=0.1;
  }
  std::cout<<"\nQuadratic Probing:\n";
  start = 0.1;
  for(int i=10; i<19; i++)
  {
    std::cout<<"Load Factor: "<<start<<" Average Time: "<<results[i]<<"\n";
    start+=0.1;
  }
  std::cout<<"\nDouble Hashing:\n";
  start = 0.1;
  for(int i=20; i<29; i++)
  {
    std::cout<<"Load Factor: "<<start<<" Average Time: "<<results[i]<<"\n";
    start+=0.1;
  }
  start = timer.stop();
  std::cout<<"\nTotal Time Elapsed: "<<start
           <<"\nNumber of trials taken per average: "<<numAvgs
           <<"\nSize of hash table during tests: "<<tableSize<<"\n\n";

}
