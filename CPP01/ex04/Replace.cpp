/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:50:15 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/30 15:50:07 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

/*
	La line devient la partie de la string avant la première occurence de s1,
	on y ajoute s2, puis on ajoute la partie de la string après S1.
	Ensuite on avance pos_0 pour ne pas tomber dans une boucle infinie.
*/
std::string	replace_line(std::string str, std::string s1, std::string s2)
{
	size_t		pos_find = 0; // position de la première occurence de s1
	size_t		pos_0 = 0;

	while((pos_find = str.find(s1, pos_0)) != std::string::npos) // npos = "/0"
	{
		str = str.substr(0, pos_find) + s2 + str.substr(pos_find + s1.length());
		pos_0 = pos_find + s2.length();
	}
	return str;
}

/*
	On cree oldfile pour avoir une instance utilisable par ifstream et qui
	contient le filename.
	On cree newfile pour avoir une instance utilisable par ofstream et qui
	contient le filename + ".replace".
	Ensuite ch
*/
void	ft_replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	OldFile(filename.c_str());

	if(!OldFile.is_open())
	{
		std::cout << RED << BOLD << "Error: Le fichier n'est pas ouvert." << RESET << std::endl;
		return ;
	}

	std::string		NewFileName = filename + ".replace";
	std::ofstream	NewFile(NewFileName.c_str());

	if(!NewFile.is_open())
	{
		std::cout << RED << BOLD << "Error: Le nouveau fichier n'a pas pu etre ouvert" << RESET << std::endl;
		OldFile.close();
		return ;
	}

	std::string		line;
	int i = 0;

	while(std::getline(OldFile, line))
	{
		std::cout << YELLOW << BOLD << "Ligne " << i + 1 << ":" << RESET << std::endl;
		std::cout << "Avant modification: " << line << std::endl;

		line = replace_line(line, s1, s2);
		NewFile << line << std::endl;
		
		std::cout << "Après modification: " << line << std::endl;
		i++;
	}
	OldFile.close();
	NewFile.close();
}

