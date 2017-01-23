/**
*	@file: main.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.23
*	@brief: A program to interact with a DoubleLinkedList that was implemented recursively
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DoubleLinkedList.h"

/* @return a DLL structure populated with values from a .txt file named fileName */
DoubleLinkedList* createDLLfromFile(std::string fileName)
{
  std::ifstream fileIn(fileName);
  int numData = 11; //number of integers in data.txt
  int value;
  DoubleLinkedList* DLL = new DoubleLinkedList();

  for(int i=0; i<numData; i++)
  {
    fileIn>>value;
    DLL->insert(value);
  }

  fileIn.close();
  return DLL;
}

void printMenu()
{
  std::cout<<"\nPlease choose one of the following commands:\n"
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
  DoubleLinkedList* DLL = createDLLfromFile("data.txt");
  std::cout<<"\ndata.txt elements: ";
  DLL->print();
  std::cout<<"---------------------------------------------\n";

  do
  {
    printMenu();
    std::cin >> choice;
    if(choice == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>value;
      DLL->insert(value);
    }

    else if(choice == 2)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>value;
      DLL->deletenode(value);
    }

    else if(choice == 3)
    {
      DLL->reverse();
    }

    else if (choice == 4)
    {
      DLL->print();
    }

  }while(choice != 5);

  delete DLL;
  return 0;
}
