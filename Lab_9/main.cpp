
#include <iostream>
#include "BinomialQueue.h"

void printMenu()
{
  std::cout<<"Please choose one of the following commands:"
           <<"\n1) Insert"
           <<"\n2) Delete Min"
           <<"\n3) Level Order"
           <<"\n4) Exit\n";
}


int main(int argc, char** argv)
{
  int choice, value;
  BinomialQueue q = BinomialQueue("data.txt");
  do
  {
    printMenu();
    std::cin>>choice;
    switch(choice)
    {
      case 1:
        std::cout<<"Enter a value to insert:";
        std::cin>>value;
        q.insert(value);
        break;
      case 2:
        q.deleteMin();
        break;
      case 3:
        q.levelOrder();
        break;

    }
  } while(choice != 4);
}
