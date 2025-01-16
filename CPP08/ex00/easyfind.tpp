#pragma once

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	if(container.empty())
		throw std::invalid_argument("Container is empty");
	if(typeid(typename T::value_type) != typeid(int))
		throw std::invalid_argument("Container is not of type int");
	if(value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		throw std::invalid_argument("Value is out of range");

	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end())
		throw std::invalid_argument("Value not found");
	return it;
}
