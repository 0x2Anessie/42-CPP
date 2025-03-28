#include "Span.hpp"

int main()
{
	std::cout << "\033c";

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST DE 42 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << GREEN_BOLD << "BASIC TEST WITH RANDOM NUMBERS:" << RESET << std::endl;

	Span Test1 = Span(5);

	Test1.addNumber(6);
	Test1.addNumber(3);
	Test1.addNumber(17);
	Test1.addNumber(9);
	Test1.addNumber(11);

	std::cout << BOLD << "Numbers in the container: " << RESET;
	for (int i = 0; i < 5; i++)
		std::cout << Test1[i] << " ";

	std::cout << std::endl;
	std::cout << BOLD << "Shortest Span: " << RESET << Test1.shortestSpan() << std::endl;
	std::cout << BOLD << "Longest Span: " << RESET << Test1.longestSpan() << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST ADDNUMBERssss FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << GREEN_BOLD << "CREATE A SPAN OF 10000+ VALUES" << RESET << std::endl;

	Span Test2 = Span(13001);

	std::vector<int> vec; // pour recuperer les valeurs de begin a end
	for (int i = 1; i <= 13001; i++)
		vec.push_back(i);

	Test2.addNumbers(vec.begin(), vec.end());
	
	// std::cout << BOLD << "Numbers in the container: " << RESET;
	// for (int i = 0; i < 13001; i++)
	// 	std::cout << Test2[i] << " ";
	// std::cout << std::endl;
	
	std::cout << BOLD << "Shortest Span: " << RESET << Test2.shortestSpan() << std::endl;
	std::cout << BOLD << "Longest Span: " << RESET << Test2.longestSpan() << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ADDING TO A FULL SPAN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO ADD A NUMBER TO A FULL SPAN..." << RESET << std::endl;
	try
	{
		Span Test3 = Span(3);

		Test3.addNumber(1);
		Test3.addNumber(2);
		Test3.addNumber(3);
		Test3.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CREATE A EMPTY SPAN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO CREATE AN EMPTY SPAN..." << RESET << std::endl;
	try
	{
		Span Test4 = Span(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SINGLE VALUE SPAN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO SEARCH SHORTEST & LONGEST SPAN IN A SINGLE VALUE SPAN..." << RESET << std::endl;
	try
	{
		Span Test5 = Span(1);

		Test5.addNumber(1);
		Test5.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try
	{
		Span Test6 = Span(1);

		Test6.addNumber(1);
		Test6.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO ADD THE MAX INT VALUE TO THE SPAN..." << RESET << std::endl;
	try
	{
		Span Test7 = Span(43);
		std::vector<long> vec3;

		for (int i = 1; i <= 42; i++)
			vec3.push_back(i);
		vec3.push_back(2147483648);

		Test7.addNumbers(vec3.begin(), vec3.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return 0;
}
