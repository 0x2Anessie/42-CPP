#include "Fonction.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Cette fonction utilise dynamic_cast pour identifier le type de la classe pointée par le pointeur p.
int main()
{
	std::srand(std::time(0));
	for(int i = 0; i < 6; i++)
	{
		// On utilise la fonction generate pour créer un objet de type A, B ou C
		Base *base = generate();

		// On utilise la fonction identify pour identifier le type de l'objet
		// Pour cela on utilise un pointeur et une référence sur la classe de base
		std::cout << BOLD << "Identifying pointer: " << RESET;
		identify(base);
		std::cout << BOLD << "Identifying reference: " << RESET;
		identify(*base);

		std::cout << std::endl;
		delete base;
	}
	return 0;
}