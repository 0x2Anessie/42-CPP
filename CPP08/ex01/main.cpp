#include "Span.hpp"

int main()
{
	std::cout << YELLOW << "42 test" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << YELLOW << "Test span exception" << RESET << std::endl;
	try
	{
		Span sp2 = Span(3);
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(3);
		sp2.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "Test span too empty exception" << RESET << std::endl;
	try
	{
		Span sp3 = Span(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "Test short and longest exception" << RESET << std::endl;
	try
	{
		Span sp4 = Span(1);
		sp4.addNumber(1);
		sp4.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Span sp5 = Span(1);
		sp5.addNumber(1);
		sp5.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "Test addNumbers" << RESET << std::endl;
	Span sp6 = Span(10000);
	std::vector<int> vec;
	for (int i = 1; i <= 10000; i++)
		vec.push_back(i);
	sp6.addNumbers(vec.begin(), vec.end());
	std::cout << sp6.longestSpan() << std::endl;

	std::cout << std::endl << YELLOW << "Test addNumbers exception" << RESET << std::endl;
	try
	{
		Span sp7 = Span(42);
		std::vector<int> vec2;
		for (int i = 1; i <= 42; i++)
			vec2.push_back(i);
		sp7.addNumbers(vec2.begin(), vec2.end());
		std::cout << sp7.longestSpan() << std::endl;
		sp7.addNumber(43);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << YELLOW << "Test addNumbers exception int max" << RESET << std::endl;
	try
	{
		Span sp8 = Span(43);
		std::vector<long> vec3;
		for (int i = 1; i <= 42; i++)
			vec3.push_back(i);
		vec3.push_back(2147483648);
		sp8.addNumbers(vec3.begin(), vec3.end());
		std::cout << sp8.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
