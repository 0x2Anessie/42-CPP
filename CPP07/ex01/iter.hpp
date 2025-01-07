#pragma once

template <typename T, typename P>
void iter(T *array, int length, P *func)
{
	for (int i = 0; i < length; ++i)
	{
		func(array[i]);
	}
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