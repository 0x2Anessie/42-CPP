#include "Form.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FORM CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

Form::Form(const std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute), isSigned(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN_BOLD << "Form constructor called!" << RESET << std::endl;
}

Form::Form(Form const &other)
: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
	std::cout << GREEN_BOLD << "Form copy constructor called!" << RESET << std::endl;
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	std::cout << GREEN_BOLD << "Form assignation operator called!" << RESET << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << RED_BOLD << "Form destructor called!" << RESET << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

std::string const &Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SIGN FORM FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void Form::beSigned(Bureaucrat const &b)
{
	if (isSigned)
		return;
	if (b.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS DEFINITIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

const char *Form::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" RESET;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" RESET;
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return RED "Form is already signed" RESET;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OVERLOAD OPERATOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

std::ostream &operator <<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName() << " is signed: " << f.getIsSigned()
		<< std::endl << "Sign grade: " << f.getGradeToSign() << std::endl
		<< "Exec grade: " << f.getGradeToExecute() << std::endl;
	return os;
}
