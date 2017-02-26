
template <typename T>
MinKHeap<T>::MinKHeap(int k, int size)
{
  m_k = k;
  m_arraySize = size;
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
  T value;
  int temp = 0;
  std::ifstream fileIn(fileName);
  std::cout<<"Data.txt elements: ";
  while(fileIn >> value)
  {
    theHeap[temp] = value;
    std::cout<<value<<" ";
    temp++;
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
  int temp=0;
  int numonlevel =1;
  for(int i=0; i<=5; i++)
  {
    for(int j=1; j<=numonlevel; j++)
    {
      printChildren(temp);
      std::cout<<" ";
      temp +=1;
    }
    numonlevel += 2;
    std::cout<<"\n";

  }
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








//
