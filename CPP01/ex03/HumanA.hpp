/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:23 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 11:58:06 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

// BOB
class HumanA
{
	public:
		HumanA(std::string name, Weapon &arme);
		~HumanA();
		void	attack();
	private:
		Weapon			&_arme;
		std::string		_name;
};
