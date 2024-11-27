#include "Weapon.hpp"

Weapon::Weapon(std::string  arme) : _type(arme)
{}

Weapon::~Weapon()
{}

// Getter
std::string const		&Weapon::getType() const
{
	return(_type);
}

// Setter
void	Weapon::setType(std::string const &newtype)
{
	_type = newtype;
}
