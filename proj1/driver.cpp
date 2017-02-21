/**************************************************************
* File:    Driver.cpp
* Project: CMSC 341 - Project 1
* Author : Frank Zastawnik
* Date   : 12-February-2016
* Section:
* E-mail:  frankz2@umbc.edu
*
* Sample driver file for project 1.
*
*************************************************************/
#include "List341.h"
#include "Stack341.h"
#include "Queue341.h"
#include "Exceptions341.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {

	Stack341<int> *myStack = new Stack341<int>();
	Queue341<int> myQueue;


	try {
		for (int i = 0; i < 10;) {
			myStack->Push(i);
			myQueue.Push(i++);
			myStack->Pop();
		}
		cout << "Queue size: " << myQueue.Size() << endl;
		cout << "Queue cleared = " << myQueue.Clear() << endl;

	}
	catch (Exceptions341 &E) {
		cout << "Exception: " << E.GetMessage() << endl;
	}

	delete myStack;
}
