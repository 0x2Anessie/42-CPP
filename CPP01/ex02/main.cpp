/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:59:26 by acatusse          #+#    #+#             */
/*   Updated: 2024/09/24 18:03:13 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	▶ Vise a montrer ce qu'est une référence en C++.

	Une référence est un alias, ou un autre nom pour une variable existante.
	Elle est déclarée en utilisant le symbole &.
	A travers cette serie de tests, on va montrer que la référence s'utilise
	comme la variable originale.
*/
int		main()
{
	std::cout << "\033c";

	std::string		String = "HI THIS IS BRAIN";
	std::string		*StringPTR = &String;
	std::string		&StringREF = String;

	std::cout << "\x1b[1mNous avons trois variables:\x1b[0m " << std::endl;
	std::cout << "\x1b[35m  String      \x1b[0m= " << String << "  \x1b[35m//\x1b[0m De type string" << std::endl;
	std::cout << "\x1b[35m  StringPTR   \x1b[0m= " << StringPTR << "    \x1b[35m//\x1b[0m De type string*" << std::endl;
	std::cout << "\x1b[35m  StringREF   \x1b[0m= " << StringREF << "  \x1b[35m//\x1b[0m De type string&" << std::endl;
	std::cout << std::endl;

	std::cout << "\x1b[1mPour afficher l'adresse:\x1b[0m " << std::endl;
	std::cout << "  \x1b[35m&\x1b[0mString    -> " << &String << std::endl;
	std::cout << "  StringPTR  -> " << StringPTR << std::endl;
	std::cout << "  \x1b[35m&\x1b[0mStringREF -> " << &StringREF << std::endl;
	std::cout << std::endl;

	std::cout << "\x1b[1mPour afficher la valeur:\x1b[0m " << std::endl;
	std::cout << "  String     -> " << String << std::endl;
	std::cout << "  \x1b[35m*\x1b[0mStringPTR -> " << *StringPTR << std::endl;
	std::cout << "  StringREF  -> " << StringREF << std::endl;
	std::cout << std::endl;

	std::cout << "\x1b[35mEn gros, une référence est un alias, ou un autre nom pour une variable existante, \x1b[0m" << std::endl;
	std::cout << std::endl;
}
