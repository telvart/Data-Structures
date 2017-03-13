#ifndef LHNODE_H
#define LHNODE_H

class LHNode
{

public:

  LHNode();
  LHNode(int val);
  ~LHNode();
  int getRank();
  int getVal();
  LHNode* getLeft();
  LHNode* getRight();

  void setRank(int rank);
  void setVal(int val);
  void setLeft(LHNode* left);
  void setRight(LHNode* right);

//private:

  int m_rank;
  int m_value;
  LHNode* m_left;
  LHNode* m_right;
};

#endif
