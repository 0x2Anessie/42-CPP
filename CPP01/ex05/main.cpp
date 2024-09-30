/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:50:36 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 16:27:46 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
	▶ Vise a montrer comment fonctionne les methodes de classe, comment on peut
	stocker des pointeurs de methodes dans un tableau et comment on peut les
	appeler.

	Le main va créer une instance de Harl et va appeler la méthode complain
	avec un des quatre levels possible.
*/
int		main()
{
	Harl harl;
	
	std::cout << "\033c";
	std::cout << GREEN << "DEBUG : " << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << GREEN << "INFO : " << RESET << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << GREEN << "WARNING : " << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << GREEN << "ERROR : " << RESET << std::endl;
	harl.complain("ERROR");

	// std::cout << std::endl;
	// std::cout << MAGENTA << "TEST : " << RESET << std::endl;
	// harl.complain("TEST");
}