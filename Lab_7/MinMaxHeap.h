
#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

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

    bool onMinLevel(double index);

    void build();
    void swap(int index1, int index2);

    int child(int index, int childNum);
    int parent(int index);
    int grandParent(int index);
    bool isGrandChild(int parent, int grandchild);

    void trickleDown(int index);
    void trickleDownMin(int index);
    void trickleDownMax(int index);

    void bubbleUp(int index);
    void bubbleUpMin(int index);
    void bubbleUpMax(int index);

    int minOfChildrenGrandChildren(int index);
    int maxOfChildrenGrandChildren(int index);

    int* theHeap;
    int m_entries;
    int m_arraySize;

};
#endif
