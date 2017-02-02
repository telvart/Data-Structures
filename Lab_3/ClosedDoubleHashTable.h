/**
*	@file: ClosedDoubleHashTable.h
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.2.1
*	@brief: A hash table based on the double hashing collision resolution scheme
*/
#ifndef CLOSEDDOUBLEHASHTABLE_H
#define CLOSEDDOUBLEHASHTABLE_H
#include "Bucket.h"

class ClosedDoubleHashTable
{
  public:

    /** Constructor */
    ClosedDoubleHashTable(int m);

    /** Destructor */
    ~ClosedDoubleHashTable();

    /** @post key will be inserted into the table */
    void insert(int key);

    /** @post key will be removed from the table if it exists */
    void deletenode(int key);

    /** @return true if key is in the table, otherwise false */
    bool search(int key);

    /** @post each entry in the hash table will be printed as such
             index: entry */
    void print();

  private:

    /** @return key % m_buckets */
    int hash(int key);

    /** @return p - (key % p) */
    int hashPlus(int key, int p);

    /** @return index a new key should be inserted into the table. -1 if not possible */
    int collisionResolution(int key, int i);

    /** @post key will be removed from the table */
    void deletenode(int key, int i);

    /** @return true if key is in the table, otherwise false */
    bool search(int key, int i);


    //member variables
    int m_buckets;
    int m_entries;
    Bucket* m_table;


};

#endif
