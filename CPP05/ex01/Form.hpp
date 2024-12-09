#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string _name, int _gradeToSign, int _gradeToExecute);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();
		// ━━━━━━━━━━━━━━━━ Functions ━━━━━━━━━━━━━━━━━ //
		void beSigned(Bureaucrat const &b);
		// ━━━━━━━━━━━━━━━━━ Getters ━━━━━━━━━━━━━━━━━━ //
		std::string const &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		// ━━━━━━━━━━━━━━━━ Exceptions ━━━━━━━━━━━━━━━━ //
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
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const	name;
		int const			gradeToSign;
		int const			gradeToExecute;
		bool				isSigned;
};

std::ostream &operator <<(std::ostream &os, const Form &f);
