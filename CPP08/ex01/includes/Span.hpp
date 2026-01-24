/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:38:13 by bnespoli          #+#    #+#             */
/*   Updated: 2026/01/24 14:38:14 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class AddFail: public std::exception {
	public:
		const char* what() const throw() {
			return "Error: cannot add more numbers, Span is full!";
		}
};

class LongFail: public std::exception {
	public:
		const char* what() const throw() {
			return "Error: not enough numbers to calculate longest span!";
		}
};

class ShortFail: public std::exception {
	public:
		const char* what() const throw() {
			return "Error: not enough numbers to calculate shortest span!";
		}
};

class Span {
	private:
		std::vector<int> _numbers;
		unsigned int _size;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& rhs);
		~Span();
		Span& operator=(const Span& rhs);

		std::vector<int> getNumber();

		void addNumber(int n);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif