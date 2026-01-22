/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDetection.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:33:49 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/22 17:36:17 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Type impossibleType(std::string const& str) {
	Type tarr[8] = {TNAN, TNAN, NEG_INF, NEG_INF, POS_INF, POS_INF, POS_INF, POS_INF};

	std::string Type[8] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff", "inf", "inff"};
	for (int i = 0; i < 8; i++) {
		if (str == Type[i]) {
			return tarr[i];
		}
	}
	return INVALID;
}

Type testOverflow(std::string const& str) {
	std::istringstream iss(str);
	int num = 0;
	iss.exceptions(std::ios::failbit);
	try {
		iss >> num;
	} catch (std::exception& e) {
		(void)e;
		return INVALID;
	}
	return INT;
}

Type testInfinite(std::string const& str, Type type) {
	std::istringstream iss(str);
	double numd = static_cast<double>(0);
	float numf = static_cast<float>(0);
	iss.exceptions(std::ios::failbit);
	switch(type)
	{	
		case FLOAT:
			try {
				iss >> numf;
				if(std::isinf(numf))
					return numf < 0 ? NEG_INF : POS_INF;
				return FLOAT;
			} catch (std::exception& e) {
				(void)e;
				return INVALID;
			}
			break;
		case DOUBLE:
			try {
				iss >> numd;
				if(std::isinf(numd))
					return numd < 0 ? NEG_INF : POS_INF;
				return DOUBLE;
			} catch (std::exception& e) {
				(void)e;
				return INVALID;
			}
			break;
		default:
			return INVALID;
	}
}

Type validType(std::string const& str) {
	if(str.size() == 1 && !isdigit(str[0]))
		return CHAR;
	else if(str.find_first_of(".") == std::string::npos)
		return testOverflow(str);
	else if(str.find_first_of("f") != std::string::npos)
		return testInfinite(str, FLOAT);
	else if(str.find_first_of(".") != std::string::npos)
		return testInfinite(str, DOUBLE);
	return INVALID;
}

Type detectType(std::string const& str) {
	switch (impossibleType(str)) {
		case TNAN:
			return TNAN;
		case NEG_INF:
			return NEG_INF;
		case POS_INF:
			return POS_INF;
		default:
			break;
	}
	switch (validType(str)) {
		case CHAR:
			return CHAR;
		case INT:
			return INT;
		case FLOAT:
			return FLOAT;
		case DOUBLE:
			return DOUBLE;
		case INVALID:
			return INVALID;
		case POS_INF:
			return POS_INF;
		case NEG_INF:
			return NEG_INF;
		default:
			break;
	}
	return INVALID;
}