/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:33 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 11:58:35 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

// JIM
class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(const Weapon &newarme);
		void	attack();
	private:
		const Weapon	*_arme;
		std::string		_name;
};
