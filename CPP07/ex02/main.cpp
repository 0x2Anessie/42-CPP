#include "Array.hpp"
#include <iostream>

int main()
{
	std::cout << YELLOW << "Test Array<std::string>: " << RESET;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	for(unsigned int i = 0; i < stringArray.size(); ++i)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl << std::endl;


	std::cout << YELLOW << "Test Array<int>: " << RESET;
	Array<int> intArray(5);
	for(unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = i * 10;
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl << std::endl;


	std::cout << YELLOW << "Test exeception: " << RESET;
	try
	{
		std::cout << intArray[8] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Test copie constructor: " << RESET;
	Array<int> copiedIntArray(intArray);
	for(unsigned int i = 0; i < copiedIntArray.size(); ++i)
		std::cout << copiedIntArray[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "Test [] operator: " << RESET << std::endl;
	intArray[0] = 42;
	std::cout << BLUE << "Original intArray after modification: " << RESET;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl << BLUE << "Copied intArray to check if it remains unchanged: " << RESET;
	for (unsigned int i = 0; i < copiedIntArray.size(); ++i)
		std::cout << copiedIntArray[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "Test exception [] operator: " << RESET;
	try
	{
		intArray[6] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}