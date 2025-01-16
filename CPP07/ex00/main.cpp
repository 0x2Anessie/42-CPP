#include "whatever.hpp"

int main( void )
{
	std::cout << "\033c";
	std::cout << GREEN_BOLD << "TESTS DONNÉS DANS LE SUJET" << RESET << std::endl;

	int a = 2;
	int b = 3;
	
	std::cout << MAGENTA << BOLD << "valeurs de a et b avant swap :" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	::swap( a, b );

	std::cout << MAGENTA << BOLD << "valeurs de a et b apres swap :" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	
	std::cout << MAGENTA << BOLD << "\ntests fonction min et max :" << RESET << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << MAGENTA << BOLD << "\nvaleurs de c et d avant swap :" << RESET << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;

	::swap(c, d);
	std::cout << MAGENTA << BOLD << "valeurs de c et d apres swap" << RESET << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << MAGENTA << BOLD << "\ntests fonction min et max :" << RESET << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	
	return 0;
}