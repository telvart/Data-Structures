#include "Bucket.h"

Bucket::Bucket()
{
    m_value = 0;
    m_beenDeleted = false;
    m_hasValue =  false;
}

int Bucket::value()
{
  return m_value;
}

void Bucket::setValue(int val)
{
 m_value = val;
 m_hasValue = true;
}

void Bucket::removeVal()
{
  m_hasValue = false;
  m_beenDeleted = true;

}

bool Bucket::isEmpty()
{
  return !m_hasValue;
}

bool Bucket::beenDeleted()
{
  return m_beenDeleted;
}
