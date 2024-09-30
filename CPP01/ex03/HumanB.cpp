/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:27 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 11:58:25 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// JIM
HumanB::HumanB(std::string name) : _name(name)
{
	_arme = NULL;
}

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	if(_arme)
		std::cout << _name << " attack with their " << _arme->getType() << std::endl;
	else
		std::cout << _name << " attack with their mind" << std::endl;
}

void	HumanB::setWeapon(const Weapon &newarme)
{
	_arme = &newarme;
}
