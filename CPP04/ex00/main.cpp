#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
	Vise a montrer l'importance de l'implementation en virtual de certaines
	instances des classes parents.
	L'implémentation en virtual permet le polymorphisme en C++. Cela signifie que
	les méthodes marquées comme virtual peuvent être redéfinies dans les classes
	dérivées, permettant ainsi un comportement spécifique à chaque sous-classe.
	Ici c'est makeSound qui est en virtual pour Animal, ce qui fait que quand
	une de ses classes enfants utilisera sa fonction makeSound ce sera son sound
	et pas celui de son parent.
*/
int main()
{
	std::cout << "\033c";
	std::cout << BOLD << "           INIT" << RESET << std::endl;
	
	std::cout << "Construction of the parent class :" << std::endl;
	const Animal* meta = new Animal();
	
	std::cout << "\nConstruction of Doggo :" << std::endl;
	const Animal* doggo = new Dog();

	std::cout << "\nConstruction of Gatito :" << std::endl;
	const Animal* gatito = new Cat();

	std::cout << "\nConstruction of Wrong Animal :" << std::endl;
	const WrongAnimal* fraude1 = new WrongAnimal();

	std::cout << "\nConstruction of Wrong Cat :" << std::endl;
	const WrongAnimal* fraude2 = new WrongCat();

	std::cout << "\nConstruction of Wrong Cat 2 :" << std::endl;
	const WrongCat* fraude3 = new WrongCat();

	std::cout << BOLD << "\n           TESTS" << RESET << std::endl;

	std::cout << "Doggo's type : " << CYAN << BOLD << doggo->getType() << RESET << std::endl;
	std::cout << "Gatito's type : " << MAGENTA << BOLD << gatito->getType() << RESET << std::endl;
	std::cout << "Animals type : " << BOLD << BLUE << meta->getType() << RESET << std::endl;
	std::cout << "Wrong Animal type : " << BOLD << YELLOW << fraude1->getType() << RESET << std::endl;
	std::cout << "Wrong Cat type : " << BOLD << RED << fraude2->getType() << RESET << std::endl;
	std::cout << "Wrong Cat 2 type : " << BOLD << RED << fraude3->getType() << RESET << std::endl;

	std::cout << "\nDoggo's sound : " << std::endl;
	doggo->makeSound();
	std::cout << std::endl;

	std::cout << "Gatito's sound : " << std::endl;
	gatito->makeSound();
	std::cout << std::endl;

	std::cout << "Animals sound : " << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Wrong Animal sound : " << std::endl;
	fraude1->makeSound();
	std::cout << std::endl;

	std::cout << "Wrong Cat's sound : " << std::endl;
	fraude2->makeSound();
	std::cout << std::endl;

	std::cout << "Wrong Cat's 2 sound : " << std::endl;
	fraude3->makeSound();
	
	std::cout << BOLD << "\n         DESTRUCTION" << RESET << std::endl;
	std::cout << BOLD << "Deleting Animal: " << RESET << std::endl;
	delete meta;
	std::cout << BOLD << "Deleting Dog: " << RESET << std::endl;
	delete doggo;
	std::cout << BOLD << "Deleting Cat: " << RESET << std::endl;
	delete gatito;
	std::cout << BOLD << "Deleting Wrong Animal: " << RESET << std::endl;
	delete fraude1;
	std::cout << BOLD << "Deleting Wrong Cat: " << RESET << std::endl;
	delete fraude2;
	std::cout << BOLD << "Deleting Wrong Cat 2: " << RESET << std::endl;
	delete fraude3;
	
	return 0;
}
