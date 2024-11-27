#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << RED << BOLD << "✧ Wrong Cat default constructor called." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << RED << "Wrong Cat copy constructor called." << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << RED << "Wrong Cat assignation operator called." << RESET << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "Wrong Cat default destructor called." << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << RED << MAGENTA << "  MeEeeEOooOwWw MeEEeEOooOW MeeOooOWwWww" << RESET << std::endl;
}
