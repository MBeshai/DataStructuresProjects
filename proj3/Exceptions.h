


#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Exceptions : public exception
{

public:
	 Exceptions() throw();
	virtual ~Exceptions() throw();
	virtual void ItemNotFound() throw();
	
	

private:
	string m_invalidArg;
	string m_invalidCom;
	string m_nodeNotFound;
	string m_itemNF;
	string m_NULL;
};


#endif


