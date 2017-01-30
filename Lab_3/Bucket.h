
#ifndef BUCKET_H
#define BUCKET_H

class Bucket
{
public:

  Bucket();
  int value();
  void setValue(int val);
  void removeVal();
  bool beenDeleted();
  bool isEmpty();


private:

  bool m_beenDeleted;
  bool m_hasValue;
  int m_value;

};

#endif
