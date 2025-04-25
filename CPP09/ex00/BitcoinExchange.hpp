#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
	public:
		// ━━━━━━━━━━━━━━━━━━━━ class init ━━━━━━━━━━━━━━━━━━━━ //
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// ━━━━━━━━━━━━━━━━━━ public methods ━━━━━━━━━━━━━━━━━━ //
		void	GetDataFile(const std::string &filename); // data.csv
		void	processInput(const std::string &filename); // input.txt
		double	getBitcoinValue(const std::string &date) const;

	private:
		// ━━━━━━━━━━━━━━━━ private attributes ━━━━━━━━━━━━━━━━ //
		// fonctionnement key(date)-value(taux de change) / tri chronologique automatique
		// utilisation de lower_bound pour trouver la date precedente la plus proche comme demande dans le sujet
		std::map<std::string, double> BTCvaluePerDate;

		// ━━━━━━━━━━━━━━━ date parsing methods ━━━━━━━━━━━━━━━ //
		bool	checkDate(const std::string &date) const;
		bool	checkDateFormat(const std::string &date) const;
		bool	checkDateRange(int year, int month, int day) const;

		// ━━━━━━━━━━━━━━━ value parsing methods ━━━━━━━━━━━━━━━ //
		bool	checkValue(const std::string &value) const;

		// ━━━━━━━━━━━━━━━ input's lines methods ━━━━━━━━━━━━━━━ //
		void	processLine(const std::string &line);
		bool	parseLine(const std::string &line, std::string &datePart, std::string &valuePart);
};

bool		isNotSpace(char c);
std::string &trimLeft(std::string &str);
std::string &trimRight(std::string &str);
std::string &trim(std::string &s);

//━━━━━━━━ANSI CODES━━━━━━━━━//
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"
#define WHITE		"\x1b[37m"
#define RESET		"\x1b[0m"

#define BOLD		"\x1b[1m"
#define UNDERLINE	"\x1b[4m"
#define RESET		"\x1b[0m"
#define RED_BOLD	"\033[1;31m"
#define GREEN_BOLD	"\033[1;32m"
