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
    theHeap[m_entries+1]=value;
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
  std::cout<<"\nLevel Order:\n";
  for(int i = 1; i<=m_entries; i++)
  {
    std::cout<<theHeap[i]<<" ";

    if(i == currentMultiple + totalAbove)
    {
      std::cout<<"\n";
      totalAbove = i;
      currentLevel++;
      currentMultiple *= 2;
    }
  }
  std::cout<<"\n\n";
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

bool MinMaxHeap::onMinLevel(double index)
{
  return (int)floor(log(index)/log(2)) % 2 == 0;
}

int MinMaxHeap::parent(int index)
{
  return index/2;
}

int MinMaxHeap::child(int index, int childNum)
{
  return(2*index + childNum);
}

void MinMaxHeap::trickleDown(int index)
{
  if(onMinLevel(index))
  {
    trickleDownMin(index);
  }
  else
  {
    trickleDownMax(index);
  }
}

void MinMaxHeap::trickleDownMin(int index)
{

}

void MinMaxHeap::trickleDownMax(int index)
{

}

void MinMaxHeap::bubbleUp(int index)
{

}

void MinMaxHeap::bubbleUpMin(int index)
{

}

void MinMaxHeap::bubbleUpMax(int index)
{

}

int MinMaxHeap::minOfChildrenGrandChildren(int index)
{
  if(child(index,0) <= m_entries)
  {

  }
  return 1;
}

int MinMaxHeap::maxOfChildrenGrandChildren(int index)
{
  return 1;
}
