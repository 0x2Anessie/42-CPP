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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET DATA.CSV ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// Lit le fichier data.csv et stocke taux de change correspondant à chaque date dans la map
void BitcoinExchange::GetDataFile(const std::string &filename)
{
	std::ifstream dataFile(filename.c_str()); // ouvre le fichier data.csv
	if (!dataFile)
		throw std::runtime_error("Could not open file");

	std::string line;
	std::string date;
	double rate;

	// recupère les donnees de la première ligne si ce n'est pas le header
	if (std::getline(dataFile, line) && line != "date,exchange_rate") 
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate)) // extrait la date et convertit le taux de change de str a double
			BTCvaluePerDate[date] = rate;
	}

	// si il y a un header, on passe a ce bloc et on lit et stocke les données de toutes les lignes
	while (std::getline(dataFile, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate))
			BTCvaluePerDate[date] = rate; // on stocke la date et le taux de change dans la map
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DATE PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool BitcoinExchange::checkDateFormat(const std::string &date) const
{
	// Vérifie le format de la date (YYYY-MM-DD)
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	// Vérifie que les caractères de la date sont des chiffres
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
	if (!checkDateFormat(date))
	return false;
	
	// extrait les parties de la date YYYY-MM-DD et les convertit en entiers
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	return checkDateRange(year, month, day); // retourne true si la date est valide
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ VALUE PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// Renvoie true si la valeur est valide (c'est-à-dire un nombre positif), false sinon
bool BitcoinExchange::checkValue(const std::string &value) const
{
	char *end;
	double val = strtod(value.c_str(), &end); // on utilise strtod pour convertir la chaîne en double

	return end != value.c_str() && *end == '\0' && val >= 0; // conversion réussie et valeur est positive
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ INPUT'S LINES PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool BitcoinExchange::parseLine(const std::string &line, std::string &dateInput, std::string &valueInput)
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

	// Extraire la date et la valeur de la ligne
	std::stringstream ss(line);
	if (!std::getline(ss, dateInput, '|') || !std::getline(ss, valueInput))
	{
		std::cout << RED << "Error: " << RESET << "invalid input: " << line << std::endl;
		return false;
	}

	// Supprimer les espaces autour des parties extraites
	trim(dateInput);
	trim(valueInput);

	return true;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET THE INPUT'S DATA ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// On lui donne av[1] (input.txt) et il va le lire ligne par ligne
void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream inputFile(filename.c_str()); // ouvre le fichier input.txt
	if (!inputFile)
		throw std::runtime_error("Could not open file");

	std::string line;
	bool firstLine = true;

	while (std::getline(inputFile, line)) // on lit input.txt ligne par ligne
	{
		trim(line); // on supprime les espaces autour des infos

		if (firstLine)
		{
			if (line != "date | value")
			{
				std::cout << RED << "Error: " << RESET << "invalid header: " << line << std::endl;
				return;
			}
			firstLine = false; // si la première ligne est le header, on passe a false pour  indiquer que les lignes suivantes ne sont plus des header
			continue;
		}

		processLine(line); // on traite chaque ligne avec la fonction processLine
	}
}

void BitcoinExchange::processLine(const std::string &line)
{
	std::string dateInput;
	std::string valueInput;
	std::stringstream ss(line);

	// appel des fonctions de parsing
	if (!parseLine(line, dateInput, valueInput))
		return;
	if (!checkDate(dateInput))
	{
		std::cout << RED << "Error: " << RESET << "invalid date: " << dateInput << std::endl;
		return;
	}
	if (!checkValue(valueInput))
	{
		std::cout << RED << "Error: " << RESET << "invalid value: " << valueInput << std::endl;
		return;
	}

	// Verifie que la valeur ne depasse pas 1000
	double value = atof(valueInput.c_str());
	if (value > 1000)
	{
		std::cout << RED << "Error: " << RESET << "too large (over 1000)" << std::endl;
		return;
	}

	double rate = getBitcoinValue(dateInput); // on utilise la date pour trouver le taux de change

	std::cout << dateInput << " => " << value << " = " << value * rate << std::endl; // valeur * taux de change
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET BITCOIN VALUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

double BitcoinExchange::getBitcoinValue(const std::string &date) const
{
	// on va chercher la date exacte ou la date precedente la plus proche (avec lower_bound)
	std::map<std::string, double>::const_iterator it = BTCvaluePerDate.lower_bound(date);

	if (it == BTCvaluePerDate.end() || it->first != date) // si it est à la fin ou si la date n'existe pas
	{
		if (it == BTCvaluePerDate.begin()) // si la date est avant la première date de la map
			return 0;
		--it;
	}
	return it->second; // renvoie le taux de change
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TRIM UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

// Trim les espaces à gauche et à droite d'une chaîne
bool isNotSpace(char c)
{
	return !std::isspace(static_cast<unsigned char>(c));
}

std::string &trimLeft(std::string &str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), isNotSpace));
	return str;
}

std::string &trimRight(std::string &str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), isNotSpace).base(), str.end());
	return str;
}

std::string &trim(std::string &s)
{
	return trimLeft(trimRight(s));
}
