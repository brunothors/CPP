/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:29:23 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/19 19:39:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << name << " contructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    std::cout << "ClapTrap assignment operator called." << std::endl;
    if (this != &rhs) {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ClapTrap::setName(std::string const &name) {
    _name = name;
}

void ClapTrap::setHitPoints(unsigned int const hitPoints) {
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int const energyPoints) {
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int const attackDamage) {
    _attackDamage = attackDamage;
}

std::string ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}

void ClapTrap::attack(std::string const &target) {
    if (target.empty()) {
        std::cout << "ClapTrap " << _name << " cannot attack nothing!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is destroyed and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    } else if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
} 

void ClapTrap::takeDamage(unsigned int amount) {
    if(_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
        return;
    }
    if (_hitPoints > 0 && amount <= _hitPoints) {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
        if( _hitPoints == 0) {
            std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
        }
    } else if (_hitPoints > 0 && amount > _hitPoints) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
        std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
        return;
    } 
    if(_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
        return;
    } else if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points! Hit points now: " << _hitPoints << std::endl;
    }
}