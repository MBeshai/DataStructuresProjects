#pragma once
#include "Food.h"
class Sweet :
	public Food
{
public:
	Sweet();
	Sweet(std::string name, double cost);
	~Sweet();
};

