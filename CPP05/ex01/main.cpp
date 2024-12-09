#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*bureaucrat = NULL;
	Form		*form = NULL;

	// ━━━━━━━━━━━━━━━━━━ Valid Name and grade ━━━━━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("Amy Santiago", 1);
		std::cout << *bureaucrat;
		delete bureaucrat;
		bureaucrat = NULL;
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
		bureaucrat = NULL;
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
		bureaucrat = NULL;
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
		bureaucrat = NULL;
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
		bureaucrat = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << RED_BOLD << "Grade is too low" << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━ Valid Grade sign form ━━━━━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("Amy Santiago", 1);
		form = new Form("Form", 1, 150);
		std::cout << *bureaucrat;
		std::cout << *form;
		bureaucrat->signForm(*form);
		std::cout << *form;
		if (form->getIsSigned())
			std::cout << GREEN << "Form is signed" << RESET << std::endl;
		delete bureaucrat;
		delete form;
		bureaucrat = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// ━━━━━━━━━━━━ Grade too low try to sign form ━━━━━━━━━━━━━━ //

	try
	{
		bureaucrat = new Bureaucrat("Jake Peralta", 151);
		form = new Form("Form", 50, 150);
		std::cout << *bureaucrat;
		std::cout << *form;
		bureaucrat->signForm(*form);
		std::cout << *form;
		if (form->getIsSigned())
			std::cout << GREEN << "Form is signed" << RESET << std::endl;
		else
			std::cout << RED << "Form is not signed" << RESET << std::endl;
		delete bureaucrat;
		delete form;
		bureaucrat = NULL;
		form = NULL;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << RED_BOLD << "Grade is too low to sign form" << std::endl;
	}
}
