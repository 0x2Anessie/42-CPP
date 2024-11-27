#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	std::cout << "\033c";
	std::cout << BOLD << BLUE << "       CLAPTRAP INIT" << RESET << std::endl;
	ClapTrap Clapita("Clapita");
	ClapTrap Clapito("Clapito");
	ScavTrap Scavita("Scavita");
	ScavTrap Scavito("Scavito");
	std::cout << std::endl;

	std::cout << BOLD << BLUE << "          BATTLE" << RESET << std::endl;
	std::cout << "Clapita and Clapito have 10 Hit Points and 10 Energy Points\n" << std::endl;
	Clapita.attack("Trapita");
	Clapita.takeDamage(5);
	Clapita.takeDamage(7);
	Clapita.beRepaired(5);
	std::cout << std::endl;

	Clapito.attack("Trapito");
	Clapito.takeDamage(5);
	Clapito.beRepaired(5);
	Clapito.takeDamage(5);
	Clapito.takeDamage(5);
	Clapito.takeDamage(5);
	std::cout << std::endl;

	std::cout << "Scavita and Scavito have 100 Hit Points and 50 Energy Points\n" << std::endl;
	Scavita.guardGate();
	Scavita.attack("Vitta");
	Scavita.takeDamage(100);
	Scavita.takeDamage(2);
	Scavita.beRepaired(50);
	Scavita.takeDamage(49);
	Scavita.takeDamage(2);
	std::cout << std::endl;
	
	Scavito.guardGate();
	Scavito.attack("Vitto");
	Scavito.takeDamage(50);
	Scavito.beRepaired(30);
	Scavito.takeDamage(70);
	Scavito.takeDamage(10);
	
	std::cout << std::endl;
	std::cout << BOLD << BLUE << "      CLAPTRAP DESTRUCT" << RESET << std::endl;
	return (0);
}
