#include "Test.h"


void Test::run()
{
int n = 100;
MSTSolver mst = MSTSolver();
AdjList* graph = new AdjList(n);
Timer timer;
srand(time(NULL));


for(int i=0; i<n; i++)
{
  for(int j=0; j<n; j++)
  {
    if(i != j)
    {
      double makeEdge = 0;
      if((makeEdge = (rand() / (double)RAND_MAX)) > 0.5){
        listEntry e;
        e.cost = rand() % (4*n) + 1;
        e.vertex = j;
        graph->theList[i].insert(e);
      }
    }
  }
}

double kTime = 0, pTime = 0;;
int kCost = 0, pCost = 0;;
timer.start();
kCost = mst.kruskalSolve(graph);
kTime = timer.stop();
std::cout<<"\nKruskal-> Cost: "<<kCost<<" Time: "<<kTime<<"\n";
 // timer.start();
 // pCost = mst.primSolve(graph);
 // pTime = timer.stop();


std::cout<<"\nPrim   -> Cost: "<<pCost<<" Time: "<< pTime<<"\n";







}
