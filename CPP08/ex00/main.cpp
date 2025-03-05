#include "easyfind.hpp"
#include <vector>

/*
	STL ALGO = Standard Template Library Algorithm
	STD::VECTOR = classe de la STL qui représente un tableau dynamique
*/
int main()
{
	std::cout << "\033c";

	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> intContainer(array, array + 5);

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PRINT CONTAINER ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	
	std::cout << GREEN_BOLD << "Int vector content: " << RESET;
	for (std::vector<int>::iterator it = intContainer.begin(); it != intContainer.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ VALID TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << GREEN_BOLD << "Test easyfind with a valid value (4)" << RESET << std::endl;
	try
	{
		easyfind(intContainer, 4);
		std::cout << GREEN << "Value 4 was found in the container!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	std::cout << GREEN_BOLD << "Test easyfind with a valid value (2)" << RESET << std::endl;
	try
	{
		easyfind(intContainer, 2);
		std::cout << GREEN << "Value 2 was found in the container!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	std::cout << GREEN_BOLD << "Test easyfind with a valid value (1)" << RESET << std::endl;
	try
	{
		easyfind(intContainer, 1);
		std::cout << GREEN << "Value 1 was found in the container!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ INVALID TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	std::cout << std::endl << RED_BOLD << "Test easyfind with value that is not in the container (42)" << RESET << std::endl;
	try
	{
		easyfind(intContainer, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OUT OF RANGE TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "Test easyfind with value out of range (long max)" << RESET << std::endl;
	try
	{
		easyfind(intContainer, static_cast<int>(std::numeric_limits<long>::max()));
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	std::cout << GREEN_BOLD << "\nCreating an empty container" << RESET;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━ EMPTY CONTAINER TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "Test easyfind with empty container" << RESET << std::endl;
	int emptyArray[] = {};
	std::vector<int> emptyContainer(emptyArray, emptyArray);
	try
	{
		easyfind(emptyContainer, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FLOAT CONTAINER ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::vector<float> floatContainer(floatArray, floatArray + 5);
	std::cout << GREEN_BOLD << "\nCreating a float container" << RESET;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━ INVALID TYPE CONTAINER TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "Test easyfind with container not of type int" << RESET << std::endl;
	try
	{
		easyfind(floatContainer, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}
}