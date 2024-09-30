/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:17 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 11:52:54 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// BOB
HumanA::HumanA(std::string name, Weapon &arme) : _arme(arme), _name(name)
{}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << _name << " attack with their " << _arme.getType() << std::endl;
}
