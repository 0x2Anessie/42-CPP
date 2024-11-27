#include "ClapTrap.hpp"

ClapTrap::ClapTrap (std::string name) : _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "ClapTrap ✧" << CYAN << _name << RESET << "✧ created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap " << _name << " copy constructor" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << _name << " assignation operator" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_HitPoint = other._HitPoint;
	_EnergyPoint = other._EnergyPoint;
	_AttackDamage = other._AttackDamage;
	return (*this);
}

ClapTrap::~ClapTrap ()
{
	std::cout << "ClapTrap ✧" << CYAN << _name << RESET << "✧ destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoint == 0 || _HitPoint == 0)
	{
		std::cout << "ClapTrap " << CYAN << _name << " can't attack because it's out of energy or hit points." << RESET << std::endl;
		return;
	}
	--_EnergyPoint;
	std::cout << "ClapTrap " << CYAN << _name << " attack " << target << ", causing " << _AttackDamage << " damage" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoint == 0)
	{
		std::cout << "ClapTrap " <<CYAN <<  _name << " can't take more damage!" << RESET << std::endl;
		return;
	}
	if (amount > _HitPoint)
	{
		std::cout << "ClapTrap " <<CYAN <<  _name << " can't take more damage!" << RESET << std::endl;
		return;
	}
	else
	{
		_HitPoint -= amount;
		std::cout << "ClapTrap " << _name << RED << " took " << amount << " damage!" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoint == 0)
	{
		std::cout << "ClapTrap " << CYAN << _name << " can't heal because it's out of energy or hit points." << RESET << std::endl;
		return;
	}
	_HitPoint += amount;
	--_EnergyPoint;
	std::cout << "ClapTrap " << _name << GREEN << " healed of " << amount << " points!" << RESET << std::endl;
}
