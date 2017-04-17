
template <typename T>
MinKHeap<T>::MinKHeap(int k, int size)
{
  m_k = k;
  m_arraySize = size;
  m_entries=0;
  theHeap = new T[size];
  for(int i=0; i<size; i++)
  {
    theHeap[i] = T();
  }
}

template <typename T>
MinKHeap<T>::MinKHeap(int k, int size, std::string fileName)
{
  m_k = k;
  m_arraySize = size;
  theHeap = new T[size];
  m_entries=0;
  T value;
  int temp = 0;
  std::ifstream fileIn(fileName);
  std::cout<<"\n"<<fileName<<" elements: ";
  while(fileIn >> value)
  {
    theHeap[temp] = value;
    std::cout<<value<<" ";
    temp++;
    m_entries++;
  }
  for(int i=temp; i<size; i++)
  {
    theHeap[i] = T();
  }
  std::cout<<"\n***************************"<<std::endl;
  buildHeapify();
}

template <typename T>
MinKHeap<T>::~MinKHeap()
{
  delete[] theHeap;
}

template <typename T>
void MinKHeap<T>::insert(T val)
{
  if(m_entries == m_arraySize)
  {
    return;
  }
  m_entries++;
  theHeap[m_entries-1] = val;
  upHeap(m_entries-1);


}

template <typename T>
void MinKHeap<T>::upHeap(int index)
{
  int parentIndex;
  if(index != 0)
  {
    parentIndex = parent(index);
    if(theHeap[parentIndex] > theHeap[index])
    {
      swap(parentIndex, index);
      upHeap(parentIndex);
    }
  }
}

template <typename T>
void MinKHeap<T>::deleteMin()
{
  theHeap[0]=theHeap[m_entries-1];
  theHeap[m_entries-1]=T();
  m_entries--;
  heapify(0);
}

template <typename T>
void MinKHeap<T>::deleteMax()
{
  int maxIndex = findMax();
  theHeap[maxIndex] = theHeap[m_entries-1];
  theHeap[m_entries-1]=T();
  m_entries--;
  heapify(maxIndex);
}

template <typename T>
void MinKHeap<T>::removeVal(T val)
{
  int index=-1;
  for(int i=0; i<m_entries; i++)
  {
    if(theHeap[i] == val)
    {
      index = i;
      break;
    }
  }
  if(index != -1)
  {
    std::cout<<val<<" was found at index "<<index<<"\n";
    theHeap[index]=theHeap[m_entries-1];
    theHeap[m_entries-1]=T();
    m_entries--;
    heapify(index);
    removeVal(val);
  }
  else
  {
    std::cout<<val<<" was not found\n";
  }
}

template <typename T>
void MinKHeap<T>::levelOrder()
{
  std::cout<<"\nLevel Order:\n\n";
  int currentLevel = 0;
  int currentMultiple = 1;
  int totalAbove = 0;
  for(int i=0; i<m_entries; i++)
  {
    std::cout<<theHeap[i];
    if(i%m_k == 0 && i != currentMultiple+totalAbove-1  && i != m_entries-1)
    {
      std::cout<<" - ";
    }
    else
    {
      std::cout<<" ";
    }
    if(i == currentMultiple + totalAbove -1)
    {
      std::cout<<"\n";
      totalAbove = i+1;
      currentLevel++;
      currentMultiple = exp(m_k, currentLevel);
    }
  }
  std::cout<<"\n\n";
}

template <typename T>
int MinKHeap<T>::parent(int index)
{
  return floor((index - 1) / m_k);
}

template <typename T>
int MinKHeap<T>::child(int parent, int childNum)
{
  return (m_k*parent + childNum);
}

template <typename T>
void MinKHeap<T>::buildHeapify()
{
  int firstChecked = parent(m_entries-1);

  for(int i = firstChecked; i>=0; i--)
  {
    heapify(i);
  }
}

template <typename T>
void MinKHeap<T>::heapify(int index)
{
  int lowestChild=0;
  T lowestVal = theHeap[index];
  for(int i=1; i<=m_k; i++)
  {
    if(child(index,i) < m_entries)
    {
      T cur = theHeap[child(index,i)];
      if(cur < lowestVal)
      {
        lowestVal = cur;
        lowestChild = i;
      }
    }
  }
  if(lowestChild != 0)
  {
    swap(child(index,lowestChild), index);
    heapify(child(index, lowestChild));
  }
}

template <typename T>
void MinKHeap<T>::swap(int index1, int index2)
{
  T temp = theHeap[index1];
  theHeap[index1] = theHeap[index2];
  theHeap[index2] = temp;
}

template <typename T>
int MinKHeap<T>::exp(int num, int power)
{
  if(power == 0)
  {
    return 1;
  }
  int returnVal=num;
  for(int i=1; i<power; i++)
  {
    returnVal *= returnVal;
  }
  return returnVal;
}

template <typename T>
int MinKHeap<T>::findMax()
{
  int firstLeaf = floor(((m_entries - 2) / m_k) + 1);
  T max = theHeap[firstLeaf];
  int index = firstLeaf;
  for(int i=firstLeaf; i<m_entries; i++)
  {
    if(theHeap[i] > max)
    {
      max = theHeap[i];
      index = i;
    }
  }
  return index;
}
