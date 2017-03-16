
#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include "LHNode.h"
#include "Queue.h"
#include <fstream>
#include <string>
#include <iostream>

class LeftistHeap
{
  public:

    LeftistHeap();
    LeftistHeap(std::string fileName);
    ~LeftistHeap();

    void insert(int val);
    void deleteMin();
    void preOrder();
    void inOrder();
    void levelOrder();
    bool isEmpty();

  private:

    LHNode* merge(LHNode* h1, LHNode* h2);

    void preOrder(LHNode* subtree);
    void inOrder(LHNode* subtree);
    void deleteTree(LHNode* subtree);

    LHNode* m_root;

};

#endif
