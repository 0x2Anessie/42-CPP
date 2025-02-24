#pragma once

#include <stack>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {} // call the constructor of the parent class
		MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {} // call the copy constructor of the parent class

		MutantStack<T>& operator=(const MutantStack<T>& other) // call the operator= of the parent class
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		virtual ~MutantStack() {} // call the destructor of the parent class

		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return std::stack<T>::c.begin(); } // return the iterator of the beginning of the stack
		iterator end() { return std::stack<T>::c.end(); } // return the iterator of the end of the stack
		const_iterator begin() const { return std::stack<T>::c.begin(); } // return the const iterator of the beginning of the stack
		const_iterator end() const { return std::stack<T>::c.end(); } // return the const iterator of the end of the stack
		reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); } // return the reverse iterator wich is the end of the stack
		reverse_iterator rend() { return std::stack<T>::c.rend(); } // return the reverse iterator wich is the beginning of the stack
		const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); } // return the const reverse iterator wich is the end of the stack
		const_reverse_iterator rend() const { return std::stack<T>::c.rend(); } // return the const reverse iterator wich is the beginning of the stack
};

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