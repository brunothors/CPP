/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:57:21 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/25 18:58:02 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& rhs) {
	_stack = rhs._stack;
}

RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		_stack = rhs._stack;
	}
	return *this;
}

RPN::~RPN() {}

ssize_t RPN::calculate(const std::string& expr) {
	for (size_t i = 0; i < expr.length(); ++i) {
		char token = expr[i];

		if (isdigit(token)) {
			_stack.push(token - '0');
		} else if (token == '+' || token == '-' || token == '*' || token == '/') {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error: insufficient values in expression.");
			}
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int result;

			switch (token) {
				case '+': result = a + b; break;
				case '-': result = a - b; break;
				case '*': result = a * b; break;
				case '/':
					if (b == 0) {
						throw std::runtime_error("Error: division by zero.");
					}
					result = a / b; break;
			}
			_stack.push(result);
		} else if (token != ' ') {
			throw std::runtime_error(std::string("Error: invalid token '") + token + "'.");
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error: too many values in expression.");
	}

	return _stack.top();
}