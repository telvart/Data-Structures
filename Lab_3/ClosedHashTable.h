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

    /* @post key will be inserted if it is not already in the table */
    void insert(int key);

    /* @post key will be removed from the table if it exists */
    void deletenode(int key);

    /* @return true if key is in the table, otherwise false */
    bool search(int key);

    /* @post the hashing scheme being used will be set to quadratic probing */
    void setQuadraticProbing();

    /* @post the hashing scheme being used will be set to double hashing */
    void setDoubleHashing();

    /* @post each entry in the table will be printed as such
             0: <entry> flag = <flag value>
             1: <entry> flag = <flag value>  ... */
    void print();

    /* @return the current load factor(lambda) of the table: m_entries / m_buckets */
    double loadfactor();

  private:

    /* @return key % m_buckets */
    int hash(int key);

    /** @return p - (key % p) */
    int hashPlus(int key, int p);

    /* @return index to insert key into the table. determined by the recursive
               resolution function being used */
    int collisionResolution(int key, int i);

    /* @return true if key is in the table. */
    bool search(int key, int i);

    /* @post key will be removed from the table. Uses quadratic prpbing to search */
    void deletenode(int key, int i);

    /* @post The size of the table will doubled, and rounded to the nearest prime number.
             All values in the original hash table will be reinserted */
    void rehash();

    /* @post sets m_buckets to the new size to be used when rehashing */
    void resize();

    /* @return true if key is a prime number, otherwise false */
    bool isPrime(int key);

    /* @return (hash(key) + i^2) % m_buckets */
    int quadraticProbing(int key, int i);

    /* @return (hash(key) + (i * hashPlus(key, p))) % m_buckets */
    int doubleHashing(int key, int i);

    // member variables
    int (ClosedHashTable::*resolutionFunction)(int,int);
    int m_buckets;
    int m_entries;
    Bucket* m_table;
};

#endif
