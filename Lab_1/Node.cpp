/**
*	@file: Node.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: implementation of methods declared in Node.h
*/

#include "Node.h"

Node::Node(int value)
{
  m_dataContained = value;
  m_next=nullptr;
  m_prev=nullptr;
}

void Node::setNext(Node* next)
{
  m_next = next;
}

void Node::setPrev(Node* prev)
{
  m_prev = prev;
}
void Node::setValue(int val)
{
  m_dataContained = val;
}
int Node::getData()
{
  return m_dataContained;
}
Node* Node::getNext()
{
  return m_next;
}
Node* Node::getPrev()
{
  return m_prev;
}
