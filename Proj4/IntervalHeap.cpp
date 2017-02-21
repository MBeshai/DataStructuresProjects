#include "IntervalHeap.h"

IntervalHeap::IntervalHeap()
{
	m_pRoot = new Node();
	//sdgasdgadfgsd
}
IntervalHeap::~IntervalHeap() {
	
}
Node * IntervalHeap::getRoot()
{
	return m_pRoot;
}
void IntervalHeap::insert(Food * x)
{
	double costOffood=x->getCost();
	Node *root = m_pRoot;
	while (root != NULL) {
		if (NULL != root->getLeftFoodItem() && NULL != root->getRightFoodItem()) {
			if (root->getLeftChildNode() != NULL) {
				root = root->getLeftChildNode();
			}
			else if (root->getRightChildNode() != NULL) {
				root = root->getRightChildNode();
			}
		}
	
		if (NULL == root->getLeftFoodItem() ) {
			root->setRightFoodItem (x);
			
		}
		else if(NULL != root->getLeftFoodItem()&& NULL == root->getRightFoodItem()) {
			root->setRightFoodItem(x);

		}
		else if (NULL != root->getLeftFoodItem() && NULL != root->getRightFoodItem()) {
			if (root->getLeftChildNode() == NULL) {
				Node * newNode = new Node();
				root->setLeftChildNode(newNode);
				root->getLeftChildNode()->setLeftFoodItem(x);
			}
			if (root->getLeftChildNode() == NULL &&  NULL !=root->getRightChildNode()) {
				Node * newNode = new Node();
				root->setRightChildNode(newNode);
				root->getRightChildNode()->setLeftFoodItem(x);
			}

		}
		
		
		
		Node* parentRoot = root->getParentNode();
		if (NULL == root->getLeftFoodItem() && NULL == root->getRightFoodItem()) {
			if (root->getLeftFoodItem()->getCost() > root->getRightFoodItem()->getCost()) {
				Food* temp = root->getLeftFoodItem();
				root->setLeftFoodItem(root->getRightFoodItem());
				root->setRightFoodItem(temp);
			}
		}
		if (root->getLeftFoodItem()->getCost() > parentRoot->getLeftFoodItem()->getCost()) {
			Food* temp = parentRoot->getLeftFoodItem();
			parentRoot->setLeftFoodItem(root->getLeftFoodItem());
			root->setLeftFoodItem(temp);
		}
		if (root->getRightFoodItem()->getCost() > parentRoot->getRightFoodItem()->getCost()) {
			Food* temp = parentRoot->getRightFoodItem();
			parentRoot->setRightFoodItem(root->getRightFoodItem());
			root->setRightFoodItem(temp);
		}
	}
}

Food * IntervalHeap::deleteMin()
{
	Node* root = m_pRoot;
	Food* min = m_pRoot->getLeftFoodItem();
	while (NULL != root->getLeftChildNode()) {
		root->setLeftFoodItem(root->getLeftChildNode()->getLeftFoodItem());
		root = root->getLeftChildNode();
	}
	
	return min;
}

Food * IntervalHeap::deleteMax()
{
	Node* root = m_pRoot;
	Food* max = m_pRoot->getRightFoodItem();
	while (NULL != root->getRightChildNode()) {
		root->setRightFoodItem(root->getRightChildNode()->getRightFoodItem());
		root->getRightChildNode();
	}
	if (NULL == root->getRightChildNode() && NULL != root->getLeftChildNode()) {
		return root->getLeftChildNode()->getLeftFoodItem();
	}
	return max;
}
