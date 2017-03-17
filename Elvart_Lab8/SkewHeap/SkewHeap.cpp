#include "SkewHeap.h"

SkewHeap::SkewHeap(std::string fileName)
{
  m_root = nullptr;
  std::ifstream fileIn(fileName);
  int value;
  std::cout<<fileName<<" elements:\n";
  while(fileIn>>value)
  {
    std::cout<<value<<" ";
    insert(value);
  }
  fileIn.close();
  std::cout<<"\n";
}

SkewHeap::~SkewHeap()
{
  deleteTree(m_root);
}

void SkewHeap::insert(int val)
{
  SHNode* temp = new SHNode(val);
  m_root = merge(m_root, temp);
}

void SkewHeap::deleteMin()
{
  if(m_root == nullptr) {return;}
  
  SHNode* oldRoot = m_root;
  m_root = merge(m_root->m_left, m_root->m_right);
  delete oldRoot;
}

void SkewHeap::preOrder()
{
  std::cout<<"PRE ORDER: ";
  preOrder(m_root);
  std::cout<<"\n";
}

void SkewHeap::inOrder()
{
  std::cout<<"IN ORDER: ";
  inOrder(m_root);
  std::cout<<"\n";
}
void SkewHeap::levelOrder()
{
  if (m_root == nullptr) {return;}

  std::cout<<"\nLEVEL ORDER:\n\n";
  Queue<SHNode*> queue = Queue<SHNode*>();
  queue.enqueue(m_root);
  queue.enqueue(nullptr);

  while(!queue.isEmpty())
  {
    SHNode* currentNode = queue.dequeue();
    if(currentNode == nullptr)
    {
      std::cout<<"\n";
      if(!queue.isEmpty())
      {
        currentNode=queue.dequeue();
        queue.enqueue(nullptr);
      }
      else {return;}
    }

    std::cout<<currentNode->m_val<<" ";

    if(currentNode->m_left != nullptr)
    {
      queue.enqueue(currentNode->m_left);
    }
    if(currentNode->m_right != nullptr)
    {
      queue.enqueue(currentNode->m_right);
    }
  }
  std::cout<<"\n";
}

bool SkewHeap::isEmpty()
{
  return m_root == nullptr;
}

SHNode* SkewHeap::merge(SHNode* h1, SHNode* h2)
{
  if(h1 == nullptr) {return h2;}
  else if(h2 == nullptr) {return h1;}
  else
  {
    if(h1->m_val > h2->m_val)
    {
      SHNode* temp = h1;
      h1 = h2;
      h2 = temp;
    }
    SHNode* temp = h1->m_right;
    h1->m_right = h1->m_left;
    h1->m_left = merge(temp,h2);
  }
  return h1;
}

void SkewHeap::preOrder(SHNode* subtree)
{
  if(subtree == nullptr) {return;}

  std::cout<<subtree->m_val<<" ";
  preOrder(subtree->m_left);
  preOrder(subtree->m_right);
}

void SkewHeap::inOrder(SHNode* subtree)
{
  if(subtree == nullptr) {return;}

  inOrder(subtree->m_left);
  std::cout<<subtree->m_val<<" ";
  inOrder(subtree->m_right);
}

void SkewHeap::deleteTree(SHNode* subtree)
{
  if(subtree == nullptr) {return;}

  deleteTree(subtree->m_left);
  deleteTree(subtree->m_right);
  delete subtree;
}
