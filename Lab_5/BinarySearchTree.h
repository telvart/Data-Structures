
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <string>
#include <fstream>
#include <iostream>

#include "BSTNode.h"
#include "Queue.h"


template <typename T>
class BinarySearchTree
{
  public:

    BinarySearchTree();
    BinarySearchTree(std::string fileName);
    ~BinarySearchTree();
    void insert(T key);
    void removeVal(T key);
    void deleteMin();
    void deleteMax();
    BSTNode<T>* search(T key);
    void preOrder();
    void inOrder();
    void levelOrder();

  private:
    void insert(T key, BSTNode<T>* subtree);
    void removeVal(T key, BSTNode<T>* subtree);
    BSTNode<T>* search(T key, BSTNode<T>* subtree);
    void preOrder(BSTNode<T>* subtree);
    void inOrder(BSTNode<T>* subtree);
    void deleteTree(BSTNode<T>* subtree);
    void deleteMin(BSTNode<T>* subtree);
    void deleteMax(BSTNode<T>* subtree);

    BSTNode<T>* m_root;
    int m_entries;
};

#include "BinarySearchTree.hpp"
#endif
