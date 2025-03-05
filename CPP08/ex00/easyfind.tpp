#pragma once

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &intContainer, int nb)
{
	if(intContainer.empty()) // vide
		throw std::invalid_argument("The container is empty");

	if(typeid(typename T::value_type) != typeid(int)) // pas de type int
		throw std::invalid_argument("The container is not of type int");

	if(nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max()) // hors de la plage
		throw std::invalid_argument("The value is out of range");

	// std::find() renvoie la première occurrence de nb ou end() si nb n'est pas trouvé
	typename T::iterator it = std::find(intContainer.begin(), intContainer.end(), nb);
	if(it == intContainer.end())
		throw std::invalid_argument("The value cannot be found");

	return it;
}
