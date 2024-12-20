#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

// Pour toute nos convertions on utilise static_cast pour convertir un type en un autre
void ScalarConverter::convert(std::string const &literal)
{
	char *endptr;
	errno = 0;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━ CHECK SI LA STRING A CONVERTIR EST VIDE ━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	if(literal.empty())
	{
		std::cout << RED_BOLD << "Error: " << RESET << BOLD << "Empty String" << std::endl;
		return ;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GERE LES CAS SPECIAUX ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	// nan = not a number pour les double
	// nanf = not a number pour les float
	if(literal == "nan" || literal == "nanf")
	{
		std::cout << BOLD << "<Not A Number> TO CONVERT: " << MAGENTA << "nan " << RESET << BOLD << "OR" << MAGENTA << " nanf" << RESET << std::endl;
		std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		std::cout << MAGENTA << BOLD << "Convertion to INT " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "nanf" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "nan" << std::endl;
		return ;
	}

	// inf et +inf : infini positif pour les double
	// inff et +inff : infini positif pour les float
	if(literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
	{
		std::cout << BOLD << "POSITIVE INFINITE TO CONVERT: " << MAGENTA << "inf " << RESET << BOLD << "OR" << MAGENTA << " inff" << RESET << std::endl;
		std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		std::cout << MAGENTA << BOLD << "Convertion to INT " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "inff" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "inf" << std::endl;
		return ;
	}

	// -inf : infini negatif pour les double
	// -inff : infini negatif pour les float
	if(literal == "-inf" || literal == "-inff")
	{
		std::cout << BOLD << "POSITIVE INFINITE TO CONVERT: " << MAGENTA << "-inf " << RESET << BOLD << "OR" << MAGENTA << " -inff" << RESET << std::endl;
		std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		std::cout << MAGENTA << BOLD << "Convertion to INT " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "-inff" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "-inf" << std::endl;
		return ;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONVERTI UN CHAR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	if(literal.length() == 1 && !isdigit(literal[0]) && std::isprint(literal[0]))
	{
		char c = literal[0];
		std::cout << BOLD << "CHAR TO CONVERT: " << MAGENTA << c << RESET << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to CHAR " << RESET << BOLD << "  ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "'" << c << "'" << RESET << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to INT " << RESET << BOLD << "   ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << static_cast<int>(c) << RESET << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << static_cast<float>(c) << ".0f" << RESET << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << static_cast<double>(c) << ".0" << RESET << std::endl;
		return ;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONVERTI UN INT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	long int i = std::strtol(literal.c_str(), &endptr, 10);
	if(errno != ERANGE && *endptr == '\0' && i >= INT_MIN && i <= INT_MAX)
	{
		std::cout << BOLD << "INT TO CONVERT: " << MAGENTA << i << RESET << std::endl;
		if(i < 0 || i > 127)
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << std::endl;
		else if(!std::isprint(static_cast<char>(i)))
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " non displayable" << std::endl;
		else
		std::cout << BOLD << MAGENTA << "Converted to CHAR " << RESET << BOLD << "   ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to INT " << RESET << BOLD << "    ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << i << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << "  ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
		return ;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONVERTI UN FLOAT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	errno = 0;
	float f = std::strtof(literal.c_str(), &endptr);
	if((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0' && errno != ERANGE)
	{
		std::cout << BOLD << "FLOAT TO CONVERT: " << MAGENTA << f << RESET << std::endl;

		// Convertion to CHAR
		if(f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
			std::cout << BOLD << MAGENTA << "Converted to CHAR " << RESET << BOLD << "   ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "'" << static_cast<char>(f) << "'" << RESET << std::endl;
		else if(f < 0 || f > 127)
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;
		else if(f < ' ' || f > '~')
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " non displayable" << RESET << std::endl;
		/* Sinon on affiche impossible */
		else
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;

		// Convertion to INT
		/* Si le float est compris entre INT_MIN et INT_MAX on affiche l'entier */
		if(f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
			std::cout << BOLD << MAGENTA << "Converted to INT " << RESET << BOLD << "    ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << static_cast<int>(f) << RESET << std::endl;
		/* Sinon on affiche impossible */
		else
			std::cout << MAGENTA << BOLD << "Convertion to INT " << RESET << BOLD << "   ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;

		// Convertion to FLOAT
		/* Si le float est compris entre -FLT_MAX et FLT_MAX on affiche le float */
		if(f >= -FLT_MAX && f <= FLT_MAX)
			std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << "  ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
		/* Sinon on affiche impossible */
		else
			std::cout << MAGENTA << BOLD << "Convertion to FLOAT " << RESET << BOLD <<  "༼つಠ益ಠ༽つ" << RED_BOLD << "impossible, you are over FLOATMAX or under FLOATMIN" << RESET << std::endl;

		// Convertion to DOUBLE
		/* Si le float est compris entre -DBL_MAX et DBL_MAX on affiche le double */
		if(f >= -DBL_MAX && f <= DBL_MAX)
			std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << std::fixed << std::setprecision(1) << static_cast<double>(f) << RESET << std::endl;
		/* Sinon on affiche impossible */
		else
			std::cout << MAGENTA << BOLD << "Convertion to DOUBLE " << RESET << BOLD << "༼つಠ益ಠ༽つ" << RED_BOLD << "impossible, you are over DOUBLEMAX or under DOUBLEMIN" << RESET << std::endl;
		return ;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONVERTI UN DOUBLE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //
	errno = 0;
	double d = std::strtod(literal.c_str(), &endptr);
	if(*endptr == '\0' && errno != ERANGE)
	{
		// Convertion to CHAR

		std::cout << BOLD << "DOUBLE TO CONVERT: " << MAGENTA << d << RESET << std::endl;

		/* Si le double est compris entre 0 et 127 et est un caractere affichable */
		if(d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
			std::cout << BOLD << MAGENTA << "Converted to CHAR " << RESET << BOLD << "  ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "'" << static_cast<char>(d) << "'" << RESET << std::endl;
		/* Si le double est inferieur a 0 ou superieur a 127 */
		else if(d < 0 || d > 127)
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;
		/* Si le double n'est pas un caractere affichable */
		else if(d < ' ' || d > '~')
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " Non displayable" << RESET << std::endl;
		/* Sinon on affiche impossible */
		else
			std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;

		// Convertion to INT
		/* Si le double est compris entre INT_MIN et INT_MAX */
		if(d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
			std::cout << BOLD << MAGENTA << "Converted to INT " << RESET << BOLD << "   ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << static_cast<int>(d) << RESET << std::endl;
		/* Sinon on affiche impossible */
		else
			std::cout << BOLD << MAGENTA << "Converted to INT " << RESET << BOLD << "   ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;

		// Convertion to FLOAT
		/* Si superieur au max float */
		if(d > FLT_MAX)
			std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "inff" << RESET << std::endl;
		/* Si inferieur au min float */
		else if(d < -FLT_MAX)
			std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "-inff" << RESET << std::endl;
		/* Si egale a 0 */
		else if(d == 0)
			std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "0.0f" << RESET << std::endl;
		/* Sinon on affiche le float */
		else
			std::cout << BOLD << MAGENTA << "Converted to FLOAT " << RESET << BOLD << " ༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << RESET << std::endl;

		// Convertion to DOUBLE
		/* Si superieur au max double */
		if(d > DBL_MAX)
			std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "inf" << RESET << std::endl;
		/* Si inferieur au min double */
		else if(d < -DBL_MAX)
			std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "-inf" << RESET << std::endl;
		/* Si egale a 0 */
		else if(d == 0)
			std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << "0.0" << RESET << std::endl;
		/* Sinon on affiche le double */
		else
			std::cout << BOLD << MAGENTA << "Converted to DOUBLE " << RESET << BOLD << "༼∩☉ل͜☉༽⊃━☆ﾟ. * ･ ｡ﾟ " << GREEN_BOLD << std::fixed << std::setprecision(1) << d << RESET << std::endl;
		return ;
	}
	std::cout << MAGENTA << BOLD << "Convertion to CHAR " << RESET << BOLD << "  ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;
	std::cout << MAGENTA << BOLD << "Convertion to INT " << RESET << BOLD << "   ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;
	std::cout << MAGENTA << BOLD << "Convertion to FLOAT " << RESET << BOLD << " ༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;
	std::cout << MAGENTA << BOLD << "Convertion to DOUBLE " << RESET << BOLD << "༼つಠ益ಠ༽つ" << RED_BOLD << " impossible" << RESET << std::endl;
}
