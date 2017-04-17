
#ifndef MINKHEAP_H
#define MINKHEAP_H

#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

template <typename T>
class MinKHeap
{
  public:

    MinKHeap(int k, int size);
    MinKHeap(int k, int size, std::string fileName);
    ~MinKHeap();
    void insert(T val);
    void deleteMin();
    void deleteMax();
    void removeVal(T val);
    void levelOrder();

  private:

    int parent(int index);
    int child(int parent, int childNum);
    void swap(int index1, int index2);
    void heapify(int index);
    void buildHeapify();
    int exp(int num, int power);
    int findMax();
    void upHeap(int index);

    T* theHeap;
    int m_entries;
    int m_k;
    int m_arraySize;
};

#include "MinKHeap.hpp"
#endif
