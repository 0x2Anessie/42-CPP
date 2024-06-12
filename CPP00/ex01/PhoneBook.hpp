#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"

/*
	PhoneBook
	- On definit un tableau de 8 contacts
	- On definit les methodes add et search
*/
class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
	private:
		contact ami[8];
};
