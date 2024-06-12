#include <iostream>
#include <string>

/*
	Megaphone
	- Si on a pas d'argument, on renvoie le message "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
	- On met chaque argument dans une string puis on les met en majuscule
	- On ajoute chaque string dans une string qui contient tous les arguments en majuscule
	- On affiche la string en majuscule
*/
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string arg;
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		for (int len = 0; str[len]; len++)
			str[len] = std::toupper(str[len]);
		arg += str;
	}
	std::cout << arg << std::endl;
	return (0);
}
