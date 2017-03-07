
#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <string>

class MinMaxHeap
{
  public:

    MinMaxHeap(int arraySize);
    MinMaxHeap(int arraySize, std::string fileName);
    ~MinMaxHeap();
    
    void insert(int val);
    void deletemin();
    void deletemax();
    void levelorder();

  private:

    int* theHeap;
    int m_entries;
    int m_arraySize;

};
#endif
