#include "BinomialQueue.h"


BinomialQueue::BinomialQueue(std::string fileName)
{
  std::cout<<fileName<<" elements: ";
  std::ifstream fileIn(fileName);
  int value;
  while(fileIn>>value)
  {
    insert(value);
    std::cout<<value<<" ";
  }
  std::cout<<"\n";
}

BinomialQueue::~BinomialQueue()
{

}

void BinomialQueue::insert(int val)
{
  BNode* temp = new BNode(val);
  if(m_root == nullptr)
  {
    m_root = temp;
    return;
  }
  else
  {
    merge(temp, m_root);
  }
}

void BinomialQueue::deleteMin()
{

}

void BinomialQueue::levelOrder()
{

}

void BinomialQueue::merge(BNode* h1, BNode* h2)
{

}
