#ifndef ORDERS_H
#define ORDERS_H
#include "Order.h"
#include "Food.h"
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

class Orders {
public:
	
	/****************************
	** Name:addORder
	**preconditions: pointer to an Order
	**postconditions: adds an Order to the orders
	*****************************/
	void addOrder(Order* m);

	/****************************
	** Name:completeOrder
	**preconditions: none
	**postconditions: completes an order
	*****************************/
	void completeOrder();
	/****************************
	** Name:getNumOfOrders
	**preconditions: none
	**postconditions: returns the number of orders
	*****************************/
	int getNumOfOrders();

	/****************************
	** Name:getCurrentORder
	**preconditions: none
	**postconditions: returns the current order first to last
	*****************************/
	Order* getCurrentORder();

	/****************************
	** Name:loadOrders
	**preconditions: filename
	**postconditions: prints the orders to the file
	*****************************/
	void loadOrders(string filename);
	/****************************
	** Name:printOrders
	**preconditions: pointer to the out file
	**postconditions: prints the orders to the outfile
	*****************************/
	void printOrders(ofstream& out);
	/****************************
	** Name:getOrdersUnfiled
	**preconditions: none
	**postconditions: returns the unfilled orders
	*****************************/
	queue<Order*> getOrdersUnfilled();
private:
	queue<Order*> m_ordersUnfilled;        //unfilled orders 
	queue<Order*> m_ordersCompleted;       ///completed orderes
	Order* m_pCurrentOrder;                 //current order
};



#endif#pragma once
