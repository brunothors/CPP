/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:37:10 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/16 23:19:47 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed") {
	std::cout << _name << " zombie created." << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " zombie destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}