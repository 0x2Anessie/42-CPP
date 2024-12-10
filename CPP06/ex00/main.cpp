#include <iostream>
#include "ScalarConverter.hpp"
#include <climits>
#include <cfloat>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	return 0;
}