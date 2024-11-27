#include "FragTrap.hpp"

/*
	appelle le constructeur de ClapTrap avec le paramètre name. Cela initialise
	les membres de la classe de base ClapTrap.
	Ensuite on modifie les valeurs des membres herites de claptrap selon les
	demandes du sujet.
*/
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	std::cout << "-> FragTrap ✧" << MAGENTA << _name << RESET << "✧ comes into the world!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " comes into the world by copy!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " comes into the world by assignation!" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "-> FragTrap ✧" << MAGENTA << _name << RESET << "✧ has left the world" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " is asking for a high five!" << RESET << std::endl;
}
