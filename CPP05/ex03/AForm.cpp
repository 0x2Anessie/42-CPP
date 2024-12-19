#include "AForm.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FORM CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

AForm::AForm(const std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute), isSigned(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << GREEN_BOLD << "Form constructor called!" << RESET << std::endl;
}

AForm::AForm(AForm const &other)
: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
	std::cout << GREEN_BOLD << "Form copy constructor called!" << RESET << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	std::cout << GREEN_BOLD << "Form assignation operator called!" << RESET << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << RED_BOLD << "Form destructor called!" << RESET << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

std::string const &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SIGN FORM FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void AForm::beSigned(Bureaucrat const &b)
{
	if (isSigned)
		throw AForm::FormAlreadySignedException();
	if (b.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS DEFINITIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

const char *AForm::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" RESET;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" RESET;
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return RED "Form is already signed" RESET;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return RED "Form is not signed" RESET;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OVERLOAD OPERATOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

std::ostream &operator <<(std::ostream &os, const AForm &f)
{
	os << "The form " << f.getName() << " signed status is: " << f.getIsSigned()
		<< std::endl << "-> Grade required to sign the form: " << f.getGradeToSign() << std::endl
		<< "-> Grade required to execute the form: " << f.getGradeToExecute() << std::endl;
	return os;
}
