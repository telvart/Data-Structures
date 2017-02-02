
#ifndef CLOSEDDOUBLEHASHTABLE_H
#define CLOSEDDOUBLEHASHTABLE_H
#include "Bucket.h"

class ClosedDoubleHashTable
{
  public:

    ClosedDoubleHashTable(int m);
    ~ClosedDoubleHashTable();

    void insert(int key);
    void deletenode(int key);
    bool search(int key);
    void print();

  private:

    int hash(int key);
    int hashPlus(int key, int p);
    int collisionResolution(int key, int i);
    void deletenode(int key, int i);
    bool search(int key, int i);

    int m_buckets;
    int m_entries;
    Bucket* m_table;


};

#endif
