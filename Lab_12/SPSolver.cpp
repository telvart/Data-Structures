 #include "SPSolver.h"

SPSolver::SPSolver()
{
  populateGraphs("data.txt");
}

SPSolver::~SPSolver()
{
  for(int i = 0; i < numGraphs; i++)
  {
    for(int j = 0; j < dimensions[i]; j++)
    {
      delete[] graphs[i][j];
    }
    delete[] graphs[i];
  }
  delete[] graphs;
  delete[] dimensions;
}

void SPSolver::run()
{
  std::cout<<"\nSolutions: \n";
  for(int i = 0; i < numGraphs; i++){
    dijkstraSolve(graphs[i], dimensions[i], 0);
  }
}

void SPSolver::dijkstraSolve(int** myGraph, int gDim, int startVertex)
{

  int* distances = new int[gDim];
  int* prevs = new int[gDim];
  bool* visited = new bool[gDim];

  for(int i = 0; i < gDim; i++)
  {
    distances[i] = INFINITY;
    visited[i] = false;
  }

  distances[startVertex] = 0;

  for(int i = 0; i < gDim; i++)
  {
    int w = minDist(distances, visited, gDim);
    visited[w] = true;
    for(int j = 0; j < gDim; j++)
    {
      if((visited[j] == false) && (myGraph[w][j] > 0) && (distances[w] + myGraph[w][j] < distances[j]))
      {
        prevs[j] = w;
        distances[j] = distances[w] + myGraph[w][j];
      }
    }
  }

  for(int i = 0; i < gDim; i++) {std::cout << distances[i] << " ";}
  std::cout << "\n";

  delete[] distances;
  delete[] prevs;
  delete[] visited;
}

int SPSolver::minDist(int* distances, bool* visitedArr, int gDim)
{
  int minVal = INFINITY;
  int minVertex = 0;
  for(int i = 0; i < gDim; i++)
  {
    if(distances[i] <= minVal && visitedArr[i] == false)
    {
      minVal = distances[i];
      minVertex = i;
    }
  }
  return minVertex;
}

void SPSolver::populateGraphs(std::string fileName)
{
  std::ifstream fileIn(fileName);
  fileIn >> numGraphs;
  std::cout << numGraphs << "\n";
  dimensions = new int[numGraphs];
  graphs = new int**[numGraphs];
  int curDim;

  for(int i=0; i<numGraphs; i++)
  {
    fileIn >> curDim;
    dimensions[i] = curDim;
    std::cout << curDim << "\n";

    graphs[i] = new int*[curDim];
    for(int j = 0; j < curDim; j++) {graphs[i][j] = new int[curDim];}

    for(int j = 0; j < curDim; j++)
    {
      for(int k = 0; k < curDim; k++)
      {
        fileIn >> graphs[i][j][k];
        std::cout << graphs[i][j][k] << " ";
      }
      std::cout<< "\n";
    }
  }
}
