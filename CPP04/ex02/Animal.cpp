#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << BLUE << BOLD << "✧ Animal default constructor called." << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "|" << BLUE << "Animal copy constructor called." << RESET << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "|" << BLUE << "  Animal assignation operator called." << RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << BOLD << BLUE << "    ->Animal default destructor called." << RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << BOLD << BLUE << "*animal noise*" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
