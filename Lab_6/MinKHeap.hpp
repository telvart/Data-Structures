
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
  std::cout<<"Data.txt elements: ";
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
  heapify();
  std::cout<<"\n***************************"<<std::endl;
}

template <typename T>
MinKHeap<T>::~MinKHeap()
{
  delete[] theHeap;
}

template <typename T>
void MinKHeap<T>::insert(T val)
{
  for(int i=1; i<=3; i++)
  {
    std::cout<<"Child "<<i<<" of "<<val<<": "<<child(val,i)<<"\n";
  }
}

template <typename T>
void MinKHeap<T>::deleteMin()
{

}

template <typename T>
void MinKHeap<T>::deleteMax()
{

}

template <typename T>
void MinKHeap<T>::remove(T val)
{

}

template <typename T>
void MinKHeap<T>::levelOrder()
{

  // int currentPower = 0;
  // int currentMultiple = 0;
  // int entries = 0;
  // for(int i=0; i<m_entries; i++)
  // {
    std::cout<<theHeap[0]<<"\n";
    for(int i=1; i<4; i++)
    {
      std::cout<<theHeap[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=4; i<13; i++)
    {
      std::cout<<theHeap[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=13; i<m_entries; i++)
    {
      std::cout<<theHeap[i]<<" ";
    }



  //}
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
void MinKHeap<T>::heapify()
{
  int firstChecked = floor(m_entries/m_k) - 1;
  std::cout<<"FIRST: "<<firstChecked<<"\n";
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
    T cur = theHeap[child(index,i)];
    if(cur < lowestVal)
    {
      lowestVal = cur;
      lowestChild = i;
    }
  }

  if(lowestChild != 0)
  {
    swap(child(index,lowestChild), index);
  }


  //std::cout<<index<<"\n";
  // T lowest = theHeap[index];
  // int lowestChild=1;
  // for(int i=1; i<=m_k; i++)
  // {
  //
  // }
  // if (lowest != theHeap[index])
  // {
  //   swap(index, child(index,lowest));
  // }


  // for(int j=0; j<m_entries; j++)
  // {
  //   for(int i=m_entries-1; i>=0; i--)
  //   {
  //     if(theHeap[parent(i)] > theHeap[i])
  //     {
  //       swap(i, parent(i));
  //     }
  //   }
  // }
}

template <typename T>
void MinKHeap<T>::swap(int index1, int index2)
{
  T temp = theHeap[index1];
  theHeap[index1] = theHeap[index2];
  theHeap[index2] = temp;
}

template <typename T>
void MinKHeap<T>::printChildren(int parent)
{
  for(int i=0; i<m_k; i++)
  {

      std::cout<<theHeap[child(parent,i)]<<" ";


  }
}

template <typename T>
int MinKHeap<T>::exp(int num, int power)
{
  if(power == 0)
  {
    return 1;
  }
  if(power <0 )
  {
    return 0;
  }
  int returnVal=num;
  for(int i=1; i<power; i++)
  {
    returnVal *= returnVal;
  }
  return returnVal;
}








//
