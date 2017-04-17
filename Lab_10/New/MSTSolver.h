
#ifndef MSTSOLVER_H
#define MSTSOLVER_H

#include <iostream>
#include <string>
#include <fstream>
#include "MinKHeap.h"
#include "DoubleLinkedList.h"

struct listEntry{
  int vertex, cost;
};

struct edge{
  int i, j, cost;
  bool operator>(edge& rhs){
    return this->cost > rhs.cost;
  }
  bool operator<(edge& rhs){
    return this->cost < rhs.cost;
  }
};

class AdjList{

public:
  AdjList(int dimension);
  ~AdjList();
  void convertToList(int** adjMatrix);

  DoubleLinkedList<listEntry>* theList;
};


class MSTSolver{

public:

  MSTSolver(std::string fileName);
  ~MSTSolver();
  void run();

private:

  void kruskalSolve(DoubleLinkedList<listEntry> adjList);
  void primSolve(DoubleLinkedList<listEntry> adjList);

  MinKHeap<edge> fillSortedEdges(DoubleLinkedList<listEntry> adjList, int dimension);

  AdjList** adjacencyLists;
  int numGraphs;

};



#endif
