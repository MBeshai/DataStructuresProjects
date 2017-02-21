#pragma once
#include "Food.h"
class Meat : public Food
{
	public:
		Meat();
		Meat( std::string name, double cost );

		~Meat();
};

