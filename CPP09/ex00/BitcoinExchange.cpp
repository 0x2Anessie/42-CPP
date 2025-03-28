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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DATE VALIDATION ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool BitcoinExchange::checkDateFormat(const std::string &date) const
{
	return date.size() == 10 && date[4] == '-' && date[7] == '-';
}

bool BitcoinExchange::checkDigits(const std::string &date) const
{
	for (int i = 0; i < 4; ++i)
		if (!std::isdigit(date[i]))
			return false;
	for (int i = 5; i < 7; ++i)
		if (!std::isdigit(date[i]))
			return false;
	for (int i = 8; i < 10; ++i)
		if (!std::isdigit(date[i]))
			return false;
	return true;
}

bool BitcoinExchange::checkDateRange(int year, int month, int day) const
{
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		return day <= 29 && (day != 29 || isLeap);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	return true;
}

bool BitcoinExchange::checkDate(const std::string &date) const
{
	if (!checkDateFormat(date) || !checkDigits(date))
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	return checkDateRange(year, month, day);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ VALUE VALIDATION ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool BitcoinExchange::checkValue(const std::string &value) const
{
	char *end;
	double val = strtod(value.c_str(), &end);
	return end != value.c_str() && *end == '\0' && val >= 0;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FILE LOADING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void BitcoinExchange::loadFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Could not open file");

	std::string line;
	std::string date;
	double rate;

	// Lire la première ligne (en-tête)
	if (std::getline(file, line) && line != "date,exchange_rate")
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate))
			BTCvaluePerDate[date] = rate;
	}

	// Lire les lignes restantes
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

	double value = atof(valuePart.c_str());
	if (value > 1000)
	{
		std::cout << RED << "Error: " << RESET << "invalid value: too large" << std::endl;
		return;
	}

	double rate = getBitcoinValue(datePart);
	std::cout << datePart << " => " << value << " = " << value * rate << std::endl;
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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET BITCOIN VALUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

double BitcoinExchange::getBitcoinValue(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = BTCvaluePerDate.lower_bound(date);
	if (it == BTCvaluePerDate.end() || it->first != date)
	{
		if (it == BTCvaluePerDate.begin())
			return 0;
		--it;
	}
	return it->second;
}