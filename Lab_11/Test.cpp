#include "Test.h"


void Test::run()
{
int n = 100;
MSTSolver mst = MSTSolver();
AdjList* graph = new AdjList(n);
Timer timer;
srand(time(NULL));



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


graph->convertToList(temp);

for(int i=0; i<n; i++){
  for(int j=0; j<n; j++){
    //std::cout<<temp[i][j]<<" ";
  }
  delete[] temp[i];
//  std::cout<<"\n";
}
delete[] temp;








// for(int i=0; i<n; i++)
// {
//   for(int j=0; j<n; j++)
//   {
//     if(i != j)
//     {
//       double makeEdge = 0;
//       if((makeEdge = (rand() / (double)RAND_MAX)) > 0.5){
//         listEntry e;
//         listEntry e2;
//         e.cost = rand() % (4*n) + 1;
//         e2.cost = e.cost;
//         e.vertex = j;
//         e2.vertex = i;
//         graph->theList[i].insert(e);
//         graph->theList[j].insert(e2);
//       }
//     }
//   }
// }

double kTime = 0, pTime = 0;;
int kCost = 0, pCost = 0;;
timer.start();
kCost = mst.kruskalSolve(graph);
kTime = timer.stop();
std::cout<<"\nKruskal-> Cost: "<<kCost<<" Time: "<<kTime<<"\n";
 timer.start();
 pCost = mst.primSolve(graph);
 pTime = timer.stop();


std::cout<<"\nPrim   -> Cost: "<<pCost<<" Time: "<< pTime<<"\n";







}
