/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:49:09 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/24 16:51:15 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	Zombie::Zombie(std::string name) : _name(name)
	{
		std::cout << GREEN << "Le Zombie " << _name << " a été créé" << RESET << std::endl;
	}

	Zombie::~Zombie()
	{
		std::cout << RED << "Le Zombie " << _name << " vient d'être détruit" << RESET << std::endl;
	}

	void	Zombie::announce(void)
	{
		std::cout << "▶ " << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
