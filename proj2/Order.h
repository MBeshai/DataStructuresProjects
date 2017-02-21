#ifndef ORDER_H
#define ORDER_H

#include "Food.h"

#include <queue>
#include <string>
#include <iostream>
using namespace std;


class Order {
public:
	/****************************
	** Name:Order
	**preconditions: none
	**postconditions: creates a order object
	*****************************/
	Order();
	/****************************
	** Name:Order
	**preconditions: name, partial order or not  and order
	**postconditions: creates an order object
	*****************************/
	Order(string name, bool partialOrder, queue<Food::FOOD_TYPE> requests);

	/****************************
	** Name:setCustomerName
	**preconditions: name
	**postconditions: sets the name of the person who ordered
	*****************************/
	void setCustomerName(string name);
	/****************************
	** Name:setAcceptPartial
	**preconditions:bool 
	**postconditions: sets if th eorder canbe partial or not
	*****************************/
	void setAcceptPartial(bool partial);
	/****************************
	** Name:setOrderComplete
	**preconditions: none
	**postconditions: marks the order complete
	*****************************/
	void setOrderComplete();
	/****************************
	** Name:isAcceptPartial
	**preconditions: none
	**postconditions:returns a bool of whether it can be partial or not
	*****************************/
	bool isAcceptPartial();
	/****************************
	** Name:getCustomerName
	**preconditions: none
	**postconditions: returns the customer name
	*****************************/
	string getCustomerName();
	/****************************
	** Name:getNumRequests
	**preconditions: none
	**postconditions: returns the amount of food requests
	*****************************/
	int getNumRequests();
	/****************************
	** Name:getRequests
	**preconditions: none
	**postconditions: returns the requests
	*****************************/
	vector<Food::FOOD_TYPE> getRequests();
	/****************************
	** Name:getNextRequest
	**preconditions: none
	**postconditions: returns the next request in order
	*****************************/
	Food::FOOD_TYPE& getNextRequest();
	/****************************
	** Name:addRequestToOrder
	**preconditions: foodtype
	**postconditions: adds food to the order
	*****************************/
	void addRequestToOrder(Food::FOOD_TYPE);


private:
	string m_sCustomerName;							//customer name
	queue <Food::FOOD_TYPE> m_requests;				//the requests
	bool m_bAcceptsPartialOrder;                    // partial order or not
	bool m_bOrderCompleted;                         //completed orders
	queue<Food*> m_filledREquests;                  //the requests

};

#endif#pragma once
