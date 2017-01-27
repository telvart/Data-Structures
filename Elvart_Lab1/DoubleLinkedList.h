/**
*	@file: DoubleLinkedList.h
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: A DoubleLinkedList data structure that holds integers and has recursive methods
*/

#ifndef DOUBLELiNKEDLIST_H
#define DOUBLELiNKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class DoubleLinkedList
{

public:

  /* Constructor */
  DoubleLinkedList();

  /* Destructor */
  ~DoubleLinkedList();

  /* @pre: DLL exists
     @post: num will be inserted at the end of the list, if the list does not already contain num */
  void insert(T num);

  /* @pre: DLL exists
     @post: num will be removed from the list if it exists within it */
  void deletenode(T num);

  /* @pre: DLL exists
     @post: Each value in the list will be printed to the command line followed by a space */
  void print();

  /*@pre: DLL exists
    @post: The DLL will be reversed in order */
  void reverse();

  /* @return true if the list is empty, false otherwise */
  bool isEmpty();

  /* @return the value at the front of the list, if list is empty, default constructor for T returned */
  T peek();

  /* @post the front node in the list will be removed
     @return the value at the front of the list, if list is empty, default constructor for T returned */
  T pop();

private:

  /* @post: this function is called to recursively insert to the DLL */
  void insertRec(T num, Node<T>* start);

  /* @post: this function is called to recursively delete from the DLL */
  void deleteRec(T num, Node<T>* start);

  /* @post: this function is called to recursively reverse the DLL's order */
  void reverseRec(Node<T>* prev, Node<T>* curr);

  //member variables
  int m_size;
  Node<T>* m_front;
  Node<T>* m_rear;
};

#include "DoubleLinkedList.hpp"
#endif
