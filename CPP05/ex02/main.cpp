#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	Bureaucrat				b1("Jake Peralta", 150);
	Bureaucrat				b2("Amy Santiago", 1);
	Bureaucrat				b3("Charles Boyle", 50);
	PresidentialPardonForm	presidentialPardonForm1("Jake Peralta");
	PresidentialPardonForm	presidentialPardonForm2("Amy Santiago");
	PresidentialPardonForm	presidentialPardonForm3("Charles Boyle");
	RobotomyRequestForm		robotomyRequestForm1("Jake Peralta");
	RobotomyRequestForm		robotomyRequestForm2("Amy Santiago");
	RobotomyRequestForm		robotomyRequestForm3("Charles Boyle");
	ShrubberyCreationForm	shrubberyCreationForm1("Jake Peralta");
	ShrubberyCreationForm	shrubberyCreationForm2("Amy Santiago");
	ShrubberyCreationForm	shrubberyCreationForm3("Charles Boyle");

	std::cout << BOLD << BLUE << "\nWE HAVE 3 BUREAUCRATS :" << RESET << std::endl;
	std::cout << b1;
	std::cout << b2;
	std::cout << b3;

	std::cout << BOLD << BLUE << "\nAND 3 FORMS THEY WILL TRY TO SIGN AND EXECUTE:" << RESET << std::endl;
	std::cout << presidentialPardonForm1 << std::endl;
	std::cout << robotomyRequestForm1 << std::endl;
	std::cout << shrubberyCreationForm1;

	std::cout << BOLD << BLUE << "\nPRESIDENTIAL PARDON FORM TESTS" << RESET << std::endl;
	try
	{
		std::cout << BOLD << "\nTEST #1: Jake" << RESET << std::endl;
		b1.signForm(presidentialPardonForm1);
		b1.executeForm(presidentialPardonForm1);

		std::cout << BOLD << "\nTEST #2: Amy" << RESET << std::endl;
		b2.signForm(presidentialPardonForm2);
		b2.executeForm(presidentialPardonForm2);

		std::cout << BOLD << "\nTEST #3: Charles" << RESET << std::endl;
		b3.signForm(presidentialPardonForm3);
		b3.executeForm(presidentialPardonForm3);
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	std::cout << BOLD << BLUE << "\nROBOTOMY REQUEST FORM TESTS" << RESET << std::endl;
	try
	{
		std::cout << BOLD << "\nTEST #1: Jake" << RESET << std::endl;
		b1.signForm(robotomyRequestForm1);
		b1.executeForm(robotomyRequestForm1);

		std::cout << BOLD << "\nTEST #2: Amy" << RESET << std::endl;
		b2.signForm(robotomyRequestForm2);
		b2.executeForm(robotomyRequestForm2);

		std::cout << BOLD << "\nTEST #3: Charles" << RESET << std::endl;
		b3.signForm(robotomyRequestForm3);
		b3.executeForm(robotomyRequestForm3);
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}

	std::cout << BOLD << BLUE << "\nSHRUBBERY CREATION FORM TESTS" << RESET << std::endl;
	try
	{
		std::cout << BOLD << "\nTEST #1: Jake" << RESET << std::endl;
		b1.signForm(shrubberyCreationForm1);
		b1.executeForm(shrubberyCreationForm1);

		std::cout << BOLD << "\nTEST #2: Amy" << RESET << std::endl;
		b2.signForm(shrubberyCreationForm2);
		b2.executeForm(shrubberyCreationForm2);

		std::cout << BOLD << "\nTEST #3: Charles" << RESET << std::endl;
		b3.signForm(shrubberyCreationForm3);
		b3.executeForm(shrubberyCreationForm3);
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD << "Exception caught: " << RESET;
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}
