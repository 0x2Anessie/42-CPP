#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// meta->makeSound();

	std::cout << "\033c";
	const int size = 4;
	Animal* animals[size];

	std::cout << BOLD << "THE TAB TEST:" << RESET << std::endl;
	std::cout << BOLD << "Creating a tab of animals..." << RESET << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << BOLD << "\nMaking them speak..." << RESET << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << BLUE << BOLD << "Animal #" << i + 1 << RESET << " is a " << animals[i]->getType() << " and it says ";
		animals[i]->makeSound();
	}
	std::cout << BOLD << "\nDeleting them..." << RESET << std::endl;
	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << BOLD << "\nTHE DEEP COPY TEST:" << RESET << std::endl;
	std::cout << BOLD << "Creating a dog and a cat..." << RESET << std::endl;
	Dog OGdog;
	OGdog.getBrain()->setIdea(0, "I am a dog");
	Cat OGcat;
	OGcat.getBrain()->setIdea(0, "I am a cat");

	std::cout << BOLD << "\nCreating a copy of the dog and the cat..." << RESET << std::endl;
	Dog copyDog(OGdog);
	std:: cout << std::endl;
	Cat copyCat(OGcat);

	std::cout << BOLD << "\nRead their minds..." << RESET << std::endl;
	std::cout << BOLD << GREEN << "OG dog idea : " << RESET << OGdog.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << BOLD << RED << "Copy dog idea : " << RESET << copyDog.getBrain()->getIdea(0) << RESET << std::endl;

	std::cout << BOLD << GREEN << "OG cat idea : " << RESET << OGcat.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << BOLD << RED << "Copy cat idea : " << RESET << copyCat.getBrain()->getIdea(0) << RESET << std::endl;

	std::cout << BOLD << "\nChanging the ideas of the copies..." << RESET << std::endl;
	copyDog.getBrain()->setIdea(0, "I'm a copy of a dog");
	copyCat.getBrain()->setIdea(0, "I'm a copy of a cat");

	std::cout << BOLD << GREEN << "OG dog idea : " << RESET << OGdog.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << BOLD << RED << "Copy dog idea : " << RESET << copyDog.getBrain()->getIdea(0) << RESET << std::endl;

	std::cout << BOLD <<GREEN << "OG cat idea : " << RESET << OGcat.getBrain()->getIdea(0) << RESET << std::endl;
	std::cout << BOLD << RED << "Copy cat idea : " << RESET << copyCat.getBrain()->getIdea(0) << RESET << std::endl;

	std::cout << BOLD << "\nDeleting the OGs and copies..." << RESET << std::endl;

	return 0;
}
