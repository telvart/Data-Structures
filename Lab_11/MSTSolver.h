
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
    return (this->i == rhs.i) && (this->j == rhs.j) && (this->cost == rhs.cost);
  }
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
  MSTSolver();
  ~MSTSolver();
  void run();
  int kruskalSolve(int** matrix, int dimension);
  int primSolve(int** matrix, int dimension);

private:


  void updateHeap(int** matrix, int dimension, std::vector<int> visited,
     std::vector<edge> MSTEdges, MinKHeap<edge>* heap);
  bool setContains(std::vector<int> set, int check);

  MinKHeap<edge> fillKruskalHeap(int** matrix, int dimension);
  MinKHeap<edge>* buildPrimHeap(int** matrix, int dimension);

  int numGraphs;

};

#endif
