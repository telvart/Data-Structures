/**
*	@file: DoubleLinkedList.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: implementation of methods declared in DoubleLinkedList.h
*/

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
  m_size = 0;
  m_front = nullptr;
  m_rear = nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
  Node<T>* temp;
  while(m_front != nullptr)
  {
    temp = m_front->getNext();
    delete m_front;
    m_front = temp;
  }
}

template <typename T>
void DoubleLinkedList<T>::insert(T num)
{
  if(isEmpty())
  {
    Node<T>* temp = new Node<T>(num);
    m_front = temp;
    m_rear = temp;
    m_size++;
    return;
  }
  insertRec(num, m_front);
}

template <typename T>
void DoubleLinkedList<T>::insertRec(T num, Node<T>* start)
{
  // if(start->getData() == num)
  // {
  //   return;
  // }
  if(start == m_rear)// && start->getData() != num)
  {
    Node<T>* temp = new Node<T>(num);
    start->setNext(temp);
    temp->setPrev(start);
    m_rear = temp;
    m_size++;
    return;
  }
  insertRec(num,start->getNext());
}

template <typename T>
void DoubleLinkedList<T>::deletenode(T num)
{
  if(m_size == 1 && m_front->getData() == num)
  {
    delete m_front;
    m_size--;
    m_front=nullptr;
    m_rear=nullptr;
    return;
  }
  deleteRec(num, m_front);
}

template <typename T>
void DoubleLinkedList<T>::deleteRec(T num, Node<T>* start)
{
  if(start==nullptr)
  {
    std::cout<<"That value was not in the list";
    return;
  }

  if(start->getData() == num)
  {
    if(start == m_front)
    {
      Node<T>* temp = m_front;
      m_front = m_front->getNext();
      m_front->setPrev(nullptr);
      delete temp;
    }
    else if(start == m_rear)
    {
      Node<T>* temp = m_rear;
      m_rear = m_rear->getPrev();
      m_rear->setNext(nullptr);
      delete temp;
    }
    else
    {
      start->getPrev()->setNext(start->getNext());
      start->getNext()->setPrev(start->getPrev());
      delete start;
    }
    m_size--;
    return;
  }
  deleteRec(num, start->getNext());

}

template <typename T>
void DoubleLinkedList<T>::print()
{
  Node<T>* temp = m_front;
  std::cout<<"\n";
  while(temp != nullptr)
  {
    std::cout<<temp->getData()<<" ";
    temp = temp->getNext();
  }
  std::cout<<"\n";
  return;
}

template <typename T>
void DoubleLinkedList<T>::reverse()
{
  reverseRec(nullptr,m_front);
}

template <typename T>
void DoubleLinkedList<T>::reverseRec(Node<T>* prev, Node<T>* curr)
{
  if(curr != nullptr)
  {
    reverseRec(curr, curr->getNext());
    curr->setPrev(curr->getNext());
    curr->setNext(prev);
  }
  else
  {
    m_rear = m_front;
    m_front = prev;
  }
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
  return m_front==nullptr;
}

template <typename T>
T DoubleLinkedList<T>::peek()
{
  if(!isEmpty())
  {
    return m_front->getData();
  }
  return T();
}

template <typename T>
T DoubleLinkedList<T>::pop()
{
  if(!isEmpty())
  {
    T pop = peek();
    deletenode(m_front->getData());
    return pop;
  }
  return T();
}

template <typename T>
bool DoubleLinkedList<T>::search(T value)
{
  Node<T>* temp = m_front;
  while(temp != nullptr)
  {
    if(temp->getData == value)
    {
      return true;
    }
    temp=temp->getNext();
  }
  return false;
}
