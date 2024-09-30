/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:53:38 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/24 17:54:49 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	Zombie::Zombie(std::string name) : _name(name)
	{
		std::cout << "▶ " << GREEN << _name << " créé." << RESET << std::endl;
	}
	Zombie::~Zombie()
	{
		// std::cout << _name << " destructeur" << std::endl;
	}

	Zombie::Zombie()
	{}
	void	Zombie::announce(void)
	{
		std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
