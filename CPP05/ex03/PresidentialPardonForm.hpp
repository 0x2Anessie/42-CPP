#pragma once
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string const &_target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		// ━━━━━━━━━━━━━━━━ Functions ━━━━━━━━━━━━━━━━━ //
		void execute(Bureaucrat const &executor) const;

	private:
		std::string target;
};
