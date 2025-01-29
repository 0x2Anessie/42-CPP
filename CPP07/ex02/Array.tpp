#include "Array.hpp"

/*
	Constructor without size
*/
template<typename T>
Array<T>::Array() : _elem(NULL), _size(0)
{}

/*
	Constructor with size
*/
template<typename T>
Array<T>::Array(unsigned int n) : _elem(new T[n]()), _size(n)
{}

/*
	Copy constructor
*/
template<typename T>
Array<T>::Array(const Array &other) : _elem(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
	{
		_elem[i] = other._elem[i];
	}
}

/*
	Assignment operator
*/
template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	delete[] _elem;
	_size = other._size;
	_elem = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
	{
		_elem[i] = other._elem[i];
	}
	return *this;
}

/*
	Destructor
*/
template<typename T>
Array<T>::~Array()
{
	delete[] _elem;
}

/*
	Operator [] to access the array elements with bounds checking
*/
template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutLimitsException();
	return _elem[i];
}

/*
	Const operator [] to access the array elements with bounds checking
*/
template<typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutLimitsException();
	return _elem[i];
}

/*
	Return the size of the array
*/
template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

/*
	Exception message
*/
template<typename T>
const char *Array<T>::OutLimitsException::what() const throw()
{
	return "Out of limits";
}