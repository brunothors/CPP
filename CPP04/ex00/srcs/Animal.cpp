/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:40:40 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 19:53:09 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.getType();
	}
	return *this;
}

std::string Animal::getType() const {
	return type_;
}

void Animal::setType(const std::string &type) {
	type_ = type;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a sound" << std::endl;
}