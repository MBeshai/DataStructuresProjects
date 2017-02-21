#include "Starch.h"



Starch::Starch()
{
	setType(Food::STARCH);
}

Starch::Starch(std::string name, double cost) : Food(name, cost)
{
	setType(Food::STARCH);
}


Starch::~Starch()
{
}
