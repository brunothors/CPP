/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:40:40 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 21:59:29 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type_("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.getType();
	}
	return *this;
}

std::string AAnimal::getType() const {
	return type_;
}

void AAnimal::setType(const std::string &type) {
	type_ = type;
}