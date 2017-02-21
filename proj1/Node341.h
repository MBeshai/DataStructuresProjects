#ifndef NODE341_H
#define NODE341_H
#include <iostream>
using namespace std;


template <class T>
class Node341 {


public:
	Node341();
	Node341(const T& data);
	const T& GetData();
	void SetData(const T& data);
	Node341<T>* GetNext();
	void SetNext(Node341<T>* next);
private:
	T m_data;
	Node341<T>* m_next;


};

template <class T>
Node341<T>::Node341()
{

	
}
template <class T>
Node341<T>::Node341(const T& data)
{
	m_data = data;

}

template <class T>
const T& Node341<T>::GetData()
{
	return m_data;
}
template <class T>
void Node341<T>::SetData(const T& data)
{
	m_data = data;
}
template <class T>
Node341<T>* Node341<T>::GetNext()
{
	return m_next;
}
template <class T>
void Node341<T>::SetNext(Node341<T>* next)
{
	m_next = next;
}

#endif