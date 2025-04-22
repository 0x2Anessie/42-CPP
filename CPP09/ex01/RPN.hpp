#pragma once

#include <algorithm>
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
		// ━━━━━━━━━━━━━━━━━━━━ class init ━━━━━━━━━━━━━━━━━━━━ //
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		// ━━━━━━━━━━━━━━━━━━ public methods ━━━━━━━━━━━━━━━━━━ //
		double	evaluateExpression(const std::string &expression);

	private:
		// ━━━━━━━━━━━━━━━━ private attribute ━━━━━━━━━━━━━━━━━ //
		// structure Last In, First Out qui permet de sortir les deux derniers operandes quand
		// on tombe sur un operateur. Ensuite on ajoute le resultat de l'operation dans la pile.
		// std::stack<double> est donc une pile de double dans laquelle on stock nos operande en
		// attendant de trouver des operations, et les resultats apres les avoir fait.
		std::stack<double> stack;

		// ━━━━━━━━━━━━━━━━━━ private methods ━━━━━━━━━━━━━━━━━ //
		bool	isOperator(const char &token) const;
		double	performOperation(const char &op, const double &operand1, const double &operand2);
		void	processToken(const std::string &token);
		void	handleOperator(const char &op);
		void	handleOperand(const std::string &token);
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
