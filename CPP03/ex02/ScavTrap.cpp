#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
	std::cout << "-> ScavTrap ✧" << BLUE << _name << RESET << "✧ is born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " is born by copy!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << " is born by assignation!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "-> ScavTrap ✧" << BLUE << _name << RESET << "✧ is dead!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_EnergyPoint == 0 || _HitPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack because it's out of energy or hit points." << std::endl;
		return;
	}
	--_EnergyPoint;
	std::cout << "ScavTrap " << BLUE << _name << " attack " << target << ", causing " << _AttackDamage << " damage" << RESET << std::endl;
}
