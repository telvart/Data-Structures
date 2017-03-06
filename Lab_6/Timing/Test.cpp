#include "Test.h"

void Test::runTestSuite()
{
  std::cout<<"\nBUILD TESTS:\n";
  double* buildResults = new double[2];
  srand(1);



}
double** Test::buildTest()
{
  // MinKHeap<int> heap = MinKHeap<int>(3,2*n);
  // BinarySearchTree<int> BST =BinarySearchTree<int>();
  Timer timer;
  double** results = new double*[4];
  for(int i=0; i<4; i++)
  {
    results[i] = new double[2];
  }
  double lastTime=0;
  MinKHeap<int> heap = MinKHeap<int>(3,100000); //n=50000
  MinKHeap<int> heap2 = MinKHeap<int>(3,100000); //n=100000
  MinKHeap<int> heap3 = MinKHeap<int>(3,100000); //n
  MinKHeap<int> heap4 = MinKHeap<int>(3,100000);

  BinarySearchTree<int> BST = BinarySearchTree<int>();
  BinarySearchTree<int> BST2 = BinarySearchTree<int>();
  BinarySearchTree<int> BST3 = BinarySearchTree<int>();
  BinarySearchTree<int> BST4 = BinarySearchTree<int>();


  std::cout<<"BUILD TIMES:\n";
  for(int i=0; i<5; i++)
  {
    std::cout<<"Trial: "<<i+1<<"\n";
    srand(i+1);

    int n=50000;
    for(int i=0; i<4; i++)
    {
      // for()
      // {
      //
      // }
      // for()
      // {
      //
      // }
    }




    // timer.start();
    // for(int j=0; j<50000; j++)
    // {
    //   BST.insert(rand() % 200000 +1);
    // }
    // lastTime = timer.stop();
    // std::cout<<"BST: "<<lastTime<<"\n";
    // results[0][0]+=lastTime;
    //
    // timer.start();
    // for(int k=0; k<50000; k++)
    // {
    //   heap.theHeap[k]=rand()%200000+1;
    //   heap.m_entries++;
    // }
    // heap.buildHeapify();
    // lastTime = timer.stop();
    // std::cout<<"Min 3 Heap: "<<lastTime<<"\n\n";
    // results[0][1]+=lastTime;
  }
  // results[0][0]=results[0][0]/5;
  // results[0][1]=results[0][1]/5;
  // std::cout<<"Average after 5 trials\nBST: "<<results[0][0]<<"\nMin 3 Heap: "<<results[0][1]<<"\n";





  return results;


}
