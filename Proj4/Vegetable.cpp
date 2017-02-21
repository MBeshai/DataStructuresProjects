#include "Vegetable.h"



vegetable::vegetable()
{
	setType(Food::VEGETABLE);
}

vegetable::vegetable(std::string name, double cost) : Food(name, cost)
{
	setType(Food::VEGETABLE);
}

vegetable::~vegetable()
{
}
