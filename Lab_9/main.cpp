
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
  //
  // BNode* temp1=new BNode(3);
  // temp1->m_firstChild = new BNode(4);
  // temp1->m_firstChild->m_right = new BNode(8);
  // temp1->m_firstChild->m_firstChild = new BNode(6);
  // temp1->m_left=temp1;
  // temp1->m_firstChild->m_left = temp1->m_firstChild->m_right;
  // temp1->m_firstChild->m_right->m_left = temp1->m_firstChild;
  // temp1->m_firstChild->m_firstChild->m_left = temp1->m_firstChild->m_firstChild;
  // temp1->m_order = 2;
  // temp1->m_firstChild->m_order = 1;
  //
  // BNode* temp2=new BNode(3);
  // temp2->m_firstChild = new BNode(4);
  // temp2->m_firstChild->m_right = new BNode(8);
  // temp2->m_firstChild->m_firstChild = new BNode(6);
  // temp2->m_left=temp2;
  // temp2->m_firstChild->m_left = temp2->m_firstChild->m_right;
  // temp2->m_firstChild->m_right->m_left = temp2->m_firstChild;
  // temp2->m_firstChild->m_firstChild->m_left = temp2->m_firstChild->m_firstChild;
  // temp2->m_order = 2;
  // temp2->m_firstChild->m_order = 1;


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
