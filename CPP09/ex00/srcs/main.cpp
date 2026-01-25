/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:20:26 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 19:46:40 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	if (!btc.readDataBase("data.csv"))
	{
		std::cerr << "Error: could not open database." << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::getline(inputFile, line); // Skip header line
	if(line != "date | value") {
		std::cerr << "Error: Invalid input format" << std::endl;
		return 1;	
	} // Check header format(necessary in some subjects)

	while(getline(inputFile, line)) {
		std::string date;
		double value = 0;
		
		size_t delimPos = line.find(" | ");
		if (delimPos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		date = line.substr(0, delimPos);
		std::string valueStr = line.substr(delimPos + 3);
		
		// Trim whitespace from valueStr
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
		
		if (valueStr.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::istringstream iss(valueStr);
		if (!(iss >> value)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (!btc.dateCheck(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
		}
		else if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
		}
		else if (value > 1000) {
			std::cout << "Error: too large a number" << std::endl;
		}
		else {
			btc.printDataBase(date, value);
		}
	}

	return 0;
}