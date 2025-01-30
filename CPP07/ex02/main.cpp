#include "Array.hpp"
#include <iostream>

int main()
{
	std::cout << "\033c";
	std::cout << BLUE << BOLD << "TESTING BASIC ARRAYS\n\n" << RESET;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━ STRING ARRAY TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << GREEN_BOLD << "Creating an array of three strings...\n" << RESET;

	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";

	for(unsigned int i = 0; i < stringArray.size(); ++i)
		std::cout << BOLD << "Line " << i + 1 << ": " << RESET << stringArray[i] << "\n";
	std::cout << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ INT ARRAY TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << GREEN_BOLD << "Creating an array of five ints...\n" << RESET;

	Array<int> intArray(5);

	for(unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = i * 10;
		std::cout << BOLD << "Line " << i + 1 << ": " << RESET << intArray[i] << "\n";
	}
	std::cout << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ COPY ARRAY TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << GREEN_BOLD << "Creating a copy array based on the previous int array...\n" << RESET;

	Array<int> copiedIntArray(intArray);

	for(unsigned int i = 0; i < copiedIntArray.size(); ++i)
				std::cout << BOLD << "Line " << i + 1 << ": " << RESET << copiedIntArray[i] << "\n";

	std::cout << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OUT OF LIMITS TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << BLUE << BOLD << "TESTING OUT OF LIMITS EXCEPTION\n\n" << RESET;

	std::cout << RED_BOLD << "Trying to print the tenth int of a five int array...\n" << RESET;
	try
	{
		std::cout << intArray[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_BOLD << "Exception caught: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OPERATOR TESTS ━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << BLUE << BOLD << "TESTING [] OPERATOR\n\n" << RESET;

	std::cout << GREEN_BOLD << "Trying to change the value of an element of the array..." << RESET << std::endl;

	intArray[0] = 42;

	std::cout << GREEN_BOLD << "Original intArray after modification:\n" << RESET;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << BOLD << "Line " << i + 1 << ": " << RESET << intArray[i] << "\n";

	std::cout << std::endl << GREEN_BOLD << "Copied intArray to check if it remains unchanged:\n" << RESET;
	for (unsigned int i = 0; i < copiedIntArray.size(); ++i)
				std::cout << BOLD << "Line " << i + 1 << ": " << RESET << copiedIntArray[i] << "\n";
	std::cout << std::endl;

	std::cout << RED_BOLD << "Trying to change the value of the sixth int of an array of five ints...\n" << RESET;
	try
	{
		intArray[6] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_BOLD << "Exception caught: " << RESET << e.what() << std::endl;
	}

	return 0;
}