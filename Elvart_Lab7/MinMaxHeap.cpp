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
    m_entries++;
    theHeap[m_entries]=value;
    std::cout<<value<<" ";
  }
  build();
  std::cout<<"\n\n";
}

MinMaxHeap::~MinMaxHeap()
{
  delete[] theHeap;
}

void MinMaxHeap::insert(int val)
{
  m_entries++;
  theHeap[m_entries] = val;
  bubbleUp(m_entries);
}

void MinMaxHeap::deletemin()
{
  if (m_entries == 0) {return;}
  else if (m_entries == 1) {m_entries--;}
  else if (m_entries == 2)
  {
    swap(1,2);
    m_entries--;
  }
  else
  {
    theHeap[1] = theHeap[m_entries];
    m_entries--;
    trickleDown(1);
  }
}

void MinMaxHeap::deletemax()
{
  if (m_entries == 0) {return;}
  else if (m_entries == 1) {m_entries--;}
  else if (m_entries == 2)
  {
    swap(1,2);
    m_entries--;
  }
  else
  {
    int max = maxOfChildrenGrandChildren(1,true);
    int secondMax = maxOfChildrenGrandChildren(max,true);
    std::cout<<secondMax<<"\n";
    theHeap[max]=theHeap[secondMax];
    theHeap[secondMax] = theHeap[m_entries];
    m_entries--;

    bubbleUp(secondMax);
  }

}

void MinMaxHeap::levelorder()
{
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
      currentMultiple *= 2;
    }
  }
  std::cout<<"\n\n";
}

bool MinMaxHeap::onMinLevel(double index)
{
  return (int)floor(log(index)/log(2)) % 2 == 0;
}

int MinMaxHeap::parent(int index)
{
  return index/2;
}

int MinMaxHeap::grandParent(int index)
{
  return index/4;
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
  int m = minOfChildrenGrandChildren(index);
  if(isGrandChild(index,m))
  {
    if(theHeap[m] < theHeap[index])
    {
        swap(index,m);
        if(theHeap[m] > theHeap[parent(m)])
        {
          swap(m,parent(m));
        }
        trickleDownMin(m);
    }
  }
  else
  {
    if(theHeap[m] < theHeap[index])
    {
      swap(m,index);
    }
  }

}

void MinMaxHeap::trickleDownMax(int index)
{
  int m = maxOfChildrenGrandChildren(index,false);
  if(isGrandChild(index, m))
  {
    if(theHeap[m] > theHeap[index])
    {
      swap(m,index);
      if(theHeap[m] < theHeap[parent(m)])
      {
        swap(m,parent(m));
      }
      trickleDownMax(m);
    }
  }
  else
  {
    if(theHeap[m] > theHeap[index])
    {
      swap(m,index);
    }
  }
}

void MinMaxHeap::bubbleUp(int index)
{
  int Parent = parent(index);
  if(onMinLevel(index))
  {
    if(index > 1 && theHeap[index] > theHeap[Parent])
    {
      swap(index, Parent);
      bubbleUpMax(Parent);
    }
    else
    {
      bubbleUpMin(index);
    }
  }
  else
  {
    if(index > 1 && theHeap[index] < theHeap[Parent])
    {
      swap(index, Parent);
      bubbleUpMin(Parent);
    }
    else
    {
      bubbleUpMax(index);
    }
  }
}

void MinMaxHeap::bubbleUpMin(int index)
{
  int grandparent = grandParent(index);
  if(grandparent > 0)
  {
    if(theHeap[index] < theHeap[grandparent])
    {
      swap(index, grandparent);
      bubbleUpMin(grandparent);
    }
  }
}

void MinMaxHeap::bubbleUpMax(int index)
{
  int grandparent = grandParent(index);
  if(grandparent > 0)
  {
    if(theHeap[index] > theHeap[grandparent])
    {
      swap(index, grandparent);
      bubbleUpMax(grandparent);
    }
  }
}

