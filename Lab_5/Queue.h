
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template<typename T>
class Queue
{
  public:
    Queue();
    ~Queue();
    void enqueue(T val);
    Node<T>* dequeue(T val);
    bool isEmpty();
    void size();
  private:

    int m_size;
    Node<T>* m_front;
    Node<T>* m_rear;

};

#include "Queue.hpp"
#endif
