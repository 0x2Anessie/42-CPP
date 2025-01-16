#include "easyfind.hpp"
#include <vector>

#define TEST(expression, message) \
	if (expression) \
		std::cout << GREEN << "Test passed : " << message << RESET << std::endl; \
	else \
		std::cout << RED << "Test failed : " << message << RESET << std::endl;
int main()
{
	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(array, array + 5);

	std::cout << YELLOW << "Test easyfind with vector<int>" << RESET << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 4);
		TEST(*it == 4, "Value found");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not throw an exception");
	}

	std::cout << std::endl << YELLOW << "Test easyfind with value not found" << RESET << std::endl;
	try
	{
		easyfind(vec, 42);
		TEST(false, "Should throw an exception");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(true, "Value not found");
	}

	std::cout << std::endl << YELLOW << "Test easyfind with empty container" << RESET << std::endl;
	int empty_array[] = {};
	std::vector<int> empty_vec(empty_array, empty_array);
	try
	{
		easyfind(empty_vec, 42);
		TEST(false, "Should throw an exception");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(true, "Container is empty");
	}

	std::cout << std::endl << YELLOW << "Test easyfind with container not of type int" << RESET << std::endl;
	float float_array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::vector<float> float_vec(float_array, float_array + 5);
	try
	{
		easyfind(float_vec, 4);
		TEST(false, "Should throw an exception");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(true, "Container is not of type int");
	}

	/*
	std::cout << std::endl << YELLOW << "Test easyfind with value out of range" << RESET << std::endl;
	try
	{
		easyfind(vec, 2147483648);
		TEST(false, "Should throw an exception");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(true, "Value is out of range");
	}
	*/
}