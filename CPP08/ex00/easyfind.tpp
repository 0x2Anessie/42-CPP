#pragma once

#include "easyfind.hpp"

/*
	cette fonction doit trouver la première occurrence de nb dans intContainer.
	std::invalid_argument est une classe d'exception qui est définie dans la bibliotheque
	standard C++. Elle est utilisée pour signaler qu'un argument invalide a été passé à
	une fonction.
	la methode find() de la bibliotheque standard C++ renvoie un itérateur pointant vers
	la première occurrence de nb dans le container. Si la valeur n'est pas trouvée, la
	méthode renvoie un itérateur pointant vers la fin du container.
*/
template <typename T>
typename T::iterator easyfind(T &intContainer, int nb)
{
	// si le container est vide
	if(intContainer.empty())
		throw std::invalid_argument("The container is empty");

	// si le container n'est pas de type int
	if(typeid(typename T::value_type) != typeid(int))
		throw std::invalid_argument("The container is not of type int");

	// si la valeur est en dehors des limites d'un int
	if(nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		throw std::invalid_argument("The value is out of range");

	// si la valeur ne peut pas être trouvée entre le premier et le dernier élément du container
	typename T::iterator it = std::find(intContainer.begin(), intContainer.end(), nb);
	if(it == intContainer.end())
		throw std::invalid_argument("The value cannot be found");
	return it; // retourne l'itérateur pointant vers la première occurrence de nb
}
