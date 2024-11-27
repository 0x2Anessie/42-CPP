#include "Fixed.hpp"

/*
	Constructeur par defaut de la classe Fixed
*/
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
	Constructeur de copie
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
	Operateur d'affectation pour =.
*/
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
	Construit un objet "Fixed" avec une valeur entière.
	On décale la valeur entière de 8 bits vers la gauche pour la transformer
	en représentation à virgule fixe.
			-> 10 << 8 = 2560
			-> _value = 2560
*/
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_value = intValue << _fractionalBits;
}

/*
	Construit un objet "Fixed" avec une valeur flottante.
	Roundf permet d'arrondir le float a la valeur la plus proche.
	FloatValue est la valeur a laquelle on veut initialiser value.
	On le multiplie par 256 ou 2^8 pour le transformer en representation
	a virgule fixe.
			-> 1234.4321 * 256 = 316415.6416
			-> roundf(316415.6416) = 316416
			-> _value = 316416
*/
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/*
	On fait divise par 256 ou 2^8 pour retrouver la valeur flottante
	qui a ete transformee en representation a virgule fixe.
			-> 316416 / 256 = 1234.43
*/
float Fixed::toFloat() const
{
	// std::cout << "toFloat called" << std::endl;
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

/*
	On fait un decalage de 8 bits vers la droite pour retrouver la valeur
	entiere qui a ete transformee en representation a virgule fixe.
			-> 2560 >> 8 = 10
*/
int Fixed::toInt() const
{
	// std::cout << "toInt called" << std::endl;
	return _value >> _fractionalBits;
}

/*
	Par défaut, std::ostream affiche les valeurs flottantes sans
	les zéros après la virgule si elles sont des nombres entiers.
	Donc, 10.0 sera affiché comme 10.
*/
std::ostream& operator << (std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
