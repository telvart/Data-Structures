
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
  m_root = nullptr;
  m_entries = 0;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(std::string fileName)
{
  m_root = nullptr;
  m_entries = 0;
  std::ifstream fileIn(fileName);
  T value;
  std::cout<<"\ndata.txt elements: ";
  while(fileIn >> value)
  {
    std::cout<<value<<" ";
    insert(value);
  }
  std::cout<<std::endl;
  fileIn.close();
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteTree(m_root);
}

template <typename T>
void BinarySearchTree<T>::insert(T key)
{
  if (m_root == nullptr)
  {
    BSTNode<T>* temp = new BSTNode<T>(key);
    m_root = temp;
    m_entries++;
    return;
  }
  insert(key,m_root);
}

template<typename T>
void BinarySearchTree<T>::insert(T key, BSTNode<T>* subtree)
{
  if(key == subtree->getValue()) {return;}

  if(key < subtree->getValue())
  {
    if(subtree->getLeft() != nullptr)
    {
      insert(key,subtree->getLeft());
    }
    else
    {
      BSTNode<T>* temp = new BSTNode<T>(key);
      subtree->setLeft(temp);
      m_entries++;
      return;
    }
  }
  else// if(key >= subtree->getValue())
  {
    if(subtree->getRight() != nullptr)
    {
      insert(key,subtree->getRight());
    }
    else
    {
      BSTNode<T>* temp = new BSTNode<T>(key);
      subtree->setRight(temp);
      m_entries++;
      return;
    }
  }
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::search(T key)
{
  if(m_root == nullptr) {return nullptr;}

  return search(key, m_root);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::search(T key, BSTNode<T>* subtree)
{
  if(subtree != nullptr)
  {
    if(key == subtree->getValue())
    {
      return subtree;
    }
    else if(key < subtree->getValue())
    {
      return search(key, subtree->getLeft());
    }
    else if(key > subtree->getValue())
    {
      return search(key, subtree->getRight());
    }
  }
  return nullptr;
}

template <typename T>
void BinarySearchTree<T>::removeVal(T key)
{
  if(m_root == nullptr) {return;}

  m_root =removeVal(key, m_root);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::removeVal(T key, BSTNode<T>* subtree)
{
  if(key < subtree->getValue())
  {
    subtree->setLeft(removeVal(key, subtree->getLeft()));
  }
  else if(key > subtree->getValue())
  {
    subtree->setRight(removeVal(key, subtree->getRight()));
  }
  else
  {
    if(subtree->getLeft() == nullptr)
    {
      BSTNode<T>* temp = subtree->getRight();
      delete subtree;
      m_entries--;
      return temp;
    }
    else if(subtree->getRight() == nullptr)
    {
      BSTNode<T>* temp = subtree->getLeft();
      delete subtree;
      m_entries--;
      return temp;
    }

    BSTNode<T>* temp = findMin(subtree->getRight());
    subtree->setValue(temp->getValue());
    subtree->setRight(removeVal(temp->getValue(), subtree->getRight()));
  }
  return subtree;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::findMin(BSTNode<T>* subtree)
{
  BSTNode<T>* current = subtree;
  while(current->getLeft() != nullptr)
  {
    current = current->getLeft();
  }
  return current;
}

template <typename T>
void BinarySearchTree<T>::deleteMin()
{
  if(m_root == nullptr) {return;}

  deleteMin(m_root);
}

template <typename T>
void BinarySearchTree<T>::deleteMin(BSTNode<T>* subtree)
{
  if(subtree == m_root && m_root->getLeft() == nullptr)
  {
    BSTNode<T>* temp = subtree;
    m_root = subtree->getRight();
    delete temp;
    m_entries--;
    return;
  }
  if(subtree->getLeft() != nullptr)
  {
    if(subtree->getLeft()->getLeft() != nullptr)
    {
      deleteMin(subtree->getLeft());
    }
    else
    {
      if(subtree->getLeft()->getRight() != nullptr)
      {
        BSTNode<T>* temp = subtree->getLeft();
        subtree->setLeft(subtree->getLeft()->getRight());
        m_entries--;
        delete temp;
      }
      else
      {
        delete subtree->getLeft();
        subtree->setLeft(nullptr);
        m_entries--;
      }
    }
  }
}

template <typename T>
void BinarySearchTree<T>::deleteMax()
{
  if(m_root == nullptr) {return;}

  deleteMax(m_root);
}

template <typename T>
void BinarySearchTree<T>::deleteMax(BSTNode<T>* subtree)
{
  if(subtree == m_root && subtree->getRight() == nullptr)
  {
    BSTNode<T>* temp = subtree;
    m_root = subtree->getLeft();
    m_entries--;
    delete temp;
    return;
  }
  if(subtree->getRight() != nullptr)
  {
    if(subtree->getRight()->getRight() != nullptr)
    {
      deleteMax(subtree->getRight());
    }
    else
    {
      if(subtree->getRight()->getLeft() != nullptr)
      {
        BSTNode<T>* temp = subtree->getRight();
        subtree->setRight(subtree->getRight()->getLeft());
        m_entries--;
        delete temp;
      }
      else
      {
        m_entries--;
        delete subtree->getRight();
        subtree->setRight(nullptr);
      }
    }
  }
}

template <typename T>
void BinarySearchTree<T>::deleteTree(BSTNode<T>* subtree)
{
  if(subtree != nullptr)
  {
    deleteTree(subtree->getLeft());
    deleteTree(subtree->getRight());
    delete subtree;
  }
}

template <typename T>
void BinarySearchTree<T>::preOrder()
{
  preOrder(m_root);
}

template <typename T>
void BinarySearchTree<T>::preOrder(BSTNode<T>* subtree)
{
  if(subtree == nullptr) {return;}

  std::cout<<subtree->getValue()<<" ";
  preOrder(subtree->getLeft());
  preOrder(subtree->getRight());
}

template <typename T>
void BinarySearchTree<T>::inOrder()
{
  inOrder(m_root);
}

template <typename T>
void BinarySearchTree<T>::inOrder(BSTNode<T>* subtree)
{
  if(subtree == nullptr) {return;}

  inOrder(subtree->getLeft());
  std::cout<<subtree->getValue()<<" ";
  inOrder(subtree->getRight());
}

template <typename T>
void BinarySearchTree<T>::levelOrder()
{
  if(m_root == nullptr) {return;}

  Queue<BSTNode<T>*> queue = Queue<BSTNode<T>*>();
  queue.enqueue(m_root);

  while(!queue.isEmpty())
  {
    BSTNode<T>* currentNode = queue.dequeue();
    std::cout<<currentNode->getValue()<<" ";

    if(currentNode->getLeft() != nullptr)
    {
      queue.enqueue(currentNode->getLeft());
    }
    if(currentNode->getRight() != nullptr)
    {
      queue.enqueue(currentNode->getRight());
    }
  }
  std::cout<<std::endl;
}
