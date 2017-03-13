#include "LeftistHeap.h"

LeftistHeap::LeftistHeap()
{

}

LeftistHeap::LeftistHeap(std::string fileName)
{
  std::ifstream fileIn(fileName);
  m_root = nullptr;


}

LeftistHeap::~LeftistHeap()
{
  deleteTree(m_root);
}

void LeftistHeap::insert(int val)
{
  m_root = insert(val,m_root);
}

void LeftistHeap::deleteMin()
{

}

void LeftistHeap::preOrder()
{
  std::cout<<"PRE ORDER: ";
  preOrder(m_root);
  std::cout<<"\n";
}

void LeftistHeap::inOrder()
{
  std::cout<<"IN ORDER: ";
  inOrder(m_root);
  std::cout<<"\n";
}

void LeftistHeap::levelOrder()
{
  if (m_root == nullptr) {return;}

  Queue<LHNode*> queue = Queue<LHNode*>();
  queue.enqueue(m_root);
  //queue.enqueueBack(nullptr); when this shows up, print new line and add to end of queue
  while(!queue.isEmpty())
  {
    LHNode* currentNode = queue.dequeue();
    std::cout<<currentNode->m_value<<" ";

    if(currentNode->getLeft() != nullptr)
    {
      queue.enqueue(currentNode->m_left);
    }
    if(currentNode->getRight() != nullptr)
    {
      queue.enqueue(currentNode->m_right);
    }
  }
}

bool LeftistHeap::isEmpty()
{
  return m_root == nullptr;
}


void LeftistHeap::preOrder(LHNode* subtree)
{
  if (subtree == nullptr) {return;}

  std::cout<<subtree->m_value<<" ";
  preOrder(subtree->m_left);
  preOrder(subtree->m_right);

}

void LeftistHeap::inOrder(LHNode* subtree)
{
  if(subtree == nullptr) {return;}

  inOrder(subtree->m_left);
  std::cout<<subtree->m_value<<" ";
  inOrder(subtree->m_right);
}

void LeftistHeap::deleteTree(LHNode* subtree)
{
  if(subtree == nullptr) {return;}

  deleteTree(subtree->m_left);
  deleteTree(subtree->m_right);
  delete subtree;
}


LHNode* LeftistHeap::insert(int val, LHNode* subtree)
{
  return merge(subtree, new LHNode(val));
}

LHNode* LeftistHeap::minOfTree(LHNode* subtree)
{
  return m_root;
}
LHNode* LeftistHeap::merge(LHNode* h1, LHNode* h2)
{
  if(h1 == nullptr)
  {
    return h2;
  }
  else if(h2 == nullptr)
  {
    return h1;
  }
  else if (h1->m_value > h2->m_value)
  {
    swap(h1,h2);
  }
  h1->m_right = merge(h1->m_right, h2);
  h1->m_rank = h1->m_right->m_rank + 1;


  if(h1->m_left == nullptr)
  {
    h1->m_left = h1->m_right;
  }

  if(h1->m_left != nullptr && h1->m_right != nullptr)
  {
    if(h1->m_left->m_rank < h1->m_right->m_rank)
    {
      LHNode* temp = h1->m_left;
      h1->m_left=h1->m_right;
      h1->m_right=temp;
      //swap(h1->m_left, h1->m_right);
    }
  }

  return h1;
  // if(h1->getVal() > h2->getVal())
  // {
  //   swap(h1,h2);
  // }
  // if(h1->getRight() == nullptr)
  // {
  //   h1->setRight(h2);
  // }
  // else
  // {
  //   h1->setRight(merge(h1->getRight(), h2));
  // }
  // if(h1->getLeft()->getRank() < h1->getRight()->getRank())
  // {
  //   swap(h1->getLeft(),h1->getRight());
  // }
  // h1->setRank(h1->getRight()->getRank() + 1);
  // return h1;
}

void LeftistHeap::swap(LHNode* h1, LHNode* h2)
{
  LHNode* temp = h1;
  h1=h2;
  h2=temp;
}














//
