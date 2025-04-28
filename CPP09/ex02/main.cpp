#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::cout << "\033c";

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ arg check ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	if(ac < 2)
	{
		std::cerr << RED << "Usage: " << av[0] << " [value1] [value2] ..." << RESET << std::endl;
		return (1);
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ merge-insert sorting ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	try
	{
		PmergeMe pmergeMe(ac, av);
		pmergeMe.merge();
	}
	catch(const std::exception &e)
	{
		std::cerr << RED_BOLD << "Error: " << e.what() << RESET << std::endl;
		return (1);
	}
}
