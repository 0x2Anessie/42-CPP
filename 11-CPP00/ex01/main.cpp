#include "PhoneBook.hpp"

/*
	main
	- On cree une string input pour stocker les entrees de l'utilisateur
	- On cree un objet PhoneBook repertoire
	- On affiche le titre du programme
	- On cree une boucle infinie
	- On demande a l'utilisateur d'entrer une commande
	- Si l'utilisateur entre "EXIT" ou "exit", on quitte le programme
	- Si l'utilisateur entre "ADD" ou "add", on appelle la methode add de repertoire
	- Si l'utilisateur entre "SEARCH" ou "search", on appelle la methode search de repertoire
*/
int		main()
{
	std::string input;
	PhoneBook repertoire;
	std::cout << "\033c";
	std::cout << "\033[36m┓ ┏  ┓                      ┏┓┓       ┳┓    ┓ " << std::endl;
	std::cout << "┃┃┃┏┓┃┏┏┓┏┳┓┏┓  ╋┏┓  ┏┳┓┓┏  ┃┃┣┓┏┓┏┓┏┓┣┫┏┓┏┓┃┏" << std::endl;
	std::cout << "┗┻┛┗ ┗┗┗┛┛┗┗┗   ┗┗┛  ┛┗┗┗┫  ┣┛┛┗┗┛┛┗┗ ┻┛┗┛┗┛┛┗\033[0m" << std::endl;
	while(1)
	{
		std::cout << "\nADD/SEARCH/EXIT: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if(input == "EXIT" || input == "exit")
			return(0);
		else if(input == "ADD" || input == "add")
			repertoire.add();
		else if(input == "SEARCH" || input == "search")
			repertoire.search();
	}
}