int MinMaxHeap::minOfChildrenGrandChildren(int index)
{
  int returnIndex = index;
  int minValue = theHeap[index];

  int firstChild = child(index,0);
  int secondChild= child(index,1);
  int firstGrand = child(child(index,0),0);
  int secondGrand= child(child(index,0),1);
  int thirdGrand = child(child(index,1),0);
  int fourthGrand= child(child(index,1),1);

  if(firstChild <= m_entries)
  {
    if(theHeap[firstChild] < minValue)
    {
      minValue = theHeap[firstChild];
      returnIndex = firstChild;
    }
    if(firstGrand <= m_entries)
    {
      if(theHeap[firstGrand] < minValue)
      {
        minValue = theHeap[firstGrand];
        returnIndex = firstGrand;
      }
    }
    if(secondGrand <= m_entries)
    {
      if(theHeap[secondGrand] < minValue)
      {
        minValue = theHeap[secondGrand];
        returnIndex = secondGrand;
      }
    }
  }
  if( secondChild <= m_entries)
  {
    if(theHeap[secondChild] < minValue)
    {
      minValue = theHeap[secondChild];
      returnIndex = secondChild;
    }
    if(thirdGrand <= m_entries)
    {
      if(theHeap[thirdGrand] < minValue)
      {
        minValue = theHeap[thirdGrand];
        returnIndex = thirdGrand;
      }
    }
    if(fourthGrand <= m_entries)
    {
      if(theHeap[fourthGrand] < minValue)
      {
        minValue = theHeap[fourthGrand];
        returnIndex = fourthGrand;
      }
    }
  }
  return returnIndex;
}

int MinMaxHeap::maxOfChildrenGrandChildren(int index, bool deleting)
{
  int returnIndex = index;
  int maxValue = theHeap[index];
  if(deleting)
  {
    returnIndex = child(index,0);
    maxValue = theHeap[returnIndex];
  }

  int firstChild = child(index,0);
  int secondChild= child(index,1);
  int firstGrand = child(child(index,0),0);
  int secondGrand= child(child(index,0),1);
  int thirdGrand = child(child(index,1),0);
  int fourthGrand= child(child(index,1),1);

  if(firstChild <= m_entries)
  {
    if(theHeap[firstChild] > maxValue)
    {
      maxValue = theHeap[firstChild];
      returnIndex = firstChild;
    }
    if(firstGrand <= m_entries)
    {
      if(theHeap[firstGrand > maxValue])
      {
        maxValue = theHeap[firstGrand];
        returnIndex = firstGrand;
      }
    }
    if(secondGrand <= m_entries)
    {
      if(theHeap[secondGrand] > maxValue)
      {
        maxValue = theHeap[secondGrand];
        returnIndex = secondGrand;
      }
    }
  }
  if( secondChild <= m_entries)
  {
    if(theHeap[secondChild] > maxValue)
    {
      maxValue = theHeap[secondChild];
      returnIndex = secondChild;
    }
    if(thirdGrand <= m_entries)
    {
      if(theHeap[thirdGrand] > maxValue)
      {
        maxValue = theHeap[thirdGrand];
        returnIndex = thirdGrand;
      }
    }
    if(fourthGrand <= m_entries)
    {
      if(theHeap[fourthGrand] > maxValue)
      {
        maxValue = theHeap[fourthGrand];
        returnIndex = fourthGrand;
      }
    }
  }
  return returnIndex;
}

void MinMaxHeap::swap(int index1, int index2)
{
    int temp = theHeap[index1];
    theHeap[index1]=theHeap[index2];
    theHeap[index2]=temp;
}

bool MinMaxHeap::isGrandChild(int index, int grandchild)
{
  int firstGrand = child(child(index,0),0);
  int secondGrand= child(child(index,0),1);
  int thirdGrand = child(child(index,1),0);
  int fourthGrand= child(child(index,1),1);

  if(grandchild == firstGrand || grandchild == secondGrand
     || grandchild == thirdGrand || grandchild == fourthGrand)
  {
    return true;
  }
  return false;
}

void MinMaxHeap::build()
{
  for(int i=parent(m_entries); i >0; i--)
  {
    trickleDown(i);
  }
}
