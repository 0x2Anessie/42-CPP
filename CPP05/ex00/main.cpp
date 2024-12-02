#include "Bureaucrat.hpp"

/*
** Les exceptions sont des objets qui sont lancés (throw) lorsqu'une erreur est détectée.
** Elles sont attrapées (catch) par des blocs try/catch.
*/
int	main()
{
	Bureaucrat	*bureaucrat = NULL;

	// ━━━━━━━━━━━━━━━━━━ Valid Name and grade ━━━━━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("Amy Santiago", 1);
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━ Wrong Name ━━━━━━━━━━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("", 1);
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << RED_BOLD << "Wrong Name" << std::endl;
	}
	
	//***********************************************************//
	
	try
	{
		bureaucrat = new Bureaucrat("Jake99", 1);
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << RED_BOLD << "Wrong Name" << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━ Grade Too High ━━━━━━━━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("Ray Holt", 0);
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << RED_BOLD << "Grade is too high" << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━ Grade Too Low ━━━━━━━━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("Jake Peralta", 151);
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << RED_BOLD << "Grade is too low" << std::endl;
	}
}