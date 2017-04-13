#include "MSTSolver.h"


MSTSolver::MSTSolver()
{
  std::ifstream fileIn("data.txt");
  std::cout<< "data.txt elements:\n";
  fileIn>>numGraphs;
  std::cout<<numGraphs<<"\n";
  adjacencyMatricies = new int**[numGraphs];
  graphDimensions = new int[numGraphs];
  int dimension, value;
  for(int i=0; i<numGraphs; i++)
  {
    fileIn>>dimension;
    graphDimensions[i]=dimension;
    std::cout<<dimension<<"\n";
    initializeSingleMatrix(i,dimension);
    for(int j=0; j<dimension; j++)
    {
      for(int k=0; k<dimension; k++)
      {
        fileIn>>adjacencyMatricies[i][j][k];
        std::cout<<adjacencyMatricies[i][j][k]<<" ";
      }
      std::cout<<"\n";
    }
  }
  fileIn.close();
}

void MSTSolver::initializeSingleMatrix(int graphNum, int dim)
{
  adjacencyMatricies[graphNum] = new int*[dim];
  for(int i=0; i<dim; i++)
  {
    adjacencyMatricies[graphNum][i] = new int[dim];
  }
}

MSTSolver::~MSTSolver()
{

}

void MSTSolver::run()
{
  kruskalSolve(adjacencyMatricies[0], graphDimensions[0]);
}

void MSTSolver::kruskalSolve(int** myMatrix, int dim)
{
  MinKHeap<edge> sortedEdges = fillKruskalHeap(myMatrix, dim);
  edge possibleEdge = sortedEdges.deleteMin();
  //a DJS data structure must be used. If DJS.find(i) != DJS.find(j)
  //then select the edge, otherwise it is rejected;
  //implement kruskal's algorithm
}

MinKHeap<edge> MSTSolver::fillKruskalHeap(int** matrix, int dim)
{
  MinKHeap<edge> h = MinKHeap<edge>(3, 100);
  int cost;
  for(int i=0; i<dim; i++)
  {
    for(int j=i; j<dim; j++)
    {
      if((cost = matrix[i][j]) != 0)
      {
        edge temp;
        temp.i = i;
        temp.j = j;
        temp.cost = cost;
        h.insert(temp);
      }
    }
  }
  return h;
}



void MSTSolver::primSolve(int** myMatrix, int dim)
{

}
