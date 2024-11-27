#include "HumanA.hpp"

// BOB
HumanA::HumanA(std::string name, Weapon &arme) : _arme(arme), _name(name)
{}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << _name << " attack with their " << _arme.getType() << std::endl;
}
