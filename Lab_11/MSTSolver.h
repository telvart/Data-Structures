
#ifndef MSTSOLVER_H
#define MSTSOLVER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "MinKHeap.h"
#include "DoubleLinkedList.h"

struct listEntry{
  int vertex, cost;
  bool operator==(listEntry& rhs){
    return this->vertex == rhs.vertex && this->cost == rhs.cost;
  }
};

struct edge{
  int i, j, cost;
  bool operator>(edge& rhs){
    return this->cost > rhs.cost;
  }
  bool operator<(edge& rhs){
    return this->cost < rhs.cost;
  }
  bool operator==(edge& rhs){
    return (this->i + this->j) == (rhs.i + rhs.j);
  }
};

class AdjList{

public:
  AdjList(int dimension);
  ~AdjList();
  void convertToList(int** adjMatrix);
  DoubleLinkedList<listEntry>* theList;
  int myDim;
};

class DJSNode{
public:
  DJSNode(){}
  int vertex, rank;
  DJSNode* parent;
};

class DJS{
public:

  DJS(int verticies);
  ~DJS();
  DJSNode* find(int vertex);
  void join(DJSNode* n1, DJSNode* n2);

  int numVerticies;
  DJSNode** auxArray;
};

class MSTSolver{

public:

  MSTSolver(std::string fileName);
  MSTSolver();
  ~MSTSolver();
  void run();
  int kruskalSolve(AdjList* adjList);
  int primSolve(AdjList* adjList);

private:


  MinKHeap<edge> updateHeap(MinKHeap<edge> h, std::vector<edge> Et, std::vector<int> visited, AdjList* graph);
  bool setContains(std::vector<int> set, int check);

  MinKHeap<edge> fillKruskalHeap(AdjList* adjList);
  MinKHeap<edge> buildPrimHeap(AdjList* list);



  AdjList** adjacencyLists;
  int numGraphs;

};

#endif
