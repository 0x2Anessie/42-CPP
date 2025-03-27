#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN()
{}

double RPN::calculate(const std::string str)
{
	std::istringstream iss(str);
	std::string token;
	double val1;
	double val2;

	while (iss >> token)
	{
		if (isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			val2 = _stack.top();
			_stack.pop();
			val1 = _stack.top();
			_stack.pop();
			_stack.push(operate(token[0], val1, val2));
		}
		else
		{
			double value;
			std::stringstream ss(token);
			if (!(ss >> value))
			{
				throw std::runtime_error("Error");
			}
			_stack.push(value);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}

bool RPN::isOperator(const char &token) const
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

double RPN::operate(const char &op, const double &val1, const double &val2)
{
	switch (op)
	{
		case '+':
			return (val1 + val2);
		case '-':
			return (val1 - val2);
		case '*':
			return (val1 * val2);
		case '/':
			if (val2 == 0)
				throw std::runtime_error("Error");
			return (val1 / val2);
	}
	return (0);
}
