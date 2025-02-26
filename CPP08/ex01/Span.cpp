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

Span::~Span()
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SURCHARGE D'OPERATEUR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

int& Span::operator[](unsigned int index)
{
	if (index >= _numbers.size())
		throw Span::OutOfRangeException();
	return _numbers[index];
}

const int& Span::operator[](unsigned int index) const
{
	if (index >= _numbers.size())
		throw Span::OutOfRangeException();
	return _numbers[index];
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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CLASS FT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

/*
	addNumber: Ajoute un nombre a la liste de nombres
*/
void Span::addNumber(unsigned int n)
{
	if(_numbers.size() >= _n)
		throw Span::SpanException();
	_numbers.push_back(n);
}

/*
	shortestSpan: Retourne la difference entre les deux nombres les plus proches
	-> Si le conteneur contient moins de 2 elements, on lance une exception
	-> On trie le conteneur avec la methode sort
	-> On initialise la variable minSpan a la valeur maximale d'un long int (pour s'assurer que la premiere difference sera plus petite)
	-> On parcourt le conteneur et on compare la difference entre chaque element
	-> Si la difference est plus petite que minSpan, on met a jour minSpan
	-> On retourne minSpan
*/
long int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw Span::SpanTooEmptyException();

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	long int minSpan = std::numeric_limits<long int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < minSpan) // On compare la difference entre chaque element et si elle est plus petite que minSpan
			minSpan = tmp[i] - tmp[i - 1];
	}
	return minSpan;
}

/*
	longestSpan: Retourne la difference entre le plus grand et le plus petit nombre
	-> Si le conteneur contient moins de 2 elements, on lance une exception
	-> On trie le conteneur avec la methode sort
	-> On initialise la variable maxSpan a la valeur minimale d'un long int  (pour s'assurer que la premiere difference sera plus grande)
	-> On recupere le plus petit et le plus grand nombre du conteneur avec les methodes min_element et max_element de la STL
	-> On retourne la difference entre le plus grand et le plus petit nombre
*/
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
