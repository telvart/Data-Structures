
#include <iostream>
#include "ClosedHashTable.h"


void printMenu()
{
  std::cout<<"********************************************\n"
           <<"Please choose one of the following commands:\n"
           <<"1) insert\n"
           <<"2) delete\n"
           <<"3) print\n"
           <<"4) exit\n";
}


int main()
{
  int choice;
  int value;
  ClosedHashTable hashTable = ClosedHashTable(7);
  do
  {
    printMenu();
    std::cin>>choice;
    if(choice == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      hashTable.insert(value);
    }
    else if(choice == 2)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>value;
      hashTable.deletenode(value);
    }
    else if(choice == 3)
    {
      hashTable.print();
    }
  }while(choice != 4);
}
