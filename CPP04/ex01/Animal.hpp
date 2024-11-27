#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal (const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

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

#endif
