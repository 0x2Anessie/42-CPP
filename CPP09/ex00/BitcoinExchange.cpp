#include "BitcoinExchange.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CLASS INIT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : m_bitcoinValues(other.m_bitcoinValues)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		m_bitcoinValues = other.m_bitcoinValues;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool isNotSpace(char c)
{
	return !std::isspace(static_cast<unsigned char>(c));
}

std::string &ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
	return s;
}

std::string &rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
	return s;
}

std::string &trim(std::string &s)
{
	return ltrim(rtrim(s));
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 4; ++i)
		if (!std::isdigit(date[i]))
			return false;
	for (int i = 5; i < 7; ++i)
		if (!std::isdigit(date[i]))
			return false;
	for (int i = 8; i < 10; ++i)
		if (!std::isdigit(date[i]))
			return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && !isLeap))
			return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
	char* end;
	double val = strtod(value.c_str(), &end);

	return end != value.c_str() && *end == '\0' && val >= 0;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DATA PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void BitcoinExchange::loadFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if(!file)
		throw std::runtime_error("Could not open file");
	std::string line;
	std::string date;
	double rate;
	if(std::getline(file, line))
	{
		if(line != "date,exchange_rate")
		{
			std::istringstream ss(line);
			if(std::getline(ss, date, ',') && (ss >> rate))
				m_bitcoinValues[date] = rate;
		}
	}
	while(getline(file, line))
	{
		std::istringstream ss(line);
		if(getline(ss, date, ',') && (ss >> rate))
		{
			m_bitcoinValues[date] = rate;
		}
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PROCESSING DATA METHODS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if(!file)
		throw std::runtime_error("Could not open file");
	std::string fileLine;
	std::string datePart;
	std::string valuePart;
	double value;
	bool firstLine = true;

	while(getline(file, fileLine))
	{
		trim(fileLine);
		if(firstLine)
		{
			if(fileLine == "date | value")
			{
				firstLine = false;
				continue;
			}
		}
		firstLine = false;
		std::stringstream ss(fileLine);
		if (fileLine[11] != '|' || fileLine[10] != ' ' || fileLine[12] != ' ')
		{
			fileLine = fileLine.empty() ? "empty" : fileLine;
			std::cout << "Invalid input: " << fileLine << std::endl;
			continue;
		}
		if(getline(ss, datePart, '|'))
		{
			if(!getline(ss, valuePart))
			{
				std::cout << "Invalid input: " << fileLine << std::endl;
				continue;
			}
			datePart.erase(datePart.find_last_not_of(" \n\r\t") + 1);
			valuePart.erase(0, valuePart.find_first_not_of(" \n\r\t"));
			if(!isValidDate(datePart))
			{
				std::cout << "Invalid input: " << datePart << std::endl;
				continue;
			}
			if(!isValidValue(valuePart))
			{
				std::cout << "Invalid input: " << valuePart << std::endl;
				continue;
			}
			value = atof(valuePart.c_str());
			if(value > 1000)
			{
				std::cout << "Invalid value: too large"<< std::endl;
				continue;
			}
			double rate = getBitcoinValue(datePart);
			std::cout << datePart << " => " << value << " = " << value * rate << std::endl;
		}
		else
		{
			fileLine = fileLine.empty() ? "empty" : fileLine;
			std::cout << "Invalid input: " << fileLine << std::endl;
		}
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET BTC VALUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

double BitcoinExchange::getBitcoinValue(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = m_bitcoinValues.lower_bound(date);
	if(it == m_bitcoinValues.end() || it->first != date)
	{
		if(it == m_bitcoinValues.begin())
			return 0;
		--it;
	}
	return it->second;
}
