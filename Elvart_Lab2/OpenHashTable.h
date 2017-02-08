/**
*	@file: OpenHashTable.h
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.1.31
*	@brief: An OpenHashTable with chaining to store integers
*/

#ifndef OPENHASHTABLE_H
#define OPENHASHTABLE_H

#include "DoubleLinkedList.h"

class OpenHashTable
{

public:

  /* Construcor */
  OpenHashTable(int m);

  /* Destructor */
  ~OpenHashTable();

  /* @post key will be inserted to the hash table */
  void insert(int key);

  /* @post if key is in the table, it will be removed */
  void deleteVal(int key);

  /* @return true if key is in the table, otherwise false */
  bool find(int key);

  /* @return the current size of the table */
  int getNumBuckets();

  /* @return current number of entries in the table */
  int getNumEntries();

  /* @return the current load factor(lambda) of the table :: m_entries/m_buckets */
  int getLoadFactor();

  /* @post Every chained integer in the table will be printed as such
           index: entry entry entry ... */
  void printTable();

private:

  /* @return integer representing index to insert into the table */
  int hashFunction(int key);

  //member variables
  DoubleLinkedList<int>* m_table;
  int m_buckets;
  int m_entries;
  int m_loadFactor;

};

#endif
