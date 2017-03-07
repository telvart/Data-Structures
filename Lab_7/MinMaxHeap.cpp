#include "MinMaxHeap.h"

MinMaxHeap::MinMaxHeap(int arraySize)
{
  m_entries=0;
  m_arraySize=arraySize;
  theHeap = new int[arraySize];
}

MinMaxHeap::MinMaxHeap(int arraySize, std::string fileName)
{
  
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

}
