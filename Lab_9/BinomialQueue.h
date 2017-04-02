
#include <fstream>
#include <iostream>
#include <string>
#include "BNode.h"

#ifndef BINOMIALQUEUE_H
#define BINOMIALQUEUE_H

class BinomialQueue
{

  public:
    BinomialQueue(std::string fileName);
    ~BinomialQueue();
    void insert(int val);
    void deleteMin();
    void levelOrder();


  private:
    void merge(BNode* q1, BNode* q2);
    BNode* m_root;
    

};

#endif
