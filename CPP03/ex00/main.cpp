#include "ClapTrap.hpp"

/*
	Quand Clapita attaque, elle perd 1 EnergyPoint et cause 0 AttackDamage
	aux HitPoint de Trapita.
	Quand elle takeDamage, elle perd <amount> HitPoint.
	Quand elle beRepaired, elle regagne <amount> HitPoint et perd 1 EnergyPoint.
*/
int	main()
{
	std::cout << "\033c";
	std::cout << BOLD << BLUE << "       CLAPTRAP INIT" << RESET << std::endl;
	ClapTrap Clapita("Clapita");
	ClapTrap Clapito("Clapito");
	std::cout << std::endl;

	std::cout << BOLD << BLUE << "          BATTLE" << RESET << std::endl;
	std::cout << "Clapita and Clapito have 10 Hit Points and 10 Energy Points\n" << std::endl;
	Clapita.attack("Trapita");
	Clapita.takeDamage(10);
	Clapita.takeDamage(5);
	Clapita.beRepaired(10);
	std::cout << std::endl;

	Clapito.attack("Trapito");
	Clapito.takeDamage(5);
	Clapito.beRepaired(5);
	Clapito.takeDamage(5);
	Clapito.takeDamage(5);
	Clapito.takeDamage(5);
	std::cout << std::endl;
	std::cout << BOLD << BLUE << "      CLAPTRAP DESTRUCT" << RESET << std::endl;
}
