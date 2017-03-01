
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
    void remove(T val);
    void levelOrder();

  //private:

    int parent(int index);
    int child(int parent, int childNum);
    void swap(int index1, int index2);
    void printChildren(int parent);
    int exp(int num, int power);
    void heapify(int index);
    void heapify();


    T* theHeap;
    int m_entries;
    int m_k;
    int m_arraySize;
};

#include "MinKHeap.hpp"
#endif
