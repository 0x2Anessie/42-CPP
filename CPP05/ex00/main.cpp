#include "Bureaucrat.hpp"

/*
** Les exceptions sont des objets qui sont lancés (throw) lorsqu'une erreur est détectée.
** Elles sont attrapées (catch) par des blocs try/catch.
*/
int	main()
{
	Bureaucrat	*bureaucrat = NULL;

	// ━━━━━━━━━━━━━━━━━━ Valid Name and grade ━━━━━━━━━━━━━━━━━━ //

	std::cout << BOLD << "\nTEST #1:" << GREEN << " Valid Name and grade bureaucrat" << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Amy Santiago", 1);
		std::cout << BOLD << "Bureaucrat announce : " << RESET << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━ Wrong Name ━━━━━━━━━━━━━━━━━━━━━━━ //
	std::cout << BOLD << "\nTEST #2:" << RED << " Invalid name bureaucrat" << RESET << std::endl;
	std::cout << "Trying to create a bureaucrat with no name..." << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("", 1);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
	
	//***********************************************************//
	
	std::cout << BOLD << "\nTEST #3:" << RED << " Invalid name bureaucrat" << RESET << std::endl;
	std::cout << "Trying to create a bureaucrat with the name 'Jake99'..." << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jake99", 1);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	// ━━━━━━━━━━━━━━━━━━━━━ Grade Too High ━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << BOLD << "\nTEST #4:" << RED << " Grade too high exception" << RESET << std::endl;
	std::cout << "Trying to create Ray Holt with a grade of 0..." << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Ray Holt", 0);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	// ━━━━━━━━━━━━━━━━━━━━━━ Grade Too Low ━━━━━━━━━━━━━━━━━━━━━ //

	std::cout << BOLD << "\nTEST #5:" << RED << " Grade too low exception" << RESET << std::endl;
	std::cout << "Trying to create Jake Peralta with a grade of 151..." << RESET << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jake Peralta", 151);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}