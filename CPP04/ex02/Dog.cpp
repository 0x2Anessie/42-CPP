#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	std::cout << BOLD << CYAN << "    ->Dog default constructor called." << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "|" << CYAN << "      Dog copy constructor called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		std::cout << CYAN << "Dog assignation operator called." << RESET << std::endl;
		Animal::operator=(other);
		if (_brain != NULL) {
			delete _brain;
			_brain = NULL;
		}
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << BOLD << CYAN << "✧ Dog default destructor called." << RESET << std::endl;
	if (_brain != NULL) {
		delete _brain;
		_brain = NULL;
	}
}

void Dog::makeSound() const
{
	std::cout << BOLD << CYAN << "Woof Woof Woof" << RESET << std::endl;
}

Brain *Dog::getBrain() const
{
	return (_brain);
}
