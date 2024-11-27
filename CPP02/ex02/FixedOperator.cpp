#include "Fixed.hpp"

/*
	La surcharge d'opérateur permet de définir comment les instances de votre
	classe doivent se comporter lorsqu'elles sont utilisées avec des opérateurs
	spécifiques.
	Par défaut, les opérateurs ne sont définis que pour les types primitifs
	(comme int, float, etc.). Pour les types définis par l'utilisateur
	comme les classes, vous devez explicitement définir le comportement
	des opérateurs.
	RHS = Right Hand Side, c'est a dire ce qui se trouve a droite de l'opérateur.
*/

// Operateurs de comparaison
bool Fixed::operator>(const Fixed& rhs) const
{
	return this->value > rhs.value; // retourne true si la valeur de l'objet courant est superieure a celle de rhs
}
bool Fixed::operator<(const Fixed& rhs) const
{
	return this->value < rhs.value; // retourne true si la valeur de l'objet courant est plus inferieure a celle de rhs
}
bool Fixed::operator>=(const Fixed& rhs) const
{
	return this->value >= rhs.value; // retourne true si la valeur de l'objet courant est superieure ou égale à celle de rhs
}
bool Fixed::operator<=(const Fixed& rhs) const
{
	return this->value <= rhs.value; // retourne true si la valeur de l'objet courant est inferieure ou égale à celle de rhs
}
bool Fixed::operator==(const Fixed& rhs) const
{
	return this->value == rhs.value; // retourne true si la valeur de l'objet courant est égale à celle de rhs
}
bool Fixed::operator!=(const Fixed& rhs) const
{
	return this->value != rhs.value; // retourne true si la valeur de l'objet courant est différente de celle de rhs
}

// Operateurs arithmétiques
Fixed Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat()); // retourne un nouvel objet Fixed avec la somme des deux objets
}
Fixed Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat()); // retourne un nouvel objet Fixed avec la différence des deux objets
}
Fixed Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat()); // retourne un nouvel objet Fixed avec le produit des deux objets
}
Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.toFloat() == 0) // si rhs est égal à 0
	{
		std::cerr << "Erreur: Tentative de division par zero." << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / rhs.toFloat()); // retourne un nouvel objet Fixed avec le quotient des deux objets
}

// Operateurs d'incrémentation et de décrémentation
Fixed& Fixed::operator++()
{
	this->value++; // incrémente la valeur de l'objet courant
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this; // crée une copie temporaire de l'objet courant
	++(*this); // incrémente la valeur de l'objet courant
	return temp; // retourne l'état non incrémenté
}
Fixed& Fixed::operator--()
{
	this->value--; // décrémente la valeur de l'objet courant
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this; // crée une copie temporaire de l'objet courant
	--(*this); // décrémente la valeur de l'objet courant
	return temp; // retourne l'état non décrémenté
}
