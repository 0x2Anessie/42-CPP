#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << CYAN << BOLD << "✧ Dog default constructor called." << RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << CYAN << "Dog copy constructor called." << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << CYAN << "Dog assignation operator called." << RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog default destructor called." << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << BOLD << CYAN << "  Woof Woof Woof" << RESET << std::endl;
}
