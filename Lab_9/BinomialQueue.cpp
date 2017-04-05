#include "BinomialQueue.h"


BinomialQueue::BinomialQueue(std::string fileName)
{
  std::cout<<fileName<<" elements: ";
  std::ifstream fileIn(fileName);
  int value;
  m_root = nullptr;
  for(int i=0; i<MAX_ORDER; i++){m_BOrders[i] = nullptr;}


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
  int maxorder = 0;
  for(int i=0; i<MAX_ORDER; i++)
  {
    if(m_BOrders[i] != nullptr) {maxorder=i;}
  }

  int currentOrder;
  bool mergeOccured;
  do
  {
      currentOrder = temp->m_order;
      BNode* temp2 = m_BOrders[currentOrder];
      if(temp2 == nullptr)
      {
        mergeOccured = false;
        m_BOrders[currentOrder] = temp;
        m_BOrders[currentOrder] -> m_right = m_BOrders[currentOrder+1];
        if(m_BOrders[currentOrder+1] != nullptr) {m_BOrders[currentOrder+1]->m_left = m_BOrders[currentOrder];}
        if(currentOrder == 0)
        {
          m_BOrders[currentOrder] ->m_left = m_BOrders[maxorder];
        }
      }
      else
      {

      }
  } while(mergeOccured);


  // do
  // {
  //   currentOrder = temp->m_order;
  //   BNode* temp2 = m_BOrders[currentOrder];
  //   if(temp2 == nullptr)
  //   {
  //     m_BOrders[currentOrder] = temp;
  //     m_BOrders[currentOrder]->m_right = m_BOrders[currentOrder+1];
  //     if(currentOrder != 0) {m_BOrders[currentOrder]->m_left = m_BOrders[currentOrder-1];}
  //     mergeOccured = false;
  //   }
  //   else
  //   {
  //     m_BOrders[currentOrder] = nullptr;
  //     temp = merge(temp,temp2);
  //     mergeOccured = true;
  //   }
  //
  // } while(mergeOccured);

  m_root = m_BOrders[0];


  // if(m_BOrders[0] == nullptr)
  // {
  //   m_BOrders[0] = temp;
  // }
  // else
  // {
  //   bool mergeOccured=false;
  //   int currentOrder=0;
  //   do
  //   {
  //     currentOrder = temp->m_order;
  //     BNode* temp2 = m_BOrders[currentOrder];
  //   } while(mergeOccured);


  //
  // int min;
  // if(m_BOrders[0] != nullptr)
  // {
  //   min = m_BOrders[0]->m_key;
  //   m_root = m_BOrders[0];
  // }
  // for(int i=0; i<MAX_ORDER; i++)
  // {
  //   if(m_BOrders[i] != nullptr)
  //   {
  //     m_BOrders[i]->m_right = m_BOrders[i+1];
  //     if(m_BOrders[i]->m_key < min)
  //     {
  //       min = m_BOrders[i]->m_key;
  //       m_root = m_BOrders[i];
  //     }
  //   }
  // }
}

void BinomialQueue::deleteMin()
{

}

void BinomialQueue::levelOrder()
{

}

BNode* BinomialQueue::merge(BNode* q1, BNode* q2)
{
  if(q1->m_key > q2->m_key)
  {
    BNode* temp = q1;
    q1=q2;
    q2=temp;
  }

  if(q1->m_order == 0 && q2->m_order == 0)
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
  return q1;
}

bool BinomialQueue::mergeNeeded(BNode* newNode)
{

}
