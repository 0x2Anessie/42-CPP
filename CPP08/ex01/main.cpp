#include "Span.hpp"


int main()
{
	std::cout << "\033c";

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST DE 42 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << GREEN_BOLD << "BASIC TEST:" << RESET << std::endl;

	Span Test1 = Span(5); // Conteneur de 5 éléments max

	Test1.addNumber(6);
	Test1.addNumber(3);
	Test1.addNumber(17);
	Test1.addNumber(9);
	Test1.addNumber(11);

	std::cout << BOLD << "Numbers in the container: " << RESET; // 
	for (int i = 0; i < 5; i++)
		std::cout << Test1[i] << " ";

	std::cout << std::endl;
	std::cout << BOLD << "Shortest Span: " << RESET << Test1.shortestSpan() << std::endl; // 11 - 9 = 2
	std::cout << BOLD << "Longest Span: " << RESET << Test1.longestSpan() << std::endl; // 17 - 3 = 14

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST ADDNUMBERS FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << GREEN_BOLD << "CREATE A SPAN OF 13001 VALUES" << RESET << std::endl;

	Span Test2 = Span(13001); // Conteneur de 13001 éléments max

	std::vector<int> vec; // On utilise un vecteur pour ajouter 
	for (int i = 1; i <= 13001; i++)
		vec.push_back(i); // On ajoute les éléments de 1 à 13001 dans le vecteur

	Test2.addNumbers(vec.begin(), vec.end()); // On ajoute les éléments du vecteur dans le conteneur
	std::cout << BOLD << "Longest Span: " << RESET << Test2.longestSpan() << std::endl;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ADDING TO A FULL SPAN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO ADD A NUMBER TO A FULL SPAN..." << RESET << std::endl;
	try
	{
		Span Test4 = Span(3);

		Test4.addNumber(1);
		Test4.addNumber(2);
		Test4.addNumber(3);
		Test4.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CREATE A EMPTY SPAN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO CREATE AN EMPTY SPAN..." << RESET << std::endl;
	try
	{
		Span sp3 = Span(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SINGLE VALUE SPAN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO SEARCH SHORTEST & LONGEST SPAN IN A SINGLE VALUE SPAN..." << RESET << std::endl;
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
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TEST ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << std::endl << RED_BOLD << "TRYING TO ADD THE MAX INT VALUE TO THE SPAN..." << RESET << std::endl;
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
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return 0;
}
