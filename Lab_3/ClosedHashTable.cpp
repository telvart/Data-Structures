#include "ClosedHashTable.h"


ClosedHashTable::ClosedHashTable(int m)
{
  m_buckets=m;
  m_entries=0;
  m_table = new Bucket[m];
}

ClosedHashTable::~ClosedHashTable()
{
  delete[] m_table;
}

void ClosedHashTable::insert(int key)
{

  int index = collisionResolution(hash(key),0);
  if(index >= 0)
  {
    m_table[index].setValue(key);
  }
}

void ClosedHashTable::deletenode(int key)
{
  deletenode(key, hash(key), 0);
}

bool ClosedHashTable::search(int key)
{

  return searchResolution(key, hash(key), 0);

}

void ClosedHashTable::print()
{
  std::cout<<"\n";
  for(int i=0; i<m_buckets; i++)
  {
    if(!m_table[i].isEmpty())
    {
      std::cout<<i<<": "<<m_table[i].value()<<"\n";
    }
    else
    {
      std::cout<<i<<": 0\n";
    }

  }
}

int ClosedHashTable::hash(int key)
{
  return key % m_buckets;
}

int ClosedHashTable::collisionResolution(int initialHash, int i)
{
  if(i > m_buckets)
  {
    return -1;
  }

  int newIndex = (initialHash + (i * i)) % m_buckets;
  if(m_table[newIndex].isEmpty())
  {
    return newIndex;
  }
  return collisionResolution(initialHash, i+1);

}

bool ClosedHashTable::searchResolution(int key, int initialHash, int i)
{
  if(i >= m_buckets)
  {
    return false;
  }
  int newIndex = (initialHash + (i * i)) % m_buckets;
  bool empty = m_table[newIndex].isEmpty();
  int val = m_table[newIndex].value();
  bool beenDeleted = m_table[newIndex].beenDeleted();

  if(empty)
  {
    if(beenDeleted)
    {
      return false;
    }
    else
    {
      return searchResolution(key,initialHash,i+1);
    }
  }
  else
  {
    if(val == key)
    {
      return true;
    }
    else
    {
      return searchResolution(key,initialHash,i+1);
    }
  }
}

void ClosedHashTable::deletenode(int key, int initialHash, int i)
{
  if ( i>= m_buckets)
  {
    return;
  }
  int newIndex = (initialHash + (i * i)) % m_buckets;
  bool empty = m_table[newIndex].isEmpty();
  int val = m_table[newIndex].value();
  bool beenDeleted = m_table[newIndex].beenDeleted();

  if(empty)
  {
    if(beenDeleted)
    {
      deletenode(key,initialHash,i+1);
    }
    else
    {
      return;
    }
  }
  else
  {
    if(val == key)
    {
      m_table[newIndex].removeVal();
    }
    else
    {
       deletenode(key,initialHash,i+1);
    }
  }

}

void ClosedHashTable::rehash()
{
  
}
































//
