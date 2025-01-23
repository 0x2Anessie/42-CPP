#pragma once

#include <iostream>

/*
	Adresse du tableau // Taille du tableau // Fonction à appliquer
	Se balade dans le tableau et applique la fonction à chaque élément,
	c'est a dire print le contenu de chaque élément
*/
template <typename T, typename P>
void iter(T *array, int length, P *func)
{
	for (int i = 0; i < length; ++i)
	{
		func(array[i]);
	}
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