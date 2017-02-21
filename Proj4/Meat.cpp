#include "Meat.h"



Meat::Meat()
{
	setType(Food::MEAT);
}

Meat::Meat(std::string name, double cost) : Food( name, cost )
{
	setType(Food::MEAT);
}

Meat::~Meat()
{
}
