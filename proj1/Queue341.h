#ifndef QUEUE341_H
#define QUEUE341_H
#include "Node341.h"
#include "List341.h"
#include "Exceptions341.h"

template <class T> class Node;

template <class T>
class Queue341:public List341<T> {
public:
	Queue341();
	Node341<T>* getFront();
	Node341<T>* getBack();
	virtual int Size() const; //Returns the size of a list
	virtual bool Empty() const; //Returns whether a list has data or not
	virtual bool Push(T obj); //Pushes data into the list
	virtual bool Pop() ; //Pops data from a list
	virtual bool Clear() ; //Clears a list
	
private:
	int m_size;
	Node341<T>* m_top;
	Node341<T>* m_front;
};


template <class T> Queue341<T>::Queue341() {
	m_size = 0;

}
template <class T> int Queue341<T>::Size() const {


	return m_size;
}

template <class T> bool Queue341<T>::Empty() const
{
	if (0 == m_size) {
		return true;
	}
	return false;
}
template <class T> bool Queue341<T>::Push(T obj) {

	Node341<T>* newNode = new Node341<T>();
	newNode->SetData(obj);
	if (m_size== 0) {
		m_front = newNode;
		m_top = newNode;
	}
	if (m_size >0 ) {
	
		
		m_top->SetNext(newNode);
		m_top = m_top->GetNext();
	}
	
	m_size++;


	return true;

}
template <class T> bool Queue341<T>::Pop() {
	if (m_size > 0) {
		
		Node341<T>* temploop = m_front;
		
		
		int i = 0;
		while (i<m_size) {
		
			temploop = temploop->GetNext();
			if (i == m_size + 1) {
				Node341<T>* temploop2 = m_front->GetNext();
					delete temploop2;
				temploop2 = NULL;
			}
			i++;
		}
	}
	else {

		throw Exceptions341("Queue – empty, couldnt pop");
	}
	

	m_size--;
	return true;
}
template <class T> bool Queue341<T>::Clear() {
	
	while (m_size > 0) {
		Pop();
	}
	
	
	return true;
}

template <class T> Node341<T>* Queue341<T>::getFront() {
	
	if (m_size == 0) {
		throw Exceptions341("Its empty, there is no front");
	}
	return m_top;
}
template <class T> Node341<T>* Queue341<T>::getBack() {
	if (m_size == 0) {
		throw Exceptions341("Its empty, there is no back");
	}
	return m_front;

}

#endif
