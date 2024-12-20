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
	L'initialisation du générateur de nombres aléatoires avec l'heure actuelle (std::srand(std::time(0)))
	garantit que les séquences de nombres aléatoires sont différentes à chaque exécution du programme. Ensuite,
	std::rand() génère un nombre aléatoire, et l'opérateur modulo (% 2) est utilisé pour vérifier si ce nombre
	est pair ou impair. Si le nombre est pair, le robotomize est réussi, sinon il a échoué.
	*/
	std::srand(std::time(0));
	if(std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << RESET <<std::endl;
	else
		std::cout << RED << "Robotomization of " << target << " has failed" << RESET << std::endl;

}
