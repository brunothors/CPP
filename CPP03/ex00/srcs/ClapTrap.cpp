/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:29:23 by bnespoli         #+#    #+#             */
/*   Updated: 2025/06/19 07:29:24 by bnespoli        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

Claptrap::Claptrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Claptrap default constructor called." << std::endl;
}

Claptrap::Claptrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Claptrap " << name << " contructor called" << std::endl;
}

Claptrap::Claptrap(Claptrap const &src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
    std::cout << "Claptrap copy constructor called." << std::endl;
}

Claptrap::~Claptrap() {
    std::cout << "Claptrap destructor called." << std::endl;
}

Claptrap &Claptrap::operator=(Claptrap const &rhs) {
    std::cout << "Claptrap assignment operator called." << std::endl;
    if (this != &rhs) {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

void Claptrap::setName(std::string const &name) {
    _name = name;
}

void Claptrap::setHitPoints(unsigned int const hitPoints) {
    _hitPoints = hitPoints;
}

void Claptrap::setEnergyPoints(unsigned int const energyPoints) {
    _energyPoints = energyPoints;
}

void Claptrap::setAttackDamage(unsigned int const attackDamage) {
    _attackDamage = attackDamage;
}

std::string Claptrap::getName() const {
    return _name;
}

unsigned int Claptrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int Claptrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int Claptrap::getAttackDamage() const {
    return _attackDamage;
}

void Claptrap::attack(std::string const &target) {
    if (target.empty()) {
        std::cout << "Claptrap " << _name << " cannot attack nothing!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "Claptrap " << _name << " is destroyed and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "Claptrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    } else if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "Claptrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
} 

void Claptrap::takeDamage(unsigned int amount) {
    if(_hitPoints == 0) {
        std::cout << "Claptrap " << _name << " is already destroyed!" << std::endl;
        return;
    }
    if (_hitPoints > 0 && amount <= _hitPoints) {
        _hitPoints -= amount;
        std::cout << "Claptrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
        if( _hitPoints == 0) {
            std::cout << "Claptrap " << _name << " is destroyed!" << std::endl;
        }
    } else if (_hitPoints > 0 && amount > _hitPoints) {
        _hitPoints = 0;
        std::cout << "Claptrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
        std::cout << "Claptrap " << _name << " is destroyed!" << std::endl;
    }
}

void Claptrap::beRepaired(unsigned int amount) {
    if(_hitPoints == 0) {
        std::cout << "Claptrap " << _name << " is already destroyed!" << std::endl;
        return;
    } 
    if(_energyPoints == 0) {
        std::cout << "Claptrap " << _name << " has no energy left to repair!" << std::endl;
        return;
    } else if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "Claptrap " << _name << " is repaired by " << amount << " points! Hit points now: " << _hitPoints << std::endl;
    }
}