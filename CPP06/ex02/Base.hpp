#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

// ANSI color codes
#define RED            "\x1b[31m"
#define GREEN        "\x1b[32m"
#define YELLOW        "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA        "\x1b[35m"
#define CYAN        "\x1b[36m"
#define RESET        "\x1b[0m"

// ANSI text style codes
#define BOLD        "\x1b[1m"
#define UNDERLINE    "\x1b[4m"
#define RESET        "\x1b[0m"