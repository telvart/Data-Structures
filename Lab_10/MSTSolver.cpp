#include "MSTSolver.h"

MSTSolver::MSTSolver(std::string fileName)
{
  std::cout<<fileName<<" elements:\n";
  std::ifstream fileIn(fileName);
  fileIn >> numGraphs;
  std::cout<<numGraphs<<"\n";

  adjacencyLists = new AdjList*[numGraphs];

  for(int i = 0; i < numGraphs; i++)
  {
   int curDim;
   fileIn >> curDim;
   std::cout<<curDim<<"\n";
   int** temp = new int*[curDim];
   for(int l=0; l<curDim; l++) {temp[l] = new int[curDim];}

   for(int j = 0; j < curDim; j++){
    for(int k = 0; k < curDim; k++){
       fileIn >> temp[j][k];
      std::cout << temp[j][k] << " ";
    }
     std::cout<<"\n";
  }
     adjacencyLists[i] = new AdjList(curDim);
     adjacencyLists[i]->convertToList(temp);
     for(int l = 0; l<curDim; l++) {delete[] temp[l];}
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
  for(int i = 0; i < numGraphs; i++) {delete adjacencyLists[i];}
  delete[] adjacencyLists;
}

AdjList::~AdjList()
{
  delete[] theList;
}

DJS::~DJS()
{
  for(int i = 0; i < numVerticies; i++) {delete auxArray[i];}
  delete[] auxArray;
}

void AdjList::convertToList(int** adjMatrix)
{
  int cost;
  for(int row = 0; row < myDim; row++){
    for(int col = 0; col < myDim; col++){
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
  for(int i = 1; i <= numGraphs; i++)
  {
    std::cout<<"Graph: "<<i<<"\nKruskal: ";
    kruskalSolve(adjacencyLists[i-1]);
    std::cout<<"\nPrim: ";
    primSolve(adjacencyLists[i-1]);
  }
}

void MSTSolver::kruskalSolve(AdjList* adjList)
{
  DJS disjointSet = DJS(adjList->myDim);
  MinKHeap<edge> sortedEdges = fillKruskalHeap(adjList);
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
    for(int i = 0; i < MSTsize; i++)
    {
      edge e = solutionSet.at(i);
      std::cout<<"("<<e.i<<", "<<e.j<<") ";
    }
  }
  else {std::cout<<"A Minimal Spanning tree does not exist";}
}

void MSTSolver::primSolve(AdjList* adjList)
{

  std::vector<edge> Et;
  std::vector<int> Vt;
  Vt.push_back(0);
  int verticies = adjList->myDim;

  MinKHeap<edge> sortedEdges = buildPrimHeap(adjList);

  while(!sortedEdges.isEmpty() && Vt.size() != verticies)
  {
    edge vw = sortedEdges.deleteMin();
    Et.push_back(vw);
    Vt.push_back(vw.j);
    sortedEdges = updateHeap(sortedEdges, Vt, adjList);
  }
//TODO: check if was valid solution
  for(int i = 0; i < Et.size(); i++)
  {
    edge e = Et.at(i);
    std::cout<<"("<<e.i<<", "<<e.j<<") ";
  }
std::cout<<"\n";
}

MinKHeap<edge> MSTSolver::updateHeap(MinKHeap<edge> h, std::vector<int> visited, AdjList* graph)
{
  while(!h.isEmpty()) {h.deleteMin();}
  int dim = graph->myDim;
  for(int i = 0; i < dim; i++)
  {
    if(setContains(visited, i)) // if x is visited
    {
      for(int j = 0; j < graph->theList[i].m_size; j++) //for all adjacent to x
       {
        listEntry e = graph->theList[i].at(j);
        if(!setContains(visited, e.vertex))
        {
          edge temp;
          temp.i = i;
          temp.j = e.vertex;
          temp.cost = e.cost;
          h.insert(temp);
        }
       }
     }
  }
  return h;
}

bool MSTSolver::setContains(std::vector<int> set, int check)
{
  for(int i = 0; i < set.size(); i++)
  {
    if(set[i] == check) {return true;}
  }
  return false;
}

MinKHeap<edge> MSTSolver::buildPrimHeap(AdjList* list)
{
  MinKHeap<edge> h = MinKHeap<edge>(3, 200);
  for(int i = 0; i < list->theList[0].m_size; i++)
  {
    listEntry e = list->theList[0].at(i);
    edge temp;
    temp.i = 0;
    temp.j = e.vertex;
    temp.cost = e.cost;
    h.insert(temp);
  }
  return h;
}

MinKHeap<edge> MSTSolver::fillKruskalHeap(AdjList* adjList)
{
  MinKHeap<edge> h = MinKHeap<edge>(3, 200);
  for(int i = 0; i < adjList->myDim; i++)
  {
    for(int j = 0; j < adjList->theList[i].m_size; j++)
    {
      listEntry e = adjList->theList[i].at(j);
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
