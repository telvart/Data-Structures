
#ifndef SPSOLVER_H
#define SPSOLVER_H

#include <string>

class SPSolver
{

public:


  SPSolver();
  ~SPSolver();
  void dijkstraSolve(int startVertex);
  void populateGraphs(std::string fileName);


private:
  int*** graphs;


};




#endif
