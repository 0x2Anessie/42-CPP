#pragma once
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string arme);
		~Weapon();
		std::string const		&getType() const;
		void					setType(std::string const &newtype);
	private:
		std::string		_type;
};
