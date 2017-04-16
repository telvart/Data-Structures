
#ifndef MSTSOLVER_H
#define MSTSOLVER_H

#include <string>
#include <fstream>
#include <iostream>

#include "MinKHeap.h"
#include "DJSNode.h"

struct edge{
  int i, j, cost;
  bool operator>(edge& rhs){
    return this->cost > rhs.cost;
  }
  bool operator<(edge& rhs){
    return this->cost < rhs.cost;
  }
};

class MSTSolver
{
  public:
    MSTSolver();
    ~MSTSolver();

    void run();
    void kruskalSolve(int** myMatrix, int dim);
    void primSolve(int** myMatrix, int dim);


  private:
    void initializeSingleMatrix(int graphNum, int dim);
    void initializeDJS(int dim);
    MinKHeap<edge> fillKruskalHeap(int** matrix, int dim);
    int*** adjacencyMatricies;
    int* graphDimensions;
    DJSNode** disjointArray;
    int numGraphs, numEdges;


};


#endif
