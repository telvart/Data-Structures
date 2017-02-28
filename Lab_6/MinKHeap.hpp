
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

  int currentMultiple = 1;
  int currentLevel = 0;
  int lastMultiple = 0;
  for(int i=0; i<m_entries; i++)
  {
    std::cout<<theHeap[i]<<" ";
    if(i == currentMultiple - lastMultiple - 1)
    {
      currentLevel++;
      lastMultiple = currentMultiple;
      currentMultiple = exp(m_k, currentLevel);
      std::cout<<"\n";
    }
  }
  // int numonlevel = exp(3,0);
  // for(int i=0; i<numonlevel; i++)
  // {
  //   std::cout<<theHeap[i]<<" ";
  // }
  // std::cout<<"\n";
  // numonlevel = exp(3,1);
  // for(int i=1; i<numonlevel+1; i++)
  // {
  //   std::cout<<theHeap[i]<<" ";
  // }
  // std::cout<<"\n";
  // numonlevel = exp(3,2);
  // for(int i=3; i<numonlevel+3; i++)
  // {
  //   std::cout<<theHeap[i]<<" ";
  // }

  // int temp=0;
  // int numonlevel =1;
  // for(int i=0; i<=5; i++)
  // {
  //   for(int j=1; j<=numonlevel; j++)
  //   {
  //     printChildren(temp);
  //     std::cout<<" ";
  //     temp +=1;
  //   }
  //   numonlevel += 2;
  //   std::cout<<"\n";
  // }

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
void MinKHeap<T>::swap(int index1, int index2)
{

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
  int returnVal=num;
  for(int i=1; i<power; i++)
  {
    returnVal *= returnVal;
  }
  return returnVal;
}








//
