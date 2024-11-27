#include "Zombie.hpp"

/*
	▶ Vise a montrer comment creer un tableau de N instances d'une classe.
	
	Dans la fonction zombieHorde on va creer un tableau de N instances de la
	classe Zombie et on va appeler le constructeur pour chaque instance.
	Vu qu'on utilise new pour creer le tableau, il faudra penser a delete le
	tableau a la fin de la fonction main pour eviter les fuites memoire.
	
	Ensuite on va appeler la methode announce pour chaque instance de la Horde.
*/
int		main()
{
	int		i;
	int		NombreDeZombies;
	Zombie		*HordeDeZombies;

	i = 0;
	NombreDeZombies = 5;
	
	std::cout << "\033c";
	std::cout << BOLD << "La horde de Zombies comporte " << NombreDeZombies << " Zombies\n" << RESET << std::endl;
	HordeDeZombies = zombieHorde(NombreDeZombies, "Zombie");
	std::cout << GREEN << "\nLa Horde de Zombies a été créée avec succés !" << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << "Appel de la méthode announce pour chaque Zombie de la Horde :" << RESET << std::endl;
	while(i < NombreDeZombies)
	{
		std::cout << GREEN << i + 1 << RESET << " ▶ ";
		HordeDeZombies[i].announce();
		i++;
	}
	delete[] HordeDeZombies;
	std::cout << std::endl;
}
