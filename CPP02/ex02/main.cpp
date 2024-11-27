#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 10 ) );
	Fixed const d( Fixed( 42 ) );

	std::cout << a << std::endl; // 0
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl; // 0.0078125
	std::cout << b << std::endl; // 10.1016

	std::cout << Fixed::max( a, b ) << std::endl;
	// std::cout << Fixed::min( a, b ) << std::endl;
	// std::cout << Fixed::min( c, d ) << std::endl;
	// std::cout << Fixed::max( c, d ) << std::endl;

	// std::cout << c + d << std::endl;
	// std::cout << c - d << std::endl;
	// std::cout << c * d << std::endl;
	// std::cout << c / d << std::endl;

	return 0;
}
