#ifndef STACK341_H
#define STACK341_h
#include "Node341.h"
#include "List341.h"
#include "Exceptions341.h"

template <class T> class Node341;
template <class T>
class Stack341 : public List341<T> {
	public:
	Stack341();
	Stack341(const T& data);


	virtual int Size() const; //Returns the size of a list
	virtual bool Empty() const ; //Returns whether a list has data or not
	virtual bool Push(T obj); //Pushes data into the list
	virtual bool Pop() ; //Pops data from a list
	virtual bool Clear() ; //Clears a list
private:
	int m_size;
	Node341<T>* m_top;
	Node341<T>* m_previous;
};
template <class T> Stack341<T>::Stack341() {
	m_size = 0;
}
template <class T> Stack341<T>::Stack341(const T& data)
{

	Node341<T>* newNode = new Node341<T>();
	newNode->SetData(data);
	m_top=newNode;
	m_size = 1;

}
template <class T> int Stack341<T>::Size() const {
	return m_size;
}

template <class T> bool Stack341<T>::Empty() const
{
	if (m_size > 0) {
		return false;
	}
	return true;
}
template <class T> bool Stack341<T>::Push(T obj) {
	Node341<T>* newNode = new Node341<T>();
	newNode->SetData(obj); 
	
	if (m_size == 0) {
		m_top = newNode;
	}
	else {
		m_previous = m_top;
		m_top->SetNext(newNode);
	}
	m_size++;
	return true;
}
template <class T> bool Stack341<T>::Pop() {
	if (m_size > 0) {
		Node341<T>* tempNode = new Node341<T>();
		m_top = m_previous;
		delete tempNode;
		tempNode = NULL;
	
	}
	else {

		throw Exceptions341("Queue – empty, couldnt pop");
	}


	m_size--;
	return true;

}
template <class T> bool Stack341<T>::Clear() {
	while (m_size > 0) {
		Pop();
	}
	return true;
}
template class Stack341<int>;


#endif