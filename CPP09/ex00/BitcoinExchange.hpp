#pragma once

#include <iostream>
#include <map>

class BitcoinExchange
{
	public:
		// ━━━━━━━━━━━━━━━━━━ class init ━━━━━━━━━━━━━━━━━━ //
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// ━━━━━━━━━━━━━━━━━━━━ methods ━━━━━━━━━━━━━━━━━━━ //
		void getData(const std::string &filename);
		void processData(const std::string &filename);
		double getBTCvalue(const std::string &date) const;

	private:
		std::map<std::string, double> ValuePerDate; // conteneur map -> association clé-valeur + tri auto selon clés
		bool checkValue(const std::string &value) const;
		bool checkDate(const std::string &date) const;
};

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
