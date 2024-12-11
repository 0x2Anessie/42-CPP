#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data myData;
	myData.id = 42;
	myData.name = "Pierre";
	Data* originalPtr = &myData; // Pointeur original vers l'objet Data

	uintptr_t serializedData = Serializer::serialize(originalPtr);
	Data* deserializedPtr = Serializer::deserialize(serializedData);

	if (deserializedPtr == originalPtr)
		std::cout << GREEN << "La désérialisation a réussi" << RESET << std::endl;
	else
		std::cout << RED << "La désérialisation a échoué" << RESET << std::endl;
	// Modification de la donnee serialisee pour simuler une erreur.
	uintptr_t modifiedSerializedData = serializedData + 1;
	deserializedPtr = Serializer::deserialize(modifiedSerializedData);

	if (deserializedPtr == originalPtr)
		std::cout << RED << "La désérialisation a réussi" << RESET << std::endl;
	else
		std::cout << GREEN << "La désérialisation a échoué" << RESET << std::endl;
	return 0;
}