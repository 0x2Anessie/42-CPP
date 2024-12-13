#include "Fonction.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

// Génère un objet de type A, B ou C aléatoirement
// std::rand() % 3 == 0 génère un nombre aléatoire entre 0 et 2
Base *generate(void)
{
	if(std::rand() % 3 == 0)
	{
		std::cout << BOLD << BLUE << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟA element generated" << RESET << std::endl;
		return new A();
	}
	else if(std::rand() % 3 == 1)
	{
		std::cout << BOLD << CYAN << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟB element generated" << RESET << std::endl;
		return new B();
	}
	else
	{
		std::cout << BOLD << MAGENTA << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟC element generated" << RESET << std::endl;
		return new C();
	}
}

// Utilise dynamic_cast pour identifier le type de la classe pointée par le pointeur p.
// dynamic_cast renvoie un pointeur de la classe demandée si le cast est possible, sinon il renvoie nullptr.
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << BOLD << BLUE << "  A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BOLD << CYAN << "  B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BOLD << MAGENTA << "  C" << RESET << std::endl;
	else
		std::cerr << BOLD << RED << "Unknown type" << RESET << std::endl;
}

// Utilise dynamic_cast pour identifier le type de la classe référencée par la référence p
// En gros a chaque fois on essaie de caster p en A, B et C, si on arrive a caster p en A ca veut dire que p est un A
// donc on peut le return, sinon on essaie de caster p en B, si on y arrive c'est un B, sinon on essaie de caster p en C.
// On utilise try catch parce que si le cast echoue lance une exception.
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << BOLD << BLUE << "A" << RESET << std::endl;
		return;
	}
	catch(...)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << BOLD << CYAN << "B" << RESET << std::endl;
		return;
	}
	catch(...)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << BOLD << MAGENTA << "C" << RESET << std::endl;
		return;
	}
	catch(...)
	{
		std::cerr << BOLD << RED << "Unknown type" << RESET << std::endl;
	}
}
