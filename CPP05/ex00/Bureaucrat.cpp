#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade)
{
	std::cout << BOLD << GREEN << "Bureaucrat constructor called!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
	std::cout << BOLD << GREEN << "Bureaucrat copy constructor called!" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	std::cout << BOLD << GREEN << "Bureaucrat assignation operator called!" << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD << RED << "Bureaucrat destructor called!" << RESET << std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	grade--;
}

void Bureaucrat::decrementGrade()
{
	grade++;
}