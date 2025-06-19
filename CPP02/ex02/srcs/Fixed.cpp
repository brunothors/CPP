/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:07:26 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/18 21:07:30 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(float const value) : _value(roundf(value * ( 1 << _fBits))) {}

Fixed::Fixed(int const value) : _value(value << _fBits) {}

Fixed::Fixed(Fixed const &other) {
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other) {
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

int Fixed::getRawBits(void) const {
	return _value;
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fBits);
}

int Fixed::toInt(void) const {
	return _value >> _fBits;
}

std::ostream &operator<<(std::ostream &oS, Fixed const &other) {
	oS << other.toFloat();
	return oS;
}

bool Fixed::operator>(Fixed const &param) const {
	return _value > param.getRawBits();
}

bool Fixed::operator<(Fixed const &param) const {
	return _value < param.getRawBits();
}

bool Fixed::operator>=(Fixed const &param) const {
	return _value >= param.getRawBits();
}

bool Fixed::operator<=(Fixed const &param) const {
	return _value <= param.getRawBits();
}

bool Fixed::operator==(Fixed const &param) const {
	return _value == param.getRawBits();
}

bool Fixed::operator!=(Fixed const &param) const {
	return _value != param.getRawBits();
}

Fixed Fixed::operator+(Fixed const &param) {
	return Fixed(this->toFloat() + param.toFloat());
}

Fixed Fixed::operator-(Fixed const &param) {
	return Fixed(this->toFloat() - param.toFloat());
}

Fixed Fixed::operator*(Fixed const &param) {
	return Fixed(this->toFloat() * param.toFloat());
}

Fixed Fixed::operator/(Fixed const &param) {
	if (param.getRawBits() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / param.toFloat());
}

Fixed Fixed::operator++(void) {
	_value++;
	return *this;
}

Fixed Fixed::operator--(void) {
	_value--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}