/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:28:58 by acatusse          #+#    #+#             */
/*   Updated: 2024/10/17 15:07:11 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	Constructeur par defaut de la classe Fixed
*/
Fixed::Fixed() : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

/*
	Constructeur de copie
*/
Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
	Operateur d'affectation pour =.
*/
Fixed&  Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/*
	Construit un objet "Fixed" avec une valeur entière.
	On décale la valeur entière de 8 bits vers la gauche pour la transformer
	en représentation à virgule fixe.
*/
Fixed::Fixed(const int intValue)
{
	value = intValue << fractionalBits;
}

/*
	Construit un objet "Fixed" avec une valeur flottante.
	Roundf permet d'arrondir le float a la valeur la plus proche.
	FloatValue est la valeur a laquelle on veut initialiser value.
	On le multiplie par 256 ou 2^8 pour le transformer en representation
	a virgule fixe.
*/
Fixed::Fixed(const float floatValue)
{
	value = roundf(floatValue * (1 << fractionalBits));
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

/*
	On fait divise par 256 ou 2^8 pour retrouver la valeur flottante
	qui a ete transformee en representation a virgule fixe.
*/
float Fixed::toFloat() const
{
	return static_cast<float>(value) / (1 << fractionalBits);
}

/*
	On fait un decalage de 8 bits vers la droite pour retrouver la valeur
	entiere qui a ete transformee en representation a virgule fixe.
*/
int Fixed::toInt() const
{
	return value >> fractionalBits;
}

/*
	Operateur de surcharge <<.
*/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

/*
	Retourne le min pour les objets non constants
*/
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

/*
	Retourne le min pour les objets constants
*/
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

/*
	Retourne le max pour les objets non constants
*/
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

/*
	Retourne le max pour les objets constants
*/
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}
