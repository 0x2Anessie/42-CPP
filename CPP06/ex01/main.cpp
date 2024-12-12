#include "Serializer.hpp"
#include <iostream>

/*
	Note: La sérialisation est le processus de conversion d'un objet en une séquence
	d'octets ou en une autre forme de données qui peut être facilement stockée ou transmise.
	-> Ici, on convertit un pointeur en un entier non signé de type uintptr_t.
	La désérialisation est le processus inverse de la sérialisation, on reconvertit
	la séquence d'octets en un objet.
	-> Ici, on reconvertit un entier non signé de type uintptr_t en un pointeur de type Data*.
	Cet exercice consiste juste à vérifier si la désérialisation fonctionne correctement.
*/
int main()
{
	// Création de plusieurs objets Data
	Data data1 = {1, "Alice"};
	Data data2 = {2, "Bob"};
	Data data3 = {3, "Charlie"};

	Data* ptr1 = &data1;
	Data* ptr2 = &data2;
	Data* ptr3 = &data3;

	// Affichage des adresses des objets
	std::cout << BOLD << "Adresses des objets Data :\n" << RESET << std::endl;
	std::cout << "Data 1 : " << BLUE << BOLD << ptr1 << RESET << std::endl;
	std::cout << "Data 2 : " << BLUE << BOLD << ptr2 << RESET << std::endl;
	std::cout << "Data 3 : " << BLUE << BOLD << ptr3 << RESET << "\n" << std::endl;

	// Sérialisation
	uintptr_t serialized1 = Serializer::serialize(ptr1);
	uintptr_t serialized2 = Serializer::serialize(ptr2);
	uintptr_t serialized3 = Serializer::serialize(ptr3);

	// Vérification des sérialisations
	std::cout << MAGENTA << BOLD << "Sérialisations :\n" << RESET << std::endl;
	std::cout << "Data 1 : " << (serialized1 == (uintptr_t)ptr1 ? GREEN_BOLD "Réussi" : RED_BOLD "Échoué") << RESET << std::endl;
	std::cout << "Adresse après sérialisations : " << MAGENTA << BOLD << serialized1 << RESET << "\n" << std::endl;
	std::cout << "Data 2 : " << (serialized2 == (uintptr_t)ptr2 ? GREEN_BOLD "Réussi" : RED_BOLD "Échoué") << RESET << std::endl;
	std::cout << "Adresse après sérialisations : " << MAGENTA << BOLD << serialized2 << RESET << "\n" << std::endl;
	std::cout << "Data 3 : " << (serialized3 == (uintptr_t)ptr3 ? GREEN_BOLD "Réussi" : RED_BOLD "Échoué") << RESET << std::endl;
	std::cout << "Adresse après sérialisations : " << MAGENTA << BOLD << serialized3 << RESET << "\n" << std::endl;

	// Désérialisation
	Data* deserialized1 = Serializer::deserialize(serialized1);
	Data* deserialized2 = Serializer::deserialize(serialized2);
	Data* deserialized3 = Serializer::deserialize(serialized3);

	// Vérification des deserialisations
	std::cout << BLUE << BOLD << "Désérialisations :\n" << RESET << std::endl;
	std::cout << "Data 1 : " << (deserialized1 == ptr1 ? GREEN_BOLD "Réussi" : RED_BOLD "Échoué") << RESET << std::endl;
	std::cout << "Adresse après désérialisation : " << BLUE << BOLD << deserialized1 << RESET << "\n" << std::endl;
	std::cout << "Data 2 : " << (deserialized2 == ptr2 ? GREEN_BOLD "Réussi" : RED_BOLD "Échoué") << RESET << std::endl;
	std::cout << "Adresse après désérialisation : " << BLUE << BOLD << deserialized2 << RESET << "\n" << std::endl;
	std::cout << "Data 3 : " << (deserialized3 == ptr3 ? GREEN_BOLD "Réussi" : RED_BOLD "Échoué") << RESET << std::endl;
	std::cout << "Adresse après désérialisation : " << BLUE << BOLD << deserialized3 << RESET << std::endl;

	return 0;
}