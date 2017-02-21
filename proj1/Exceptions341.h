/**************************************************************
* File:    MyExceptions.h
* Project: CMSC 341 - Project 1
* Author : Frank Zastawnik
* Date   : 12-February-2016
* Section:
* E-mail:  frankz2@umbc.edu
*
* MyExceptions Class definition.
*
*************************************************************/
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class Exceptions341 {
public:
	/**********************************************************************
	* Name: MyExceptions (Constructor)
	* PreCondition: String containing error description.
	*
	* PostCondition:  Error object
	*********************************************************************/
	Exceptions341(std::string message) : m_message(message) {}

	/**********************************************************************
	* Name: GetMessage
	* PreCondition: None.
	*
	* PostCondition:  Returns error message.
	*********************************************************************/
	const std::string GetMessage() { return m_message; }

private:

	std::string m_message; //Error message.
};

#endif
