#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string _name, int _gradeToSign, int _gradeToExecute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm();
		// ━━━━━━━━━━━━━━━━ Functions ━━━━━━━━━━━━━━━━━ //
		void beSigned(Bureaucrat const &b);
		virtual void execute(Bureaucrat const &executor) const = 0;
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
		class FormNotSignedException : public std::exception
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
