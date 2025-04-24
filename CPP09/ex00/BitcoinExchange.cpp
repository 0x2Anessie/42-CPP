#include "BitcoinExchange.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CLASS INIT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : BTCvaluePerDate(other.BTCvaluePerDate) 
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		BTCvaluePerDate = other.BTCvaluePerDate;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ STRING UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool isNotSpace(char c)
{
	return !std::isspace(static_cast<unsigned char>(c));
}

// 5
std::string &trimLeft(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), isNotSpace));
	return str;
}
// 4
std::string &trimRight(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), isNotSpace).base(), str.end());
	return str;
}

// 3
std::string &trim(std::string &s)
{
	return trimLeft(trimRight(s));
}

// Renvoie true si la valeur est valide (c'est-à-dire un nombre positif), false sinon
bool BitcoinExchange::checkValue(const std::string &value) const
{
	char *end;
	double val = strtod(value.c_str(), &end); // on utilise strtod pour convertir la chaîne en double

	return end != value.c_str() && *end == '\0' && val >= 0; // conversion réussie et valeur est positive
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DATE PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// Verifie si la date est au format YYYY-MM-DD
bool BitcoinExchange::checkDateFormat(const std::string &date) const
{
	return date.size() == 10 && date[4] == '-' && date[7] == '-';
}

// Verifie que les caracteres de la date sont des chiffres
bool BitcoinExchange::checkDigits(const std::string &date) const
{
	for (int i = 0; i < 4; ++i) // YYYY
		if (!std::isdigit(date[i]))
			return false;

			for (int i = 5; i < 7; ++i) // MM
			if (!std::isdigit(date[i]))
			return false;

	for (int i = 8; i < 10; ++i) // DD
		if (!std::isdigit(date[i]))
			return false;

	return true;
}

// Verifie que le jour et le mois sont dans une plage valide et traite les cas speciaux
bool BitcoinExchange::checkDateRange(int year, int month, int day) const
{
	// Verifie que le mois et le jour sont dans une plage valide
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Pour fevrier, on verifie si l'annee est bissextile
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // bissextile si divisible par 4, non divisible par 100, divisible par 400
		return day <= 29 && (day != 29 || isLeap);
	}

	// Pour les mois de 30 jours, on verifie que le jour ne depasse pas 30
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;

	return true;
}

bool BitcoinExchange::checkDate(const std::string &date) const
{
	// Vérifier si la date est au format YYYY-MM-DD et qu'elle contient des chiffres
	if (!checkDateFormat(date) || !checkDigits(date))
	return false;
	
	// extrait les parties de la date YYYY-MM-DD et les convertit en entiers
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	return checkDateRange(year, month, day); // retourne true si la date est valide
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &datePart, std::string &valuePart)
{
	// Vérifier si la ligne est vide
	if (line.empty())
	{
		std::cout << RED << "Error: " << RESET << "invalid input: empty" <<  std::endl;
		return false;
	}

	// Vérifier si le format de la ligne est incorrect
	if (line.size() < 13 || line[11] != '|' || line[10] != ' ' || line[12] != ' ')
	{
		std::cout << RED << "Error: " << RESET << "invalid input: " << line << std::endl;
		return false;
	}

	// Extraire les parties date et valeur
	std::stringstream ss(line);
	if (!std::getline(ss, datePart, '|') || !std::getline(ss, valuePart))
	{
		std::cout << RED << "Error: " << RESET << "invalid input: " << line << std::endl;
		return false;
	}

	// Supprimer les espaces autour des parties extraites
	trim(datePart);
	trim(valuePart);
	return true;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FILE LOADING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// Lit le fichier data.csv et stocke les valeurs dans une map
void BitcoinExchange::loadFile(const std::string &filename)
{
	std::ifstream file(filename.c_str()); // ouvre le fichier data.csv
	if (!file)
		throw std::runtime_error("Could not open file");

	std::string line;
	std::string date;
	double rate;

	// Verife la première ligne du fichier
	if (std::getline(file, line) && line != "date,exchange_rate") 
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate)) 
			BTCvaluePerDate[date] = rate;
	}

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate))
			BTCvaluePerDate[date] = rate;
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ INPUT PROCESSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Could not open file");

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		trim(line);

		if (firstLine)
		{
			if (line != "date | value")
			{
				std::cout << RED << "Error: " << RESET << "invalid header: " << line << std::endl;
				return;
			}
			firstLine = false;
			continue;
		}
		processLine(line);
	}
}

void BitcoinExchange::processLine(const std::string &line)
{
	std::string datePart, valuePart;
	std::stringstream ss(line);

	// appel des fonctions de parsing
	if (!parseLine(line, datePart, valuePart))
		return;
	if (!checkDate(datePart))
	{
		std::cout << RED << "Error: " << RESET << "invalid date: " << datePart << std::endl;
		return;
	}
	if (!checkValue(valuePart))
	{
		std::cout << RED << "Error: " << RESET << "invalid value: " << valuePart << std::endl;
		return;
	}

	// Verifie si la valeur est positive et ne depasse pas 1000
	double value = atof(valuePart.c_str());
	if (value > 1000)
	{
		std::cout << RED << "Error: " << RESET << "too large (over 1000)" << std::endl;
		return;
	}

	double rate = getBitcoinValue(datePart); // on utilise la date pour trouver le taux de change
	std::cout << datePart << " => " << value << " = " << value * rate << std::endl; // la valeur est multipliee par le taux de change
}


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET BITCOIN VALUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

double BitcoinExchange::getBitcoinValue(const std::string &date) const
{
	// on va chercher la date exacte ou la date precedente la plus proche (avec lower_bound)
	std::map<std::string, double>::const_iterator it = BTCvaluePerDate.lower_bound(date);

	if (it == BTCvaluePerDate.end() || it->first != date)
	{
		if (it == BTCvaluePerDate.begin())
			return 0;
		--it;
	}
	return it->second;
}