#ifndef MANAGER_H
#define MANAGER_H
#include "Store.h"

#include "Orders.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


#include "MEAT.h"
#include "FRUIT.h"
#include "STARCH.h"
#include "VEGETABLES.h"
#include "SWEET.h"



class Manager {
public:
	/****************************
	** Name:Manager
	**preconditions: none
	**postconditions: makes the manager object
	*****************************/
	Manager();
	/****************************
	** Name:Manager
	**preconditions: store and orders char array names of files
	**postconditions:opens the files and read them and creates a store and orders
	*****************************/
	Manager(char * store, char * orders);
	/****************************
	** Name:createStore
	**preconditions: string filename
	**postconditions: reads the file and creates the store from it
	*****************************/
	void createStore(string filename);
	/****************************
	** Name:createOrders
	**preconditions:string filename
	**postconditions: reads the file and creates the store from it
	*****************************/
	void createOrders(string filename);
	/****************************
	** Name:fillOrders
	**preconditions: pointer to the outfile
	**postconditions: prints to the outfile
	*****************************/
	void fillOrders(ofstream &n);
	/****************************
	** Name:printStatus
	**preconditions: none
	**postconditions: prints the status of the orders and store
	*****************************/
	void printStatus(ofstream &n);
	

private:
	Store m_store;      //store of m_store
	Orders m_orders;    //orders
	int m_header;       //the header of my name checker
};

#endif



#pragma once
