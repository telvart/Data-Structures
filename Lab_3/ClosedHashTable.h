

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
    bool search(int key);
    void print();
    double loadfactor();

  private:

    int hash(int key);
    int collisionResolution(int initialHash, int i);
    bool search(int key, int initialHash, int i);
    void deletenode(int key, int initialHash, int i);
    void rehash();
    void resize();
    bool isPrime(int key);

    int m_buckets;
    int m_entries;
    Bucket* m_table;
};

#endif