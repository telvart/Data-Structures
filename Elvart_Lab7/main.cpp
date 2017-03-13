
#include <iostream>
#include "MinMaxHeap.h"

void printMenu()
{
    std::cout<<"********************************************\n"
             <<"Please choose one of the following commands:\n"
             <<"1) Insert\n"
             <<"2) Delete Min\n"
             <<"3) Delete Max\n"
             <<"4) Level Order\n"
             <<"5) Exit\n";
}

int main()
{
  int value, choice = 0;
  MinMaxHeap heap = MinMaxHeap(200, "data.txt");

  do
  {
    printMenu();
    std::cin>>choice;
    if(choice == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      heap.insert(value);
    }
    else if(choice == 2)
    {
      heap.deletemin();
    }
    else if(choice == 3)
    {
      heap.deletemax();
    }
    else if(choice == 4)
    {
      heap.levelorder();
    }
  }while(choice != 5);
  return 0;
}
