#pragma once

# include <iostream>

/*
	Les templates permettent d'ecrire du code (fonctions, classes) qui peuvent
	fontionner avec n'importe quel type de données. Cela permet de réutiliser
	le code pour plusieurs types.
	Les templates sont déclarés avec le mot-clé template suivi d'une liste
	de paramètres de template entre chevrons (< >).
	Le paramètre de type T peut ensuite être utilisé dans la définition
	de la fonction ou de la classe.
*/

template <typename T>
void	swap(T &a, T &b)
{
		T tmp = a;
		a = b;
		b = tmp;
}

template <typename T>
T const &min(const T &a, const T &b)
{
	return ( a < b ? a : b ); // if a < b, return a, else return b
}

template <typename T>
T const &max(const T &a, const T &b )
{
	return ( a > b ? a : b ); // if a > b, return a, else return b
}

// ANSI color codes
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"
#define WHITE		"\x1b[37m"
#define RESET		"\x1b[0m"

// ANSI text style codes
#define BOLD		"\x1b[1m"
#define UNDERLINE	"\x1b[4m"
#define RESET		"\x1b[0m"
#define RED_BOLD "\033[1;31m"
#define GREEN_BOLD "\033[1;32m"