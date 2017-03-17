#ifndef SKEWHEAP_H
#define SKEWHEAP_H

#include "SHNode.h"
#include "Queue.h"
#include <string>
#include <fstream>
#include <iostream>

class SkewHeap
{
  public:

    SkewHeap(std::string fileName);
    ~SkewHeap();

    void insert(int val);
    void deleteMin();
    void preOrder();
    void inOrder();
    void levelOrder();
    bool isEmpty();

  private:

    SHNode* merge(SHNode* h1, SHNode* h2);
    void preOrder(SHNode* subtree);
    void inOrder(SHNode* subtree);
    void deleteTree(SHNode* subtree);

    SHNode* m_root;
};
#endif
