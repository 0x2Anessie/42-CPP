#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <limits>
#include <iterator>

class Span
{
	public:
		// ━━━━━━━━━━━━━━ declarations ━━━━━━━━━━━━━━ //
		Span(unsigned int n);
		Span(Span const &other);
		~Span();

		// ━━━━━━━━━ surcharge d'operateurs ━━━━━━━━━ //
		Span &operator=(Span const &other);
		int& operator[](unsigned int index);
		const int& operator[](unsigned int index) const;

		// ━━━━━━━━━━━━━━━━ methodes ━━━━━━━━━━━━━━━━ //
		void addNumber(unsigned int n);
		long int shortestSpan();
		long int longestSpan();

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);

		// ━━━━━━━━━━━━━━━ exceptions ━━━━━━━━━━━━━━━ //
		class SpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SpanTooEmptyException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		unsigned int maxSize; // taille maximale du conteneur
		std::vector<int> container; // conteneur de nombres
};


template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	unsigned int count = 0;

	for(Iterator it = begin; it != end; it++)
	{
		if(*it < std::numeric_limits<int>::min() || *it > std::numeric_limits<int>::max())
			throw Span::OutOfRangeException();
		count++; // on compte le nombre d'elements a ajouter
	}

	if (container.size() + count > maxSize) // check si y'a encore de la place dans le conteneur
		throw Span::SpanException();

	for(Iterator it = begin; it != end; it++) // remplissage du conteneur avec la valeur de l'iterateur
		container.push_back(*it);
}


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