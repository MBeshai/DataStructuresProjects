#ifndef LIST341_H
#define LIST341_H

#include "Node341.h"
template <class T> class Node;
template <class T>
class List341 {

public:
	virtual int Size() const ; //Returns the size of a list
	virtual bool Empty() const ; //Returns whether a list has data or not
	virtual bool Push(T obj) ; //Pushes data into the list
	virtual bool Pop() ; //Pops data from a list
	virtual bool Clear() ; //Clears a list
		
protected:
	
	Node341<T>* m_next;
	Node341<T>* m_previous;

};

#endif



