
#ifndef OPENHASHTABLE_H
#define OPENHASHTABLE_H

#include "DoubleLinkedList.h"

class OpenHashTable
{

public:

  OpenHashTable(int m);
  ~OpenHashTable();
  void insert(int key);
  void deleteVal(int key);
  bool find(int key);

  int getNumBuckets();
  int getNumEntries();
  int getLoadFactor();

  void printTable();

private:
  int hashFunction(int key);
  void rehash();

  DoubleLinkedList<int>** m_table;
  int m_buckets;
  int m_entries;
  int m_loadFactor;

};

#endif
