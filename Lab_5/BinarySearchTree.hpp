
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
  m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(std::string fileName)
{
  m_root = nullptr;
  std::ifstream fileIn(fileName);
  int value;
  std::cout<<"\ndata.txt elements: ";
  while(fileIn >> value)
  {
    std::cout<<value<<" ";
    this->insert(value);
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
    }
  }
  else if(key > subtree->getValue())
  {
    if(subtree->getRight() != nullptr)
    {
      insert(key,subtree->getRight());
    }
    else
    {
      BSTNode<T>* temp = new BSTNode<T>(key);
      subtree->setRight(temp);
    }

  }
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::search(T key)
{
  if(m_root == nullptr){return nullptr;}

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

}

template <typename T>
void BinarySearchTree<T>::removeVal(T key, BSTNode<T>* subtree)
{

}



template <typename T>
void BinarySearchTree<T>::deleteMin()
{
  deleteMin(m_root);
}

template <typename T>
void BinarySearchTree<T>::deleteMin(BSTNode<T>* subtree)
{
  if(subtree ->getLeft() != nullptr)
  {
    if(subtree->getLeft()->getLeft() != nullptr)
    {
      deleteMin(subtree->getLeft());
    }
    else
    {
      //TODO: reassign the right child if needed
      delete subtree->getLeft();
      subtree->setLeft(nullptr);
    }
  }
}

template <typename T>
void BinarySearchTree<T>::deleteMax()
{
  deleteMax(m_root);
}

template <typename T>
void BinarySearchTree<T>::deleteMax(BSTNode<T>* subtree)
{
  if(subtree->getRight() != nullptr)
  {
    if(subtree->getRight()->getRight() != nullptr)
    {
      deleteMax(subtree->getRight());
    }
    else
    {
      //TODO: reassign the left child if needed
      delete subtree->getRight();
      subtree->setRight(nullptr);
    }
  }
  else
  {
    m_root = subtree->getLeft();
    delete subtree;
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
  if(subtree == nullptr){return;}

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
  if(subtree == nullptr){return;}

  inOrder(subtree->getLeft());
  std::cout<<subtree->getValue()<<" ";
  inOrder(subtree->getRight());
}

template <typename T>
void BinarySearchTree<T>::levelOrder()
{
  Queue<T> queue = Queue<T>();
}














//
