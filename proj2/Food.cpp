#include "Food.h"

Food::Food(string name, Food::FOOD_TYPE foodtype, double cost)
{
	m_sName = name;
	m_eType = foodtype;
	m_dCost = cost;
}

void Food::setName(string name)
{
	m_sName = name;
}

string Food::getName()
{
	return m_sName;
}

double Food::getCost()
{
	return m_dCost;
}

Food::FOOD_TYPE Food::getType()
{
	return m_eType;
}

void Food::printFood(ofstream & out)
{
	//out("results.txt", out);
}
