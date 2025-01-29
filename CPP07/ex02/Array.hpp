#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:

		// ━━━━━━━━━━━━━━━━ Constructors ━━━━━━━━━━━━━━━━ //
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		// ━━━━━━━━━━━━━━━━ Operator [] ━━━━━━━━━━━━━━━━ //
		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;

		// ━━━━━━━━━━━━━━━━━ Get size ━━━━━━━━━━━━━━━━━━ //
		unsigned int size() const;

		// ━━━━━━━━━━━━━━━━ Exceptions ━━━━━━━━━━━━━━━━━ //
		class OutLimitsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		T *_elem; // Array of elements
		unsigned int _size; // Size of the array
};

#include "Array.tpp"

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