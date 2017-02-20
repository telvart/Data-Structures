
#include <iostream>
#include "BinarySearchTree.h"

void printMenu()
{
  std::cout<<"****************************\n"
           <<"Please choose one of the following commands:\n"
           <<"1) Insert\n"
           <<"2) Remove\n"
           <<"3) deleteMin\n"
           <<"4) deleteMax\n"
           <<"5) preOrder\n"
           <<"6) inOrder\n"
           <<"7) levelOrder\n"
           <<"8) Exit\n";
}


int main(int argc, char** argv)
{
  BinarySearchTree<int> BST = BinarySearchTree<int>("data.txt");

  int choice, value = 0;

  do
  {
    printMenu();
    std::cin>>choice;
    if(choice == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      BST.insert(value);
    }
    else if(choice == 2)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>value;
      BST.removeVal(value);
    }
    else if(choice == 3)
    {
      BST.deleteMin();
    }
    else if(choice == 4)
    {
      BST.deleteMax();
    }
    else if(choice == 5)
    {
      std::cout<<"PRE-ORDER: ";
      BST.preOrder();
      std::cout<<"\n";
    }
    else if(choice == 6)
    {
      std::cout<<"IN-ORDER: ";
      BST.inOrder();
      std::cout<<"\n";
    }
    else if(choice == 7)
    {
      std::cout<<"LEVEL-ORDER: ";
      BST.levelOrder();
      std::cout<<"\n";
    }


  }while(choice != 8);
  std::cout<<"Exiting...\n";

}
