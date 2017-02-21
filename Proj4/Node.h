#ifndef NODE_H
#define NODE_H

#include "Food.h"
#include <iostream>
using namespace std;
class Node {

public:
	Node();
	Food* getLeftFoodItem();
	Food* getRightFoodItem();
	Node* getParentNode();
	Node* getLeftChildNode();
	Node* getRightChildNode();

	void setLeftFoodItem(Food* m);
	void setRightFoodItem(Food* m);
	void setParentNode(Node* m);
	void setLeftChildNode(Node* m);
	void setRightChildNode(Node* m);


private:
	Food* m_pLeftFoodItem;
	Food* m_pRightFoodItem;
	Node* m_pParentNode;
	Node* m_pLeftChildNode;
	Node* m_pRightChildNode;
};

#endif