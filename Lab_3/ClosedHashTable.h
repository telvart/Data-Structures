/**
*	@file: ClosedHashTable.h
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.2.1
*	@brief: A ClosedHashTable with open addressing to store integers
*/

#ifndef CLOSEDHASHTABLE_H
#define CLOSEDHASHTABLE_H
#include <iostream>
#include "Bucket.h"

class ClosedHashTable
{
  public:

    /* Constructor */
    ClosedHashTable(int m);

    /* Destructor */
    ~ClosedHashTable();

    /* @post key will be inserted into the ClosedHashTable */
    void insert(int key);

    /* @post key will be removed from the ClosedHashTable */
    void deletenode(int key);

    /* @return true if key is in the table, otherwise false */
    bool search(int key);

    /* @post each entry in the table will be printed as such
             index: entry
             index: entry ... */
    void print();

    /* @return the current load factor(lambda) of the table m_entries/m_buckets */
    double loadfactor();

  private:

    /* @return key % m_buckets */
    int hash(int key);

    /* @return index to insert key into the table. determined by quadratic probing
               resolution scheme with recursion  */
    int collisionResolution(int initialHash, int i);

    /*@return true if key is in the table. Searches with quadratic probing */
    bool search(int key, int initialHash, int i);

    /* @post key will be removed from the table. Uses quadratic prpbing to search */
    void deletenode(int key, int initialHash, int i);

    /* @post The size of the table will doubled, and rounded to the nearest prime number.
             All values in the hash table will remain present */
    void rehash();

    /* @post sets m_buckets to the new size to be used when rehashing */
    void resize();

    /* @return true if key is a prime number, otherwise false */
    bool isPrime(int key);

    // member variables
    int m_buckets;
    int m_entries;
    Bucket* m_table;
};

#endif
