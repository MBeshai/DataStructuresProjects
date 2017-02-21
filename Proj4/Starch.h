#pragma once
#include "Food.h"
class Starch :
	public Food
{
public:
	Starch();
	Starch(std::string name, double cost);
	~Starch();
};

