

#ifndef CLOSEDHASHTABLE_H
#define CLOSEDHASHTABLE_H
#include <iostream>
#include "Bucket.h"

class ClosedHashTable
{
  public:
    ClosedHashTable(int m);
    ~ClosedHashTable();

    void insert(int key);
    void deletenode(int key);
    void search(int key);
    void print();

  private:

    int hash(int key);
    int collisionResolution(int initialHash, int i);
    int resolutionFunction();

    int m_buckets;
    int m_entries;
    Bucket* m_table;
};

#endif
