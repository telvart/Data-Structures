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
  unlinkOrders();
  BNode* temp = new BNode(val);
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
        //if(m_BOrders[currentOrder+1] != nullptr) {m_BOrders[currentOrder+1]->m_left = m_BOrders[currentOrder];}
      }
      else
      {
        temp = merge(temp, temp2);
        mergeOccured = true;
        m_BOrders[currentOrder]=nullptr;
      }
  } while(mergeOccured);


  linkRights();
  linkLefts();
  updateRoot();

}

void BinomialQueue::deleteMin()
{

}

void BinomialQueue::levelOrder()
{

}

void BinomialQueue::unlinkOrders()
{
  for(int i=0; i<MAX_ORDER; i++)
  {
    BNode* temp = m_BOrders[i];
    if(temp != nullptr)
    {
      temp->m_left = temp;
      temp->m_right = nullptr;

    }
  }
}
void BinomialQueue::linkRights()
{
  for(int i=0; i<MAX_ORDER; i++)
  {
    int next;
    if((next = nextOrder(i)) != -1)
    {
      if(m_BOrders[i] != nullptr) {m_BOrders[i]->m_right = m_BOrders[next];}
    }
  }
}

void BinomialQueue::linkLefts()
{
  int maxOrder = 0;
  for(int i=0; i<MAX_ORDER; i++)
  {
    if(m_BOrders[i] != nullptr)
    {
      if(i > maxOrder) {maxOrder=i;}
    }
  }

  for(int i=0; i<MAX_ORDER; i++)
  {
    if(m_BOrders[i] != nullptr)
    {
      m_BOrders[i]->m_left = m_BOrders[maxOrder];
      break;
    }
  }
  for(int i = MAX_ORDER-1; i>0; i--)
  {
    int prev;
    if((prev = prevOrder(i)) != -1)
    {
      if(m_BOrders[i] != nullptr){m_BOrders[i]->m_left = m_BOrders[prev];}
    }
  }


}

int BinomialQueue::prevOrder(int order)
{
  if(order > 0)
  {
    for(int i = order-1; i>=0; i--)
    {
      if(m_BOrders[i]!=nullptr) {return i;}
    }
  }
  return -1;
}

int BinomialQueue::nextOrder(int order)
{
  for(int i=order+1; i<MAX_ORDER; i++)
  {
    if(m_BOrders[i]!= nullptr) {return i;}
  }
  return -1;
}

void BinomialQueue::updateRoot()
{
  int minVal, minOrder;
  for(int i=0; i<MAX_ORDER; i++)
  {
    if(m_BOrders[i] != nullptr)
    {
      minVal = m_BOrders[i]->m_key;
      minOrder = i;
      break;
    }
  }

  for(int i=0; i<MAX_ORDER; i++)
  {
    if(m_BOrders[i] != nullptr)
    {
      if(m_BOrders[i]->m_key < minVal)
      {
        minOrder = i;
        minVal = m_BOrders[i]->m_key;
      }
    }
  }
  m_root = m_BOrders[minOrder];
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
