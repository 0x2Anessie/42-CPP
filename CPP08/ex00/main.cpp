#include "easyfind.hpp"
#include <vector>

/*
	Un container est une classe ou une structure de donnees de taille dynamique.
	Ils utilisent des itérateurs pour parcourir les éléments comme std::vector,
	std::list, std::map, std::set.
	->	Ici on utilise std::vector<int> vec(array, array + 5) pour initialiser un
		vecteur d'entiers avec les valeurs de array.
*/
int main()
{
	std::cout << "\033c";

	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(array, array + 5); // vec est un conteneur d'entiers

	// Affichage du contenu du vecteur
	std::cout << GREEN_BOLD << "Int vector content: " << RESET;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	// Vérification de la fonction easyfind avec une valeur valide
	std::cout << GREEN_BOLD << "Test easyfind with a valid value (4)" << RESET << std::endl;
	try
	{
		easyfind(vec, 4);
		std::cout << GREEN << "Value 4 was found in the container!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	// Vérification de la fonction easyfind avec une valeur non trouvée
	std::cout << std::endl << RED_BOLD << "Test easyfind with value that is not in the container (42)" << RESET << std::endl;
	try
	{
		easyfind(vec, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	// Test easyfind with value out of range
	std::cout << std::endl << RED_BOLD << "Test easyfind with value out of range (long max)" << RESET << std::endl;
	try
	{
		easyfind(vec, static_cast<int>(std::numeric_limits<long>::max()));
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	std::cout << GREEN_BOLD << "\nCreating an empty container\n" << RESET;

	// Vérification de la fonction easyfind avec un conteneur vide
	std::cout << std::endl << RED_BOLD << "Test easyfind with empty container" << RESET << std::endl;
	int empty_array[] = {};
	std::vector<int> empty_vec(empty_array, empty_array);
	try
	{
		easyfind(empty_vec, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	float float_array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::vector<float> float_vec(float_array, float_array + 5);

	std::cout << GREEN_BOLD << "\nCreating a float container\n" << RESET;

	// Looking for an int value in a float container
	std::cout << std::endl << RED_BOLD << "Test easyfind with container not of type int" << RESET << std::endl;
	try
	{
		easyfind(float_vec, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}
}