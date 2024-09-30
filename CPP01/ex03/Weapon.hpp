/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:04:54 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 11:52:34 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string arme);
		~Weapon();
		std::string const		&getType() const;
		void					setType(std::string const &newtype);
	private:
		std::string		_type;
};
