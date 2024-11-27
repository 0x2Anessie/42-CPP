#pragma once
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		Zombie();
		void	announce(void);
	private:
		std::string		_name;
};

Zombie*		zombieHorde(int N, std::string name);

// ANSI color codes
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"
#define RESET		"\x1b[0m"

// ANSI text style codes
#define BOLD		"\x1b[1m"
#define UNDERLINE	"\x1b[4m"
#define RESET		"\x1b[0m"
