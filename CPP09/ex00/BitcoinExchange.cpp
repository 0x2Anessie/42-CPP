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

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DATA PARSING ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

bool BitcoinExchange::checkValue(const std::string &value) const
{}

bool BitcoinExchange::checkDate(const std::string &date) const
{}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ UTILS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //



// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PROCESSING DATA METHODS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //



// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GET BTC VALUE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ //

