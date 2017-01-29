
#include <iostream>
#include "OpenHashTable.h"
#include <unistd.h>


void printMenu()
{
  std::cout<<"Please choose one of the following commands:\n"
           <<"1) Insert to hash table\n"
           <<"2) Delete from hash table\n"
           <<"3) Find in hash table\n"
           <<"4) Print the table\n"
           <<"5) Exit\n";
}

int main()
{
  std::cout<<"Hello world!\r"<<std::flush;
  usleep(1000000);
  std::cout<<"How are you doing today?\r"<<std::flush;
  usleep(1000000);
  std::cout<<"Pretty good thank you for asking\r"<<std::flush;
  usleep(1000000);
  std::cout<<"Have a good day!\r\n"<<std::flush;

  for(int i=0; i<1000000; i++)
  {
    std::cout<<i<<"/1000000\r"<<std::flush;
  }


  std::cout<<"Exiting...\n";
/*  int choice;
  int value;

  OpenHashTable* hashTable = new OpenHashTable(29);

  do
  {
    printMenu();
    std::cin>>choice;

    if(choice == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      hashTable->insert(value);
    }
    else if(choice == 2)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>value;
      hashTable->deleteVal(value);
    }
    else if(choice == 3)
    {
      std::cout<<"Enter a value to search for:\n";
      std::cin>>value;
      if (hashTable->find(value))
      {
        std::cout<<value<<" was in the table!\n";

      }
      else
      {
        std::cout<<value<<" was not in the table!\n";
      }
    }
    else if(choice == 4)
    {
      hashTable->printTable();
    }

  }while(choice != 5);

  delete hashTable;*/
  return 0;
}
