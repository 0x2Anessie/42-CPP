#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n)
{
	if(n == 0)
	throw Span::SpanTooEmptyException();
}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span()
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SURCHARGE D'OPERATEUR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

int& Span::operator[](unsigned int index)
{
	if (index >= container.size())
		throw Span::OutOfRangeException();
	return container[index];
}

const int& Span::operator[](unsigned int index) const
{
	if (index >= container.size())
		throw Span::OutOfRangeException();
	return container[index];
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		if(maxSize == 0)
			throw Span::SpanTooEmptyException();
		maxSize = other.maxSize;
		container = other.container;
	}
	return *this;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ METHODS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void Span::addNumber(unsigned int n)
{
	if(container.size() >= maxSize)
		throw Span::SpanException();
	container.push_back(n);
}

long int Span::shortestSpan()
{
	if (container.size() < 2)
		throw Span::SpanTooEmptyException();

	std::vector<int> tmp = container;
	std::sort(tmp.begin(), tmp.end());

	long int minSpan = std::numeric_limits<long int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < minSpan) // si la difference entre les deux elements est inferieur a minSpan
			minSpan = tmp[i] - tmp[i - 1]; // on met a jour minSpan
	}

	return minSpan;
}

long int Span::longestSpan()
{
	if (container.size() < 2)
		throw Span::SpanTooEmptyException();

	std::vector<int> tmp = container;
	std::sort(tmp.begin(), tmp.end());

	long int maxSpan = std::numeric_limits<long int>::min();
	long int min = *std::min_element(tmp.begin(), tmp.end());
	long int max = *std::max_element(tmp.begin(), tmp.end());
	maxSpan = max - min;

	return maxSpan;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

const char *Span::SpanException::what() const throw()
{
	return RED "Span is full" RESET;
}

const char *Span::SpanTooEmptyException::what() const throw()
{
	return RED "Span is empty" RESET;
}

const char *Span::OutOfRangeException::what() const throw()
{
	return RED "Value is out of range" RESET;
}
