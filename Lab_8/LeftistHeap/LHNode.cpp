#include "LHNode.h"

LHNode::LHNode()
{
  m_left=nullptr;
  m_right=nullptr;
  m_value=0;
  m_rank=1;
}

LHNode::LHNode(int val)
{
  m_value=val;
  m_left=nullptr;
  m_right=nullptr;
  m_rank=1;
}

LHNode::~LHNode()
{

}

int LHNode::getRank()
{
  return m_rank;
}

int LHNode::getVal()
{
  return m_value;
}

LHNode* LHNode::getLeft()
{
  return m_left;
}

LHNode* LHNode::getRight()
{
  return m_right;
}

void LHNode::setRank(int rank)
{
  m_rank = rank;
}

void LHNode::setVal(int val)
{
  m_value = val;
}

void LHNode::setLeft(LHNode* left)
{
  m_left = left;
}

void LHNode::setRight(LHNode* right)
{
  m_right = right;
}
