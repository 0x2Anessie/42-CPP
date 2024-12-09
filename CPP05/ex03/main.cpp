#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#define TEST(expression, message) \
	if (expression) \
		std::cout << GREEN << "Test passed : " << message << RESET << std::endl; \
	else \
		std::cout << RED << "Test failed : " << message << RESET << std::endl;

int main()
{
	Intern Dimitri;

	std::cout << std::endl << YELLOW << "ShrubberyCreationForm test" << RESET << std::endl;
	try
	{
		AForm *shrubbery = Dimitri.makeForm("shrubbery creation", "garden");
		std::cout << *shrubbery;
		TEST(shrubbery->getName() == "ShrubberyCreationForm", "Name is correct");
		TEST(shrubbery->getGradeToSign() == 145, "Sign grade is correct");
		TEST(shrubbery->getGradeToExecute() == 137, "Exec grade is correct");
		TEST(shrubbery->getIsSigned() == false, "Is not signed");
		delete shrubbery;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "RobotomyRequestForm test" << RESET << std::endl;
	try
	{
		AForm *robotomy = Dimitri.makeForm("robotomy request", "patient");
		std::cout << *robotomy;
		TEST(robotomy->getName() == "RobotomyRequestForm", "Name is correct");
		TEST(robotomy->getGradeToSign() == 72, "Sign grade is correct");
		TEST(robotomy->getGradeToExecute() == 45, "Exec grade is correct");
		TEST(robotomy->getIsSigned() == false, "Is not signed");
		delete robotomy;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "PresidentialPardonForm test" << RESET << std::endl;
	try
	{
		AForm *presidential = Dimitri.makeForm("presidential pardon", "intern");
		std::cout << *presidential;
		TEST(presidential->getName() == "PresidentialPardonForm", "Name is correct");
		TEST(presidential->getGradeToSign() == 25, "Sign grade is correct");
		TEST(presidential->getGradeToExecute() == 5, "Exec grade is correct");
		TEST(presidential->getIsSigned() == false, "Is not signed");
		delete presidential;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}

	std::cout << std::endl << YELLOW << "Invalid form name test" << RESET << std::endl;
	try
	{
		AForm *invalid = Dimitri.makeForm("invalid name", "invalid");
		TEST(false, "Should not be here");
		delete invalid;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(true, "Invalid form name");
	}

	std::cout << std::endl << YELLOW << "Empty name test" << RESET << std::endl;
	try
	{
		AForm *empty = Dimitri.makeForm("", "empty");
		TEST(false, "Should not be here");
		delete empty;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(true, "Empty name");
	}
}

