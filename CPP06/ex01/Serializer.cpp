#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &other)
{
	(void)other;
}

Serializer &Serializer::operator=(Serializer const &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{}

// On utilise reinterpret_cast, cette forme de cast est utilisée pour convertir un pointeur en un autre type de pointeur.
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// On utilise reinterpret_cast, cette forme de cast est utilisée pour convertir un pointeur en un autre type de pointeur.
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
