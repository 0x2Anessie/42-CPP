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
	std::istringstream iss(str); // on utilise istringstream pour separer les tokens
	std::string arg;

	// on avance dans la string 
	while(iss >> arg)
	{
		// on verifie si le token est un operateur ou un nombre
		if (!isOperator(arg[0]) && !isNumber(arg))
			return false;

		// et que si c'est un operateur, il ne soit pas collé à un autre operateur ou à un nombre
		if (arg[0] == '+' && arg[1] != '\0' && arg[1] != ' ')
			return false;
		if (arg[0] == '-' && arg[1] != '\0' && arg[1] != ' ')
			return false;
		if (arg[0] == '*' && arg[1] != '\0' && arg[1] != ' ')
			return false;
		if (arg[0] == '/' && arg[1] != '\0' && arg[1] != ' ')
			return false;
	}

	return true; // si on a pas eu d'erreur dans l'operation, on renvoie true
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
		double result = rpn.evaluateExpression(str); // renvoie le resultat de l'expression
		std::cout << result << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}