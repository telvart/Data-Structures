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
  int initialHash = hash(key);
  if(m_table[initialHash].isEmpty())
  {
    m_table[initialHash].setValue(key);
    return;
  }
  int newIndex = collisionResolution(initialHash,0);
  if(newIndex >= 0)
  {
    m_table[newIndex].setValue(key);
  }
}

void ClosedHashTable::deletenode(int key)
{

}

void ClosedHashTable::search(int key)
{

}

void ClosedHashTable::print()
{
  std::cout<<"\n";
  for(int i=0; i<m_buckets; i++)
  {
    std::cout<<i<<": "<<m_table[i].value()<<"\n";
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

  int newIndex = initialHash + (i * i);
  if(m_table[newIndex].isEmpty())
  {
    return newIndex;
  }
  return collisionResolution(initialHash, i+1);

}

int ClosedHashTable::resolutionFunction()
{
  return 0;
}










//
