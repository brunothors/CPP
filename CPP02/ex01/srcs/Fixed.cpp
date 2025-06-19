/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:07:26 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/18 20:30:37 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * ( 1 << _fBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _fBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(Fixed const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
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