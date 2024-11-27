#include "Fixed.hpp"

/*
	Comprendre les operateurs d'affectations et les constructeurs de copie.
*/
int	main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// Test setRawBits
	// a.setRawBits(20);
	// std::cout << a.getRawBits() << std::endl;

	return 0;
}
