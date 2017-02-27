
template <typename T>
Queue<T>::Queue()
{
  m_front=nullptr;
  m_rear=nullptr;
  m_size=0;
}

template <typename T>
Queue<T>::~Queue()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

template <typename T>
void Queue<T>::enqueue(T val)
{
  Node<T>* temp = new Node<T>(val);
  if(isEmpty())
  {
    m_front = temp;
    m_rear = temp;
  }
  else
  {
    m_rear->setNext(temp);
    temp->setPrev(m_rear);
    m_rear = temp;
  }
  m_size++;
}

template <typename T>
T Queue<T>::dequeue()
{
  if(isEmpty())
  {
    return nullptr;
  }
  else
  {
    if(m_size == 1)
    {
      m_size=0;
      Node<T>* temp = m_front;
      m_front=nullptr;
      m_rear=nullptr;
      return temp->getData();
    }
    else
    {
      Node<T>* temp = m_front;
      m_front = m_front->getNext();
      m_front->setPrev(nullptr);
      m_size--;
      return temp->getData();
    }
  }
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return m_front == nullptr;
}

template <typename T>
int Queue<T>::size()
{
  return m_size;
}
