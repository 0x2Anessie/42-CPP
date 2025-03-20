#include "BitcoinExchange.hpp"

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CLASS INIT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : ValuePerDate(other.ValuePerDate)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		ValuePerDate = other.ValuePerDate;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //



// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DATA PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool BitcoinExchange::checkValue(const std::string &value) const
{}

bool BitcoinExchange::checkDate(const std::string &date) const
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PROCESSING DATA METHODS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

void BitcoinExchange::getData(const std::string &filename)
{
	std::string currentLine;
	std::string date;
	double exchangeRate;
	std::ifstream file(filename.c_str());

	if (!file)
		throw std::runtime_error("ERROR! File could not be opened");

	if (std::getline(file, currentLine))
	{
		if (currentLine != "date,exchange_rate")
		{
			std::istringstream LineStream(currentLine);

			if (std::getline(LineStream, date, ',') && (LineStream >> exchangeRate))
				ValuePerDate[date] = exchangeRate;
		}
	}

	while (getline(file, currentLine))
	{
		std::istringstream LineStream(currentLine);

		if (getline(LineStream, date, ',') && (LineStream >> exchangeRate))
			ValuePerDate[date] = exchangeRate;

	}
}

void BitcoinExchange::processData(const std::string &filename)

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET BTC VALUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

