/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:50:26 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 16:29:53 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do !" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

/*
	"Levels" est un tableau de string contenant les levels de complains.
	"Fonction" est un tableau de pointeurs ou chaque pointeur correspond
	à une méthode de Harl.
	Vu que la fonction complain prend en paramètre un des quatre complains
	possible, on va parcourir le tableau de string "Levels" et si on trouve
	le level passé en paramètre, on va appeler la méthode correspondante.
*/
void	Harl::complain(std::string level)
{
	std::string		Levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*fonction[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for(size_t i = 0; i < 4; i++)
	{
		if(Levels[i] == level)
		{
			(this->*(fonction[i]))();
			return ;
		}
	}
	std::cout << "Invalide complaint level " << level << std::endl;
}
