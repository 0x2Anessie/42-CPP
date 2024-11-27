#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BOLD << YELLOW << "  ->Brain default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << "|" << YELLOW << "    Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << YELLOW << BOLD << "  ->Brain destructor called" << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100) {
		std::cout << "Index out of range" << std::endl;
		return "";
	}
	return ideas[index];
}
