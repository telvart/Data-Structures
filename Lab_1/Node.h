#ifndef NODE_H
#define NODE_H

class Node
{

public:
  Node(int value);
  void setNext(Node* next);
  void setPrev(Node* prev);
  void setValue(int val);

  int getData();
  Node* getNext();
  Node* getPrev();


private:
  int m_dataContained;
  Node* m_next;
  Node* m_prev;
};

#endif
