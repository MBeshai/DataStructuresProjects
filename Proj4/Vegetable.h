#pragma once
#include "Food.h"
class vegetable :
	public Food
{
public:
	vegetable();
	vegetable(std::string name, double cost);
	~vegetable();
};

