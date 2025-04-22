#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	public:
		// ━━━━━━━━━━━━━━━━━━━━ class init ━━━━━━━━━━━━━━━━━━━━ //
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();

		// ━━━━━━━━━━━━━━━━━━ public methods ━━━━━━━━━━━━━━━━━━ //
		void	merge();
		PmergeMe(int ac, char **av);

	private:
		// ━━━━━━━━━━━━━━━━ private attribute ━━━━━━━━━━━━━━━━━ //
		std::vector<double>	m_vector;
		std::deque<double>	m_deque;
		size_t				m_size;
};


//━━━━━━━━ANSI CODES━━━━━━━━━//
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"
#define WHITE		"\x1b[37m"
#define RESET		"\x1b[0m"

#define BOLD		"\x1b[1m"
#define UNDERLINE	"\x1b[4m"
#define RESET		"\x1b[0m"
#define RED_BOLD	"\033[1;31m"
#define GREEN_BOLD	"\033[1;32m"
