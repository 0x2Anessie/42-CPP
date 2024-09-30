/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:53:48 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/24 17:57:07 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	Cree un tableau de N instances de la classe Zombie.
	Pour chaque instance, on appelle le constructeur de la classe Zombie.
*/
Zombie		*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie		*Horde;

	i = 0;
	Horde = new Zombie[N];
	while(i < N)
	{
		std::cout << BOLD << "Appel du constructeur pour le Zombie " << i + 1 << " :" << RESET << std::endl;
		Horde[i] = Zombie(name);
		i++;
	}
	return(Horde);
}
