
#include <iostream>
#include "LeftistHeap.h"


void printMenu()
{
  std::cout<<"\nPlease choose one of the following commands:\n"
           <<"1) Insert\n"
           <<"2) Delete Min\n"
           <<"3) preOrder\n"
           <<"4) inOrder\n"
           <<"5) levelOrder\n"
           <<"6) Exit\n\n";
}

int main(int argc, char** argv)
{
  int value, choice = 0;
  LeftistHeap heap = LeftistHeap("data.txt");

  do
  {
    printMenu();
    std::cin>>choice;

    if(choice == 1)
    {
      //std::cout<<"BLAHJ\n";
      //std::cout<<"Please enter a value to insert:\n";
      std::cin>>value;
      heap.insert(value);
    }
    else if(choice == 2)
    {
      heap.deleteMin();
    }
    else if(choice == 3)
    {
      heap.preOrder();
    }
    else if(choice == 4)
    {
      heap.inOrder();
    }
    else if(choice == 5)
    {
      heap.levelOrder();
    }
  }while(choice != 6);


  return 0;
}
