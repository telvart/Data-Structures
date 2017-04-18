#include "MSTSolver.h"

MSTSolver::MSTSolver(std::string fileName)
{
  std::cout<<fileName<<" elements:\n";
  std::ifstream fileIn(fileName);
  fileIn >> numGraphs;
  std::cout<<numGraphs<<"\n";

  adjacencyLists = new AdjList*[numGraphs];

  for(int i=0; i<numGraphs; i++)
  {
   int curDim;
   fileIn >> curDim;
   std::cout<<curDim<<"\n";
   int** temp = new int*[curDim];
   for(int l=0; l<curDim; l++) {temp[l] = new int[curDim];}

   for(int j=0; j<curDim; j++){
    for(int k=0; k<curDim; k++){
       fileIn >> temp[j][k];
      std::cout << temp[j][k] << " ";
    }
     std::cout<<"\n";
  }
     adjacencyLists[i] = new AdjList(curDim);
     adjacencyLists[i]->convertToList(temp);
     for(int l=0; l<curDim; l++) {delete[] temp[l];}
     delete[] temp;

   }
   std::cout<<"**********************************\n";
}

AdjList::AdjList(int dimension)
{
  theList = new DoubleLinkedList<listEntry>[dimension];
  myDim = dimension;
}

DJS::DJS(int verticies)
{
  numVerticies = verticies;
  auxArray = new DJSNode*[numVerticies];
  for(int i=0; i<numVerticies; i++)
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
  for(int i=0; i<numGraphs; i++) {delete adjacencyLists[i];}
  delete[] adjacencyLists;
}

AdjList::~AdjList()
{
  delete[] theList;
}

DJS::~DJS()
{
  for(int i=0; i<numVerticies; i++) {delete auxArray[i];}
  delete[] auxArray;
}

void AdjList::convertToList(int** adjMatrix)
{
  int cost;
  for(int row=0; row<myDim; row++){
    for(int col=0; col<myDim; col++){
      if((cost = adjMatrix[row][col]) != 0){
        listEntry e;
        e.cost=cost;
        e.vertex=col;
        theList[row].insert(e);
      }
    }
  }
}

void MSTSolver::run()
{
  for(int i=0; i<numGraphs; i++)
  {
     std::cout<<"Graph: "<<i;
     std::cout<<"\nKruskal: ";
    kruskalSolve(adjacencyLists[i]);
    std::cout<<"\nPrim: ";
    primSolve(adjacencyLists[i]);
  }
}


void MSTSolver::kruskalSolve(AdjList* adjList)
{
  DJS disjointSet = DJS(adjList->myDim);
  MinKHeap<edge> sortedEdges = fillSortedEdges(adjList);
  std::vector<edge> solutionSet;
  int MSTsize = adjList->myDim-1;
  while(!sortedEdges.isEmpty() && (solutionSet.size() != MSTsize))
  {
    edge candidate = sortedEdges.deleteMin();
    if(disjointSet.find(candidate.i) != disjointSet.find(candidate.j))
    {
      solutionSet.push_back(candidate);
      disjointSet.join(disjointSet.find(candidate.i), disjointSet.find(candidate.j));
    }
  }
  if(solutionSet.size() == MSTsize)
  {
    for(int i=0; i<MSTsize; i++)
    {
      edge e = solutionSet.at(i);
      std::cout<<"("<<e.i<<", "<<e.j<<") ";
    }
  }
  else
  {
    std::cout<<"A Minimal Spanning tree does not exist for this graph";
  }
}

void MSTSolver::primSolve(AdjList* adjList)
{
  std::cout<<"lol dude do this already\n";
}

MinKHeap<edge> MSTSolver::fillSortedEdges(AdjList* adjList)
{
  MinKHeap<edge> h = MinKHeap<edge>(3, 200);

  for(int i=0; i<adjList->myDim; i++)
  {
    while(!adjList->theList[i].isEmpty())
    {
      listEntry e = adjList->theList[i].pop();
      if(e.vertex < i)
      {
        edge temp;
        temp.i = e.vertex;
        temp.j = i;
        temp.cost = e.cost;
        h.insert(temp);
      }
    }
  }
  return h;
}

DJSNode* DJS::find(int vertex)
{
  DJSNode* start = auxArray[vertex];
  DoubleLinkedList<DJSNode*> pathCompress = DoubleLinkedList<DJSNode*>();
  while(start -> parent != start)
  {
    start = start->parent;
    pathCompress.insert(start);
  }

  while(!pathCompress.isEmpty())
  {
    DJSNode* temp = pathCompress.pop();
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
  else if(n1->rank < n2->rank)
  {
    n1->parent = n2;
  }
  else
  {
    n2->parent = n1;
  }
}
