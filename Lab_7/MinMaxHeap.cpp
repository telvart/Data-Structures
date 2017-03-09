#include "MinMaxHeap.h"

MinMaxHeap::MinMaxHeap(int arraySize)
{
  m_entries=0;
  m_arraySize=arraySize;
  theHeap = new int[arraySize];
}

MinMaxHeap::MinMaxHeap(int arraySize, std::string fileName)
{
  m_entries=0;
  m_arraySize=arraySize;
  theHeap=new int[arraySize];
  std::ifstream fileIn(fileName);
  int value;
  std::cout<<fileName<<" elements: ";
  while (fileIn>>value)
  {
    theHeap[m_entries]=value;
    std::cout<<value<<" ";
    m_entries++;
  }
  std::cout<<"\n**************************\n\n";
}

MinMaxHeap::~MinMaxHeap()
{
  delete[] theHeap;
}

void MinMaxHeap::insert(int val)
{

}

void MinMaxHeap::deletemin()
{

}

void MinMaxHeap::deletemax()
{

}

void MinMaxHeap::levelorder()
{
  int currentLevel=0;
  int currentMultiple=1;
  int totalAbove=0;
  for(int i = 0; i<m_entries; i++)
  {
    std::cout<<theHeap[i];

    if( i % 2 == 0 && i != currentMultiple + totalAbove - 1)
    {
      std::cout<<"-";
    }
    else
    {
      std::cout<<" ";
    }

    if(i == currentMultiple + totalAbove - 1)
    {
      std::cout<<"\n";
      totalAbove = i+1;
      currentLevel++;
      currentMultiple = exp(2, currentLevel);
    }

  }
  std::cout<<"\n";
}

int MinMaxHeap::exp(int num, int power)
{
  if(power == 0)
  {
    return 1;
  }
  int returnValue = num;
  for(int i=1; i < power; i++)
  {
    returnValue *= returnValue;
  }
  return returnValue;
}
