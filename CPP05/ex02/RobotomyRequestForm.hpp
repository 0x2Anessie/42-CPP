#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string const &_target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm();
		// ━━━━━━━━━━━━━━━━ Functions ━━━━━━━━━━━━━━━━━ //
		void execute(Bureaucrat const &executor) const;

	private:
		std::string target;
};
