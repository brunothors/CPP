/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:19:15 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 17:21:38 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include <stdexcept>
# include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> _exchange;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		double getExchangeValue(std::string date) const;

		bool readDataBase(std::string filename);
		void createDataBase(std::string date, double value);
		void printDataBase(std::string date, double value);
		bool dateCheck(std::string date);
};

#endif