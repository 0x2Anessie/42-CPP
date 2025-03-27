#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		double calculate(const std::string str);

	private:
		std::stack<double, std::list<double> > _stack;
		bool isOperator(const char &token) const;
		double operate(const char &op, const double &val1, const double &val2);
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
