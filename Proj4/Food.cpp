#include <iostream>
#include <iomanip>

#include "Food.h"

using namespace std;

// Public Functions
Food::Food() {}

Food::Food(std::string name, double cost) :
	m_sName(name), m_dCost(cost) { }

void Food::printFood(std::ofstream& fileStream) const {
	fileStream << m_sName;
	fileStream << " $";
	fileStream.precision(2);
	fileStream.setf(std::ios::fixed, std::ios::floatfield);
	fileStream << m_dCost;
	fileStream << endl;
}

Food::FOOD_TYPE Food::getType() const {
	return m_eType;
}

std::string Food::getTypeName(Food::FOOD_TYPE type ) {
	string typeNames[] = { "Meat", "Fruit", "Vegetable", "Starch", "Sweet" };
	return typeNames[type];
}

// Protected Functions
void Food::setType(Food::FOOD_TYPE type) {
	m_eType = type;
}