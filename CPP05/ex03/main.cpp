#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << std::endl;

	Intern DougJudy;

	try
	{
		std::cout << BOLD << "\nTEST #1: Intern creates a Presidential Pardon Form for Jake Peralta\n" << RESET << std::endl;
		AForm *shrubbery = DougJudy.makeForm("shrubbery creation", "Jake Peralta");
		std::cout << "\n" << *shrubbery;
		std::cout << std::endl;
		delete shrubbery;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << BOLD << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
		std::cout << BOLD << "\nTEST #2: Intern creates a Robotomy Request Form for Amy Santiago\n" << RESET << std::endl;
		AForm *robotomy = DougJudy.makeForm("robotomy request", "Amy Santiago");
		std::cout << "\n" << *robotomy;
		std::cout << std::endl;
		delete robotomy;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << BOLD << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
		std::cout << BOLD << "\nTEST #3: Intern creates a Shrubbedy Creation Form for Charles Boyle\n" << RESET << std::endl;
		AForm *shrubbery = DougJudy.makeForm("shrubbery creation", "Charles Boyle");
		std::cout << "\n" << *shrubbery;
		std::cout << std::endl;
		delete shrubbery;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << BOLD << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
		std::cout << BOLD << "\nTEST #4: Intern creates a form that doesn't exist\n" << RESET << std::endl;
		AForm *form = DougJudy.makeForm("nonexistent form", "nonexistent target");
		std::cout << "\n" << *form;
		std::cout << std::endl;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}