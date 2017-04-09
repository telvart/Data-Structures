
#include <fstream>
#include <iostream>
#include <string>
#include "BNode.h"
#include "Queue.h"

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

  private:

    void unlinkOrders();
    void linkRights();
    void linkLefts();
    void updateRoot();

    void subTraversal(BNode* q);
    void deleteQueue (BNode* q);
    void deleteHelper(BNode* q);

    int nextOrder(int order);
    int prevOrder(int order);

    BNode* merge(BNode* q1, BNode* q2);

    BNode* m_root;
    BNode* m_BOrders[MAX_ORDER];
};

#endif
