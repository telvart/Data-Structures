
#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>
class BSTNode
{
public:
  BSTNode();
  BSTNode(T value);
  void setValue(T value);
  void setLeft(BSTNode<T>* left);
  void setRight(BSTNode<T>* right);

  T getValue();
  BSTNode<T>* getLeft();
  BSTNode<T>* getRight();


private:
  T m_value;
  BSTNode<T>* m_left;
  BSTNode<T>* m_right;
};

#include "BSTNode.hpp"
#endif
