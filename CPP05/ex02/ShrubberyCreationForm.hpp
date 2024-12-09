#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();
		// ━━━━━━━━━━━━━━━━ Functions ━━━━━━━━━━━━━━━━━ //
		void execute(Bureaucrat const &executor) const;
		// ━━━━━━━━━━━━━━━━ Exceptions ━━━━━━━━━━━━━━━━ //
		class FileNotOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string target;
};
