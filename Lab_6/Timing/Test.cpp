#include "Test.h"

void Test::runTestSuite()
{
  std::cout<<"\nBUILD TESTS:\n";
//  double** buildResults = buildTest();
  double** opResults = operationsTest();

}
double** Test::buildTest()
{
  Timer timer;
  double** results = new double*[4];
  for(int i=0; i<4; i++)
  {
    results[i] = new double[2];
  }
  double lastTime=0;

  int i, j, k, f = 0;
  std::cout << "\nBUILD TIMES:\n";
  for(i = 0; i < 5; i++)
  {
    std::cout << "Trial: " << i+1 << "\n";
    srand(i+1);
    int n = 50000;
    for(j = 0; j < 4; j++)
    {
      MinKHeap<int> heap = MinKHeap<int>(3, n+1);
      BinarySearchTree<int> BST = BinarySearchTree<int>();

      std::cout <<"n = " << n << "\nB Search Tree: ";
      timer.start();
      for(k = 0; k < n; k++)
      {
        BST.insert(rand() % 4*n +1);
      }
      lastTime = timer.stop();
      results[j][0] += lastTime;

      std::cout << lastTime << "\nMin 3 Heap: ";
      timer.start();
      for(f = 0; f < n; f++)
      {
        heap.theHeap[k] = rand() % 4*n + 1;
        heap.m_entries++;
      }
      heap.buildHeapify();
      lastTime = timer.stop();
      results[j][1] += lastTime;
      std::cout << lastTime << "\n\n";
      n *= 2;

    }
  }
  for(i = 0; i < 4; i++)
  {
    for( j = 0; j < 2; j++)
    {
      results[i][j] = results[i][j] / 5;
    }
  }

  std::cout << "\n\nAVERAGES AFTER 5 TRIALS:\n"
            << "\nn = 50,000  BST: "<<results[0][0]<<" Min 3 Heap: "<<results[0][1]
            << "\nn = 100,000 BST: "<<results[1][0]<<" Min 3 Heap: "<<results[1][1]
            << "\nn = 200,000 BST: "<<results[2][0]<<" Min 3 Heap: "<<results[2][1]
            << "\nn = 400,000 BST: "<<results[3][0]<<" Min 3 Heap: "<<results[3][1]<<"\n\n";

  return results;

}

double** Test::operationsTest()
{
  double** results = new double*[4];
  Timer timer;
  for(int i=0; i<4; i++)
  {
    results[i]=new double[2];
  }
  double lastTime=0;

  for(int i=0; i<5; i++)
  {
    srand(i+1);
    int n=50000;

    for(int j=0; j<4; j++)
    {
      MinKHeap<int> heap = MinKHeap<int>(3, n+1);
      BinarySearchTree<int> BST = BinarySearchTree<int>();

      for(int k=0; k<n; k++)
      {
        BST.insert(rand() % 4*n +1);
      }
      for(int k=0; k<n; k++)
      {
        heap.theHeap[i] = rand() % 4*n +1;
        heap.m_entries++;
      }
      heap.buildHeapify();

      for(double k=0; k<0.1*n; k++)
      {
        double x = (double)rand() / RAND_MAX;
        if( x >= 0 && x < 0.1)
        {
          timer.start();
          BST.deleteMin();
          lastTime = timer.stop();
          timer.start();
          heap.deleteMin();
          lastTime = timer.stop();
        }
        else if(x >= 0.1 && x < 0.2)
        {
          timer.start();
          BST.deleteMax();
          timer.stop();
          timer.start();
          heap.deleteMin();
          timer.stop();
        }
        else if(x >= 0.2 && x < 0.5)
        {
          int y = rand() % 4*n +1;
          timer.start();
        //  BST.removeVal(y);
          timer.stop();
          timer.start();
        //  heap.removeVal(y);
          timer.stop();
        }
        else
        {
          int y = rand() % 4*n + 1;
          timer.start();
          BST.insert(y);
          timer.stop();
          timer.start();
          heap.insert(y);
          timer.stop();
        }
      }








      n *= 2;
    }


  }






  return nullptr;
}





























//
