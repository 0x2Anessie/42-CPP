#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << MAGENTA << BOLD << "✧ Cat default constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << MAGENTA << "Cat copy constructor called." << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << MAGENTA << "Cat assignation operator called." << RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << MAGENTA << "Cat default destructor called." << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << BOLD << MAGENTA << "  Meow Meow Meow" << RESET << std::endl;
}
