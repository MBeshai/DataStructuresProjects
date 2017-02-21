#include "Store.h"

#include <stdlib.h>

#include "Meat.h"
#include "Fruit.h"
#include "Vegetable.h"
#include "Starch.h"
#include "Sweet.h"

using namespace std;

Store::Store() {
	// Create a stack for each food type
	m_aBin.resize(Food::TOTAL);
	IntervalHeap x;
	for (int i =0; i < 5; i++) {
		m_bins.push_back(x);
	}
}


Store::~Store() {	
	Food* temp;
	for (vector< stack < Food* > >::iterator it = m_aBin.begin(); it != m_aBin.end(); ++it) {
		while (!it->empty()) {
			temp = it->top();
			it->pop();
			delete temp;
		}
	}
}

void Store::addFood(Food* item) {
	m_aBin[item->getType()].push(item);
	m_bins[item->getType()].insert(item);
}

void Store::printHeaps()
{
}

Food * Store::getFoodByType(Food::FOOD_TYPE type, bool Ordertype)
{
	
	if (Ordertype==false) {
	return	m_bins[type].deleteMin();
	}
	else {
		return m_bins[type].deleteMax();
	}
}

Food* Store::getFoodByType(Food::FOOD_TYPE type) {
	Food* curFood;
	
	if (m_aBin[type].empty()) {
		return NULL;
	}

	curFood = m_aBin[type].top();
	m_aBin[type].pop();
	return curFood;
}

void Store::stockStore(string filename) {
	string inputName, inputType, inputCost;
	ifstream storeFileStream;
	Food* newFood;

	storeFileStream.open(filename.c_str());
	if (storeFileStream.is_open()) {
		while (!storeFileStream.eof()) {
			// String gotten when the second quote is found is the string we want
			getline(storeFileStream, inputName, '\"');
			getline(storeFileStream, inputName, '\"');

			storeFileStream >> inputType;
			storeFileStream >> inputCost;

			if (inputType.compare("meat") == 0) {
				newFood = new Meat(inputName, atof(inputCost.c_str()));
				
			}
			else if (inputType.compare("fruit") == 0) {
				newFood = new Fruit(inputName, atof(inputCost.c_str()));
		
			}
			else if (inputType.compare("vegetable") == 0) {
				newFood = new vegetable(inputName, atof(inputCost.c_str()));
			}
			else if (inputType.compare("starch") == 0) {
				newFood = new Starch(inputName, atof(inputCost.c_str()));
			}
			else {
				newFood = new Sweet(inputName, atof(inputCost.c_str()));
			}

			addFood(newFood);
			
		}
	}
}

void Store::printStore(std::ofstream& fileStream) {
	int stackIndex = 0;
	Food* tempFood;
	stack < Food* > tempStack;

	fileStream << "---------- Store ----------" << endl;
	for (int i = 0; i < 5; i++) {
		fileStream << Food::getTypeName((Food::FOOD_TYPE)stackIndex) << ": ";
		Node* root=m_bins[i].getRoot();
		while (root->getLeftChildNode() != NULL || root->getRightChildNode() != NULL) {
			cout << root->getLeftFoodItem()->getCost() << " " << root->getRightFoodItem()->getCost();
			if (root->getLeftChildNode() != NULL) {
				root = root->getLeftChildNode();
			}
			if (root->getRightChildNode() != NULL) {
				root = root->getRightChildNode();
			}
		}
	}
}