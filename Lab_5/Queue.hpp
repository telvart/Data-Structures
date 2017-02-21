
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
    dequeue(m_front->getData());
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
Node<T>* Queue<T>::dequeue(T val)
{
  return new Node<T>(val);
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return m_front == nullptr;
}

template <typename T>
void Queue<T>::size()
{
  return m_size;
}
