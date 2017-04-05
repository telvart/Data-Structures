
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "BNode.h"

#ifndef BINOMIALQUEUE_H
#define BINOMIALQUEUE_H
#define MAX_ORDER 64

class BinomialQueue
{

  public:
    BinomialQueue(std::string fileName);
    ~BinomialQueue();
    void insert(int val);
    void deleteMin();
    void levelOrder();


  //private:
    BNode* merge(BNode* q1, BNode* q2);
    bool mergeNeeded(BNode* newNode);
    BNode* m_root;
    BNode* m_BOrders[MAX_ORDER];



//make a function that checks whether or not a merge is needed, if it is, continue
//merging until no new merges are needed and the queue is finished

};

#endif
