#pragma once
#include "Food.h"
class Fruit :
	public Food
{
public:
	Fruit();
	Fruit( std::string name, double cost );
	~Fruit();
};

