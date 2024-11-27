#include "HumanB.hpp"

// JIM
HumanB::HumanB(std::string name) : _name(name)
{
	_arme = NULL;
}

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	if(_arme)
		std::cout << _name << " attack with their " << _arme->getType() << std::endl;
	else
		std::cout << _name << " attack with their mind" << std::endl;
}

void	HumanB::setWeapon(const Weapon &newarme)
{
	_arme = &newarme;
}
