#include "LeftistHeap.h"

LeftistHeap::LeftistHeap()
{
  m_root = nullptr;
}

LeftistHeap::LeftistHeap(std::string fileName)
{
  std::ifstream fileIn(fileName);
  m_root = nullptr;
  int value;
  std::cout<<fileName<<" values: ";
  while(fileIn>>value)
  {
    std::cout<<value<<" ";
    insert(value);
  }
  fileIn.close();
}

LeftistHeap::~LeftistHeap()
{
  deleteTree(m_root);
}

void LeftistHeap::insert(int val)
{
  LHNode* temp = new LHNode(val);
  m_root = merge(m_root, temp);
}

void LeftistHeap::deleteMin()
{
  LHNode* oldRoot = m_root;
  m_root = merge(m_root->m_left, m_root->m_right);
  delete oldRoot;
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

  std::cout<<"\nLEVEL ORDER: \n\n";
  Queue<LHNode*> queue = Queue<LHNode*>();
  queue.enqueue(m_root);
  queue.enqueue(nullptr); //when this shows up, print new line and add to end of queue

  while(!queue.isEmpty())
  {
    LHNode* currentNode = queue.dequeue();
    if(currentNode == nullptr)
    {
      std::cout<<"\n";
      if(!queue.isEmpty())
      {
        currentNode = queue.dequeue();
        queue.enqueue(nullptr);
      }
      else {return;}
    }

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
  std::cout<<"\n";
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

LHNode* LeftistHeap::merge(LHNode* h1, LHNode* h2)
{
  if(h1 == nullptr) {return h2;}
  else if(h2 == nullptr) {return h1;}

  else if (h1->m_value > h2->m_value)
  {
    LHNode* temp = h1; //swaps h1 and h2, function was not working
    h1=h2;
    h2 = temp;
  }

  h1->m_right = merge(h1->m_right, h2);

  if(h1->m_left == nullptr)
  {
    h1->m_left = h1->m_right;
    h1->m_right = nullptr;
  }

  if(h1->m_left != nullptr && h1->m_right != nullptr)
  {
    if(h1->m_left->m_rank < h1->m_right->m_rank)
    {
      LHNode* temp = h1->m_left; //swaps the left and right child
      h1->m_left=h1->m_right;
      h1->m_right=temp;
    }
    h1->m_rank = h1->m_right->m_rank + 1;
  }
  return h1;
}
