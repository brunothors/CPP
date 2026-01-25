/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:20:36 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 18:13:35 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
	*this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs) {
		this->_exchange = rhs._exchange;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getExchangeValue(std::string date) const {
	std::map<std::string, double>::const_iterator it = _exchange.lower_bound(date); //searches for the given date or the closest previously date
	if (it == _exchange.begin() && it->first != date)
		return 0; //returns 0 when the given date is lower than all of the database dates
	if (it != _exchange.begin() && it->first != date)
		return (--it)->second; //returns the closest date, when the given date doesn't exist
	return it->second;
}

bool BitcoinExchange::readDataBase(std::string filename) {
	std::ifstream db;
	std::string line;
	double value;

	db.open(filename.c_str());
	if(!db.is_open()) {
		std::cerr << "Error: File not found" << std::endl;
		return false;
	}

	std::getline(db, line);
	if(line != "date,exchange_rate") {
		std::cerr << "Error: Invalid dB format" << std::endl;
		return false;
	}

	while(getline(db, line)) {
		std::string date = line.substr(0, line.find(","));
		std::istringstream iss(line.substr(line.find(",") + 1, line.length()));
		iss >> value;
		createDataBase(date, value);
	}

	return true;
}

void BitcoinExchange::createDataBase(std::string date, double value) {
	_exchange[date] = value;
}

void BitcoinExchange::printDataBase(std::string date, double value) {
	if (!dateCheck(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	double result = getExchangeValue(date) * value;

	if (result < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else
		std::cout << date << " => " << value << " = " << result << std::endl;
}

bool BitcoinExchange::dateCheck(std::string date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2024) {
		return (false);
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	return true;
}