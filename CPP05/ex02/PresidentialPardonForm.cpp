#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PRESIDENTIAL PARDON FORM CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

PresidentialPardonForm::PresidentialPardonForm(std::string const &_target)
: AForm("PresidentialPardonForm", 25, 5), target(_target)
{
	std::cout << GREEN_BOLD << "PresidentialPardonForm default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
: AForm(other), target(other.target)
{
	std::cout << GREEN_BOLD << "PresidentialPardonForm copy constructor called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
		std::cout << GREEN_BOLD << "PresidentialPardonForm assignation operator called!" << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED_BOLD << "PresidentialPardonForm destructor called!" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXECUTE FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void PresidentialPardonForm::execute(Bureaucrat const &execution) const
{
	if(this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if(execution.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << target << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
}
