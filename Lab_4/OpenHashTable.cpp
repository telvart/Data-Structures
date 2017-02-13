/**
*	@file: OpenHashTable.cpp
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.31
*	@brief: implementation of methods declared in OpenHashTable.h
*/
#include "OpenHashTable.h"

OpenHashTable::OpenHashTable(int m)
{
  m_buckets = m;
  m_entries = 0;
  m_table = new DoubleLinkedList<int>[m];

}

OpenHashTable::~OpenHashTable()
{
  delete[] m_table;
}

void OpenHashTable::insert(int key)
{
  int index = hashFunction(key);
  if(!m_table[index].search(key))
  {
    m_table[index].insertFront(key);
    m_entries++;
  }
}

void OpenHashTable::deleteVal(int key)
{
  int index = hashFunction(key);
  if(m_table[index].search(key))
  {
    m_table[index].deletenode(key);
    m_entries--;
  }
}

bool OpenHashTable::find(int key)
{
  int index = hashFunction(key);
  return m_table[index].search(key);
}

int OpenHashTable::hashFunction(int key)
{
  return key % m_buckets;
}

int OpenHashTable::getNumBuckets()
{
  return m_buckets;
}
int OpenHashTable::getNumEntries()
{
  return m_entries;
}
int OpenHashTable::getLoadFactor()
{
  return m_entries / m_buckets;
}

void OpenHashTable::printTable()
{
  std::cout<<"\n";
  for(int i=0; i<m_buckets; i++)
  {
    std::cout<<i<<": ";
    m_table[i].print();
    std::cout<<"\n";
  }
  std::cout<<"\n";
}
















//
