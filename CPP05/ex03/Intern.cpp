#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ INTERN CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

Intern::Intern()
{
	std::cout << GREEN_BOLD << "Intern default constructor called!" << RESET << std::endl;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout << GREEN_BOLD << "Intern copy constructor called!" << RESET << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << GREEN_BOLD << "Intern assignation operator called!" << RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << RED_BOLD << "Intern destructor called!" << RESET << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAKEFORM FUNCTION ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //


AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	AForm *form = NULL;

	form = formName == "shrubbery creation" ? new ShrubberyCreationForm(target) : form;
	form = formName == "robotomy request" ? new RobotomyRequestForm(target) : form;
	form = formName == "presidential pardon" ? new PresidentialPardonForm(target) : form;

	if(form)
		std::cout << RESET << "Intern creates " << formName << " form" << std::endl;
	else
		throw Intern::InvalidFormNameException();
	return form;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS DEFINITIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

const char *Intern::InvalidFormNameException::what() const throw()
{
	return RED "Invalid form name" RESET;
}
