#pragma once
#include <iostream>
#include "Weapon.hpp"

// BOB
class HumanA
{
	public:
		HumanA(std::string name, Weapon &arme);
		~HumanA();
		void	attack();
	private:
		Weapon			&_arme;
		std::string		_name;
};
