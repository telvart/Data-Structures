
template <typename T>
BSTNode<T>::BSTNode()
{
  m_left = nullptr;
  m_right = nullptr;
  m_value = T();
}

template <typename T>
BSTNode<T>::BSTNode(T value)
{
  m_left = nullptr;
  m_right = nullptr;
  m_value = value;
}

template <typename T>
void BSTNode<T>::setValue(T value)
{
  m_value = value;
}

template <typename T>
void BSTNode<T>::setLeft(BSTNode<T>* left)
{
  m_left = left;
}

template <typename T>
void BSTNode<T>::setRight(BSTNode<T>* right)
{
  m_right = right;
}

template <typename T>
T BSTNode<T>::getValue()
{
  return m_value;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getLeft()
{
  return m_left;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getRight()
{
  return m_right;
}
