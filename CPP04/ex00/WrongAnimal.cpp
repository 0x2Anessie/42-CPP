#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << YELLOW << BOLD << "✧ Wrong Animal default constructor called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << RED << "Wrong Animal copy constructor called." << RESET << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << RED << "Wrong Animal assignation operator called." << RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "Wrong Animal default destructor called." << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << BOLD << RED << "  *wrong animal noise*" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
