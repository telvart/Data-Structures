/**
*	@file: main.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.2.1
*	@brief: A program to interact with a ClosedHashTable for integers
*/

#include <iostream>
#include <fstream>
#include <string>
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


ClosedHashTable createClosedHashTableFromFile(std::string fileName)
{
  int choice;
  int size;
  int value;

  std::cout<<"Please choose one of the following hash methods:\n"
           <<"1) Quadratic Probing\n"
           <<"2) Double Hashing\n"
           <<"3) Exit\n";
  std::cin>>choice;

  std::ifstream fileIn(fileName);
  fileIn>>size;
  ClosedHashTable t = ClosedHashTable(size);

  switch(choice)
  {
    case 1:
      t.setQuadraticProbing();
      break;
    case 2:
      t.setDoubleHashing();
      break;
    case 3:
      std::cout<<"\nExiting\n";
      exit(1);
      break;
  }

  while(fileIn>>value)
  {
    t.insert(value);
  }
  fileIn.close();
  return t;
}


int main()
{
  int choice;
  int value;

  ClosedHashTable hashTable = createClosedHashTableFromFile("data.txt");

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
