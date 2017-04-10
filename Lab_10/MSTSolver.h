
#ifndef MSTSOLVER_H
#define MSTSOLVER_H

#include <string>

class MSTSolver
{
  public:
    MSTSolver(std::string fileName);
    ~MSTSolver();

    void kruskalSolve(int** myMatrix);
    void primSolve(int** myMatrix);


  private:
    int*** adjacencyMatricies;
    int numGraphs;


};


#endif
