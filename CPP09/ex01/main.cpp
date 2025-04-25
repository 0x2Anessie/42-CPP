#include "RPN.hpp"
#include <cctype>
#include <cstdlib>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool isOperator(const char &token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

bool isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	double value = std::atof(str.c_str());
	if(value > 9)
		return (false);
	return (true);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ARG PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool checkArg(const std::string &str)
{
	std::istringstream iss(str);
	std::string arg;

	while(iss >> arg)
	{
		if (!isOperator(arg[0]) && !isNumber(arg))
			return false;

		// check si le premier char est un opérateur
		if (arg[0] == '+' && arg[1] != '\0' && arg[1] != ' ')
			return false;
		if (arg[0] == '-' && arg[1] != '\0' && arg[1] != ' ')
			return false;
		if (arg[0] == '*' && arg[1] != '\0' && arg[1] != ' ')
			return false;
		if (arg[0] == '/' && arg[1] != '\0' && arg[1] != ' ')
			return false;
	}

	return true;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MAIN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

int main(int ac, char **av)
{
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ arg check ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	if (ac != 2)
	{
		std::cerr << RED_BOLD << "ERROR! You must enter the program name and the \"expression\"" << RESET << std::endl;
		return (1);
	}
	std::string str = av[1];
	if (!checkArg(str))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ RPN ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	RPN rpn;
	try
	{
		double result = rpn.evaluateExpression(str);
		std::cout << result << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}