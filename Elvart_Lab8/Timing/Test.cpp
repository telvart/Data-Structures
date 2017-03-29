#include "Test.h"

void Test::runTest()
{
  double** buildresults = new double*[4];
  for(int i=0; i<5; i++)
  {
    buildresults[i] = new double[2];
  }

  double** operationsresults = new double*[4];
  for(int i=0; i<5; i++)
  {
    operationsresults[i] = new double[2];
  }

  Timer timer;
  double lastTime;
  Timer timer2;
  timer2.start();
  for (int seed=0; seed < 5; seed++)
  {
    srand(seed);
    int n = 50000;
    std::cout<<"\nSEED: "<<seed<<"\n";
    for(int valueN=0; valueN<4; valueN++)
    {
      LeftistHeap leftHeap = LeftistHeap();
      SkewHeap skewHeap = SkewHeap();
      std::cout<<"\nTest with n = "<<n<<"\n\nBUILD:\n";
      std::cout<<"Leftist Heap: ";
      timer.start();
      for(int i=0; i<n; i++)
      {
        leftHeap.insert( (rand() % (4*n)) + 1  );
      }
      lastTime = timer.stop();
      buildresults[valueN][0] += lastTime;
      std::cout<<lastTime<<"\nSkew Heap: ";
      timer.start();
      for(int i=0; i<n; i++)
      {
        skewHeap.insert( (rand() % (4*n)) + 1  );
      }
      lastTime = timer.stop();
      buildresults[valueN][1] += lastTime;
      std::cout<<lastTime<<"\n";


      int numOps = 0.1 * n;
      std::cout<<"OPERATIONS\n";

      timer.start();
      for(int i=0; i<numOps; i++)
      {
          double y = rand() / (double)RAND_MAX;
          if(y < 0.5)
          {
            leftHeap.deleteMin();
          }
          else
          {
            int valInserted = rand() % (4*n) + 1;
            leftHeap.insert(valInserted);
          }
      }
      lastTime = timer.stop();
      operationsresults[valueN][0] += lastTime;
      std::cout<<"Leftist Heap: "<<lastTime;
      timer.start();
      for(int i=0; i<numOps; i++)
      {
         double y = rand() / (double)RAND_MAX;
         if(y < 0.5)
          {
            skewHeap.deleteMin();
          }
          else
          {
            int valInserted = rand() % (4*n) + 1;
            skewHeap.insert(valInserted);
          }
      }
      lastTime = timer.stop();
      operationsresults[valueN][1] += lastTime;
      std::cout<<"\nSkew Heap: "<<lastTime<<"\n";

      n*=2;

    }
  }

  for(int i=0; i<4; i++)
  {
    buildresults[i][0] /= (double)5;
    buildresults[i][1] /= (double)5;
    operationsresults[i][0] /= (double)5;
    operationsresults[i][1] /= (double)5;
  }

  std::cout<<"\n\nAverage Build Results: \n";
  std::cout<<"n = 50000  Leftist Heap: "<<buildresults[0][0]<<" Skew Heap: "<<buildresults[0][1]<<"\n"
           <<"n = 100000 Leftist Heap: "<<buildresults[1][0]<<" Skew Heap: "<<buildresults[1][1]<<"\n"
           <<"n = 200000 Leftist Heap: "<<buildresults[2][0]<<" Skew Heap: "<<buildresults[2][1]<<"\n"
           <<"n = 400000 Leftist Heap: "<<buildresults[3][0]<<" Skew Heap: "<<buildresults[3][1]<<"\n";

 std::cout<<"\n\nAverage Operation Results: \n";
 std::cout<<"n = 50000  Leftist Heap: "<<operationsresults[0][0]<<" Skew Heap: "<<operationsresults[0][1]<<"\n"
          <<"n = 100000 Leftist Heap: "<<operationsresults[1][0]<<" Skew Heap: "<<operationsresults[1][1]<<"\n"
          <<"n = 200000 Leftist Heap: "<<operationsresults[2][0]<<" Skew Heap: "<<operationsresults[2][1]<<"\n"
          <<"n = 400000 Leftist Heap: "<<operationsresults[3][0]<<" Skew Heap: "<<operationsresults[3][1]<<"\n";
 std::cout<<"\n\nTotal time elapsed: "<<timer2.stop()<<" seconds\n";


}
