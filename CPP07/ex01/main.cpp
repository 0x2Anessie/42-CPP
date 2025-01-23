#include "iter.hpp"
#include <string>

int intPrint(int digit)
{
	std::cout << " / " << digit;
	return 0;
}

float floatPrint(float flottant)
{
	std::cout << " / " << flottant;
	return 0.0f;
}

void strPrint(std::string &str)
{
	std::cout << " / " << str;
}

int main()
{
	std::cout << "\033c";
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::string strArray[] = {"one", "two", "three", "four", "five"};

	std::cout << GREEN_BOLD << "PRINTING THE INT ARRAY USING ITER :" << RESET << std::endl;
	iter(intArray, 5, intPrint);
	std::cout << std::endl;

	std::cout << GREEN_BOLD << std::endl << "PRINTING THE FLOAT ARRAY USING ITER :" << RESET << std::endl;
	iter(floatArray, 5, floatPrint);
	std::cout << std::endl;

	std::cout << GREEN_BOLD << std::endl << "PRINTING THE STRING ARRAY USING ITER :" << RESET << std::endl;
	iter(strArray, 5, strPrint);
	std::cout << "\n" << std::endl;

	return 0;
}