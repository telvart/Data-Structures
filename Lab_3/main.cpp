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
#include "ClosedDoubleHashTable.h"


void printMenu()
{
  std::cout<<"********************************************\n"
           <<"Please choose one of the following commands:\n"
           <<"1) insert\n"
           <<"2) delete\n"
           <<"3) print\n"
           <<"4) insert DHT\n"
           <<"5) delete DHT\n"
           <<"6) print DHT\n"
           <<"7) exit\n";
}

ClosedHashTable createClosedHashTableFromFile(std::string fileName)
{
  std::ifstream fileIn(fileName);
  int size;
  int value;
  fileIn>>size;
  ClosedHashTable t = ClosedHashTable(size);
  while(fileIn>>value)
  {
    t.insert(value);
  }
  fileIn.close();
  return t;
}

ClosedDoubleHashTable createClosedDoubleHashTableFromFile(std::string fileName)
{
  std::ifstream fileIn(fileName);
  int size;
  int value;
  fileIn>>size;
  ClosedDoubleHashTable t = ClosedDoubleHashTable(size);
  while(fileIn>>value)
  {
    t.insert(value);
  }
  fileIn.close();
  return t;
}




int main()
{
  //test1();
  int choice;
  int value;
  ClosedHashTable hashTable = createClosedHashTableFromFile("data.txt");
  ClosedDoubleHashTable doubleHashTable = createClosedDoubleHashTableFromFile("data.txt");
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
    else if(choice == 4)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      doubleHashTable.insert(value);
    }
    else if(choice == 5)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>value;
      doubleHashTable.deletenode(value);
    }
    else if(choice == 6)
    {
      doubleHashTable.print();
    }
  }while(choice != 7);
}
