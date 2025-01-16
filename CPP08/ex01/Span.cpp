#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	if(n == 0)
		throw Span::SpanTooEmptyException();
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		if(_n == 0)
			throw Span::SpanTooEmptyException();
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(unsigned int n)
{
	if(_numbers.size() >= _n)
		throw Span::SpanException();
	_numbers.push_back(n);
}

long int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanTooEmptyException();
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	long int minSpan = std::numeric_limits<long int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < minSpan)
			minSpan = tmp[i] - tmp[i - 1];
	}
	return minSpan;
}

long int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanTooEmptyException();
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	long int maxSpan = std::numeric_limits<long int>::min();
	long int min = *std::min_element(tmp.begin(), tmp.end());
	long int max = *std::max_element(tmp.begin(), tmp.end());
	maxSpan = max - min;
	return maxSpan;
}

const char *Span::SpanException::what() const throw()
{
	return RED "Span is full" RESET;
}

const char *Span::SpanTooEmptyException::what() const throw()
{
	return RED "Span is too empty" RESET;
}

const char *Span::OutOfRangeException::what() const throw()
{
	return RED "Value is out of range" RESET;
}
