/**
*	@file: main.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.31
*	@brief: A program to interact with an OpenHashTable for integers
*/
#include <iostream>
#include <fstream>
#include <string>
#include "OpenHashTable.h"

OpenHashTable* createHashFromFile(std::string fileName)
{
  std::ifstream fileIn(fileName);
  int size;
  int value;
  fileIn>>size;
  OpenHashTable* t = new OpenHashTable(size);
  while(fileIn >> value)
  {
    t->insert(value);
  }
  fileIn.close();
  return t;

}

void printMenu()
{
  std::cout<<"********************************************\n"
           <<"Please choose one of the following commands:\n"
           <<"1) insert \n"
           <<"2) delete \n"
           <<"3) print the table\n"
           <<"4) exit\n";
}

int main()
{

  int choice;
  int value;

  OpenHashTable* hashTable = createHashFromFile("data.txt");

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
      hashTable->printTable();
    }

  }while(choice != 4);

  delete hashTable;
  return 0;
}
