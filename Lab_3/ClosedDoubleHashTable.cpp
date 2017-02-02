#include "ClosedDoubleHashTable.h"
#include <iostream>

ClosedDoubleHashTable::ClosedDoubleHashTable(int m)
{
  m_table = new Bucket[m];
  m_entries = 0;
  m_buckets = m;
}
ClosedDoubleHashTable::~ClosedDoubleHashTable()
{
  delete[] m_table;
}

void ClosedDoubleHashTable::insert(int key)
{
  int index = collisionResolution(key, 0);

  if(index >= 0)
  {
    m_table[index].setValue(key);
    m_entries++;
  }
}
void ClosedDoubleHashTable::deletenode(int key)
{
  deletenode(key, 0);
}
bool ClosedDoubleHashTable::search(int key)
{
  return search(key, 0);
}
void ClosedDoubleHashTable::print()
{
  for(int i=0; i<m_buckets; i++)
  {
    if(!m_table[i].isEmpty())
    {
      std::cout<<i<<": "<<m_table[i].value()<<"\n";
    }
    else
    {
      std::cout<<i<<": -1\n";
    }
  }
}

int ClosedDoubleHashTable::hash(int key)
{
  return key % m_buckets;
}
int ClosedDoubleHashTable::hashPlus(int key, int p)
{
  return p - (key % p);
}

int ClosedDoubleHashTable::collisionResolution(int key, int i)
{

  int newIndex = (hash(key) + (i * hashPlus(key, 5))) % m_buckets;

  if(m_table[newIndex].isEmpty())
  {
    return newIndex;
  }
  return collisionResolution(key, i+1);

}

//TODO: needs work, segfault was caused
void ClosedDoubleHashTable::deletenode(int key, int i)
{
  int index = (hash(key) + (i * hashPlus(key, 5))) % m_buckets;

  if(m_table[index].isEmpty())
  {
    if(m_table[index].beenDeleted())
    {
      deletenode(key, i+1);
    }
    else
    {
      return;
    }

  }
  else
  {
    if(m_table[index].value() == key)
    {
      m_table[index].removeVal();
    }
    deletenode(key, i+1);
  }
}
bool ClosedDoubleHashTable::search(int key, int i)
{
  int index = (hash(key) + (i * hashPlus(key, 5))) % m_buckets;

  if(m_table[index].isEmpty())
  {
    if(m_table[index].beenDeleted())
    {
      return search(key, i+1);
    }
    return false;
  }
  else
  {
    if(m_table[index].value() == key)
    {
      return true;
    }
    return search(key, i+1);
  }
}











//
