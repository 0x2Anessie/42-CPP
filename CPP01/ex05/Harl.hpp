#pragma once
#include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

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
