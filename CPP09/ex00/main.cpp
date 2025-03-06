#include "BitcoinExchange.hpp"

/*
	-> 
*/
int main(int ac, char **av)
{
	std::cout << "\033c";

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ arg check ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	if(ac != 2)
	{
		std::cerr << RED_BOLD << "ERROR! You must enter the program name and the input.txt" << RESET << std::endl;
		return 1;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ process the file's data ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	try
	{
		BitcoinExchange	btc;

		btc.getData("data.csv"); // lit le fichier data.csv et stocke dans std::map valuePerDate
		btc.processData(av[1]); // check les entrées du fichier et calcule la valeur du btc pour chaque date
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_BOLD << e.what() << RESET << std::endl;
		return 1;
	}
	
	return 0;
}