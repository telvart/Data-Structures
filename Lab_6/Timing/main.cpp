


#include <iostream>
#include "BinarySearchTree.h"
#include "MinKHeap.h"

int main(int argc, char** argv)
{
  MinKHeap<int> theHeap = MinKHeap<int>(3,200,"data.txt");
  BinarySearchTree<int> theTree = BinarySearchTree<int>("data.txt");
  std::cout<<"Hello world!\n";
}
