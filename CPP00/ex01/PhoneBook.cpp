#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	// std::cout << "constructeur called" << std::endl;

}
PhoneBook::~PhoneBook()
{
	// std::cout << "destructeur called" << std::endl;
}

/*
	PhoneBook
	- On cree une string input pour stocker les entrees de l'utilisateur
	- On cree un booleen b initialise a false
	- Pour chaque attribut d'un contact, on demande a l'utilisateur de rentrer une valeur
	- Cela fonctionne avec un systeme de boucle et de booleen pour verifier que l'utilisateur a bien rentre une valeur
	- La boucle s'arrete si l'utilisateur entre sa valeur, le booleen b passe a true et on passe a l'attribut suivant
	- A la fin de tous les assets on incremente i pour passer au contact suivant dans le tableau ami
	- On fait un modulo 8 pour que i reste entre 0 et 7 (car on a 8 contacts
*/
void	PhoneBook::add()
{
	static int		i = 0;
	std::cout << "\033c";
	std::cout << "\033[36m\033[1mNouveau Contact\n\033[0m" << std::endl;
	std::string input;
	bool b = false;
	while (b != true)
	{
		std::cout << "\033[1mC'est quoi ton ptit prénom ?\033[0m" << std::endl << "▶ ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!input.empty())
			b = true;
	}
	ami[i].setFirstName(input);
	b = false;
	while (b != true)
	{
		std::cout << "\n\033[1mTon nom de famille ?\033[0m" << std::endl << "▶ ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!input.empty())
			b = true;
	}
	ami[i].setLastName(input);
	b = false;
	while (b != true)
	{
		std::cout << "\n\033[1mTon ptit surnom ?\033[0m" << std::endl << "▶ ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!input.empty())
			b = true;
	}
	ami[i].setNickname(input);
	b = false;
	while (b != true)
	{
		std::cout << "\n\033[1mTon 06 ? (ou 07 pas de jugement)\033[0m" << std::endl << "▶ ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!input.empty())
		{
			b = true;
			if (input.length() != 10)
			{
				std::cout << "\n\033[31mTon num doit être composé de 10 chiffres\033[0m" << std::endl;
				b = false;
			}
			else
			{
				for (size_t i = 0; i < input.length(); i++)
				{
					if (!std::isdigit((unsigned char)(input[i])))
					{
						std::cout << "\n\033[31mIl semblerait que y'ait pas que des chiffres dans ton num..\033[0m" << std::endl;
						b = false;
						break;
					}
				}
			}
		}
	}
	ami[i].setPhoneNumber(input);
	b = false;
	while (b != true)
	{
		std::cout << "\n\033[1mEt enfin, quel est ton plus lourd secret ?\033[0m" << std::endl << "▶ ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!input.empty())
			b = true;
	}
	ami[i].setDarkestSecret(input);
	i++;
	i %= 8;
}

/*
	PhoneBook
	- On affiche les titres des colonnes
	- On cree une boucle de 0 a 7 pour afficher les informations de chaque contact
	- On tronque les prenoms, noms et surnoms a 10 caracteres et on ajoute un point a la fin si la longueur est de 10 caracteres
	- On affiche les informations de chaque contact dans les colonnes correspondantes
	- On demande a l'utilisateur de choisir un index entre 1 et 8 pour consulter un contact
	- On affiche les informations du contact correspondant a l'index choisi par l'utilisateur
*/
void	PhoneBook::search()
{
	std::string		input;
	int		i = 0;

	std::cout << "\033c";
	std::cout << std::setw(10) << std::right << "Index" << "|"
		<< std::setw(10) << std::right << "First name" << "|"
		<< std::setw(10) << std::right << "Last name" << "|"
		<< std::setw(10) << std::right << "Nickname" << "|"
		<< std::endl;
	while(i < 8)
	{
		std::string truncFirstName = ami[i].getFirstName().substr(0, 10);
		std::string truncLastName = ami[i].getLastName().substr(0, 10);
		std::string truncNickname = ami[i].getNickname().substr(0, 10); 
		if (truncFirstName.length() == 10)
			truncFirstName[9] = '.';
		if (truncLastName.length() == 10)
			truncLastName[9] = '.';
		if (truncNickname.length() == 10)
			truncNickname[9] = '.';
		std::cout << std::setw(10) << std::right << i + 1 << "|"
			<< std::setw(10) << std::right << truncFirstName << "|"
			<< std::setw(10) << std::right << truncLastName << "|"
			<< std::setw(10) << std::right << truncNickname << "|"
			<< std::endl;
		i++;
	}
	std::cout << "\n\033[36mQuel est l'index du contact que tu souhaite consulter ?\033[0m" << std::endl << "▶ ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	if(input.length() != 1 || (input < "1" || input > "8"))
	{
		std::cout << "\033[31mL'index doit être un chiffre entre 1 et 8\033[0m" << std::endl;
		return ;
	}
	i = std::atoi(input.c_str());
	std::cout << "\033c";
	std::cout << "\n\033[36m\033[1mFirst Name :\033[0m " << ami[i - 1].getFirstName() << std::endl;
	std::cout << "\n\033[36m\033[1mLast Name :\033[0m " << ami[i - 1].getLastName() << std::endl;
	std::cout << "\n\033[36m\033[1mNickname :\033[0m " << ami[i - 1].getNickname() << std::endl;
	std::cout << "\n\033[36m\033[1mPhone Number :\033[0m " << ami[i - 1].getPhoneNumber() << std::endl;
	std::cout << "\n\033[36m\033[1mDarkest Secret :\033[0m " << ami[i - 1].getDarkestSecret() << std::endl;
}
