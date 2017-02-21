#include "Sweet.h"



Sweet::Sweet()
{
	setType(Food::SWEET);
}

Sweet::Sweet(std::string name, double cost) : Food(name, cost)
{
	setType(Food::SWEET);
}


Sweet::~Sweet()
{
}
