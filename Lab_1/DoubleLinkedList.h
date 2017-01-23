
#ifndef DOUBLELiNKEDLIST_H
#define DOUBLELiNKEDLIST_H

#include "Node.h"
#include <iostream>

class DoubleLinkedList
{

public:

  DoubleLinkedList();
  ~DoubleLinkedList();
  void insert(int num);
  void deletenode(int num);
  void print();
  void reverse();
  bool isEmpty();

private:

  void insertRec(int num, Node* start);
  void deleteRec(int num, Node* start);
  void insertBack(int num);


  int m_size;
  Node* m_front;
  Node* m_rear;
};

#endif
