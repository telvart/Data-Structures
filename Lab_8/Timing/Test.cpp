#include "Test.h"

double** Test::buildTest()
{
  double** results = new double*[4];
  for(int i=0; i<5; i++)
  {
    results[i] = new double[2];
  }

  Timer timer;
  double lastTime;

  for (int seed=0; seed < 5; seed++)
  {
    srand(seed);
    int n = 50000;
    std::cout<<"SEED: "<<seed<<"\n";
    for(int valueN=0; valueN<4; valueN++)
    {
      LeftistHeap leftHeap = LeftistHeap();
      SkewHeap skewHeap = SkewHeap();
      std::cout<<"Build Test with n = "<<n<<"\n";
      std::cout<<"Leftist Heap: ";
      timer.start();
      for(int i=0; i<n; i++)
      {
        leftHeap.insert( (rand() % (4*n)) + 1  );
      }
      lastTime = timer.stop();
      results[valueN][0] += lastTime;
      std::cout<<lastTime<<"\nSkew Heap: ";
      timer.start();
      for(int i=0; i<n; i++)
      {
        skewHeap.insert( (rand() % (4*n)) + 1  );
      }
      lastTime = timer.stop();
      results[valueN][1] += lastTime;
      std::cout<<lastTime<<"\n\n";
      n*=2;
    }
  }

  //std::cout<<results[0][1]<<"\n";

  for(int i=0; i<4; i++)
  {
    results[i][0] /= (double)5;
    results[i][1] /= (double)5;
  }

  std::cout<<"\n\nAverage Build Results: \n";
  std::cout<<"n = 50000  LeftistHeap: "<<results[0][0]<<" Skew Heap: "<<results[0][1]<<"\n"
           <<"n = 100000 LeftistHeap: "<<results[1][0]<<" Skew Heap: "<<results[1][1]<<"\n"
           <<"n = 200000 LeftistHeap: "<<results[2][0]<<" Skew Heap: "<<results[2][1]<<"\n"
           <<"n = 400000 LeftistHeap: "<<results[3][0]<<" Skew Heap: "<<results[3][1]<<"\n";

  return results;


}

double** Test::operationsTest()
{
  return nullptr;
}

void Test::runTests()
{
  double** buildResults = buildTest();
  std::cout<<"\n";
  double** opResults = operationsTest();
}
