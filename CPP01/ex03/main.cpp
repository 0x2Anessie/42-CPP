/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:38 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/24 18:27:36 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	▶ Vise a montrer la différence entre une référence et un pointeur en C++.

	A travers cette serie de tests, on va montrer que la référence s'utilise
	comme la variable originale alors que le pointeur doit être dereferencé pour
	avoir accès à la valeur de la variable.

*/
int main()
{
	std::cout << "\033c";
	std::cout << "██████   █████   ██████   █████  ██████  ██████  ███████" << std::endl;
	std::cout << "██   ██ ██   ██ ██       ██   ██ ██   ██ ██   ██ ██     " << std::endl;
	std::cout << "██████  ███████ ██   ███ ███████ ██████  ██████  █████  " << std::endl;
	std::cout << "██   ██ ██   ██ ██    ██ ██   ██ ██   ██ ██   ██ ██     " << std::endl;
	std::cout << "██████  ██   ██  ██████  ██   ██ ██   ██ ██   ██ ███████" << std::endl;
	std::cout << std::endl;

	{
		Weapon  club = Weapon("crude spiked club");
		HumanA Bob("Bob", club);
		Bob.attack();
		club.setType("some other type of club");
		Bob.attack();
	}

	std::cout << std::endl;
	
	{
		Weapon  club = Weapon("crude spiked club");
		HumanB Jim("Jim");
		Jim.attack();
		Jim.setWeapon(club);
		Jim.attack();
		club.setType("some other type of club");
		Jim.attack();
	}
	std::cout << std::endl;
	return(0);
}
