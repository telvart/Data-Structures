/**
*	@file: ClosedHashTable.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.2.1
*	@brief: Implementation of methods declared in ClosedHashTable.h
*/

#include "ClosedHashTable.h"

ClosedHashTable::ClosedHashTable(int m)
  :resolutionFunction(&ClosedHashTable::quadraticProbing)
{
  m_buckets = m;
  m_entries = 0;
  m_table = new Bucket[m];
}

ClosedHashTable::~ClosedHashTable()
{
  delete[] m_table;
}

void ClosedHashTable::insert(int key)
{
  if(!search(key))
  {
    int index = collisionResolution(key,0);
    if(index >= 0)
    {
      m_table[index].setValue(key);
      m_entries++;
    }
  }

  // if(loadfactor() >= 0.5)
  // {
  //   rehash();
  // }
}

void ClosedHashTable::deletenode(int key)
{
  deletenode(key, 0);
}

bool ClosedHashTable::search(int key)
{
  return search(key, 0);
}

void ClosedHashTable::setQuadraticProbing()
{
  resolutionFunction = &ClosedHashTable::quadraticProbing;
}
void ClosedHashTable::setDoubleHashing()
{
  resolutionFunction = &ClosedHashTable::doubleHashing;
}

void ClosedHashTable::print()
{
  std::cout.setf(std::ios::boolalpha);
  std::cout<<"\n";
  for(int i = 0; i < m_buckets; i++)
  {
    if(!m_table[i].isEmpty())
    {
      std::cout<<i<<": "<<m_table[i].value()<<" flag = "<<m_table[i].beenDeleted()<<"\n";
    }
    else
    {
      std::cout<<i<<": -1 flag = "<<m_table[i].beenDeleted()<<"\n";
    }
  }
  std::cout<<"\n";
}

double ClosedHashTable::loadfactor()
{
  return (double)m_entries / (double)m_buckets;
}

int ClosedHashTable::hash(int key)
{
  return key % m_buckets;
}

int ClosedHashTable::hashPlus(int key, int p)
{
    return p - (key % p);
}

int ClosedHashTable::collisionResolution(int key, int i)
{
  if(i >= m_buckets)
  {
    return -1;
  }

  int newIndex = (this->*resolutionFunction)(key, i);
  if(m_table[newIndex].isEmpty())
  {
    return newIndex;
  }
  return collisionResolution(key, i+1);
}

bool ClosedHashTable::search(int key, int i)
{
  if(i >= m_buckets)
  {
    return false;
  }

  int newIndex = (this->*resolutionFunction)(key, i);
  if(m_table[newIndex].isEmpty())
  {
    if(m_table[newIndex].beenDeleted())
    {
      return search(key, i+1);
    }
    else
    {
      return false;
    }
  }
  else
  {
    if(m_table[newIndex].value() == key)
    {
      return true;
    }
    else
    {
      return search(key, i+1);
    }
  }
}

void ClosedHashTable::deletenode(int key, int i)
{
  if ( i >= m_buckets)
  {
    return;
  }

  int newIndex = (this->*resolutionFunction)(key, i);
  if(m_table[newIndex].isEmpty())
  {
    if(m_table[newIndex].beenDeleted())
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
    if(m_table[newIndex].value() == key)
    {
      m_table[newIndex].removeVal();
      m_entries--;
      return;
    }
    else
    {
       deletenode(key, i+1);
    }
  }
}

void ClosedHashTable::rehash()
{
  std::cout<<"rehashing...\r"<<std::flush;
  int oldsize = m_buckets;
  resize();
  Bucket* temp = m_table;
  m_entries = 0;
  m_table = new Bucket[m_buckets];
  for(int i = 0; i < oldsize; i++)
  {
    if(!temp[i].isEmpty())
    {
      insert(temp[i].value());
    }
  }
  delete[] temp;
  std::cout<<"            \n";
}

void ClosedHashTable::resize()
{
  int newSize = m_buckets*2;
  if(newSize % 2 == 0)
  {
    newSize += 1;
  }
  while(!isPrime(newSize))
  {
    newSize += 2;
  }
  m_buckets = newSize;
}

bool ClosedHashTable::isPrime(int key)
{
  for(int i = 2; i <= key / 2; i++)
  {
    if(key % i == 0)
    {
      return false;
    }
  }
  return true;
}

int ClosedHashTable::quadraticProbing(int key, int i)
{
  return (hash(key) + (i * i)) % m_buckets;
}

int ClosedHashTable::doubleHashing(int key, int i)
{
  return (hash(key) + (i * hashPlus(key, 5))) % m_buckets;
}
