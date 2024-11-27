#include "Zombie.hpp"

/*
	Vise a montrer les trois differentes manieres d'instancier un objet 
	de la classe Zombie.
	Pierre est cree dans le main et detruit a la fin de la fonction main, il
	est donc cree sur la pile.
	Paul est cree dans la fonction newZombie grace a la fonction new, il est
	donc cree sur le tas et doit etre detruit manuellement.
	Jacques est cree dans la fonction randomChump, il est donc cree sur la pile
	et detruit a la fin de la fonction randomChump.
*/
int		main()
{
	std::cout << "\033c";
	std::cout << BOLD << "Zombie créé sur le tas (heap) :" << RESET << std::endl;
	Zombie* HeapZombie = newZombie("Pierre");
	HeapZombie->announce();
	delete HeapZombie;
	HeapZombie = NULL;
	std::cout << std::endl;

	std::cout << BOLD << "Zombie créé sur la pile dans la fonction randomChump :" << RESET << std::endl;
	randomChump("Paul");
	std::cout << std::endl;

	std::cout << BOLD << "Zombie créé sur la pile (stack) :" << RESET << std::endl;
	Zombie MainZombie("Jacques");
	MainZombie.announce();

	std::cout << "\nFin de la fonction main\n" << std::endl;
}
