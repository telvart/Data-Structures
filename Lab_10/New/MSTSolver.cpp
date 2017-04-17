#include "MSTSolver.h"

MSTSolver::MSTSolver(std::string fileName)
{
  std::cout<<fileName<<" elements:\n";
  std::ifstream fileIn(fileName);
  fileIn >> numGraphs;
  std::cout<<numGraphs<<"\n";


  adjacencyLists = new AdjList*[numGraphs];



 //  for(int i=0; i<numGraphs; i++)
 // {
 //  int curDim;
 //  fileIn >> curDim;
 //  std::cout<<curDim<<"\n";
 //  int temp[curDim][curDim];
 //
 //  for(int j=0; j<curDim; j++){
 //    for(int k=0; k<curDim; k++){
 //      fileIn >> temp[j][k];
 //      std::cout << temp[j][k] << " ";
 //    }
 //    std::cout<<"\n";
 //  }
 //
 //    adjacencyLists[i] = new DoubleLinkedList<listEntry>[curDim];
 //  //DoubleLinkedList<listEntry> adjList[curDim];
 //
 //  for(int row=0; row<curDim; row++){
 //    adjacencyLists[i][row] = DoubleLinkedList<listEntry>();
 //    for(int col=0; col<curDim; col++){
 //      int cost;
 //      if((cost = temp[row][col]) != 0)
 //      {
 //        listEntry temp2;
 //        temp2.cost=cost;
 //        temp2.vertex=col;
 //        adjacencyLists[i][row].insert(temp2);
 //      }
 //    }
 //  }
 //
 //
 //
 //
 //
 //
 //
 //
 //
 //
 //  }
 //
 //  for(int i=0; i<numGraphs; i++)
 //  {
 //    int size = adjacencyLists[i][0].m_size;
 //  }
 //    std::cout<<"\n\n\n"<<adjacencyLists[0][1].peek().vertex;
}

MSTSolver::~MSTSolver()
{

}

void MSTSolver::run()
{

}


void MSTSolver::kruskalSolve(DoubleLinkedList<listEntry> adjList)
{

}

void MSTSolver::primSolve(DoubleLinkedList<listEntry> adjList)
{

}

// MinKHeap<edge> MSTSolver::fillSortedEdges(DoubleLinkedList<listEntry> adjList, int dimension)
// {
//
// }
