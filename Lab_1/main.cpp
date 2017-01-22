#include <iostream>
#include "DoubleLinkedList.h"


void printMenu()
{
  std::cout<<"Please choose one of the following commands:\n"
           <<"1- insert\n"
           <<"2- delete\n"
           <<"3- reverse\n"
           <<"4- print\n"
           <<"5- exit\n\n";
}

int main()
{
  int choice;
  int value;
  DoubleLinkedList* DLL = new DoubleLinkedList();
  do
  {
    printMenu();
    std::cin >> choice;

    switch (choice)
    {
      case 1:
        std::cout<<"Enter a value to insert:\n";
        std::cin>>value;
        DLL->insert(value);
      case 4:
        DLL->print();
    }
  }while(choice != 5);
  return 0;
}
