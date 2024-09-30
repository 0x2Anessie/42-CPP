/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:49 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 11:58:54 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string  arme) : _type(arme)
{}

Weapon::~Weapon()
{}

// Getter
std::string const		&Weapon::getType() const
{
	return(_type);
}

// Setter
void	Weapon::setType(std::string const &newtype)
{
	_type = newtype;
}
