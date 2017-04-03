#include "BinomialQueue.h"


BinomialQueue::BinomialQueue(std::string fileName)
{
  std::cout<<fileName<<" elements: ";
  std::ifstream fileIn(fileName);
  int value;
  m_root = nullptr;
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
    merge(temp, m_root, true);
  }
}

void BinomialQueue::deleteMin()
{

}

void BinomialQueue::levelOrder()
{

}

void BinomialQueue::merge(BNode* q1, BNode* q2, bool order0)
{
  if(q1->m_key > q2->m_key)
  {
    BNode* temp = q1;
    q1=q2;
    q2=temp;
  }

  if(order0 == true)
  {
    q1->m_firstChild = q2;
    q1->m_order += 1;
  }
  else
  {
    q2->m_left = q1->m_firstChild->m_left;
    q2->m_left->m_right = q2;
    q1->m_firstChild->m_left=q2;
    q1->m_order += 1;
  }
}

bool BinomialQueue::mergeNeeded(BNode* newNode)
{

}
