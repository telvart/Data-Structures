/**
*	@file: Node.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: implementation of methods declared in Node.h
*/

template <typename T>
Node<T>::Node(T value)
{
  m_dataContained = value;
  m_next=nullptr;
  m_prev=nullptr;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  m_next = next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* prev)
{
  m_prev = prev;
}

template <typename T>
void Node<T>::setValue(T val)
{
  m_dataContained = val;
}

template <typename T>
int Node<T>::getData()
{
  return m_dataContained;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
  return m_next;
}

template <typename T>
Node<T>* Node<T>::getPrev()
{
  return m_prev;
}
