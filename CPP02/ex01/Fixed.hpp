#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

public:
	Fixed();
	Fixed(const int intvalue);
	Fixed(const float floatvalue);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _value;
	static const int _fractionalBits = 8;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

# endif
