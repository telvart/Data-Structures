
#include "MinKHeap.h"
#include "Test.h"
#include <iostream>


void printMenu()
{
  std::cout<<"\nPlease choose one of the following commands: "
           <<"\n1) Insert"
           <<"\n2) deleteMin"
           <<"\n3) deleteMax"
           <<"\n4) Remove"
           <<"\n5) Level Order"
           <<"\n6) Exit\n";
}

int main(int argc, char** argv)
{
  MinKHeap<int> theHeap = MinKHeap<int>(3, 200, "data.txt");
  Test tester;
  int choice;
  int value;

  do
  {
    printMenu();
    std::cin>> choice;
    if(choice == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      theHeap.insert(value);
    }
    else if(choice == 2)
    {
      theHeap.deleteMin();
    }
    else if(choice == 3)
    {
      theHeap.deleteMax();
    }
    else if(choice == 4)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>value;
      theHeap.remove(value);
    }
    else if(choice == 5)
    {
      //theHeap.levelOrder();
      //std::cin>>value;
      //std::cout<<"Parent of "<<value<<": "<<theHeap.parent(value)<<"\n";
      theHeap.levelOrder();
    }

  }while(choice != 6);
  std::cout<<"Exiting...\n";

  return 0;
}
