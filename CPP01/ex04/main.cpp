/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:50:06 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 15:26:51 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

/*
	▶ Vise a remplacer une string par une autre dans un fichier.

	Ce programme prend en paramètre un fichier et deux strings, copie le 
	contenu du fichier dans le fichier.replace et va remplacer toutes les 
	occurences de la première string par la seconde string.
	On cree file pour avoir une instance utilisable par ifstream et
	pouvoir parser le fichier avec ses methodes.
*/
int		main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << RED << BOLD << "Error: Les arguments attendus sont un fichier et deux strings !" << RESET << std::endl;
		return(1);
	}

	std::string		filename(av[1]);
	std::string		s1(av[2]);
	std::string		s2(av[3]);

	if(s1.empty() || s2.empty())
	{
		std::cout << RED << BOLD << "Error: L'une des deux strings est vide !" << RESET << std::endl;
		return(1);
	}

	std::ifstream	file(filename.c_str()); // c_str() = Convertit un string en char*

	if(!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) // peek() = Verifie que le premier caractere n'est pas la fin du fichier (vide)
	{
		std::cout << RED << BOLD << "Error: Le fichier est vide ou n'est pas ouvert !" << RESET << std::endl; 
		return(1);
	}
	file.close();
	ft_replace(filename, s1, s2);
}
