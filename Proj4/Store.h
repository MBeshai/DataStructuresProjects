#pragma once

#include <fstream>
#include <vector>
#include <stack>
#include <string>

#include "Node.h"
#include "IntervalHeap.h"
#include "Food.h"

class Store
{
public:
	Store();
	~Store();

	// Public Member Functions
	void addFood(Food* item);
	Food* getFoodByType(Food::FOOD_TYPE type);
	void stockStore(std::string filename);
	void printStore(std::ofstream& fileStream);
	
	void printHeaps();
	Food* getFoodByType(Food::FOOD_TYPE type, bool Ordertype);

private:
	vector<IntervalHeap> m_bins;
	std::vector < std::stack < Food* > > m_aBin;
};

