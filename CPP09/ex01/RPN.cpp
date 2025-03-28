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

double RPN::evaluateExpression(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
		processToken(token);

	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression");

	return stack.top();
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CALCUL UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void RPN::processToken(const std::string &token)
{
	if (token.size() == 1 && isOperator(token[0])) {
		handleOperator(token[0]);
	} else {
		handleOperand(token);
	}
}

void RPN::handleOperator(const char &op)
{
	if (stack.size() < 2) {
		throw std::runtime_error("Error: Not enough operands for operation");
	}

	double operand2 = stack.top();
	stack.pop();
	double operand1 = stack.top();
	stack.pop();

	double result = performOperation(op, operand1, operand2);
	stack.push(result);
}

void RPN::handleOperand(const std::string &token)
{
	double value;
	std::stringstream ss(token);

	if (!(ss >> value)) {
		throw std::runtime_error("Error: Invalid operand");
	}

	stack.push(value);
}

bool RPN::isOperator(const char &token) const
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

double RPN::performOperation(const char &op, const double &operand1, const double &operand2)
{
	switch (op) {
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0) {
				throw std::runtime_error("Error: Division by zero");
			}
			return operand1 / operand2;
		default:
			throw std::runtime_error("Error: Unknown operator");
	}
}