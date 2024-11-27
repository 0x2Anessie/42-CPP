#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	std::cout << MAGENTA << BOLD << "    ->Cat default constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "|" << MAGENTA << "      Cat copy constructor called." << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << MAGENTA << "Cat assignation operator called." << RESET << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (_brain != NULL) {
			delete _brain;
			_brain = NULL;
		}
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << BOLD << MAGENTA << "✧ Cat default destructor called." << RESET << std::endl;
	if (_brain != NULL)
	{
		delete _brain;
		_brain = NULL;
	}
}

void Cat::makeSound() const
{
	std::cout << BOLD << MAGENTA << "Meow Meow Meow" << RESET << std::endl;
}

Brain *Cat::getBrain() const
{
	return (_brain);
}
