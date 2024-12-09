#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ROBOTOMY REQUEST FORM CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

RobotomyRequestForm::RobotomyRequestForm(std::string const &_target)
: AForm("RobotomyRequestForm", 72, 45), target(_target)
{
	std::cout << GREEN_BOLD << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other
) : AForm(other), target(other.target)
{
	std::cout << GREEN_BOLD << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
		std::cout << GREEN_BOLD << "RobotomyRequestForm assignation operator called!" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED_BOLD << "RobotomyRequestForm destructor called!" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXECUTE FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << BOLD << "Makes some drilling noises" << RESET << std::endl;
	/*
	initialise le generateur de nombres aleatoires en se servant
	de time(0) pour avoir une valeur de depart different a chaque
	 execution
	*/
	std::srand(std::time(0));
	if(std::rand() % 2 == 0)
		std::cout << BLUE << target << " has been robotomized successfully" << RESET <<std::endl;
	else
		std::cout << RED << "Robotomization of " << target << " has failed" << RESET << std::endl;

}
