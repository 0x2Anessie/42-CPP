#include "Bureaucrat.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ BUREAUCRAT CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name), grade(_grade)
{
	if(!CheckName(name))
		throw WrongNameException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN_BOLD << "Bureaucrat constructor called!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
	std::cout << GREEN_BOLD << "Bureaucrat copy constructor called!" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	std::cout << GREEN_BOLD << "Bureaucrat assignation operator called!" << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED_BOLD << "Bureaucrat destructor called!" << RESET << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

std::string const &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ INCREMENT & DECREMENT GRADES ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ NAME EXCEPTION FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool	CheckName(const std::string name)
{
	size_t	i;

	i = 0;
	if(name.empty())
		return false;
	while(i < name.length())
	{
		if(std::isdigit(name[i]))
			return false;
		else
			i++;
	}
	return true;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS DEFINITIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

/*
** La fonction what() est une fonction virtuelle pure de la classe std::exception.
** Elle est utilisée pour obtenir une description de l'exception.
** La fonction throw() est une fonction spéciale qui est utilisée pour spécifier les exceptions qui
** peuvent être lancées par une fonction.
*/
const char *Bureaucrat::WrongNameException::what() const throw()
{
	return RED_BOLD "Invalid name" RESET;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED_BOLD "Grade is too high" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED_BOLD "Grade is too low" RESET;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OVERLOAD OPERATOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

std::ostream &operator <<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}