#include "Exceptions.h"
Exceptions::~Exceptions() throw()
{
}

Exceptions::Exceptions() throw()
{
	m_invalidArg = "Invalid Argument Exception";
	m_invalidCom = "Invalid Command Exception";
	m_itemNF = "Item Not Found Exception";
	m_nodeNotFound = "Node Not Found Exception";
	m_NULL = "NULL Argument Exception";
}


void Exceptions::ItemNotFound() throw()
{
		//cout<< m_itemNF<<endl;
}
