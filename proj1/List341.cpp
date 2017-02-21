#ifndef LIST341_CPP
#define LIST341_CPP
#include "List341.h"
/*
template <class T> List341<T>::List341() {

}
template <class T> List341<T>::List341(const T& data)
{

}*/
template <class T> int List341<T>::Size() const {
	return 0;
}

template <class T> bool List341<T>::Empty() const
{
	return true;
}
template <class T> bool List341<T>::Push(T obj) {
	return true;
}
template <class T> bool List341<T>::Pop() {
	return true;
}
template <class T> bool List341<T>::Clear() {
	return true;
}
template class List341<int>;

#endif
