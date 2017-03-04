#include "Test.h"

void Test::runTestSuite(int numAvg, int n)
{

}
double* Test::singleBuildTest(int n)
{
  MinKHeap<int> heap = MinKHeap<int>(3,n+1);
  BinarySearchTree<int> BST = BinarySearchTree<int>();
  double* results = new double[2];
  Timer timer;
  srand(time(NULL));
  std::cout<<"Running build test with n = "<<n<<"\nMin 3 Heap: ";
  timer.start();
  for(int i=0; i<n; i++)
  {
    heap.insert(rand() % 4*n + 1);
  }
  results[0]=timer.stop();
  std::cout<<results[0]<<"\nBinary Search Tree: ";
  timer.start();
  for(int i =0; i<n; i++)
  {
    BST.insert(rand() % 4*n + 1);
  }
  results[1]=timer.stop();
  std::cout<<results[1]<<"\n";


}
