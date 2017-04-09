
#ifndef BNODE_H
#define BNODE_H

class BNode
{
  public:

    BNode(int val);
    int m_order;
    int m_key;
    BNode* m_left;
    BNode* m_right;
    BNode* m_firstChild;


};


#endif
