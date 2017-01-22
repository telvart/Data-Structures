#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
  m_size = 0;
  m_front = nullptr;
  m_rear = nullptr;
}
DoubleLinkedList::~DoubleLinkedList()
{
  Node* temp;
  while(m_front != nullptr)
  {
    temp = m_front->getNext();
    delete m_front;
    m_front = temp;
  }
}
void DoubleLinkedList::insert(int num)
{
  if(isEmpty())
  {
    Node* temp = new Node(num);
    m_front = temp;
    m_rear = temp;
    m_size++;
    return;
  }
  insertRec(num, m_front);
}
//TODO FIX INSERTION WEIRD ERROR
void DoubleLinkedList::insertRec(int num, Node* start)
{
  if(start->getNext() == nullptr)
  {
    Node* temp = new Node(num);
    start->setNext(temp);
    m_rear = temp;
    m_size++;
    return;
  }
  insertRec(num,start->getNext());
}

void DoubleLinkedList::erase(int num)
{

}
void DoubleLinkedList::print()
{
  Node* temp = m_front;
  while(temp != nullptr)
  {
    std::cout<<temp->getData()<<" ";
  }
}
void DoubleLinkedList::reverse()
{

}

bool DoubleLinkedList::isEmpty()
{
  return m_front==nullptr && m_rear==nullptr;
}
