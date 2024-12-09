#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &targt) const;
		// ━━━━━━━━━━━━━━━━ Exceptions ━━━━━━━━━━━━━━━━ //
		class InvalidFormNameException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
