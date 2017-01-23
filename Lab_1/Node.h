/**
*	@file: Node.h
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: Acts as a container for integers in a linked list structure
*/

#ifndef NODE_H
#define NODE_H

class Node
{

public:

  /* Constructor */
  Node(int value);

  /* @pre: Node exists
     @post: this->m_next will be set to the parameter */
  void setNext(Node* next);

  /* @pre: Node exists
     @post: this->m_prev will be set to the parameter */
  void setPrev(Node* prev);

  /* @pre: Node exists
     @post: this->m_dataContained will be set to the parameter */
  void setValue(int val);

  /* @return: the current value of this->m_dataContained */
  int getData();

  /* @return: the current address this->m_next is pointing at */
  Node* getNext();

  /* @return: the current address this->m_prev is pointing at */
  Node* getPrev();

private:

  //member variables
  int m_dataContained;
  Node* m_next;
  Node* m_prev;

};

#endif
