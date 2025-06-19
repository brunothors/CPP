/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:21:31 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:39:45 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    std::cout << "ScavTrap assignment operator called." << std::endl;
    if (this != &rhs) {
        setName(rhs.getName());
        setHitPoints(rhs.getHitPoints());
        setEnergyPoints(rhs.getEnergyPoints());
        setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

void ScavTrap::attack(std::string const &target) {
    if (target.empty()) {
        std::cout << "Scavtrap " << getName() << " cannot attack nothing!" << std::endl;
        return;
    }
    if (getHitPoints() == 0) {
        std::cout << "Scavtrap " << getName() << " is destroyed and cannot attack!" << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "Scavtrap " << getName() << " has no energy left to attack!" << std::endl;
        return;
    } else if (getEnergyPoints() > 0 && getHitPoints() > 0) {
        std::cout << "Scavtrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
}

void ScavTrap::guardGate() {
    std::cout << "Scavtrap " << getName() << " is now in Gate Keeper mode!" << std::endl;
}