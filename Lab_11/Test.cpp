#include "Test.h"

int** createGraph(int n)
{
  int** temp = new int*[n];
  for(int i=0; i<n; i++){
    temp[i] = new int[n];
  }
  double makeEdge;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      if(i != j){
        makeEdge = rand() / (double)RAND_MAX;
        if(makeEdge > 0.5){
          temp[i][j] = rand() % (4*n) + 1;
          temp[j][i] = temp[i][j];
        }
        else{
          temp[i][j] = 0;
          temp[j][i] = 0;
        }
      }
    }
  }

  return temp;
}



void Test::run()
{


MSTSolver mst = MSTSolver();
Timer timer;

int n = 1000;
for(int seed = 1; seed<21; seed++){
  srand(seed);
  int** graph = createGraph(n);

  double kTime;
  int kCost;

  std::cout<<"\nN: "<<n<<" SEED: "<<seed<<"\n";

  timer.start();
  kCost = mst.kruskalSolve(graph, n);
  kTime = timer.stop();

  if(seed%5 == 0) {n *= 2;}
  std::cout<<"Cost:"<< kCost <<"\nTime: "<<kTime<<"\n";



}




// double kTime = 0, pTime = 0;
// int kCost = 0, pCost = 0;
//
// timer.start();
// kCost = mst.kruskalSolve(graph, n);
// kTime = timer.stop();
//
// std::cout<<"\nKruskal-> Cost: "<<kCost<<" Time: "<<kTime<<"\n";
//
// // timer.start();
// // pCost = mst.primSolve(temp, n);
// // pTime = timer.stop();
//
// std::cout<<"\nPrim   -> Cost: "<<pCost<<" Time: "<< pTime<<"\n";



}
