#include "RPN.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CLASS INIT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

RPN::RPN()
{}

RPN::RPN(const RPN &other) 
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		stack = other.stack;
	return *this;
}

RPN::~RPN()
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CALCUL METHODS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

double RPN::evaluateExpression(const std::string &expression)
{
	std::istringstream iss(expression); // liste de strings separees par des espaces
	std::string token;

	while (iss >> token)
		processToken(token); // traite chaque token de l'expression

	if (stack.size() != 1) // erreur si il n'y a pas qu'un resultat final
		throw std::runtime_error("Error: Invalid RPN expression");

	return stack.top(); // a ce moment il contient le resultat final des operations
}

void RPN::processToken(const std::string &token)
{
	// si le token est un operateur, on appelle handleOperator
	if (token.size() == 1 && isOperator(token[0]))
		handleOperator(token[0]);
	
	// sinon, on appelle handleOperand
	else
		handleOperand(token);
}

// Operateur: + - / *
void RPN::handleOperator(const char &op)
{
	if (stack.size() < 2)
	{
		throw std::runtime_error("Error: Not enough operands for operation");
	}

	// on sort les deux valeurs a utiliser
	double operand2 = stack.top();
	stack.pop();
	double operand1 = stack.top();
	stack.pop();

	double result = performOperation(op, operand1, operand2); // on fait l'operation

	stack.push(result); // et on met ce resultat dans la stack
}

// Operande: valeurs
void RPN::handleOperand(const std::string &token)
{
	double value;
	std::stringstream ss(token);

	if (!(ss >> value)) // conversion de string a double
		throw std::runtime_error("Error: Invalid operand");

	stack.push(value); // met l'operande dans la stack
}

// elseif ?
double RPN::performOperation(const char &op, const double &operand1, const double &operand2)
{
	switch (op)
	{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0)
				throw std::runtime_error("Error: Division by zero");
			return operand1 / operand2;
		default:
			throw std::runtime_error("Error: Unknown operator");
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CALCUL UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool RPN::isOperator(const char &token) const
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}