#include "Fruit.h"



Fruit::Fruit()
{
	setType(Food::FRUIT);
}

Fruit::Fruit(std::string name, double cost) : Food(name, cost)
{
	setType(Food::FRUIT);
}

Fruit::~Fruit()
{
}
