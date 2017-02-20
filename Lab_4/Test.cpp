#include "Test.h"

double* Test::singleTest(double desiredLoadFactor, int tableSize)
{
  double entriesToInsert = desiredLoadFactor * tableSize;
  double* results = new double[3];
  OpenHashTable table = OpenHashTable(tableSize);
  ClosedHashTable table2 = ClosedHashTable(tableSize);
  ClosedHashTable table3 = ClosedHashTable(tableSize);
  table2.setQuadraticProbing();
  table3.setDoubleHashing();
  Timer timer;
  srand(time(NULL));
  std::cout<<"Load factor: "<<desiredLoadFactor<<"\nOpen Hashing: ";
  timer.start();
  for(int i=0; i<entriesToInsert; i++)
  {
    table.insert(rand() % 2147483647 + 1);
  }
  results[0] = timer.stop();
  std::cout<<results[0]<<"\nQuadratic Probing: ";
  timer.start();
  for(int i=0; i<entriesToInsert; i++)
  {
    table2.insert(rand() % 2147483647 + 1);
  }
  results[1] = timer.stop();
  std::cout<<results[1]<<"\nDouble Hashing: ";
  timer.start();
  for(int i=0; i<entriesToInsert; i++)
  {
    table3.insert(rand() % 2147483647 + 1);
  }
  results[2] = timer.stop();
  std::cout<<results[2]<<"\n\n";
  return results;
}

double* Test::averageTest(int iterations, double desiredLoadFactor, int tableSize)
{
  double** results = new double*[iterations];
  double* finalResults = new double[3];
  for(int i=0; i<iterations; i++)
  {
    results[i] = new double[3];
  }
  for(int i=0; i<iterations; i++)
  {
    results[i] = singleTest(desiredLoadFactor, tableSize);
  }
  for(int i=0; i<iterations; i++)
  {
    finalResults[0] += results[i][0];
  }
  for(int i=0; i<iterations; i++)
  {
    finalResults[1] += results[i][1];
  }
  for(int i=0; i<iterations; i++)
  {
    finalResults[2] += results[i][2];
  }
  for(int i=0; i<iterations; i++)
  {
    delete[] results[i];
  }
  delete[] results;
  finalResults[0] = finalResults[0] / iterations;
  finalResults[1] = finalResults[1] / iterations;
  finalResults[2] = finalResults[2] / iterations;
  std::cout<<"\n********\nAverage after "<<iterations<<" trials: "
           <<"\nOpen Hashing: "<<finalResults[0]
           <<"\nQuadratic Probing: "<<finalResults[1]
           <<"\nDouble Hashing: "<<finalResults[2]<<"\n********\n\n";
  return finalResults;
}


void Test::runTestSuite(int numAvgs, int tableSize)
{
  Timer timer;
  timer.start();
  double duration = 0;
  double** results = new double*[9];
  for(int i=0; i<9; i++)
  {
    results[i] = averageTest(numAvgs, 0.1 * (i+1), tableSize);
  }
  duration = timer.stop();
  std::cout<<"\n\nFINAL RESULTS:\n";
  for(int i=0; i<9; i++)
  {
    std::cout<<"Load Factor: "<<0.1 * (i+1)
             <<" Open Hashing: "<<results[i][0]
             <<" Quadratic Probing: "<<results[i][1]
             <<" Double Hashing: "<<results[i][2]<<"\n";
  }
  std::cout<<"\nTotal time elapsed: "<<duration
           <<"\nNumber of trials taken per average: "<<numAvgs
           <<"\nSize of table during tests: "<<tableSize<<"\n\n";
  for(int i=0; i<9; i++)
  {
    delete[] results[i];
  }
  delete[] results;
}
