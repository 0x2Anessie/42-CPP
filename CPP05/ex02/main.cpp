#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define TEST(expression, message) \
	if (expression) \
		std::cout << GREEN << "Test passed : " << message << RESET << std::endl; \
	else \
		std::cout << RED << "Test failed : " << message << RESET << std::endl;


int main()
{
	Bureaucrat b1("Yanis", 138);
	Bureaucrat b2("Karim", 46);
	Bureaucrat b3("Sofia", 6);
	Bureaucrat b4("Lydia", 150);
	ShrubberyCreationForm form1("Agadir shrub");
	RobotomyRequestForm form2("Rayan");
	PresidentialPardonForm form3("Yasmine");

	std::cout << std::endl << YELLOW << "Bureaucrat signing and executing forms" << RESET << std::endl;
	try
	{
		std::cout << std::endl << UNDERLINE << "ShrubberyCreationForm" << RESET << std::endl;
		std::cout << std::endl << b4 << std::endl;
		std::cout << form1 << std::endl;
		b4.signForm(form1);
		std::cout << std::endl << b1 << std::endl;
		b1.signForm(form1);
		std::cout << form1 << std::endl;
		b1.executeForm(form1);
		b1.incrementGrade();
		std::cout << std::endl << b1 << std::endl;
		b1.executeForm(form1);
		std::cout << std::endl << UNDERLINE << "RobotomyRequestForm" << RESET << std::endl;
		std::cout << std::endl << form2 << std::endl;
		b4.signForm(form2);
		std::cout << std::endl << b2 << std::endl;
		b2.signForm(form2);
		b2.executeForm(form2);
		b2.incrementGrade();
		std::cout << std::endl << b2 << std::endl;
		b2.executeForm(form2);
		std::cout << std::endl << UNDERLINE << "PresidentialPardonForm" << RESET << std::endl;
		std::cout << std::endl << form3 << std::endl;
		b4.signForm(form3);
		std::cout << std::endl << b3 << std::endl;
		b3.signForm(form3);
		b3.executeForm(form3);
		b3.incrementGrade();
		std::cout << std::endl << b3 << std::endl;
		b3.executeForm(form3);
		std::cout << std::endl;
		TEST(true, "Bureaucrat signing and executing forms");
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		TEST(false, "Should not be here");
	}
}
