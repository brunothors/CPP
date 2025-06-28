/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:45:56 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/20 21:00:29 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (unsigned int i = 0; i < 100; ++i) {
		ideas_[i] = "No Idea";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (unsigned int i = 0; i < 100; ++i) {
			ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(unsigned int index) const {
	if (index < 100) {
		return ideas_[index];
	}
	return "Invalid index";
}

void Brain::setIdea(unsigned int index, const std::string &idea) {
	if (index < 100) {
		ideas_[index] = idea;
	} else {
		std::cout << "Invalid index" << std::endl;
	}
}