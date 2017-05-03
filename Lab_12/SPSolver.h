
#ifndef SPSOLVER_H
#define SPSOLVER_H

#include <string>
#include <fstream>
#include <iostream>
#include <limits.h>

#define INFINITY INT_MAX

class SPSolver
{

public:

  SPSolver();
  ~SPSolver();
  void dijkstraSolve(int** myGraph, int gDim, int startVertex);
  void run();

private:

  int minDist(int* distances, bool* visitedArr, int gDim);
  void populateGraphs(std::string fileName);

  int*** graphs;
  int* dimensions;
  int numGraphs;
  
};

#endif
