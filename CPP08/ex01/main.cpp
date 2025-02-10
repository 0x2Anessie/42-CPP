#include "Span.hpp"


int main()
{
	std::cout << "\033c";
	std::cout << BLUE << BOLD << "Results of the 42 tests :" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << BOLD << "Shortest Span: " << RESET << sp.shortestSpan() << std::endl; // 11 - 9 = 2
	std::cout << BOLD << "Longest Span: " << RESET << sp.longestSpan() << std::endl; // 17 - 3 = 14

	std::cout << std::endl << BLUE << BOLD << "Test Span exception :" << RESET << std::endl;
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
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << BLUE << BOLD << "Trying to create an empty Span" << RESET << std::endl;
	try
	{
		Span sp3 = Span(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << BLUE << BOLD << "Test short and longest exception" << RESET << std::endl;
	try
	{
		Span sp4 = Span(1);
		sp4.addNumber(1);
		sp4.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
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
	Span sp6 = Span(13001);
	std::vector<int> vec;
	for (int i = 1; i <= 13001; i++)
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
