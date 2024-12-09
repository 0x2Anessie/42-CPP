#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SHRUBBERY CREATION FORM CLASS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &_target)
: AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
	std::cout << GREEN_BOLD << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other
) : AForm(other), target(other.target)
{
	std::cout << GREEN_BOLD << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
		std::cout << GREEN_BOLD << "ShrubberyCreationForm assignation operator called!" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED_BOLD << "ShrubberyCreationForm destructor called!" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXECUTE FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if(this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	// creer le nom du fichier
	std::string filename = target + "_shrubbery";
	// ouvrir le fichier + option c_str pour convertir en char* le std::string
	std::ofstream file(filename.c_str());
	if(!file.is_open())
		throw FileNotOpenException();
	file << "   *   " << std::endl;
	file << "  ***  " << std::endl;
	file << " ***** " << std::endl;
	file << "*******" << std::endl;
	file << "   |   " << std::endl;
	file << std::endl;
	file << "   *   " << std::endl;
	file << "  ***  " << std::endl;
	file << " ***** " << std::endl;
	file << "*******" << std::endl;
	file << "   |   " << std::endl;
	file.close();

	std::cout << BLUE << "ShrubberyCreationForm " << target << " has been executed by " << executor.getName() << RESET << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS DEFINITIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return RED "File could not be opened" RESET;
}
