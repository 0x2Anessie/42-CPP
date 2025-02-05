#include "easyfind.hpp"
#include <vector>

int main()
{
	std::cout << "\033c";
	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(array, array + 5);

	std::cout << BOLD << MAGENTA << "Contenu du conteneur d'ints : " << RESET;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN_BOLD << "Test easyfind with a valid value" << RESET << std::endl;
	try
	{
		easyfind(vec, 4);
		std::cout << GREEN << "Value 4 was found in the container!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	std::cout << std::endl << RED_BOLD << "Test easyfind with value not found" << RESET << std::endl;
	try
	{
		easyfind(vec, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

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

	std::cout << std::endl << RED_BOLD << "Test easyfind with container not of type int" << RESET << std::endl;
	float float_array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::vector<float> float_vec(float_array, float_array + 5);
	try
	{
		easyfind(float_vec, 4);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}

	std::cout << std::endl << RED_BOLD << "Test easyfind with value out of range" << RESET << std::endl;
	try
	{
		easyfind(vec, static_cast<int>(std::numeric_limits<long>::max()));
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << RESET << e.what() << std::endl;
	}
}