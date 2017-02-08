/**
*	@file: Bucket.h
*	@author: Tim Elvart
*	@email: telvart@ku.edu
*	@date: 2017.2.1
*	@brief: A container for integers for use in a ClosedHashTable
*/

#ifndef BUCKET_H
#define BUCKET_H

class Bucket
{

public:

  /* Constructor */
  Bucket();

  /* @return the current value being stored in the bucket */
  int value();

  /* @post the current value stored in the bucket will be updated to val
           and m_hasValue will be set to true */
  void setValue(int val);

  /* @post updates m_hasValue and m_beenDeleted to be false and true respectively */
  void removeVal();

  /* @return true if a value has been deleted from the bucket, otherwise false */
  bool beenDeleted();

  /* @return true if the bucket currently holds a value, otherwise false */
  bool isEmpty();

private:

  //member variables
  bool m_beenDeleted;
  bool m_hasValue;
  int m_value;

};

#endif
