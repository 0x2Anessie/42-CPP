#pragma once
#include <iostream>
#include "Weapon.hpp"

// JIM
class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(const Weapon &newarme);
		void	attack();
	private:
		const Weapon	*_arme;
		std::string		_name;
};
