#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <iostream>
using namespace std;

#include "MEAT.h"
#include "FRUIT.h"
#include "STARCH.h"
#include "VEGETABLES.h"
#include "SWEET.h"


class Food {
public:

	//enums of food types
	enum  FOOD_TYPE{SWEET, STARCH, MEAT, VEGETABLE, FRUIT};
	/****************************
	** Name:Food
	**preconditions: name, foodtype and cost 
	**postconditions: creates a food object
	*****************************/
	
	Food(string name, Food::FOOD_TYPE foodtype, double cost);
	/****************************
	** Name:setNAme
	**preconditions: name
	**postconditions: assigns the food a name
	*****************************/
	void setName(string name);

	/****************************
	** Name:getNAme
	**preconditions: none
	**postconditions: returns the name of the food
	*****************************/
	string getName();
	/****************************
	** Name:getcost
	**preconditions: none
	**postconditions: returns the price of the food
	*****************************/
	double getCost();
	/****************************
	** Name:getType
	**preconditions:none
	**postconditions: returns the food type
	*****************************/
	Food::FOOD_TYPE getType();
	/****************************
	** Name:printFood
	**preconditions: stream output pointer
	**postconditions: prints to the outfile
	*****************************/
	void printFood(ofstream & out);
private:
	
	string m_sName;  //name of the food
	FOOD_TYPE m_eType; //type of the food
	double m_dCost; //cost of the food
};

#endif#pragma once
