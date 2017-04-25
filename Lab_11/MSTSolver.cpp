#include "MSTSolver.h"

MSTSolver::MSTSolver()
{

}

DJS::DJS(int verticies)
{
  numVerticies = verticies;
  auxArray = new DJSNode*[numVerticies];
  for(int i = 0; i < numVerticies; i++)
  {
    DJSNode* temp = new DJSNode();
    temp->vertex = i;
    temp->rank=0;
    temp->parent = temp;
    auxArray[i] = temp;
  }
}

MSTSolver::~MSTSolver()
{
  //for(int i = 0; i < numGraphs; i++) {delete adjacencyLists[i];}
  //delete[] adjacencyLists;
}


DJS::~DJS()
{
  for(int i = 0; i < numVerticies; i++) {delete auxArray[i];}
  delete[] auxArray;
}


void MSTSolver::run()
{
  for(int i = 1; i <= numGraphs; i++)
  {
    // std::cout<<"Graph: "<<i<<"\nKruskal: ";
    // kruskalSolve(adjacencyLists[i-1]);
    // std::cout<<"\nPrim: ";
    // primSolve(adjacencyLists[i-1]);
  }
}

int MSTSolver::kruskalSolve(int** matrix, int dimension)
{
  DJS djs = DJS(dimension);
  MinKHeap<edge> sortedEdges = fillKruskalHeap(matrix, dimension);
  std::vector<edge> solutionSet;
  int MSTsize = dimension - 1;
  int mstCost = 0;

  while(!sortedEdges.isEmpty() && (solutionSet.size() != MSTsize))
  {
    edge candidate = sortedEdges.deleteMin();
    if(djs.find(candidate.i) != djs.find(candidate.j))
    {
      mstCost += candidate.cost;
      solutionSet.push_back(candidate);
      djs.join(djs.find(candidate.i), djs.find(candidate.j));
    }
  }
  if(solutionSet.size() == MSTsize) {return mstCost;}
  else {return -1;}
}

int MSTSolver::primSolve(int** matrix, int dimension)
{

   std::vector<edge> Et; //edges in the MST
   std::vector<int> Vt; //visited verticies
   Vt.push_back(0);
   int mstCost = 0;

  MinKHeap<edge>* sortedEdges = buildPrimHeap(matrix, dimension);

   while(!sortedEdges->isEmpty() && Vt.size() != dimension)
   {
     edge vw = sortedEdges->deleteMin();
     mstCost += vw.cost;
     Et.push_back(vw);
     Vt.push_back(vw.j);
     //std::cout<<"\n\nBefore"<<sortedEdges.size();
    updateHeap(matrix, dimension, Vt, Et, sortedEdges);

     //std::cout<<"\n\nAfter"<<sortedEdges.size();
   }

   delete sortedEdges;
   if(Vt.size() == dimension) {return mstCost;}
   else {return -1;}

}

bool edgeSetContains(std::vector<edge> MSTEdges, edge e){
  for(int i=0; i<MSTEdges.size(); i++)
  {
    if(MSTEdges[i] == e){return true;}
  }
  return false;
}


void MSTSolver::updateHeap(int** matrix, int dimension, std::vector<int> visited,
   std::vector<edge> MSTEdges, MinKHeap<edge>* heap)
{

  delete heap;
  heap = new MinKHeap<edge>(5, dimension * dimension);
  int tempCost;
  for(int i=0; i<visited.size(); i++)
  {
    int curVertex = visited[i];
    // now insert all edges incident from curVertex that arent already in the MST
    for(int k = 0; k< dimension; k++)
    {
      if(curVertex != k)
      {
        tempCost = matrix[k][curVertex];
        if(tempCost != 0)
        {
          edge e;
          e.i = curVertex;
          e.j = k;
          e.cost = tempCost;
          if(!setContains(visited, k) && !edgeSetContains(MSTEdges, e)){
            heap->insert(e);
          }
        }
      }
    }
  }

  // int tempCost;
  // for(int i=0; i<visited.size(); i++){
  //
  //   int curVertex = visited[i];
  //   if(curVertex == 0) {continue;}
  //   for(int j=0; j<dimension; j++){
  //     if((tempCost = matrix[j][curVertex] != 0) && curVertex != j){
  //       if(!setContains(visited, j)){
  //               edge e;
  //               e.i=j;
  //               e.j=curVertex;
  //               e.cost=tempCost;
  //               bool shouldInsert = true;
  //               for(int k=0; k<MSTEdges.size(); k++){
  //                 if(MSTEdges[k] == e){
  //                   shouldInsert = false;
  //                 }
  //               }
  //               for(int k=0; k<heap->size(); k++){
  //                 if(heap->theHeap[k] == e){shouldInsert = false;}
  //               }
  //               if(shouldInsert) {heap->insert(e);}
  //       }
  //     }
  //   }


    // for(int j=curVertex+1; j<dimension; j++){
    //   if((tempCost = matrix[curVertex][j]) != 0)
    //   {
    //     if(!setContains(visited, j))
    //     {
    //       edge e;
    //       e.i=curVertex;
    //       e.j=j;
    //       e.cost=tempCost;
    //       bool shouldInsert = true;
    //       for(int k=0; k<MSTEdges.size(); k++){
    //         if(MSTEdges[k] == e){
    //           shouldInsert = false;
    //         }
    //       }
    //       for(int k=0; k<heap->size(); k++){
    //         if(heap->theHeap[k] == e){shouldInsert = false;}
    //       }
    //       if(shouldInsert) {heap->insert(e);}
    //     }
    //   }
    // }
  //}
}

bool MSTSolver::setContains(std::vector<int> set, int check)
{
  for(int i = 0; i < set.size(); i++)
  {
    if(set[i] == check) {return true;}
  }
  return false;
}

MinKHeap<edge>* MSTSolver::buildPrimHeap(int** matrix, int dimension)
{
  //return all edges adjacent to vertex 0
  MinKHeap<edge>* h = new MinKHeap<edge>(5, dimension*dimension);
  int tempCost;
  for(int i=0; i<dimension; i++)
  {
    if((tempCost = matrix[0][i]) != 0){
      edge e;
      e.i=0;
      e.j=i;
      e.cost=tempCost;
      h->insert(e);
    }
  }
  return h;
}

MinKHeap<edge> MSTSolver::fillKruskalHeap(int** matrix, int dimension)
{
  MinKHeap<edge> h = MinKHeap<edge>(5, dimension*dimension);
  int tempCost;
  for(int row=0; row<dimension; row++){
    for(int col=row; col<dimension; col++){
      if((tempCost = matrix[row][col]) != 0){
        edge e;
        e.i = row;
        e.j = col;
        e.cost = tempCost;
        h.insert(e);
      }
    }
  }
  return h;
}

DJSNode* DJS::find(int vertex)
{
  DJSNode* start = auxArray[vertex];
  //DoubleLinkedList<DJSNode*> pathCompress = DoubleLinkedList<DJSNode*>();
  std::vector<DJSNode*> pathCompress;
  while(start -> parent != start)
  {
    pathCompress.push_back(start);
    start = start->parent;
  }

  while(pathCompress.size() != 0)
  {
    DJSNode* temp = pathCompress[0];
    pathCompress.erase(pathCompress.begin());
    temp->parent = start;
  }
  return start;
}

void DJS::join(DJSNode* n1, DJSNode* n2)
{
  if(n1->rank == n2->rank)
  {
    n2->rank++;
    n1->parent = n2;
  }

  else if (n1->rank < n2->rank) {n1->parent = n2;}
  else {n2->parent = n1;}
}
