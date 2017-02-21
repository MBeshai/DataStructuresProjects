#include "Node.h"

Node::Node()
{
	Node *m = new Node();
	m_pParentNode = m;
	m_pLeftFoodItem = NULL;
	m_pRightFoodItem = NULL;
	m_pLeftChildNode = NULL;
	m_pRightChildNode = NULL;
}

Food * Node::getLeftFoodItem()
{
	return m_pLeftFoodItem;
}

Food * Node::getRightFoodItem()
{
	return m_pRightFoodItem;
}

Node * Node::getParentNode()
{
	return m_pParentNode;
}

Node * Node::getLeftChildNode()
{
	return m_pLeftChildNode;
}

Node * Node::getRightChildNode()
{
	return m_pRightChildNode;
}

void Node::setLeftFoodItem(Food * m)
{
	m_pLeftFoodItem = m;
}

void Node::setRightFoodItem(Food * m)
{
	m_pRightFoodItem = m;
}

void Node::setParentNode(Node * m)
{
	m_pParentNode = m;
}

void Node::setLeftChildNode(Node * m)
{
	m_pLeftChildNode = m;
}

void Node::setRightChildNode(Node * m)
{
	m_pRightChildNode = m;
}
