#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Form;

/*
** Les exceptions sont definies comme des classes imbriquées dans une autre classe
** et sont généralement nommées avec le suffixe Exception.
** Elles sont declarées comme ca pour traiter les erreurs relatives a une classe precise.
*/
class Bureaucrat
{
	public:
		Bureaucrat(std::string const _name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		void executeForm(AForm const &form) const;
		// ━━━━━━━━━━━━━━━━━━ Getters ━━━━━━━━━━━━━━━━━━ //
		std::string const &getName() const;
		int getGrade() const;
		// ━━━━━━━━━━━━━━━━ Change Grade ━━━━━━━━━━━━━━━ //
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		// ━━━━━━━━━━━━━━━━ Exceptions ━━━━━━━━━━━━━━━━━ //
		class WrongNameException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const name;
		int grade;
};

// ━━━━━━━━━━━━━━━━━━━━━━━━ Functions ━━━━━━━━━━━━━━━━━━━━━━━━ //

std::ostream &operator <<(std::ostream &os, const Bureaucrat &b);
bool	CheckName(const std::string name);

// ━━━━━━━━━━━━━━━━━━━━━━━━━ Colors ━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// ANSI color codes
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"
#define RESET		"\x1b[0m"

// ANSI text style codes
#define BOLD		"\x1b[1m"
#define UNDERLINE	"\x1b[4m"
#define RESET		"\x1b[0m"
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"