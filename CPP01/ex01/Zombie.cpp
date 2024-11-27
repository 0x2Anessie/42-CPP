#include "Zombie.hpp"

	Zombie::Zombie(std::string name) : _name(name)
	{
		std::cout << "▶ " << GREEN << _name << " créé." << RESET << std::endl;
	}
	Zombie::~Zombie()
	{
		// std::cout << _name << " destructeur" << std::endl;
	}

	Zombie::Zombie()
	{}
	void	Zombie::announce(void)
	{
		std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
