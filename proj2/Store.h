#ifndef STORE_H
#define STORE_H
#include "Food.h"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>
using namespace std;
class Store {
public:
	/****************************
	** Name:addFood
	**preconditions: Food object pointer
	**postconditions: adds the food to the list of food
	*****************************/
	void addFood(Food* food);
	/****************************
	** Name:getFoodByType
	**preconditions: foodtype
	**postconditions: returns a food of a particular type
	*****************************/
	Food* getFoodByType(Food::FOOD_TYPE foodtype);
	/****************************
	** Name:stockStore
	**preconditions: filename
	**postconditions: reads the file and makes the store based on what it read
	*****************************/
	void stockStore(string filename);
	/****************************
	** Name:printStore
	**preconditions: pointer to the output file
	**postconditions:prints the store to the outfile
	*****************************/
	void printStore(ofstream &results);

private:
	vector<stack<Food*> > m_bins;
};
#endif#pragma once
